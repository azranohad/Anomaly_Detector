/*
 * SimpleAnomalyDetector.cpp
 *
 * Author: 303080097 Ohad Azran
 */
#include "SimpleAnomalyDetector.h"
#include "minCircle.h"
#include <cmath>

using namespace std;

SimpleAnomalyDetector::SimpleAnomalyDetector() {}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
    // TODO Auto-generated destructor stub
}
/*
 * Returns the distance of the farthest point in the sample from the line
 */
float SimpleAnomalyDetector::MaxDev(Point** points,Line lin_reg, size_t size) {
    float dev_coefficient = 1.1;
    float max_dev;
    for (int i_point = 0; i_point < size; i_point++) {
        Point point(points[i_point]->x, points[i_point]->y);
        float dev_temp = dev(point, lin_reg);
        if ((i_point == 0) || (dev_temp > max_dev)) {
            max_dev = dev_temp;
        }
    }
    return max_dev * dev_coefficient;
}
/*
 * Checks for the cf vector, correlatedFeatures with properties obtained
 */
bool SimpleAnomalyDetector::search_in_cf(string feature1, string feature2, vector<correlatedFeatures> cf) {
    for (auto cf_t : cf) {
        if((cf_t.feature1 == feature1) && (cf_t.feature2 == feature2)) {
            return true;
        } else if ((cf_t.feature1 == feature2) && (cf_t.feature2 == feature1)) {
            return true;
        }
    }
    return false;
}
Point** SimpleAnomalyDetector::createPoints(vector<float> x, vector<float> y){
    Point** points = new Point*[x.size()];
    for(size_t i=0;i < x.size(); i++){
        points[i]=new Point(x[i],y[i]);
    }
    return points;
}
void SimpleAnomalyDetector::deletePoint(Point** points, int size) {
    for (int i_point = 0; i_point < size; i_point++) {
        delete[] points[i_point];
    }
}
/*
 * calculate the threshold and lin_reg for one cf.
 */
void SimpleAnomalyDetector::calculate_threshold(correlatedFeatures* cf) {

    int size = cf->x_vec.size();
        Point** points = createPoints(cf->x_vec, cf->y_vec);
        cf->lin_reg = linear_reg(points, size);
        cf->threshold = MaxDev(points, cf->lin_reg, size);
        //delete points.
        deletePoint(points, size);
}
/*
 * Returns the index of the highest correlated correlatedFeatures out of the cf_vec_temp
 */
int SimpleAnomalyDetector::max_i_corr_in_cf_vec(vector<correlatedFeatures> cf_vec_temp) {
    int i_cf_temp_max = 0;
    float corr_temp_max = 0;
    for (int i = 0; i < cf_vec_temp.size(); i++) {
        if (cf_vec_temp[i].corrlation > corr_temp_max) {
            corr_temp_max = cf_vec_temp[i].corrlation;
            i_cf_temp_max = i;
        }
    }
    return i_cf_temp_max;
}

/*
 * Checks whether the cf list matches the measured property with a higher correlation
 */
bool SimpleAnomalyDetector::search_cf_higher(float corr_max_temp, string feature, vector<correlatedFeatures> cf) {
    for (auto cf_t : cf) {
        if ((cf_t.feature1 == feature) || (cf_t.feature2 == feature)) {
            if (cf_t.corrlation < corr_max_temp) {
                return false;
            }
        }
    }
    return true;
}
void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){
    int i, j;
    TimeSeries ts1 = ts;
    int size_vector = ts1.vec_col[ts1.headers[0]].size();
    for (i = 0; i < ts.vec_col.size(); i++) {
        vector<correlatedFeatures> cf_vec_temp;
        for(j = 0; j < ts.vec_col.size(); j++) {
            //the correlation is symmetric
            if (search_in_cf(ts1.headers[i], ts1.headers[j], cf)) {
                continue;
            } else if (i == j) {
                continue;
            }
            float correlation = pearson(ts1.vec_col[ts1.headers[i]].data(),
                                      ts1.vec_col[ts1.headers[j]].data(),
                                     size_vector);
            correlation = std::abs(correlation);
            if (correlation < 0.5) {
                continue;
            }
            correlatedFeatures corrF_temp;
            corrF_temp.corrlation = correlation;
            if (i < j) {
                corrF_temp.feature1 = ts1.headers[i];
                corrF_temp.feature2 = ts1.headers[j];
            } else {
                corrF_temp.feature2 = ts1.headers[i];
                corrF_temp.feature1 = ts1.headers[j];
            }
            corrF_temp.x_vec = ts1.vec_col[ts1.headers[i]];
            corrF_temp.y_vec = ts1.vec_col[ts1.headers[j]];
            cf_vec_temp.push_back(corrF_temp);
        }
        if (!cf_vec_temp.empty()) {
            int i_corr_max_cf_temp = max_i_corr_in_cf_vec(cf_vec_temp);
            if (search_cf_higher(cf_vec_temp[i_corr_max_cf_temp].corrlation, ts1.headers[i], cf)) {
                calculate_threshold(&cf_vec_temp[i_corr_max_cf_temp]);
                cf.push_back(cf_vec_temp[i_corr_max_cf_temp]);
            }
        }
    }
}
/*
 * check if the dev line bigger from threshold.
 */
bool SimpleAnomalyDetector::reportAnomaly(correlatedFeatures* cf_t, Point point) {
    float dev_line = dev(point, cf_t->lin_reg);
    if (dev_line > cf_t->threshold) {
        return true;
    }
    return false;
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
    TimeSeries ts1 = ts;
    vector<AnomalyReport> vector_report;
    int size = ts1.vec_col[ts1.headers[0]].size();
    for (auto cf_t : cf) {
        for(int i = 0; i < size; i++) {
            Point point(ts1.vec_col[cf_t.feature1][i], ts1.vec_col[cf_t.feature2][i]);
            if (reportAnomaly(&cf_t, point)) {
                AnomalyReport ar(cf_t.feature1 +"-"+cf_t.feature2, (long)i+1);
                vector_report.push_back(ar);
            }
        }
    }
    return vector_report;
}

