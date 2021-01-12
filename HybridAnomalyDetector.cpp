#include "HybridAnomalyDetector.h"
#include "anomaly_detection_util.h"
#include "SimpleAnomalyDetector.h"
#include "minCircle.h"
using namespace std;
HybridAnomalyDetector::HybridAnomalyDetector() {
    // TODO Auto-generated constructor stub
}

HybridAnomalyDetector::~HybridAnomalyDetector() {
    // TODO Auto-generated destructor stub
}
void HybridAnomalyDetector::calculate_threshold(correlatedFeatures* cf) {

    int size = cf->x_vec.size();
    if (cf->corrlation >= client_corr) {
        SimpleAnomalyDetector::calculate_threshold(cf);
    } else {
        Point** points = createPoints(cf->x_vec, cf->y_vec);
        Circle circle = findMinCircle(points, size);
        cf->threshold = circle.radius * 1.1;
        cf->x_center = circle.center.x;
        cf->y_center = circle.center.y;
        //delete points.
        deletePoint(points, size);
    }
}

/*
 * check if the dev line bigger from threshold.
 */
bool HybridAnomalyDetector::reportAnomaly(correlatedFeatures* cf_t, Point point) {

    if (cf_t->corrlation >= client_corr) {
        // is simple anomaly detector
        SimpleAnomalyDetector::reportAnomaly(cf_t, point);
    }else {
        //is circle anomaly detector
        float dist = distance(point, Point(cf_t->x_center, cf_t->y_center));
        if (dist > cf_t->threshold) {
            return true;
        }
        return false;
    }
}






