#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
                      
//My Approach
//Lets Assign a prime number to each of the 26 letters. And then we can multiply them, since the multiplication of the Prime Numbers is Different for different combinations.
//Hence we will be Avoiding the Collision Issue of The Different String colliding to one single Group while infact they do not belong there.
 
std::vector <std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
    std::vector<std::vector<std::string>> Result;
    std::unordered_map<unsigned long long, std::vector<std::string>> temp_storage; //This will be used to store Huge Multiplication Keys to later accurately Group our strings.
    std::unordered_map<char, int> groupMap = {
        {'a', 2},    {'b', 3},   {'c',  5},
        {'d', 7},    {'e', 11},  {'f', 13},
        {'g', 17},   {'h', 19},  {'i', 23},
        {'j', 29},   {'k', 31},  {'l', 37},
        {'m', 41},   {'n', 43},  {'o', 47},
        {'p', 53},   {'q', 59},  {'r', 61},
        {'s', 67},   {'t', 71},  {'u', 73},
        {'v', 79},   {'w', 83},  {'x', 89},
        {'y', 97},   {'z', 101}
    };
//    for (const auto& pair : groupMap) {
//        std::cout << pair.first << ": " << pair.second << "\n";
//    }
//    std::cout<<"\n";
    
    for(std::string st : strs){
        unsigned long long multiplication = 1;
        std::cout<<"LENGTH = ["<<st.length()<<"] CHAR-->(";
        for(int i =0; i<st.length();i++){
            multiplication *= groupMap[st[i]];
            std::cout<<st[i];
        }
        std::cout<<")-------------";
        std::cout<<"MULTIPLICATION RESULT-->("<<multiplication<<")\n";
        temp_storage[multiplication].push_back(st);
    }
    
    //Lets now Push result into the Resultant Vector of Strings
    for(auto const& [key, bucket] : temp_storage){
        Result.push_back(bucket); //The Key is the Multiplication of Primes, Whilst the Bucket is vector<string>. So we push the vector<string> in the Result Vector.
    }

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
