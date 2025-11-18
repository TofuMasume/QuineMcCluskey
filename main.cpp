#include<iostream>
#include<string>
#include<vector>

#include "lexical_analysis.hpp"

#define LA LexicalAnalysis

using namespace std;

// main.cpp の先頭あたりに追記
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

    cout << "Please input Formula : " << endl;
    cin >> StringFormula;

    lex.set(StringFormula);
    lex.lex();
    vector<LA::Token> tokenList = lex.getTokenList();
    for(int index = 0; index <= tokenList.size() - 1; index++){
        cout << "[" << "\n" << "    op : " << tokenList[index].op << "\n"
                            << "  type : " << toString(tokenList[index].type) << "\n"
             << "]" << endl;
    }
}
