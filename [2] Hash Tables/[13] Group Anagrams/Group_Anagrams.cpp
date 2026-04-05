#include <iostream>
#include <vector>
#include <string>

std::vector <std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
    std::vector<std::vector<std::string>> Result = {
        {"i am Umar"},
        {"HAHAHHAHA"},
        {"I am Totally Not Umar"}
    };
    return Result;
}

int main(){
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::cout<<"Orignal String Vector = [";
    for(int i =0; i< strs.size();i++){
        std::cout<<strs[i];
    }
    std::cout<<"]\n";
    std::vector<std::vector<std::string>> Result;
    Result = groupAnagrams(strs);
    std::cout<<"After Applying Function, String Vector =";
    for(int i =0; i< Result.size();i++){
        std::cout<<"[";
        for (int j =0; j<Result[i].size();j++){
            std::cout<<Result[i][j];
        }
        std::cout<<"]\n";
    }
    std::cout<<"]\n";

    return 0;
}
