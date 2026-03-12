#include <iostream>
#include <vector>
using namespace std;

int heightChecker(vector<int>& heights) {
    int count =0;
    //First Create Another Sorted Array and then Compare.
    vector <int> nums = heights;
    int wp =0; //Write pointer;
    for(int i=0; i<nums.size()-1;i++){
        cout<<"i = "<<i<<endl;
        int temp = 0;
        if (nums[i]>nums[i+1]){
            temp = nums[i];
            nums[i]=nums[i+1];
            nums[i+1]=temp;
            temp=0;
            i = 0; //Recheck indice.
        }
    }
    cout<<"Done Sorting \nPurging --> Misplaced Indices\n";
    for(int i =0;i<heights.size();i++){
        if(heights[i] != nums[i]){
            cout<<"Misplaced at i =  "<<i<<endl;
            count++;
        }
    }
    return count;
}

int main(){
    vector <int> heights = {1,1,4,2,1,3};
    //Expected Output = {1,1,1,2,3,4}; Arranged in Order and Also returning the incorrect indices, Such as (2,4,5).
    int output = heightChecker(heights);
    cout<<"\n[";
    for(int i=0;i<heights.size();i++){
        cout<<heights[i]<<", ";
    }
    cout<<"]"<<endl;

    cout<<"\nThe Total Misplaced Indices are Total = "<<output<<endl;
    return 0;
}
