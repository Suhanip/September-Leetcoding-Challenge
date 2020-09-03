/*PROBLEM STATEMENT:
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:
Input: "aba"
Output: False

*/

//CODE
class Solution {
public:
    
    bool issafe(string s,string str){
       for(int i=0;i<s.length();i+=str.length()){
           string cs = s.substr(i,str.length());    //all the substring be of the length of current substring
           if(cs!=str) return false;
       }
       return true;
    }
    bool repeatedSubstringPattern(string s) {
        string str="";  //substring
        for(int i=0;i<s.length()/2;i++){
            str+=s[i];
            if(s.length()%str.length()==0){
                bool x=issafe(s.substr(i+1),str);
                if(x) return true;
            }
        }
        return false;
    }
};
