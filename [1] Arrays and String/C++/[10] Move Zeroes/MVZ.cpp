#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int length = nums.size();
    cout<<"\n"<<length<<endl;
}

int main(){
    vector <int> nums = {0,1,0,3,12};
    //Expected Output = {1,3,12,0,0};
    moveZeroes(nums);
    return 0;
}
