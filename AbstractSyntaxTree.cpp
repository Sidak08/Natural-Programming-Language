#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

#define ll long long
using namespace std;

class BinOpp {
public:
    std::string opp;
    BinOpp* left;
    BinOpp* right;

    BinOpp(const string& op, BinOpp* l = nullptr, BinOpp* r = nullptr)
           : opp(op), left(l), right(r) {}
};

class Var {
    public:
        string name;
        Var* value;

    Var(string n, Var* v = nullptr) : name(n), value(v) {}
};

int main() {
    return 0;
}
