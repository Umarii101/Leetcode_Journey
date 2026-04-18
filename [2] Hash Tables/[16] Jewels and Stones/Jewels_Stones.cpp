#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int numJewelsInStones(std::string jewels, std::string stones){
    int result = 0;
    std::unordered_set<char> splitJewels;
    //Lets First Split the jewels from the string.
    for(int i =0; i < jewels.length(); i++){
        splitJewels.insert(jewels[i]);
    }//Now our Vector contains the Jewels Individually.
    //Now Lets find the jewels in our Stones.
    for(int i = 0; i < stones.length();i++){
        if(splitJewels.count(stones[i])>0){
            result++;
        }
    }
    return result;
}

int main(){
    std::string Jewels = "aA";
    std::string Stones = "aAAbAbbb";
    
    int result = numJewelsInStones(Jewels, Stones);
    std::cout<<"The Total Jewels Found in the stones are : ["<<result<<"]\n";

    return 0;
}
