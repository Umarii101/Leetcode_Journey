#include <iostream>
#include <vector>
using namespace std;
//Writing "vector<int>&nums 1" Allows this vector to be modified when it is called in the main loop. No copy of this function is made, which means that this function will
//apply changes to real Data of an array when called.
//
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int last = m + n -1; //Last Index
    while(m>0 && n>0){
        if (nums1[m-1] > nums2[n-1]){
            nums1[last]= nums1[m-1];
            m -= 1;
        }
        else{
            nums1[last] = nums2[n-1];
            n -= 1;
        }
        last -=1;
    }
    while (n>0){
         nums1[last] = nums2[n];
         n-=1;
        last-=1;
    }
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
    int m=countNonZero(nums1);
    int n=countNonZero(nums2);
    cout<<"Input nums1 = [";
    for(int i=0;i<m+n;i++){
        cout<<nums1[i];
        }
    cout<<"]\n";
    cout<<"Input nums2 = [";
    for(int i=0;i<n;i++){
        cout<<nums1[i];
        }
    cout<<"]\n";


    merge(nums1,m,nums2,n);
    cout<<"nums1 after the Merge = [";
    for(int i=0;i<m+n;i++){
        cout<<nums1[i];
        }
    cout<<"]\n";
    return 0;

}

//Example 1:

//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
//The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.


//Example 2:

//Input: nums1 = [1], m = 1, nums2 = [], n = 0
//Output: [1]
//Explanation: The arrays we are merging are [1] and [].
//The result of the merge is [1]


//Example 3:

//Input: nums1 = [0], m = 0, nums2 = [1], n = 1
//Output: [1]
//Explanation: The arrays we are merging are [] and [1].
//The result of the merge is [1].
//Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
