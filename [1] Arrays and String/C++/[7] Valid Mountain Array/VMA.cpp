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
    cout<<"Not a valid Array, Since We went through all the Array and have not found a single Descending Value\n";
    return 0;
 
}

int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9,10};
    bool sol = validMountainArray(arr);
    if (sol){
        cout<<"This is a Valid Mountain Array\n";
    }
    else{
        cout<<"This is not a Valid Mountaitn Array\n";
    }
    return 0;
}
