#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    if(arr.size()>=3){
        bool stat=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                cout<<"The Array starts in upward Direction [Good]\n";
                stat = 1;//To keep a record of actually having an upward direction initially in the array.
                cout<<"[Write] Status of our Bool = ["<<stat<<"]\n";
                continue;
            }
            else{
                cout<<"[Read 0] Status of our Bool = ["<<stat<<"]\n";

                if(stat==0){
                    cout<<"[Read 1] Status of our Bool = ["<<stat<<"]\n";
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
    vector<int> arr = {0,3,2,1};
    bool sol = validMountainArray(arr);
    if (sol){
        cout<<"This is a Valid Mountain Array\n";
    }
    else{
        cout<<"This is not a Valid Mountaitn Array\n";
    }
    return 0;
}
