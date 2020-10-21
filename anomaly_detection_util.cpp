/*
 * animaly_detection_util.cpp
 *
 * Author: write your ID and name here
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "anomaly_detection_util.h"

float avg(float* x, int size){
    if (size == 0) {
        return 0;
    }
    float sumValue = 0;
    for (int i = 0; i < size; i++) {
        sumValue = sumValue + x[i];
    }
	return sumValue / size;
}

// returns the variance of X and Y
float var(float* x, int size){
    if (size == 0) {
        return 0;
    }
    float u = avg(x, size);
    float sumVarPow = 0;

    for (int i = 0; i < size; i++) {
        float diffPow = std::pow(x[i] - u, 2);
        sumVarPow = sumVarPow + diffPow;
    }
	return sumVarPow/size;
}

// returns the covariance of X and Y
float cov(float* x, float* y, int size){
    if (size == 0) {
        return 0;
    }
    float multArr[size];
    for (int i = 0; i < size; i++) {
        multArr[i] = x[i] * y[i];
    }
    return (avg(multArr, size) - ((avg(x, size)) * avg(y,size)));
}

// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size){
    if (size == 0) {
        return 0;
    }
    float multStdv;
    multStdv = std::sqrt(var(x, size)) * std::sqrt(var(y, size));
    return cov(x, y, size) / multStdv;
}

// performs a linear regression and returns the line equation
Line linear_reg(Point** points, int size){
    float x[size];
    float y[size];
    for (int i = 0; i < size; i++) {
        x[i] = points[i]->x;
        y[i] = points[i]->y;
    }
    float a = (cov(x, y, size)) / var(x, size);
    float b = avg(y, size) - a * avg(x, size);

	return Line(a,b);
}

// returns the deviation between point p and the line equation of the points
float dev(Point p,Point** points, int size){
    if (size == 0) {
        return 0;
    }
    Line line = linear_reg(points, size);
    return dev(p, line);
}

// returns the deviation between point p and the line
float dev(Point p,Line l){
    float f_x = l.a * p.x + l.b;
    float devRet = std::abs((f_x - p.y));
    return devRet;
}




