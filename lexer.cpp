#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

#define ll long long
using namespace std;

// Token class
class Token {
public:
    string value;
    int type;

    Token(string a, int b) : value(a), type(b) {}

    // Overloading the << operator to print Token objects
    friend ostream& operator<<(ostream& os, const Token& token) {
        os << "Value: " << token.value << " Type: " << token.type << endl;
        return os;
    }
};

string fileToString(const string& filename) {
    ifstream file(filename); // Open the file
    if (!file) { // Check if the file opened successfully
        cerr << "Could not open the file: " << filename << endl;
        return "";
    }

    ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

template <typename T>
void printVector(const vector<T>& vec) {
    for (const T& element : vec) {
        cout << element << " ";  // This will now use the overloaded << operator
    }
    cout << endl;
}

unordered_map<string, int> tokenListGenrator() {
    unordered_map<string, int> tokenListRef;
    tokenListRef["var"] = 1;
    tokenListRef["NewLine"] = 2;
    tokenListRef["="] = 3;
    tokenListRef["number"] = 4;
    tokenListRef["varName"] = 5;
    tokenListRef["print"] = 6;
    tokenListRef["+"] = 7;
    tokenListRef["-"] = 8;
    tokenListRef["*"] = 9;
    tokenListRef["/"] = 10;
    tokenListRef["("] = 11;
    tokenListRef[")"] = 12;
    return tokenListRef;
}

bool checkIfNum(string number) {
    try {
       stoi(number);
    } catch (...){
        return false;
    }
    return true;
}

vector<Token> parseFile(const string& file, const unordered_map<string, int>& tokenListRef) {
    ll pointerOne = 0;
    vector<Token> tokenList;

    for (ll i = 0; i < file.length(); ++i) {
        if (file[i] == ' ') {
            string word = file.substr(pointerOne, i - pointerOne);
            auto it = tokenListRef.find(word);
            if (it != tokenListRef.end()) {
                Token tokenGen(word, it->second);
                tokenList.push_back(tokenGen);
            } else if (checkIfNum(word)) {
                Token tokenGen(word, 4);
                tokenList.push_back(tokenGen);
            } else if (word != ""){
                Token tokenGen(word, 5);
                tokenList.push_back(tokenGen);
            }
            pointerOne = i + 1;
        }
        else if (file[i] == '\n') {
            string word = file.substr(pointerOne, i - pointerOne);
            if (word != " ") {
                auto it = tokenListRef.find(word);
                if (it != tokenListRef.end()) {
                    Token tokenGen(word, it->second);
                    tokenList.push_back(tokenGen);
                } else if (checkIfNum(word)) {
                    Token tokenGen(word, 4);
                    tokenList.push_back(tokenGen);
                } else {
                    Token tokenGen(word, 5);
                    tokenList.push_back(tokenGen);
                }
            }
            pointerOne = i + 1;
            Token tokenGen("NewLine", 2);
            tokenList.push_back(tokenGen);
        }
    }
    return tokenList;
}

int main() {
    string filename = "test.en";  // Ensure the file exists in the current directory
    unordered_map<string, int> tokenListRef = tokenListGenrator();
    vector<Token> tokenList = parseFile(fileToString(filename).append(" "), tokenListRef);

    // Print the vector of tokens
    printVector(tokenList);

    return 0;
}
