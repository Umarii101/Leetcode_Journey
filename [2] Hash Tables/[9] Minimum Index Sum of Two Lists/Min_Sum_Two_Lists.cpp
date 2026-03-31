#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits> //To Get the minimum Index from our Unordered Map. It gives Variable "INT_MAX"

std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::unordered_map <int, std::vector<std::string> > Store; //This is where we shall place our common Elements and the Sums of their indexes. 
    std::vector<std::string> Result;
    for(int i =0; i < list2.size(); i++){
        for(int j = 0; j < list1.size(); j++){
            if(list1[i] == list2[j]){
                //Found a matching String. Lets push it somewhere where we can store an index,value (Maybe a Hashmap or a Hashset).
                Store[i+j].push_back(list1[i]);//This is Supposed to Sum both of the indexes and store according to that. Later i can Return The minimum Index Strings.
                   }
            }
        }
    
    //Lets Find the minimum Index Present in our map now.
    int minIndex = INT_MAX; //This way we can start our search from the largest possible INTEGER index in our map. And we will slowly reduce our minIndex as we traverse through the map.
    for(auto const& [index,value] : Store){
        if(index < minIndex){
            minIndex = index;
        }
    }
    if( Store.count(minIndex)){
        Result = Store[minIndex];
    }
    return Result;
}

int main(){
    std::vector<std::string> List1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    std::vector<std::string> List2 = {"KNN","KFC","Burger King","Tapioca Express","Shogun"};
    std::vector<std::string> Result; 
    Result = findRestaurant(List1, List2);
    // Print the result
    std::cout << "Elements at min index = [";
    for (const std::string& s : Result) {
        std::cout << s << " ";
    }
    std::cout<<"]\n";
    return 0;
}
