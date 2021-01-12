cmake_minimum_required(VERSION 3.17)
project(Anomaly_Detector)

set(CMAKE_CXX_STANDARD 11)

add_executable(Anomaly_Detector MainTrain.cpp AnomalyDetector.h
        anomaly_detection_util.cpp anomaly_detection_util.h
        SimpleAnomalyDetector.cpp SimpleAnomalyDetector.h
        HybridAnomalyDetector.h HybridAnomalyDetector.cpp
        timeseries.cpp timeseries.h
        minCircle.cpp minCircle.h
        CLI.cpp CLI.h
        commands.h)