#include <iostream>
#include <vector>
using namespace std;

vector <int> replaceElements(vector<int>& arr) {
    cout<<"Starting The Operation\n";
    bool bounds = 1;
    for(int i=0; i<arr.size();i++){
        cout<<"i = "<<i<<"\n";
        if(i+1 < arr.size() && arr[i] < arr[i+1] && bounds){
            cout<<"[Replacing] -> "<<arr[i]<<" -> "<<arr[i+1]<<endl;
            arr[i]=arr[i+1]; 
            int j = i;
            while(arr[j+1]>arr[j+2]){
                cout<<"j = "<<j<<"\n";
                j++;
            }
            cout<<"-> J = "<<j<<"\n";
            while(i<j+2){
                cout<<"Target found (Value,Index) -> ("<<arr[j+2]<<","<<j+2<<")\n";
                cout<<"[After]-> J= "<<j<<"\n";
                if(i+2 != arr.size()-1){
                    cout<<"[Replacing] -> "<<arr[i+1]<<" -> "<<arr[j+2]<<endl;
                    arr[i+1]=arr[j+2];
                }
                else{
                    cout<<"[Warning] i Out of Bounds\n";
                    bounds=0;
                    break;
                }
                cout<<"i(2) = "<<i<<"\n";
                i++;
            }
        }
    } 
    int last = arr.size()-1;
    cout<<"\n\n [SIZE]-> "<<last<<"\n\n";
    if(last > 0) arr[last-1]=arr[last];
    arr[last]=-1;
    return arr;
}
int main(){
    vector<int> arr = {56903,18666,60499,57517,26961}; //Size of Input  Array = 6
    int last = arr.size()-1;
    cout<<"Input Array = [";
    for(int i=0; i<last+1;i++){
        if(i!=last){
            cout<<arr[i]<<", ";
        }
        else{
            cout<<arr[i];
            cout<<"]\n";
        }
    }
    cout<<"Size = "<<arr.size()<<endl;
    replaceElements(arr); 
    cout<<"Output Array = [";
    for(int i=0; i<last+1;i++){
        if(i!=last){
            cout<<arr[i]<<", ";
        }
        else{
            cout<<arr[i];
            cout<<"]\n";
        }
    }
    cout<<"Size = "<<arr.size()<<endl;    return 0;
}
