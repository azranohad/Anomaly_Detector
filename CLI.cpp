#include "CLI.h"

CLI::CLI(DefaultIO* dio) {
    this->data_c = new dataCommand;
    this->data_c->dio = dio;
    this->data_c->had = HybridAnomalyDetector();
    this->opt1 = new Option1(data_c);
    this->opt2 = new Option2(data_c);
    this->opt3 = new Option3(data_c);
    this-> opt4 = new Option4(data_c);
    this-> opt5 = new Option5(data_c);
    this-> opt6 = new Option6(data_c);

}

//function send the main menu to client.
void CLI::main_menu(vector<Command*> optionList) {
    data_c->dio->write("Welcome to the Anomaly Detection Server.\n");
    data_c->dio->write("Please choose an option:\n");

    for (auto opt : optionList) {
        data_c->dio->write(opt->description);
    }
}

void CLI::start(){
    this->optionList.push_back(this->opt1);
    this->optionList.push_back(this->opt2);
    this->optionList.push_back(this->opt3);
    this->optionList.push_back(this->opt4);
    this->optionList.push_back(this->opt5);
    this->optionList.push_back(this->opt6);
    //send the main menu to client.
    main_menu(optionList);
    while (true) {

        string choose = data_c->dio->read();
        if (choose == "6") {
            break;
        }
        int choice = stoi(choose);
        this->optionList[choice - 1]->execute();
        main_menu(optionList);
    }
}

CLI::~CLI() {
    for (auto opt : optionList) {
        delete opt;
    }
    delete data_c;
}

