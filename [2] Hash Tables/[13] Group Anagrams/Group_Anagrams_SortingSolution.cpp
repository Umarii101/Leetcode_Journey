#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
    std::vector<std::vector<std::string>> Result;
    std::unordered_map<std::string, std::vector<std::string>> temp_Storage;
    //Lets first sort each String in the input string
    for(std::string st : strs){
        //Sort
        std::string sortedKey = st;
        std::sort(sortedKey.begin(),sortedKey.end());
        temp_Storage[sortedKey].push_back(st);
    }
    for(auto const& [key , bucket] : temp_Storage){
        Result.push_back(bucket);
    }
    return Result;
}

int main(){
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> Result = groupAnagrams(strs);
    
    std::cout<<"After Applying Function, String Vector =";
    for(int i =0; i< Result.size();i++){
        std::cout<<"[";
        for (int j =0; j<Result[i].size();j++){
            std::cout<<Result[i][j];
        }
        std::cout<<"]\n";
    }
    return 0;
}
