#include<string>
#include<vector>
#include "lexical_analysis.hpp"

#define LA LexicalAnalysis

using namespace std;


// 生文字列セット
void LA::set(string rawFormula){
    rawString = rawFormula;
    separateRawString();
}

// 生文字列ゲット
string LA::getRawString(){
    return rawString;
}

// 生文字列分割
void LA::separateRawString(){
    for(int index = 0; index <= rawString.size() - 1; index++){
        separatedString[index] = rawString[index];
    }
}

// 分割文字列ゲット
vector<string> LA::getSeparatedString(){
    return separatedString;
}