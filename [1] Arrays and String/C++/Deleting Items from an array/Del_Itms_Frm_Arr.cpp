#include <iostream>
#include <vector>
using namespace std;
    
int removeElement(vector<int>&nums,int val){
    last = 0; //We need to find the last index of the array to use it as a second pointed for moving backwards in the array.
    for int(num : nums){
        last;
    }
    //Pointer 1 = i, which starts from index 0 of the array.
    for(int i=0; i<last;i++){
        if (nums[i] = val || i<last){
            while(nums[i]=val){ //This while loop is used to handle the case for when the next index also contains the same val we want to remove, so we remove the value and do the shift until val is not repeated or the loop ends.
                nums[i] = nums[i+1] // Do the shift,
                i++;
                nums[last]=0; //Fill 0 at the last index
                last--; // Decrement the Last index to second last and so on
        }
    }



    return length;
}

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    val=2;
    length = removeElement(nums,val);
    cout<<"The total Length of the Array after the Val Element has been removed = "<<length;
}
