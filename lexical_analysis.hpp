#ifndef _LEXICAL_ANALYSIS_H_
#define _LEXICAL_ANALYSIS_H_

#include<string>
#include<vector>
using namespace std;

class LexicalAnalysis{
    public:
        // funcs
        void set(string rawFormula);
        string getRawString();
        vector<string> getSeparatedString();
        void separateRawString();
    private:
        // funcs
        void separate(string rawFormula);
        // variables
        string rawString;
        vector<string> separatedString = vector<string>(256, "");
};

#endif