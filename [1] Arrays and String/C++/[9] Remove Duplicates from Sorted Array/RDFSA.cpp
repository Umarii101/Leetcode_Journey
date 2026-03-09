#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int length = nums.size()-1;
    for(int i =0; i<length;i++){
        int j= i+1;
        if(nums[i] == nums[j]){
            cout<<"For (index,Value) = "<<i<<", "<<nums[i]<<"\t\tFound a duplicate at j = "<<j<<endl;
            cout<<"Replacing Index j = "<<j<<" with "<<nums[j+1]<<"\n\n";
            while(j<length){
                nums[j]=nums[j+1];
                nums[j+1]=0;
                j++;
                }
       }
    }
    return length;
}

int main(){
    vector <int> nums = {0,0,1,1,1,2,2,3,3,4};
    //Expected Output = 2, {1,2,_}; (Does'nt matter what we leave behind, hence Underscores
    int length = removeDuplicates(nums);
    cout<<"Output Array = [";
    for(int i =0; i<length+1;i++){
        cout<<nums[i]<<", ";
    }
    cout<<"]\n";
    return 0;
}
