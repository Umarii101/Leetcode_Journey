#include <iostream>
#include <vector>
using namespace std;
//Writing "vector<int>&nums 1" Allows this vector to be modified when it is called in the main loop. No copy of this function is made, which means that this function will
//apply changes to real Data of an array when called.
//
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    return; 
    }

int countNonZero(const vector<int> a){
    int count = 0;
    for (int num : a ){
        if (num != 0){
            count++;
        }
    }
    return count;
}

int main(){
    vector <int> nums1 = {1,2,3,0,0,0,0};
    vector <int> nums2 = {2,5,6};
    int L_n1=countNonZero(nums1);
    cout<<"The number of elements in Array 1 :"<<L_n1;
    return 0;

}
