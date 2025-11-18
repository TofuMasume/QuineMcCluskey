#ifndef _UTILS_H_
#define _UTILS_H_

#include<iostream>
#include<string>
#include<vector>

#include "utils.hpp"
#include "lexical_analysis.hpp"

#define LA LexicalAnalysis

using namespace std;


string type2string(LA::op_type t){
    switch (t){
            case LA::op_type::CHAR:     return  "CHAR";
            case LA::op_type::NOT:      return "NOT";
            case LA::op_type::SEPARATE: return "SEPARATE";
            case LA::op_type::EMPTY:    return "EMPTY";
            default:                    return "UNKNOWN";
    }
}




void printToken(LA::Token token){
    cout << type2string(token.type) << "[" << token.op << "]";
}



#endif