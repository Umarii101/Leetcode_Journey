#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional> // Required for std::hash
                      
//My Approach
//Lets Assign a prime number to each of the 26 letters. And then we can multiply them, since the multiplication of the Prime Numbers is Different for different combinations.
//Hence we will be Avoiding the Collision Issue of The Different String colliding to one single Group while infact they do not belong there.
bool hash_key(std::string key){
    std::hash<std::string> hasher;
    size_t x = hasher(key);
    std::cout<<"\nHash Key"<<x<<"\n";
    return true;
}
 
std::vector <std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
   std::vector<std::vector<std::string>> Result = {};
    bool n = hash_key("umar");
    bool m = hash_key("ramu");
    std::unordered_map<std::string, int> groupMap;
    for (int i = 0; i < strs.size(); i++){
        std::cout<<"\n"<<strs[i];
    }
    std::cout<<"\n";
    return Result;
}

int main(){
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    // Expected Output: [["bat"],["nat","tan"],["ate","eat","tea"]];
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
    return 0;
}
