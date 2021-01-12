/*
 * minCircle.cpp
 *
 * Author: 303080097 Ohad Azran & 313581688 Amit Ilovitch
 */
#include <algorithm>
#include <cassert>
#include <cmath>
#include <random>
#include <vector>
#include "minCircle.h"
#include "anomaly_detection_util.h"

using namespace std;

/*
 * distance between two points.
 */
float distance(const Point& a, const Point& b)
{
    float diff_x = pow(a.x - b.x, 2);
    float diff_y = pow(a.y - b.y, 2);
    return sqrt(diff_x + diff_y);
}

/*
 * the function check if the point p inside the circle.
 */
bool point_in_circle(const Circle& c, const Point& p)
{
    if (distance(c.center, p) <= c.radius) {
        return true;
    }
    return false;
}
/*
 * function helper to calculate the smallest circle from 3 points.
 */
Point func_helper_3_point(float bx, float by, float cx, float cy) {
    float B = bx * bx + by * by;
    float C = cx * cx + cy * cy;
    float D = bx * cy - by * cx;
    Point point ((cy * B - by * C) / (2 * D),(bx * C - cx * B) / (2 * D));
    return point;
}
/*
 * return the smallest circle from 3 points.
 */
Circle get_circle_3_point(const Point& A, const Point& B, const Point& C)
{
    Point help_point = func_helper_3_point(B.x - A.x, B.y - A.y,
                                C.x - A.x, C.y - A.y);

    help_point.x += A.x;
    help_point.y += A.y;
    float r = distance(help_point, A);
    Circle circle (help_point, r);
    return circle;
}

/*
 * return the smallest circle from 2 points.
 */
Circle get_circle_2_point(const Point& A, const Point& B)
{
    // center between A point & B point.
    Point C ((A.x + B.x) / 2.0, (A.y + B.y) / 2.0);
    float r = distance(A, B) / 2;
    Circle circle(C, r);
    return circle;
}
/*
 * check if all point inside the circle.
 */
bool all_point_in_circle(const Circle& c, const vector<Point>& P) {
    for (const Point& p : P)
        if (!point_in_circle(c, p))
            return false;
    return true;
}

/*
 * if number of point smallest 3, the function return the smallest circle.
 */
Circle get_circle_until_3_point(vector<Point>& points)
{
    assert(points.size() <= 3);
    if (points.empty()) {
        return { { 0, 0 }, 0 };
    }
    else if (points.size() == 1) {
        return { points[0], 0 };
    }
    else if (points.size() == 2) {
        return get_circle_2_point(points[0], points[1]);
    }

    /*
     * check if all 3 point inside circle that make from only 2 point,
     * else, all 3 point about scope the circle.
     */
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {

            Circle c = get_circle_2_point(points[i], points[j]);
            if (all_point_in_circle(c, points))
                return c;
        }
    }
    //all 3 point about scope the circle.
    return get_circle_3_point(points[0], points[1], points[2]);
}

/*
 * The function calls itself recursively with a small input at one,
 * until the number of points in the p_vec is 0.
 * back to the function from the additional recursive readings when
 * s_vec contains 3 points the function calculates their minimum circles.
 */
Circle min_circle_helper(vector<Point>& p_vec, vector<Point> s_vec, int n)
{
    // Base case when all points processed or |R| = 3
    if (n == 0 || s_vec.size() == 3) {
        return get_circle_until_3_point(s_vec);
    }
    int idx = rand() % n;
    Point p = p_vec[idx];
    swap(p_vec[idx], p_vec[n - 1]);

    Circle d = min_circle_helper(p_vec, s_vec, n - 1);

    if (point_in_circle(d, p)) {
        return d;
    }

    s_vec.push_back(p);
    return min_circle_helper(p_vec, s_vec, n - 1);
}
/*
 * return the minimal enclosure circle.
 */
Circle findMinCircle(Point** points,size_t size)
{
    vector<Point> point_vec;
    for (int i = 0; i < size; i++) {
        point_vec.push_back(*points[i]);
    }
    vector<Point> P_copy = point_vec;
    shuffle(P_copy.begin(), P_copy.end(), std::mt19937(std::random_device()()));
    return min_circle_helper(P_copy, {}, P_copy.size());
}

