

#ifndef HYBRIDANOMALYDETECTOR_H_
#define HYBRIDANOMALYDETECTOR_H_

#include "SimpleAnomalyDetector.h"
#include "minCircle.h"

class HybridAnomalyDetector:public SimpleAnomalyDetector {
public:
    float client_corr = 0.9;     //threshold of correlation.
    HybridAnomalyDetector();

    virtual ~HybridAnomalyDetector();
    virtual void calculate_threshold(correlatedFeatures *cf);
    virtual bool reportAnomaly(correlatedFeatures *cf_t, Point point);;

};

#endif /* HYBRIDANOMALYDETECTOR_H_ */
