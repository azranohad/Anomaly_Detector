//
// Created by azran on 23/11/2020.
//

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "timeseries.h"

using namespace std;

TimeSeries::TimeSeries(const char *CSVfileName) {
    this->CSVfile_name = CSVfileName;
    this->createMapFromCsv();
}
TimeSeries::TimeSeries(const TimeSeries &ts_source) {
    this->CSVfile_name = ts_source.CSVfile_name;
    this->headers = ts_source.headers;
    this->vec_col = ts_source.vec_col;
/*    createMapFromCsv();*/
}

void TimeSeries::createMapFromCsv() {
    std::ifstream file_csv(CSVfile_name);
    if (!file_csv.is_open())
    {
        exit(EXIT_FAILURE);
    }
    string line_string;
    int num_of_line = 1;
    while(getline(file_csv,line_string, '\n')) {
        std::istringstream ss(line_string);
        std::string token;
        int i = 0;
        while (std::getline(ss, token, ',')) {
            if (num_of_line == 1) {
                headers.push_back(token);
                vector<float> vec;
                vec_col[token] = vec;
            } else {
                vec_col[headers[i]].push_back(std::stof(token));
                i++;
            }
        }
        i = 0;
        num_of_line++;
    }
}


/*void TimeSeries::setVecCol(const map<string, vector<float>> &vecCol) {
    vec_col = vecCol;
}

const vector<string> &TimeSeries::getHeaders() const {
    return headers;
}*/
