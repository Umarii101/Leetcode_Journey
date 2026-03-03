#include <iostream>
#include <vector>
using namespace std;

vector <int> replaceElements(vector<int>& arr) {
    cout<<"Starting The Operation\n";
    for(int i=0; i<arr.size();i++){
        cout<<"i = "<<i<<"\n";
        if(arr[i] < arr[i+1]){
            arr[i]=arr[i+1];
            int j = i;
            while(arr[j+1]>arr[j+2]){
                cout<<"j = "<<j<<"\n";
                j++;
            }
            while(i<j){
                arr[i+1]=arr[j];
                cout<<"i(2) = "<<i<<"\n";
                i++;
            }
        }
    }
    return arr;
}

int main(){
    vector<int> arr = {17,18,5,4,6,1}; //Size of Input  Array = 6
    //Output array = {18,6,6,6,1,-1}   //Size of Output Array = 6
    cout<<"Input Array = [";
    for(int num : arr){
        cout<<num<<", ";
    }
    cout<<"]\n";
    replaceElements(arr);
    cout<<"Output Array = [";
    for(int num : arr){
        cout<<num<<", ";
    }
    cout<<"]\n";
    return 0;
}
