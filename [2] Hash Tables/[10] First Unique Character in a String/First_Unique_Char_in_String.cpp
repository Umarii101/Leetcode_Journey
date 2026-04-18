#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int firstUniqChar(std::string s) {
    std::unordered_map  < char,std::vector<int> > hashmap; //I will use this to keep track of Indexes and seen characters. 
    for (int i = 0; i<s.length();i++){
        char Character = s[i];
        if(hashmap.count(Character)){
            //Already seen this Character. Push its index into the vector.
            hashmap[Character].push_back(i);//Here i look up the character and then push the index to the assosiated vector. 
        }
        else{
            //Since it is first time seeing the Character, We have to initialize a vector since hashmap starts totally empty.
            std::vector<int> firstIndex = {i};
            hashmap[Character] = firstIndex;
        }
    }
    //After all of the operations are done. We have to identify the "First" and "Unique" Character.
    //Which means that in map a character that is mapped to a vector that contains a single entry && it must be the smallest value amongst all other single entry vectors.  
    
    //Or We can do it in a simple Manner. We iterate through the string again, And the first character that has a unit vector assosiated with it IS our desired output, We return it. Else      we return False "-1" since unique characters exist in our string.
    
    for (int i = 0; i < s.length();i++){
        char c = s[i];
        if(hashmap[c].size() == 1){
            //We've Found our first Character that is only repeated once (Unit Vector).
            return i;
        }
        else{
            continue;
        }
    }
    return -1; //Unique Character does not exist in the vector at all.
}

int main(){
    //std::string s = "leetcode";
    std::string s = "leetcodeltdco";
    //Input: s = "leetcode"
    //Output: 0
    //Explanation: The character 'l' at index 0 is the first character that does not occur at any other index.
    int Result = firstUniqChar(s);
    if(Result != -1){
        std::cout<<"The First Unique Character in the string ["<<s<<"] is Char = ("<<s[Result]<<")\n";
    }
    else{
        std::cout<<"No Unique character found in the string s = ["<<s<<"]\n";
    }
    return 0;
}
