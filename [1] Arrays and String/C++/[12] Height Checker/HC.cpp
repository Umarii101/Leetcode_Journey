#include <iostream>
#include <vector>
using namespace std;

int heightChecker(vector<int>& heights) {
    int count =0;
    //First Create Another Sorted Array and then Compare.
    vector <int> nums = heights;
    int wp =0; //Write pointer;
    for (int j =0; j<nums.size()-1;j++){
    for(int i=0; i<nums.size()-1;i++){
        cout<<"i = "<<i<<endl;
        int temp = 0;
        if (nums[i]>nums[i+1]){
            temp = nums[i];
            nums[i]=nums[i+1];
            nums[i+1]=temp;
            temp=0;
        }
    }
    cout<<"Done Sorting \nPurging --> Misplaced Indices\n";
    cout<<"\n\n\nInput Array = [";
    for(int i=0;i<heights.size();i++){
        cout<<heights[i]<<", ";
    }
    cout<<"]"<<endl;
    cout<<"\nSorted Array = [";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<", ";
    }
    cout<<"]\n\n"<<endl;
    }
   for(int i =0;i<heights.size();i++){
        if(heights[i] != nums[i]){
            cout<<"Misplaced at i =  "<<i<<endl;
            count++;
        }
    }
    return count;
}
int main(){
    vector <int> heights = {9,2,8,3,8,4,6,6,8,3,3,1,2,8,9,6,6,5,3,2};
    int output = heightChecker(heights);
    cout<<"\nThe Total Misplaced Indices are Total = "<<output<<endl;
    return 0;
}
