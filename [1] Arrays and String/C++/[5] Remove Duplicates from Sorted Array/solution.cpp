#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        int last = nums.size() - 1;
        for(int i = 0; i < last; i++){
            if(nums[i] == nums[i+1]){
                int j = i+1;
                while(j < last){
                    nums[j] = nums[j+1];
                    j++;
                }
                nums[last] = 0;
                last--;
                i--;  // Recheck this position
            }
        }
        return last + 1;
}
int main(){
    vector <int> nums = {1,1,2,2,5,5,7,7,7,8};
    cout<<"Input Vector = [";
    for(int i =0; i<nums.size();i++){
        cout<<nums[i]<<",";
    }
    cout<<"]"<<endl;
    cout<<"The total Length of this Input vector is : "<<nums.size()<<"."<<endl;
    cout<<"Removing the Duplicates from the input array :"<<endl;
    int length = removeDuplicates(nums);
    cout<<"Output Vector after Removing Duplicates = [";
    for(int i =0; i<nums.size();i++){
        cout<<nums[i]<<",";
    }
    cout<<"]"<<endl;

    cout<<"The total Length of this Output vector is : "<<length<<"."<<endl;
    return 0;
}
