#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>&nums){
    int last = nums.size(); //Last index of The input Array.
    last -=1;
    cout<<"=========================================="<<endl;
    cout<<"====== Operation Duplicates Removal ======="<<endl;
    cout<<"=========================================="<<endl;
    cout<<"\nThe Last index in the input Array = :"<<last<<endl<<endl;
    for(int i = 0;i<last;i++){
        if(nums[i]==nums[i+1]){
            cout<<endl;
            cout<<"Found the duplicate at Indexes : ["<<i<<", "<<i+1<<"] with value ("<<nums[i]<<", "<<nums[i+1]<<")"<<endl;
            cout<<endl;
            //When a duplicate is found, I need to left shift the whole array until last index, and place a 0 in place of last index.
            int j=i+1; //We want index i at its own place, we will shift from next indexes.
            while(j<last){
                cout<<"Replacing index value ("<<j<<", "<<nums[j]<<") with ("<<j+1<<", "<<nums[j+1]<<")"<<endl;
                nums[j]=nums[j+1];//Up until this point, the function can handle only 2 duplicates.
                //Need an additional check to make sure that the duplicates are repeated or not in the next indexes.
                j++;
                
            }
            //Placing 0 at last index, and moving the Last index pointer to the left one time.
       }
        nums[last] = 0;
        last -=1;
    }
    return last+1;
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
