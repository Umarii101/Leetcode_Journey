#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<int> topKFrequent(std::vector<int>& nums, int k){
    std::vector<int> Result;
    std::unordered_map<int,int> freq;

    for(int num : nums){
        freq[num]++; //Build the Freq Map First. Add all the Number from Num and their Frequency as well. 
    }

    for(int i = 0; i<k; i++){
        int maxfreq = -1;// We are to initialize this as negative, since All the elements atleast appear 1 times. Never negative. This is for safety only.
        int mostFreqNumb = 0;
        
        for(auto it = freq.begin(); it != freq.end();++it){
            if(it->second > maxfreq){
                maxfreq = it -> second;
                mostFreqNumb = it -> first;
            }
        }

        //Now at This point we have found the Biggest Winnder "K". Lets add it to our Result.
        //Also delete it from Freq map so it does not win next round.

        Result.push_back(mostFreqNumb);
        freq.erase(mostFreqNumb);
    }
    return Result;
}

int main(){
//Example 3:
    std::vector<int> nums = {3,0,1,0};
    int k = 1;
    std::vector<int> Result = topKFrequent(nums,k);
    std::cout<<"Result = {";
    for(int i=0;i<Result.size();i++){
        std::cout<<Result[i]<<",";
    }
    std::cout<<"}\n";
//Output: [1,2] Since k=2. So Top K frequncy numbers are 1 and 2.

    return 0;
}
