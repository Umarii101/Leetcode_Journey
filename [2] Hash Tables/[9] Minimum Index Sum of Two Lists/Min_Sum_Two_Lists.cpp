#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits> //To Get the minimum Index from our Unordered Map. It gives Variable "INT_MAX"

std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::unordered_map <int, std::vector<std::string> > Store; //This is where we shall place our common Elements and the Sums of their indexes. 
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
                    Store[i+j].push_back(list1[i]);//This is Supposed to Sum both of the indexes and store according to that. Later i can Return The minimum Index Strings.
    
                    //[CONCERN]-> However in this Example, If we look at happy and sad, They both map to the same index. Does that cause a collision?
                    //What Happens with this collision? Lets Find out

                    //I have Addressed the Above concern by updating the definition of map from <int,std::string> to <int, std::vector<std::string>>. This makes Sure that we can avoid co                      llisions and successfully link multiple strings to one index.
                }
            }
        }
    }

    else{
        //This means that list 2 is larger in size and has more elements.
        for(int i =0; i < list1.size(); i++){
            for(int j = 0; j < list2.size(); j++){
                if(list2[i] == list1[j]){
                    Store[i+j].push_back(list2[i]);                }
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
    std::vector<std::string> List1 = {"happy","sad","good"};
    std::vector<std::string> List2 = {"sad","happy","good"};
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
