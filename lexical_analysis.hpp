#ifndef _LEXICAL_ANALYSIS_H_
#define _LEXICAL_ANALYSIS_H_

#include<string>
#include<vector>
using namespace std;

class LexicalAnalysis{

    public:
        enum class op_type{
            CHAR,
            NOT,
            SEPARATE,
            UNKNOWN,
            EMPTY
        };

        typedef struct Token{
            string op;
            op_type type;
        } Token;
        // funcs
        void set(string rawFormula); // 生文字列セット
        string getRawString(); // 生文字列ゲット
        vector<string> getSeparatedString(); // 分割済み文字列ゲット
        void separateRawString(); // 文字列分割
        Token inferenceCharType(string str); // 一文字型推定
        void lex(); // 字句解析
        vector<Token> getTokenList(); // 字句解析済みリストゲット

    private:
        // funcs
        void separate(string rawFormula);
        // variables
        string rawString;
        vector<string> separatedString;
        vector<Token> tokenList;
};

#endif
