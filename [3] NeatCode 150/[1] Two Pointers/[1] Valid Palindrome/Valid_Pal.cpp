#include <iostream>
#include <string>
#include <cctype>    // Required for isalnum and tolower
#include <algorithm> // Required for std::remove_if 

bool isPalindrome(std::string s) {
    // 1. Convert everything to lowercase first
    for (char& c : s) {
        c = std::tolower((unsigned char)c);
    }

    // 2. Remove special characters and numbers
    // We want to KEEP only lowercase letters (a-z)
    s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {
        // Return true if it's a number OR a special character
        // (This is the same as saying: return true if it's NOT a letter)
        return !std::isalpha(c); 
    }), s.end());

   // 3. Reverse the string totally
    if(s ==  std::string(s.rbegin(), s.rend())){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    std::string s = "Was it a car or a cat I saw?";
    bool Result = isPalindrome(s);
    if(Result){
        std::cout<<"The String ["<<s<<"] is a Valid Palindrome\n";
    }
    else{
        std::cout<<"The String ["<<s<<"] is a Valid Palindrome\n";
    }
    return 0;
}
