#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    if(arr.size()>=3){
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                continue;
            }
            else{
                while(i<arr.size()){
                    if(arr[i]<arr[i-1]){
                        i++;
                        cout<<i<<endl;
                        continue;
                    }
                    else{
                        cout<<"Not a strict mountain at i = ["<<i<<"]\n";
                        return 0;
                    }
                } return 1;
            }
        }
    }
    else{
        return 0;
    }
    return 1;
}

int main(){
    vector<int> arr = {0,3,2,1,2};
    bool sol = validMountainArray(arr);
    if (sol){
        cout<<"This is a Valid Mountain Array\n";
    }
    else{
        cout<<"This is not a Valid Mountaitn Array\n";
    }
    return 0;
}
