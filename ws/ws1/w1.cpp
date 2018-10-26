// Workshop 1 - Linkage, Storage Duration, Namespaces,
// and OS Interface
// w1.cpp
// Author: Dr. Elliott Coleshill
// Date: 2018-08-22

#include <fstream>
#include <iostream>
#include "process.h"

using namespace std;

extern int STORED;

int main(int argc, char *argv[]) {
        cout << "Command Line: ";
        for (int i = 0; i < argc; i++) {
                cout << argv[i] << ' ';
        }
        if (argc < 2) {
                cout << "\nInsufficient number of arguments\n";
                return 1;
        }

        cout << endl
             << "Maximum number of characters stored: " << STORED << endl;

        for (int i = 1; i < argc; i++) {
                process(argv[i], cout);
        }

        return 0;
}