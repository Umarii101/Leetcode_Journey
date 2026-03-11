#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int last = nums.size()-1; //Last index starting from 0 to n;
    for(int rp = 0; rp <last;rp++){
        //Read Pointer Starting from index 0;
        cout<<rp<<endl;
        if (nums[rp] == 0){
            cout<<"Found a match for 0 at index i = "<<rp<<endl;
            int wp = rp;
            while(wp<last){
                nums[wp] = nums[wp+1];
                cout<<"WP = "<<wp<<endl;
                wp++;
            }
            cout<<"Placing 0 at index i = "<<last<<", Afer Shifting the whole array to left \n";
            nums[last] =0;
            last -= 1;
            rp--;
        }
    }
}

int main(){
    vector <int> nums = {0,1,0,3,12};
    //Expected Output = {1,3,12,0,0};
    //Current Output ={1,3,12,0,0};
    moveZeroes(nums);
    cout<<"[";
    for (int i =0; i < nums.size();i++){
        cout<<nums[i]<<", ";   
    }
    cout<<"]\n";
    return 0;
}
