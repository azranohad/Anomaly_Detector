

#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include "minCircle.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

struct correlatedFeatures{
    string feature1,feature2;  // names of the correlated features
    float corrlation;
    Line lin_reg;
    float threshold;

    float x_center;
    float y_center;
    vector<float> x_vec;
    vector<float> y_vec;
};


class SimpleAnomalyDetector:public TimeSeriesAnomalyDetector{
    vector<correlatedFeatures> cf;
public:
    SimpleAnomalyDetector();
    virtual ~SimpleAnomalyDetector();

/*
    virtual int max_i_corr_in_cf_vec(vector<correlatedFeatures> cf_vec_temp);
*/
    virtual bool search_in_cf(string feature1, string feature2, vector<correlatedFeatures> cf);
    virtual float MaxDev(Point* points[],Line lin_reg, size_t size);
    void learnNormal(const TimeSeries& ts);
    virtual void deletePoint(Point** points, int size);
    virtual void calculate_threshold(correlatedFeatures* cf);
    virtual bool reportAnomaly(correlatedFeatures* cf_t, Point point);
    bool search_cf_higher(float corr_max_temp, string feature, vector<correlatedFeatures> cf);
    Point** createPoints(vector<float> x, vector<float> y);
    int max_i_corr_in_cf_vec(vector<correlatedFeatures> cf_vec_temp);
    virtual vector<AnomalyReport> detect(const TimeSeries& ts);

    vector<correlatedFeatures> getNormalModel(){
        return cf;
    }

};



#endif /* SIMPLEANOMALYDETECTOR_H_ */
