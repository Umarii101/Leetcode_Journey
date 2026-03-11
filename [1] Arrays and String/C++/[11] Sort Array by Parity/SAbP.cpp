#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
        int length = nums.size()-1;//Last index of the Array.
        int temp =0;
        int wp=0; //The pointer should stay at Odd number.
        for(int i=0; i<length+1;i++){
            if(nums[i]%2==0 && nums[i] != 0){
                cout<<"Found an Even Number at index i = "<<i<<"\n\n";
                //Replacing the even number and the first index.
                temp = nums[wp];
                nums[wp] = nums[i];
                nums[i]=temp;
                temp=0;//flush temp.
                wp++;//Move the write pointer forward.
            }
        }
        return nums;
}

int main(){
    //Place The Even numbers at the beginning of the array, The order with which we place the evens or odds does not matter. 
    vector <int> nums = {3,1,2,4};
    //Expected Output = {2,4,1,3} OR {4,2,1,3} OR {2,4,3,1} etc.
    vector <int> length = sortArrayByParity(nums);
    cout<<"[";
    for (int i =0; i < length.size();i++){
        cout<<length[i]<<", ";   
    }
    cout<<"]\n";
    return 0;
}
