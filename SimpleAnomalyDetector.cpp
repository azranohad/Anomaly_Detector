/*
 * SimpleAnomalyDetector.cpp
 *
 * Author: 303080097 Ohad Azran
 */
#include "SimpleAnomalyDetector.h"
#include <cmath>

using namespace std;

SimpleAnomalyDetector::SimpleAnomalyDetector() {}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
    // TODO Auto-generated destructor stub
}
/*
 * Returns the distance of the farthest point in the sample from the line
 */
float MaxDev(Point* points[],Line lin_reg, int size) {
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
bool search_in_cf(string feature1, string feature2, vector<correlatedFeatures> cf) {
    for (auto &cf_t : cf) {
        if((cf_t.feature1 == feature1) && (cf_t.feature2 == feature2)) {
            return true;
        } else if ((cf_t.feature1 == feature2) && (cf_t.feature2 == feature1)) {
            return true;
        }
    }
    return false;
}

/*
 * Returns the index of the highest correlated correlatedFeatures out of the cf_vec_temp
 */
int max_i_corr_in_cf_vec(vector<correlatedFeatures> cf_vec_temp) {
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
bool search_cf_higher(float corr_max_temp, string feature, vector<correlatedFeatures> cf) {
    for (auto &cf_t : cf) {
        if ((cf_t.feature1 == feature) || (cf_t.feature2 == feature)) {
            if (cf_t.corrlation < corr_max_temp) {
                return false;
            }
        }
    }
    return true;
}
void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){
    int i;
    int j;
    TimeSeries ts1 = ts;
    int size_vector = ts1.vec_col[ts1.headers[0]].size();
    for (i = 0; i < ts.vec_col.size(); i++) {
        vector<correlatedFeatures> cf_vec_temp;
        for(j = 0; j < ts.vec_col.size(); j++) {
            if (search_in_cf(ts1.headers[i], ts1.headers[j], cf)) {
                continue;
            } else if (i == j) {
                continue;
            }
            float correlation = pearson(ts1.vec_col[ts1.headers[i]].data(),
                                      ts1.vec_col[ts1.headers[j]].data(),
                                     size_vector);
            correlation = std::abs(correlation);
            if (correlation < 0.9) {
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
            Point* points[size_vector];
            int i_point;
            for (i_point = 0; i_point < size_vector; i_point++) {
                points[i_point] = new Point(ts1.vec_col[ts1.headers[i]][i_point],
                            ts1.vec_col[ts1.headers[j]][i_point]);
            }
            corrF_temp.lin_reg = linear_reg(points, size_vector);
            corrF_temp.threshold = MaxDev(points, corrF_temp.lin_reg, size_vector);
            cf_vec_temp.push_back(corrF_temp);

            for (i_point = 0; i_point < size_vector; i_point++) {
                delete[] points[i_point];
            }

        }
        if (!cf_vec_temp.empty()) {
            int i_corr_max_cf_temp = max_i_corr_in_cf_vec(cf_vec_temp);
            if (search_cf_higher(cf_vec_temp[i_corr_max_cf_temp].corrlation, ts1.headers[i], cf)) {
                cf.push_back(cf_vec_temp[i_corr_max_cf_temp]);
            }
        }
    }
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
    TimeSeries ts1 = ts;
    vector<AnomalyReport> vector_report;
    for(int i = 0; i < ts1.vec_col[ts1.headers[0]].size(); i++) {
        for (auto &cf_t : cf) {
            Point point(ts1.vec_col[cf_t.feature1][i], ts1.vec_col[cf_t.feature2][i]);
            float dev_line = dev(point, cf_t.lin_reg);
            if (dev_line > cf_t.threshold) {
                AnomalyReport ar(cf_t.feature1 +"-"+cf_t.feature2, (long)i+1);
                vector_report.push_back(ar);
            }
        }
    }
    return vector_report;
}

