#include <iostream>
#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
    int left = 0;
    int longest_length = 0;
    std::unordered_set<char> validator;
    for(int right = 0; right<s.length(); right++){
        std::cout<<"The Current Character -> ["<<s[right]<<"]\n";
        //This Means that the character has been Repeated.
        while(validator.count(s[right])){
            validator.erase(s[left]);
            left++;
        }
        //Add The Current Character.
        validator.insert(s[right]);
        int current_window_size = right - left + 1;
        if(current_window_size > longest_length) {
            longest_length = current_window_size;
        }
    } 
    return longest_length;
}

int main(){
    //std::string s = "abcabcbb";    //Expected Output = 3. "Since abc appears and are repeated but we count them atleast Once.
    //std::string s = "pwwkew";     //Expected Output = 3.
    std::string s = "dvdf";      //Expected Output = 3.
    int Result = lengthOfLongestSubstring(s);
    std::cout<<"The Total Length of the Substring is ["<<Result<<"]\n";
    return 0;
}
