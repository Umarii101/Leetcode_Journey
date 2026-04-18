#include <iostream>
#include <string>
#include <cctype>    // Required for isalnum and tolower
#include <algorithm> // Required for std::remove_if 

bool isPalindrome(std::string s) {
    // 1. Convert everything to lowercase first
    for (char& c : s) {
        c = std::tolower((unsigned char)c);
    }

    // 2. Remove special characters (KEEP letters AND numbers)
    s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {
        // Return true if it's NOT an alphanumeric character
        return !std::isalnum(c); 
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
