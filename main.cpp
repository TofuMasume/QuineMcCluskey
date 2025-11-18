#include<iostream>
#include<string>
#include<vector>

#include "lexical_analysis.hpp"

using namespace std;


int main(void){
    // 分割前式
    string StringFormula;

    LexicalAnalysis lex;

    cout << "Please input Formula : " << endl;
    cin >> StringFormula;

    lex.set(StringFormula);
    cout << lex.getRawString() << endl;

    vector<string> separatedString = lex.getSeparatedString();
    for(int index = 0; index <= separatedString.size() - 1; index++){
        cout << separatedString[index] << " ";
    }
    cout << endl;
}