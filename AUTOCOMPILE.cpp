#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <conio.h>
// #include <string.h>

#define DELAY_TIME 5
#define DELAY_TIME_BATTERY 10
#define COMPILER "g++ "
#define DEFAULT_OUTPUT_FILE_NAME "compiled"
#define COMPILER_OUTPUT_ARG " -o "

using namespace std;

int main(int argc, char *argv[])
{

	if (argc != 2) {
		cout << "NOT A VALID AMMOUNT OF ARGS!" << " your command should be \"./kAutoComp fileToCompile.cpp\"" << endl;
		cout << "OR: ./AutoComp \"File To Compile With Spaces.cpp\"" << endl;
		return 0;
	}

	char const * comp_cmd;
	{
		string cs(argv[1]);
		string cmd = COMPILER + cs + COMPILER_OUTPUT_ARG + DEFAULT_OUTPUT_FILE_NAME;
		if (cmd.find(";") != std::string::npos || cmd.find("?") != std::string::npos || cmd.find("&") != std::string::npos) {
			cout << "Names Cannot contain any of the following: \";?&\""
		}
		comp_cmd = cmd.c_str();
	}

	cout << "COMMAND : " << comp_cmd << endl;
	while (true) {
		clrscr();

		cout << comp_cmd << endl;
		sleep((unsigned int)DELAY_TIME);
		//sleep((unsigned int)DELAY_TIME_BATTERY); // <--- battery mode

	}

}
