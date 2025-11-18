#include<iostream>
#include<string>
#include<vector>

#include "lexical_analysis.hpp"
#include "utils.hpp"

#define LA LexicalAnalysis

using namespace std;


const char* toString(LexicalAnalysis::op_type t){
    switch(t){
        case LexicalAnalysis::op_type::CHAR:     return "CHAR";
        case LexicalAnalysis::op_type::NOT:      return "NOT";
        case LexicalAnalysis::op_type::SEPARATE: return "SEPARATE";
        case LexicalAnalysis::op_type::EMPTY:    return "EMPTY";
        default:                                 return "UNKNOWN";
    }
}



int main(void){
    // 分割前式
    string StringFormula;

    LexicalAnalysis lex;

    cout << "Please input Formula : " << endl << endl;
    cin >> StringFormula;
    cout << endl;

    lex.set(StringFormula);
    lex.lex();
    vector<LA::Token> tokenList = lex.getTokenList();
    for(int index = 0; index <= tokenList.size() - 1; index++){
        printToken(tokenList[index]);
        cout << endl;
    }
}
