#include <iostream>
#include <vector>
using namespace std;

bool checkIfExist(vector<int>& arr){
    int length=arr.size();
    cout<<"The Total Length of the Input array is : "<<length<<"\n";
    cout<<"\nindex \t value \t\tindex \t value\n";
    for(int i=0;i<length;i++){
       for(int j=i+1;j<length;j++){
            cout<<i<<" \t "<<arr[i]<<" \t\t"<<j<<" \t "<<arr[j]<<endl;
            if(arr[i]==arr[j]*2 || arr[i]*2==arr[j]){
                cout<<"The Doubles exists at index ["<<i<<", "<<j<<"] With values ["<<arr[i]<<", "<<arr[j]<<"]\n";
                return 1;
            }
            else{
                continue;
            }
        }
        
        cout<<"This index does not have a double in the array at all : "<<i<<"\n(A message from your friendly inside the function statement)\n";
    }
    return 0;
}

int main(){
    vector<int> arr = {10,2,6,7,9,12};
    cout<<"Input Array = [";
    for(int num =0; num<arr.size();num++){
        cout<<arr[num]<<", ";
    }
    cout<<"]\n";
    bool Result = checkIfExist(arr);
    switch(Result) {
        case 0 : cout<<"The double does not exist in this array at all.\n";break;
        case 1 : cout<<"The double exists.\n";break;
    }
    return 0;
}

