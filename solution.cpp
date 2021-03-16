#include <regex>
class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        if(s.length() <= 0){
            return value;
            //cause why not have this in here...
        }
        if(regex_search(s, regex("CM"))){
            value += 900;
            s = regex_replace(s, regex("CM"),"");
        }
        if(regex_search(s, regex("CD"))){
            value += 400;
            s = regex_replace(s, regex("CD"),"");
        }
        if(regex_search(s, regex("XC"))){
            value += 90;
            s = regex_replace(s, regex("XC"),"");
        }
        if(regex_search(s, regex("XL"))){
            value += 40;
            s = regex_replace(s, regex("XL"),"");
        }
        if(regex_search(s, regex("IX"))){
            value += 9;
            s = regex_replace(s, regex("IX"),"");
        }
        if(regex_search(s, regex("IV"))){
            value += 4;
            s = regex_replace(s, regex("IV"),"");
        }
        value += searchNumeral(s, regex("MM*"), 1000);
        value += searchNumeral(s, regex("DD*"), 500);
        value += searchNumeral(s, regex("CC*"), 100);
        value += searchNumeral(s, regex("LL*"), 50);
        value += searchNumeral(s, regex("XX*"), 10);
        value += searchNumeral(s, regex("VV*"), 5);
        value += searchNumeral(s, regex("II*"), 1);
        return value;
        
    }
    int calcValue(string numeral, int value){
        
        return value*numeral.length();
        //So this should return the value for whatever numeral we're on.
    }
    int searchNumeral(string s, regex reg, int value){
        smatch match;
        if(regex_search(s, match, reg)){
            return calcValue(match[0],value);
        }
        return 0;
    }
    
    /*
    if(regex_search(s, regex("IV"))){
            value += 4;
            s = regex_replace(s, regex("IV"),"");
        }
        cout << s;
    */
};
