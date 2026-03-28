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

    return false; // Placeholder
}

int main(){
    isHappy(19); // Test with 19
    return 0;
}
