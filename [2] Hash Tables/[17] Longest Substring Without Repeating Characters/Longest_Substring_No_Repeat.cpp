#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
int lengthOfLongestSubstring(std::string s) {
    int Current_Count = 0;
    int longest_length = 0;
    std::unordered_set<char> validator;
    for(int i = 0; i<s.length(); i++){
        std::cout<<"The Current Character -> ["<<s[i]<<"]\n";
        if(validator.count(s[i]) > 0){
            //This Means that the character has been Repeated.
            validator.clear();
            validator.insert(s[i]);
            if(Current_Count > longest_length){
                longest_length = Current_Count;
            }
            Current_Count = 1;
            std::cout<<"\tIter Num -> ["<<i<<"] If Block\tCurrent Count = "<<Current_Count<<"\tLongest Length Yet = "<<longest_length<<"\n";
        }
        else{
            validator.insert(s[i]);
            Current_Count++;
            std::cout<<"\tIter Num -> ["<<s[i]<<"] Else Block\tCurrent Count = "<<Current_Count<<"\tLongest Length Yet = "<<longest_length<<"\n";
        } 
    }
    return longest_length;
}

int main(){
    //std::string s = "abcabcbb";    //Expected Output = 3. "Since abc appears and are repeated but we count them atleast Once.
    //std::string s = "pwwkew";     //Expected Output = 3.
    std::string s = "bbbbb";      //Expected Output = 1.
    int Result = lengthOfLongestSubstring(s);
    std::cout<<"The Total Length of the Substring is ["<<Result<<"]\n";
    return 0;
}
