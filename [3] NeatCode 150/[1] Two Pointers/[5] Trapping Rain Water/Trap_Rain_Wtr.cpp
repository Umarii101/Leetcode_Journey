#include <iostream>
#include <vector>

int trap(std::vector<int>& height) {
    int Result;
    //First  Things i noticed is that The Bars have Area aswell this time, and the problem is pretty much the same as previous one.
    //Lets create a bar area calculation first, then we will trap water between the bars and return the total amount of water trapped between the bars.

    for(int i = 0; i<heights.size()-1; i++){
        int currBarArea = 0;
        if(heights[i] != 0){
            while(i != heights.size()-2 && heights[i+1] != 0){
                currBarArea = currBarArea + heights[i] + heights[i+1];
                i++;
            }
        }



    }





    return Result;
}

int main(){
    std::vector<int> height = {4,2,0,3,2,5};
    int result = trap(height);
    std::cout<<"The Result is "<<result<<"\n";
    //Output =  9

    return 0;
}
