#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string T){
    int size_s = s.length();
    int size_T = T.length();

    //My Approach:
    //First I should Identify Unique Characters in each string.
    //After Identifying Unique Characters, I will try to map the Unique characters from each string to the other string.
    //If the Mapping is Successful, I will store "true' in Result and return it. If any character is left unmapped, then i return False.
    //Whilst mapping I have to make sure that each unique Character is mapped to only Another Single Unique Character. One Character Cannot be mapped to multiple Unique Characters.
    //Whilst A character Can be Mapped on to Itself.
    
    std::unordered_map <char, char> s2t;
    std::unordered_map <char, char> t2s;
    
    if(size_s != size_T){ return false;}

    for(int i =0; i < size_s; i++){
        char charS = s[i];
        char charT = T[i];
        //Check if S has a mapping Already or not :
        if(s2t.count(charS)){
            //Yes it is mapped, Then check if that mapping is mapped to the char we are seeing now?
            if(s2t[charS] != T[i]){ //In "egg" vs "add": * At index 1: 'g' maps to 'd'. (Map stores g -> d) At index 2: We see 'g' again. We check the map. The map says 'g' must partner                                       with 'd'. We look at T[2] and see it is 'd'. They match! We keep going.
                return false;
            }
        }
        //Check if T was Already Mapped to something Else, Meaning that is the Mapping being Done in Unique Fashion or Not
        else if(t2s.count(charT)){
            if(t2s[charT] != charS){
                return false;
            }
        }
    //If Neither Was mapped, Then create a new pair of mapping.
        else{
            s2t[charS] = charT;
            t2s[charT] = charS;
        }
    }
    return true;
}

int main(){
    std::string s = "egg";
    std::string t = "addd";

    bool result = isIsomorphic(s,t);
    if (result){
        std::cout<<"The string is Isomorphic\n";
    }
    else{
        std::cout<<"The String is NOT Isomorphic\n";
    }

    return 0;
}

