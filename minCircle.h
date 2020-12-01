/*
 * minCircle.h
 *
 * Author: 303080097 Ohad Azran & 313581688 Amit Ilovitch
 */
// ID1 303080097	ID2 313581688

#ifndef MINCIRCLE_H_
#define MINCIRCLE_H_


using namespace std;

// ------------ DO NOT CHANGE -----------
class Point{
public:
    float x,y;
    Point(float x,float y):x(x),y(y){}
};

class Circle{
public:
    Point center;
    float radius;
    Circle(Point c,float r):center(c),radius(r){}
};
//

// implement
Circle findMinCircle(Point** points,size_t size);
// you may add helper functions here
float distance(const Point& a, const Point& b);
bool point_in_circle(const Circle& c, const Point& p);
Circle min_circle_helper(vector<Point>& P, vector<Point> R, int n);
Circle get_circle_until_3_point(vector<Point>& P);
bool all_point_in_circle(const Circle& c, const vector<Point>& P);
Circle get_circle_2_point(const Point& A, const Point& B);
Circle get_circle_3_point(const Point& A, const Point& B, const Point& C);
Point func_helper_3_point(float bx, float by, float cx, float cy);



#endif *//* MINCIRCLE_H_
