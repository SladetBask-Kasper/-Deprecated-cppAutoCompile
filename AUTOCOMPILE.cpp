#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <conio.h>
// #include <string.h>

#define DELAY_TIME 1
#define DELAY_TIME_EXT 2
#define DELAY_TIME_BATTERY 5
#define DELAY_TIME_BATTERY_EXT 10
#define COMPILER "g++ "
#define DEFAULT_OUTPUT_FILE_NAME "compiled"
#define COMPILER_OUTPUT_ARG " -o "

using namespace std;

char const *get_cmd(char *argv1) {
	string cs(argv1);
	string cmd = COMPILER + cs + COMPILER_OUTPUT_ARG + DEFAULT_OUTPUT_FILE_NAME;
	return cmd.c_str();
}

int main(int argc, char *argv[])
{


	// cout << "argc = " << argc << endl;

	if (argc != 2) {
		cout << "NOT A VALID AMMOUNT OF ARGS!" << " your command should be \"./kAutoComp fileToCompile.cpp\"" << endl;
		cout << "OR: ./AutoComp \"File To Compile With Spaces.cpp\"" << endl;
		return 0;
	}

	char const * comp_cmd = get_cmd(argv[1]);

	cout << "COMMAND : " << comp_cmd << endl;
	while (true) {
		//cout << endl << "____________________________________________________" << endl << endl;
		clrscr();

		//system();
		//system((char*)comp_cmd);
		cout << comp_cmd << endl;
		sleep((unsigned int)DELAY_TIME);
		//sleep((unsigned int)DELAY_TIME_BATTERY); // <--- battery mode

	}

}
