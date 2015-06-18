#include "lexer.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{  	
    ifstream fin(argv[1]);
    Lexer s;
    string code;
    while (getline(fin, code))
        s.Scan(code);
}