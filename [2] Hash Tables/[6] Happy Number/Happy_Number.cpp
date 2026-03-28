#include <iostream>
#include <vector>

bool isHappy(int n) {
    std::vector<int> digits;
    
    // Process digits
    while(n > 0){
        digits.push_back(n % 10); // Add the last digit
        n = n / 10;               // Remove the last digit
    }
    // Print results
    std::cout << "The total Digits in [n] = [";
    for(int j = 0; j < digits.size(); j++){
        std::cout << digits[j] << (j == digits.size() - 1 ? "" : ", ");
    }
    std::cout << "]\n";
    int last = *(digits.end()-1);
    std::cout<<"The Last Digit is : "<<last<<"\n";
    if(last == 1){
        return true; //Happy Number
    }
    else{
        return false; // Not a happy Number
    }
}

int main(){
    bool Result;
    int n = 181;
    Result = isHappy(n);
    if(Result){
        std::cout<<n<<" is a Happy Number! :)\n";
    }
    else{
        std::cout<<n<<" is not a Happy Number! :(\n";
    }
    return 0;
}
