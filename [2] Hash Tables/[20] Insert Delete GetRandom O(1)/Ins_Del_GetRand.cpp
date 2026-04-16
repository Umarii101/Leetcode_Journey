#include <iostream>
#include <vector>
#include <unordered_set>

class Randomized_Set{
    private:
        std::unordered_set<int> RandSet;
        int number;
    public:
        Randomized_Set(){
            
        }
        bool insert(number){
            if(RandSet.count(number)>0){
                return false;//Since The Number Already Exists in the Set.
            }
            else{
                RandSet.insert(number);
            }
            return true;//Succesfully Added the Number in the Set.
        }


};

int main(){


    return 0;
}

