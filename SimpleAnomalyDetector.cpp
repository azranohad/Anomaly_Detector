
#include "SimpleAnomalyDetector.h"
#include <cmath>
SimpleAnomalyDetector::SimpleAnomalyDetector() {}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
    // TODO Auto-generated destructor stub
}

float MaxDev(Point* points[],Line lin_reg, int size) {
    float dev_coefficient = 1.1;
    for (int i_point = 0; i_point < size; i_point++) {
        Point point(points[i_point]->x, points[i_point]->y);
        float max_dev;
        float dev_temp = dev(point, lin_reg);
        if ((i_point == 0) || (dev_temp > max_dev)) {
            max_dev = dev_temp;
        }
        return max_dev * dev_coefficient;
    }
}
bool search_in_cf(string feature1, string feature2, vector<correlatedFeatures> cf) {
    for (auto &cf_t : cf) {
        if((cf_t.feature1 == feature1) && (cf_t.feature2 == feature2)) {
            return true;
        } else if ((cf_t.feature1 == feature2) && (cf_t.feature2 == feature1)) {
            return true;
        }
        return false;
    }
}
int max_i_corr_in_cf_vec(vector<correlatedFeatures> cf_vec_temp) {
    int i_cf_temp_max = 0;
    float corr_temp_max = 0;
    for (int i = 0; i < cf_vec_temp.size(); i++) {
        if (cf_vec_temp[i].correlation > corr_temp_max) {
            corr_temp_max = cf_vec_temp[i].correlation;
            i_cf_temp_max = i;
        }
    }
    return i_cf_temp_max;
}
bool search_cf_higher(float corr_max_temp, string feature, vector<correlatedFeatures> cf) {
    for (auto &cf_t : cf) {
        if ((cf_t.feature1 == feature) || (cf_t.feature2 == feature)) {
            if (cf_t.correlation < corr_max_temp) {
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
            corrF_temp.correlation = correlation;
            corrF_temp.feature1 = ts1.headers[i];
            corrF_temp.feature2 = ts1.headers[j];
            Point* points[size_vector];
            int i_point;
            for (i_point = 0; i_point < size_vector; i_point++) {
                 points[i_point] = new Point(ts1.vec_col[ts1.headers[i]][i_point],
                                     ts1.vec_col[ts1.headers[j]][i_point]);
            }
            corrF_temp.lin_reg = linear_reg(points, size_vector);
            corrF_temp.threshold = MaxDev(points, corrF_temp.lin_reg, size_vector);
            cf_vec_temp.push_back(corrF_temp);
        }
        int i_corr_max_cf_temp = max_i_corr_in_cf_vec(cf_vec_temp);
        if (search_cf_higher(cf_vec_temp[i_corr_max_cf_temp].correlation, ts1.headers[i], cf)) {
            cf.push_back(cf_vec_temp[i_corr_max_cf_temp]);
        }
    }
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
    TimeSeries ts1 = ts;
    vector<AnomalyReport> vector_report;
    for(int i = 0; i < ts1.vec_col[ts1.headers[0]].size(); i++) {
        for (auto &cf_t : cf) {
            float dev = ts1.vec_col[cf_t.feature1][i] - ts1.vec_col[cf_t.feature2][i];
            dev = std::abs(dev);
            if (dev > cf_t.threshold) {
                AnomalyReport ar(cf_t.feature1 +"-"+cf_t.feature2, (long)i+1);
                vector_report.push_back(ar);
            }
        }
    }
    return vector_report;
}

