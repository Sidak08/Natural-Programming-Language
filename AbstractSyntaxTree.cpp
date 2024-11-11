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

template <typename T>
vector<T> removeIndex(vector<T> vec, int startIndex, int endIndex) {
    if (startIndex < endIndex && endIndex <= vec.size()) {
        auto start = vec.begin() + startIndex;
        auto end = vec.begin() + endIndex;
        vec.erase(start, end);
    } else {
        cout << "Invalid range!" << endl;
    }
    return vec;
}

template <typename T>
vector<T> reccurParser(vector<T> input, vector<T> parsed) {

    // input is the big list
    // parsed is the tree


    if (input.size() == 0) {
        return parsed;
    }
    if (input[0].type == 1) {
        parsed.push_back(Var(input[1].value), reccurParser(removeIndex(input, 0, 2), parsed));
    }
    if (input[0].type == 4 && input[1].type == 2) {
        return reccurParser(removeIndex(input, 0, 2), parsed);
    }

}

int main() {
    return 0;
}
