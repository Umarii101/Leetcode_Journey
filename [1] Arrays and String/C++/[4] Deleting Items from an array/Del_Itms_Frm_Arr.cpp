#include <iostream>
#include <vector>
using namespace std;
    
int removeElement(vector<int>&nums,int val){
    int last = 0; //We need to find the last index of the array to use it as a second pointed for moving backwards in the array.
    for (int num : nums){
        cout<<"Index No : "<<last<<", value at index : "<<num<<endl;
        last++;
    }
    last--;// Decrementing the last point to accurately reflect the last index;
    cout<<"The Last pointer is at index : "<<last<<" after Calculating the last index. \n"<<endl;
    int i=0;
    //Pointer 1 = i, which starts from index 0 of the array.
    cout<<"Beginning Loop with i<last condition :"<<endl;
    while(i<=last){
        cout<<"i = : "<<i<<endl;
        if (nums[i] == val) {
            while(nums[i]==val){ //This while loop is used to handle the case for when the next index also contains the same val we want to remove, so we remove the value and do the shift until val is not repeated or the loop ends.
                for(int j=i;j<last;j++){
                    nums[j] = nums[j+1];
                }
                nums[last] = 0;
                last--; // Decrement the Last index to second last and so on
            }
        }
        else{
            i++;
        }
        
    }
    return last+1; //Since Last will be at the last index where the Last modification was dumped, Hence that will be the size of the array that is updated after removing the undesired val
}

int main(){
    vector<int> nums;
    int val; 
    int length;
    cout<<"[1] Enter the Size of the Array : ";cin>>length;
    cout<<"[2] Enter The Values of the Array :"<<endl;
    
    for(int i=0; i<length;i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }

    cout<<"Enter the Value to remove :";cin>>val;

    cout<<"The Input Array = [";
    for(int num : nums){
        cout<<num<<",";
    }
    cout<<"]"<<endl;
    cout<<"Beginning Element Removal \n";
    int size = removeElement(nums,val);
    cout<<"Size of the output Array = "<<size<<endl;
    cout<<"The Output Array = [";
    for(int num : nums){
        cout<<num<<",";
    }
    cout<<"]"<<endl;
    return 0;
}
