
#include <map>

#ifndef TIMESERIES_H_
#define TIMESERIES_H_

using namespace std;

class TimeSeries{

public:
    std::map<string, vector<float> > vec_col;
    vector<string> headers;
    std::string CSVfile_name;
    TimeSeries(const char* CSVfileName);
    TimeSeries(const TimeSeries &ts_source);
    void createMapFromCsv();

    const map<string, vector<float>> &getVecCol() const;

    void setVecCol(const map<string, vector<float>> &vecCol);

    const vector<string> &getHeaders() const;
};



#endif /* TIMESERIES_H_ */
