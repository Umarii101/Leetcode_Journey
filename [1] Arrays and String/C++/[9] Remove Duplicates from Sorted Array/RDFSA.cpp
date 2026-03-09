#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int length = nums.size()-1;
    for(int i =0; i<length;i++){
        int j= i+1;
        if(nums[i] == nums[j]){
          while(j<length){
                nums[j]=nums[j+1];
                j++;
                }
            nums[length]=0;//Last Index becomes 0.
            i--;//To check Consecutive Occurence of value.
            length--; //To make output array the size we desire at the end.
       }
    }
    return length+1;
}

int main(){
    vector <int> nums = {0,0,1,1,1,2,2,3,3,4};
    //Expected Output = 5, nums = [0,1,2,3,4,_,_,_,_,_] (Does'nt matter what we leave behind, hence Underscores
    //Code Executed Output Array = [0, 1, 1, 2, 3, 4, 0, 0, 0, 0, ]
    int length = removeDuplicates(nums);
    cout<<"Size of Array = "<<length<<"\nOutput Array = [";
    for(int i =0; i<length+1;i++){
        cout<<nums[i]<<", ";
    }
    cout<<"]\n";
    return 0;
}
