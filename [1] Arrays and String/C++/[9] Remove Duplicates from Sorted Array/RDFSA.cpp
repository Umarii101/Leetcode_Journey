#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int length = nums.size()-1;
    int dup_ptr =0; //This pointer will point to the latest index where a duplicate was found at. 
    //Length becomes 2 here, 0-2.
    for(int i =0; i<length;i++){
        for(int j=i+1;j<length+1;j++){
            if(nums[i] == nums[j]){
                cout<<"For (index,Value) = "<<i<<", "<<nums[i]<<"\t\tFound a duplicate at j = "<<j<<endl;
                cout<<"Replacing Index j = "<<j<<" with "<<nums[j+1]<<"\n\n";
                dup_ptr=j;
                nums[j]=nums[j+1];
                nums[j+1]=0;
            }
       }
    }
    return length;
}

int main(){
    vector <int> nums = {1,1,2};
    //Expected Output = 2, {1,2,_}; (Does'nt matter what we leave behind, hence Underscores
    int length = removeDuplicates(nums);
    cout<<"Output Array = [";
    for(int i =0; i<length+1;i++){
        cout<<nums[i]<<", ";
    }
    cout<<"]\n";
    return 0;
}
