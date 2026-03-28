#include <iostream>
#include <unordered_set>

int getNext(int n){
    int total_sum = 0;
    while(n > 0){
        int d = n%10;
        total_sum += d*d;
        n /=10;
    }
    return total_sum;
}

bool isHappy(int n) {
    std::unordered_set<int> seen;

    while(n !=1 && seen.find(n) == seen.end()){
        seen.insert(n);
        n = getNext(n);
    }
    return n == 1;
}

int main(){
    bool Result;
    int n = 7;
    Result = isHappy(n);
    if(Result){
        std::cout<<n<<" is a Happy Number! :)\n";
    }
    else{
        std::cout<<n<<" is not a Happy Number! :(\n";
    }
    return 0;
}
