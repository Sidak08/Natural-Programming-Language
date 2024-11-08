#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#define ll long long
using namespace std;

// define tokens
// for
// if
// print
// var
class Token {
    public:
        string value;
        int type;

    Token(string a, int b): value(a), type(b) {};
};

string fileToString(const string& filename) {
    std::ifstream file(filename); // Open the file
    if (!file) { // Check if the file opened successfully
        std::cerr << "Could not open the file: " << filename << std::endl;
        return "";
    }

    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

vector<Token> parseFile(string file) {
    for (ll i = 0; i < file.length(); i++){

    }
}



int main() {
    cout << fileToString("test.en");
    string test = "var hello = 5";
    return 0;
}
