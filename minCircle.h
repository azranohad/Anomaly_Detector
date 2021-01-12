
// ID1 303080097	ID2 313581688

#ifndef MINCIRCLE_H_
#define MINCIRCLE_H_


#include <algorithm>
#include <cassert>
#include <cmath>
#include <random>
#include <vector>
#include "anomaly_detection_util.h"
using namespace std;

class Circle{
public:
    Point center;
    float radius;
    Circle(Point c,float r):center(c),radius(r){}
};

/*
 * distance between two points.
 */
float distance(const Point& a, const Point& b);

/*
 * the function check if the point p inside the circle.
 */
bool point_in_circle(const Circle& c, const Point& p);
/*
 * function helper to calculate the smallest circle from 3 points.
 */
Point func_helper_3_point(float bx, float by, float cx, float cy);
/*
 * return the smallest circle from 3 points.
 */
Circle get_circle_3_point(const Point& A, const Point& B, const Point& C);

/*
 * return the smallest circle from 2 points.
 */
Circle get_circle_2_point(const Point& A, const Point& B);
/*
 * check if all point inside the circle.
 */
bool all_point_in_circle(const Circle& c, const vector<Point>& P);

/*
 * if number of point smallest 3, the function return the smallest circle.
 */
Circle get_circle_until_3_point(vector<Point>& points);

/*
 * The function calls itself recursively with a small input at one,
 * until the number of points in the p_vec is 0.
 * back to the function from the additional recursive readings when
 * s_vec contains 3 points the function calculates their minimum circles.
 */
Circle min_circle_helper(vector<Point>& p_vec, vector<Point> s_vec, int n);

/*
 * return the minimal enclosure circle.
 */
Circle findMinCircle(Point** points,size_t size);

#endif /* MINCIRCLE_H_*/
