#include <iostream>
#include <string>

bool is_Isomorphic(std::string s, std::string T){
    bool Result = false;
    int size_s = s.length();
    int size_T = T.length();
    return Result;
}

int main(){
    std::string s = "NOegg";
    std::string t = "add";

    bool result = is_Isomorphic(s,t);
    if (result){
        std::cout<<"The string is Isomorphic\n";
    }
    else{
        std::cout<<"The String is NOT Isomorphic\n";
    }

    return 0;
}

