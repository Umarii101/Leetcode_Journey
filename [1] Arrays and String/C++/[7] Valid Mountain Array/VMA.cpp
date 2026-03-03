#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    if(arr.size()>=3){
        bool stat=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                bool stat = 1;//To keep a record of actually having an upward direction initially in the array.
                continue;
            }
            else{
                if(stat==0){
                    cout<<"The array is just a descending downhill direction\n";
                    return 0;
                }
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
                }
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
    vector<int> arr = {9,8,7,6,5,4,3,2,1,0};
    bool sol = validMountainArray(arr);
    if (sol){
        cout<<"This is a Valid Mountain Array\n";
    }
    else{
        cout<<"This is not a Valid Mountaitn Array\n";
    }
    return 0;
}
