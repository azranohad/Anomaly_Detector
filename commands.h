

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <vector>
#include "HybridAnomalyDetector.h"

using namespace std;

class DefaultIO{
public:
	virtual string read()=0;
	virtual void write(string text)=0;
	virtual void write(float f)=0;
	virtual void read(float* f)=0;
	virtual ~DefaultIO(){}

	// you may add additional methods here
};

// you may add here helper classes
struct dataCommand{
    DefaultIO* dio;
    HybridAnomalyDetector had;
    vector<AnomalyReport> r;
};
struct AnomalyPhase{
    float start;
    float end;
    string features;
    float sum;
};
// you may edit this class
class Command{
public:
    dataCommand* dc;
    string description;

    Command(dataCommand *data_c):dc(data_c){
        this->dc->dio = data_c->dio;
        this->dc->had = data_c->had;
    }
	virtual void execute()=0;
	virtual ~Command(){}

    void setDescription(const string &description) {
         this->description = description;
    }
    const string &getDescription() const {
        return description;
    }
};

// implement here your command classes

class Option1 : public Command{
public:
    Option1(dataCommand *data_c) : Command(data_c) {
        description = "1.upload a time series csv file\n";
    }
    //function to read data from client and save it in csf file.
    void read_write_lbl(const char*  file_name_output) {
        // create and open the csv file
        ofstream outputFile(file_name_output);
        while(true) {
            string str = dc->dio->read();
            if (str == "done") {
                break;
            }
            outputFile << str << endl;
        }
        outputFile.close();
    }
    void execute() {
        dc->dio->write("Please upload your local train CSV file.\n");
        //call function to read data from client and save it in csf file.
        read_write_lbl("trainFile.csv");
        dc->dio->write("Upload complete.\n");
        //upload the test file csv.
        dc->dio->write("Please upload your local test CSV file.\n");
        read_write_lbl("testFile.csv");
        dc->dio->write("Upload complete.\n");
    }
};

class Option2 : public Command{
public:
    Option2(dataCommand *data_c) : Command(data_c) {
        description ="2.algorithm settings\n";
    }
    void execute() {
        float client_core = dc->had.client_corr;
        dc->dio->write("The current correlation threshold is ");
        dc->dio->write(to_string(dc->had.client_corr) + "\n");
        while (true){
            dc->dio->write("Type a new threshold\n");
            string input_tresh = dc->dio->read();
            float input_threshold = stof(input_tresh);
            if ((input_threshold >= 0) && (input_threshold <= 1)) {
                dc->had.client_corr = input_threshold;
                break;
            } else {
                dc->dio->write("please choose a value between 0 and 1.\n");
            }
        }
    }
};

class Option3 : public Command{
public:
    Option3(dataCommand *data_c) : Command(data_c) {
        description = "3.detect anomalies\n";
    }
    void execute() {
        TimeSeries ts_train("trainFile.csv");
        dc->had.learnNormal(ts_train);
        TimeSeries ts_test("testFile.csv");
        dc->r = dc->had.detect(ts_test);
        dc->dio->write("anomaly detection complete.\n");
    }
};
class Option4 : public Command{
public:
    Option4(dataCommand *data_c) : Command(data_c) {
        description ="4.display results\n";
    }
    void execute() {
        for (auto ar : dc->r) {
            string str = to_string(ar.timeStep) + "  " + ar.description + "\n";
            dc->dio->write(str);
        }
        dc->dio->write("Done.\n");
    }
};

class Option5 : public Command{
public:
    Option5(dataCommand *data_c) : Command(data_c) {
        description = "5.upload anomalies and analyze results\n";
    }
    //function to read data from client and save it in csf file.
    void read_true_from_client(vector<AnomalyPhase> *ap_vec) {
        while(true) {
            string str = dc->dio->read();
            if (str == "done") {
                break;
            }
            istringstream ss(str);
            string token;
            int i = 0;
            AnomalyPhase anomalyPhase;
            while (std::getline(ss, token, ',')) {
                if (i == 0){
                    anomalyPhase.start = stoi(token);
                } else if(i == 1) {
                    anomalyPhase.end = stoi(token);
                }
                i++;
            }
            anomalyPhase.sum = anomalyPhase.end - anomalyPhase.start + 1;
            ap_vec->push_back(anomalyPhase);
        }
    }

    void create_apVec_from_ar(vector<AnomalyPhase> *ap_vec) {
        float epsilon = pow(10, -10);
        int size = dc->r.size();
        AnomalyPhase ap;
        AnomalyPhase anomalyPhaseTmp;
        for(int i = 0; i <  size ; i++) {
            AnomalyReport ar = dc->r[i];

            if (i == 0) {
                ap.start = (int)ar.timeStep;
                ap.features = ar.description;
                continue;
            } else {
                //the last ar.
                if (i == (size - 1)) {
                    ap.end = (int)ar.timeStep;
                    ap.sum = ap.end - ap.start + 1;
                    ap_vec->push_back(ap);
                    break;
                //if the difference between ar to next ar time step bigger from 1.
                } else if ((abs(((float)dc->r[i + 1].timeStep - (float)ar.timeStep)) - 1) > epsilon) {
                    AnomalyReport ar_next = dc->r[i + 1];
                    ap.end = (float)ar.timeStep;
                    anomalyPhaseTmp.start = (float)ar_next.timeStep;
                    anomalyPhaseTmp.features = ar_next.description;
                    ap.sum = ap.end - ap.start + 1;
                    ap_vec->push_back(ap);
                    ap = anomalyPhaseTmp;
                    continue;
                }
            }
        }
    }
    void execute() override {
        vector<AnomalyPhase> trueAnomaly;
        vector<AnomalyPhase> reportAnomaly;
        dc->dio->write("Please upload your local anomalies file.\n");
        read_true_from_client(&trueAnomaly);
        create_apVec_from_ar(&reportAnomaly);
        dc->dio->write("Upload complete.\n");

        float n = dc->had.getNormalModel()[0].y_vec.size();
        float P = trueAnomaly.size();
        float N = 0, sumP_time = 0,  sumFP = 0, sumTP = 0;


        for  (int i = 0; i < trueAnomaly.size(); i++) {
            AnomalyPhase apT = trueAnomaly[i];
            sumP_time = sumP_time + apT.sum;
            for (int j = 0; j < reportAnomaly.size(); j++) {
                AnomalyPhase apR = reportAnomaly[j];
                if ((apR.start <= apT.end) && (apT.start <= apR.start)) {
                    sumTP++;
                } else if ((apR.end >= apT.start) && (apR.start <= apT.start)) {
                    sumTP++;
                } else if ((apT.start >= apR.start) && (apT.end <= apR.end)) {
                    sumTP++;
                } else if ((apR.start >= apT.start) && (apR.end <= apT.end)) {
                    sumTP++;
                }
            }
        }

        N = n - sumP_time;
        sumFP = reportAnomaly.size() - sumTP;
        float TPR;
        float FPR;
        TPR = sumTP / P;
        FPR = sumFP / N;

        TPR = floor(TPR * 1000) / 1000;
        FPR = floor(FPR * 1000) / 1000;



        dc->dio->write("True Positive Rate: ");
        dc->dio->write(TPR);
        dc->dio->write("\n");
        dc->dio->write("False Positive Rate: ");
        dc->dio->write(FPR);
        dc->dio->write("\n");


    }
};
class Option6 : public Command{
public:
    Option6(dataCommand *data_c) : Command(data_c) {
        description = "6.exit\n";
    }
    void execute() {

    }
};



#endif /* COMMANDS_H_ */
