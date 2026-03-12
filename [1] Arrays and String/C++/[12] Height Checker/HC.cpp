#include <iostream>
#include <vector>
using namespace std;
int heightChecker(vector<int>& heights) {
    int count =0;
    for(int i =0; i<heights.size();i++){
        cout<<"i = "<<i<<endl;
        if(heights[i]<heights[i+1]){
            cout<<"\t\tFound an incorrect indice at i = "<<i<<endl;
            count++;
        }
    }
    return count;
}

int main(){
    vector <int> heights = {1,1,4,2,1,3};
    //Expected Output = {1,1,1,2,3,4}; Arranged in Order and Also returning the incorrect indices, Such as (2,4,5).
    int output = heightChecker(heights);
    cout<<"\nThe Total Misplaced Indices are Total = "<<output<<endl;
    return 0;
}
