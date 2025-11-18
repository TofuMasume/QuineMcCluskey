#include<string>
#include<vector>
#include "lexical_analysis.hpp"

#define LA LexicalAnalysis

using namespace std;


int INT_A = static_cast<char>('A');
int INT_Z = static_cast<char>('Z');
int INT_NOT = static_cast<char>('^');
int INT_SEPARATOR = static_cast<char>('+');


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
    separatedString.clear();
    separatedString.reserve(rawString.size());

    for(char ch : rawString){
        separatedString.emplace_back(1, ch);
    }
}

// 分割文字列ゲット
vector<string> LA::getSeparatedString(){
    return separatedString;
}

// 型推定
LA::Token LA::inferenceCharType(string str){
    Token token{};
    token.op = str;
    token.type = op_type::UNKNOWN;

    if(str.empty()){
        token.type = op_type::EMPTY;
        return token;
    }

    int toIntStr = static_cast<int>(str[0]);
    if(INT_A <= toIntStr && toIntStr <= INT_Z){
        token.type = op_type::CHAR;
        return token;
    } else if(INT_NOT == toIntStr){
        token.type = op_type::NOT;
    } else if(INT_SEPARATOR == toIntStr){
        token.type = op_type::SEPARATE;
    }

    return token;
}

// 全体型推定
void LA::lex(){
    tokenList.clear();
    tokenList.reserve(separatedString.size());

    for(const string& elem : separatedString){
        tokenList.push_back(inferenceCharType(elem));
    }
}

// 字句解析済みリストゲット
vector<LA::Token> LA::getTokenList(){
    return tokenList;
}
