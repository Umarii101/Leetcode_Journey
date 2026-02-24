#include <iostream>
using namespace std;

void duplicateZeroes(int arr[], int size){
    int possibleDups = 0;
    int length = size-1;

    //Find the Last Element that will fit after Duplication
    for(int i = 0; i <= length; i++){
        if(arr[i] == 0){
            //Edge Case if Zero is at the boundary
            if(i==length){
                arr[size-1] = 0;
                length--;
                break;
            }
            possibleDups++;
            length--;
        }
    }

    //Work Backwards And Duplicate Zeroes
    int last = size -1;
    for(int i = length; i>=0;i--){
        if(arr[i] == 0){
            arr[last] = 0;
            last--;
            arr[last] = 0;
            last--;
        }
        else{
            arr[last] = arr[i];
            last--;
        }
    }
}

int main(){
    int nums[] = {8,4,5,0,0,0,0,7};
    int size =0; //To calculate the size of the input array
    
    for(int num : nums){
        size++;
    }
    cout << "Input Array = [";
    for(int i = 0; i < size; i++){
        cout << nums[i];
        if(i < size - 1) cout << ", ";
    }
    cout << "]" << endl;


    cout<<"Size of Array = "<<size<<"\n";
    duplicateZeroes(nums,size);
    
     // Print result
    cout << "Output Array = [";
    for(int i = 0; i < size; i++){
        cout << nums[i];
        if(i < size - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

