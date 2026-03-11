#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
        int length = nums.size()-1;//Last index of the Array.
        for(int i=0; i<length;i++){
            int fp=i+1;
            if(nums[i]%2==0){
                cout<<"Found an Even Number at index i = "<<i<<"\n";
            }

        }

}

int main(){
    //Place The Even numbers at the beginning of the array, The order with which we place the evens or odds does not matter. 
    vector <int> nums = {3,1,2,4};
    //Expected Output = {2,4,1,3} OR {4,2,1,3} OR {2,4,3,1} etc.
    return 0;
}
