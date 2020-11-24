cmake_minimum_required(VERSION 3.17)
project(Anomaly_Detector)

set(CMAKE_CXX_STANDARD 11)

add_executable(Anomaly_Detector anomaly_detection_util.cpp MainTrain.cpp AnomalyDetector.h SimpleAnomalyDetector.cpp SimpleAnomalyDetector.h timeseries.cpp timeseries.h)