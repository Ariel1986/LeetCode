
/* Question:
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
Tags: Hash Table
*/

// Code:
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        std::vector<std::string> result;
        if(words.empty()) return result;
        std::vector<std::string> hash{"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL","zxcvbnmZXCVBNM"};
        
        for(auto&& word : words) {
            bool r1 = true, r2 = true, r3 = true;
            for(auto&& ch : word){
                if(r1){
                    auto index = hash[0].find(ch);
                    if(index == std::string::npos){
                        r1 = false;
                    }
                }
                if(r2){
                    auto index = hash[1].find(ch);
                    if(index == std::string::npos){
                        r2 = false;
                    }
                }
                if(r3){
                    auto index = hash[2].find(ch);
                    if(index == std::string::npos){
                        r3 = false;
                    }
                }
            }
            if(r1 || r2 || r3){
                result.emplace_back(word);
            }
        }
        return result;
    }
};
