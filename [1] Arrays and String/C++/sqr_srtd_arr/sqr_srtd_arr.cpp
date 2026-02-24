#include <iostream>
using namespace std;
int main(){
	int nums[] = {-4,-1,0,3,10};
	int i = 0;
	for(int num : nums) {
		num *= num;
		nums[i] = num;
		i++;
	}
	cout<<"Squared Array: \n[";
	for (int j =0; j < i;j++){
		cout<<nums[j]<<", ";
	}
	cout<<"]";
	int temp;
	for(int pass =0; pass < i-1; pass++){
		for(int j = 0; j<i-1 - pass; j++){
			if(nums[j] > nums[j+1]){
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}	
	cout<<"\nAscending Order: \n[";
	for (int j =0; j < i;j++){
		cout<<nums[j]<<", ";
	}
	cout<<"]";
	return 0;
}
