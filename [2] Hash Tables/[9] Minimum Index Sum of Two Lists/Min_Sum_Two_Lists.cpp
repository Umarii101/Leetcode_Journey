#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::unordered_map <int, std::string> Storage; //This is where we shall place our common Elements and the Sums of their indexes. 
    std::vector<std::string> Result;
    //We have to find Common String in both of the list. And only Return the Ones that have least sum of Indexes between the Two Lists.
    //First lets find which list is smaller and contains less Elements.
        if(list1.size() - list2.size() > 0 ){
        //This means that List1 is Larger than List 2.
        //Lets only Iterate the Smaller List Since it has less elements.
        for(int i =0; i < list2.size(); i++){
            for(int j = 0; j < list1.size(); j++){
                if(list1[i] == list2[j]){
                    //Found a matching String. Lets push it somewhere where we can store an index,value (Maybe a Hashmap or a Hashset).
                    Storage[i+j] = list1[i];//This is Supposed to Sum both of the indexes and store according to that. Later i can Return The minimum Index Strings.
                    //[CONCERN]-> However in this Example, If we look at happy and sad, They both map to the same index. Does that cause a collision?
                    //What Happens with this collision? Lets Find out
                }
            }
        }
    }
    else{

    }
    






    return Result;
}

int main(){
    std::vector<std::string> List1 = {"happy","sad","good"};
    std::vector<std::string> List2 = {"sad","happy","good"};
    std::vector<std::string> Result; 
    Result = findRestaurant(List1, List2);
    return 0;
}
