#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    //Defining the N.
    int n= nums.size();

    //Defining an array for seen numbers.
    std::vector<bool> seen(n+1,false);
    
    //Setting the Flags up for seen Numbers.
    for(int x:nums){
        seen[x]=true;
    }
    //Clearing Nums to Save memory.
    nums.clear();
    
    std::vector<int> result;
    //Checking Flags to find Unseen Numbers.
    for(int i= 1; i<=n;i++){
        if(!seen[i]){
            result.push_back(i);
    }
    }
    return result;
}

int main(){
    std::vector<int> nums = {4,3,2,7,8,2,3,1};
    //Expected Output = {5,6}, Since they are not in the list of range (1,n).
    std::vector<int> output = findDisappearedNumbers(nums);
    std::cout<<"\n\nOutput Array = [";
    for(int i=0; i<output.size();i++){
        std::cout<<output[i]<<" ,";
    }
    std::cout<<"]\n";
    return 0;
}

//OLD --> Runtime 1690ms || Beats 5.00%  || Memory 53.04MB || Beats 76.59%
//NEW --> Runtime 8ms    || Beats 40.27% || Memory 53.26MB || Beats50.86%
