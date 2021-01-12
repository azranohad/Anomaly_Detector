

#ifndef CLI_H_
#define CLI_H_

#include <string.h>
#include "commands.h"

using namespace std;

class CLI {
    dataCommand *data_c;
    vector<Command*> optionList;
    Option1 *opt1;
    Option2 *opt2;
    Option3 *opt3;
    Option4 *opt4;
    Option5 *opt5;
    Option6 *opt6;

    // you can add data members
public:
	CLI(DefaultIO* dio);
	void start();
    void main_menu(vector<Command*> optionList);
	virtual ~CLI();
};

#endif /* CLI_H_ */
