#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Instruction {
    int  q;
    char x, w, h;

    Instruction() {}

    Instruction(char x, char w, char h, int q) : x(x), w(w), h(h), q(q) {}
};

struct State {
    vector<Instruction> instrs;
};
