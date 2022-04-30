#include <iostream>
#include <string>
#include <unordered_map>

/*
* Time Complexity = O(n)
*/

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> strChar;
        int max_len = 0;
        int str_start_idx = 0;
        int repeated_char_idx  = 0;
        for (int s_idx=0; s_idx<s.size(); s_idx++){
            char c = s[s_idx];
            if (strChar.find(c) != strChar.end()){
                // remove repeated
                repeated_char_idx= strChar[c];
                for (int r_idx=str_start_idx; r_idx<=repeated_char_idx; r_idx++){
                    strChar.erase(s[r_idx]);
                }
                str_start_idx = repeated_char_idx + 1;
            }
            strChar.insert({c, s_idx});

            // update max_len
            if (max_len < strChar.size()){
                max_len = strChar.size();
            }
            // cout << c << "/"<< strChar.size() <<endl;
        }
        return max_len;
    }
};
int main(){
    Solution solution;
    string s = "pwwkew";
    cout << solution.lengthOfLongestSubstring(s);
}