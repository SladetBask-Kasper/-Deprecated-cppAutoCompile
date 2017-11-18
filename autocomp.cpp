#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>

#define DELAY_TIME 5
#define DELAY_TIME_BATTERY 10
#define COMPILER "g++ "
#define DEFAULT_OUTPUT_FILE_NAME "compiled"
#define COMPILER_OUTPUT_ARG " -o "
#define MAX_UPDATE_RESET_VARIABLE 262144 // 1024 ^ 2 / 4

using namespace std;

int main(int argc, char *argv[])
{

	if (argc != 2) {
		cout << "NOT A VALID AMMOUNT OF ARGS!" << " your command should be \"./kAutoComp fileToCompile.cpp\"" << endl;
		cout << "OR: ./AutoComp \"File To Compile With Spaces.cpp\"" << endl;
		return 0;
	}

	const char * comp_cmd;
	string cmd(argv[1]);
	if (cmd.find(";") != std::string::npos || cmd.find("?") != std::string::npos ||
	cmd.find("&") != std::string::npos || cmd.find("#") != std::string::npos ||
	cmd.find("%") != std::string::npos || cmd.find("\\") != std::string::npos ||
	cmd.find("'") != std::string::npos || cmd.find("$") != std::string::npos ||
	cmd.find("(") != std::string::npos || cmd.find(")") != std::string::npos ||
	cmd.find("|") != std::string::npos)
	{
		cout << "Names cannot contain any of the following: ;?&#\\%'$()|" << endl;
		exit(0);
	}
	string cs = COMPILER + cmd + COMPILER_OUTPUT_ARG + DEFAULT_OUTPUT_FILE_NAME;
	comp_cmd = cs.c_str();

	int update = 0;

	while (true) {
		system("clear");
		cout << "Update: " << update << endl << "____________________" << endl << endl;

		system((const char*)comp_cmd);
		sleep((unsigned int)DELAY_TIME);//            <--- [Normal mode]
		//sleep((unsigned int)DELAY_TIME_BATTERY); // <--- [battery mode]
		update++;
		if (update == (int)MAX_UPDATE_RESET_VARIABLE)
			update = 0;
	}
}
