#include <iostream>
#include <vector>

int maxArea(std::vector<int>& heights){
    //Formula that i think is applicable here is Distance (Index <-> Index) * Height (Smaller between the two).
    //First Lets calculate a Suitable Distance. 
    int left = 0;
    int right = heights.size()-1;
    int volume=0; //To keep track of Current volume to Decide the Max volume.
    int maxVolume = 0;
    while(left<right){
        int height;
        int distance = right - left;
        if(heights[left] < heights[right]){
            height = heights[left];
            left++;
        }
        else{
            height = heights[right];
            right--;
        }
        volume = distance * height;
        if(volume > maxVolume){
            maxVolume = volume;
        }

    }

    return maxVolume;
}

int main(){
    std::vector<int> heights = {1,7,2,5,4,7,3,6};
    int Result = maxArea(heights);
    //Expected Output = 36 
    std::cout<<"The Result is : "<<Result<<".\n";
    return 0;
}
