#include <iostream>
#include <vector>
#include <unordered_map>

bool isValidSudoku(std::vector<std::vector<char>>& board){

    return false;
}

int main(){
    std::vector<std::vector<char>> board = {
         {"5","3",".",".","7",".",".",".","."}
        ,{"6",".",".","1","9","5",".",".","."}
        ,{".","9","8",".",".",".",".","6","."}
        ,{"8",".",".",".","6",".",".",".","3"}
        ,{"4",".",".","8",".","3",".",".","1"}
        ,{"7",".",".",".","2",".",".",".","6"}
        ,{".","6",".",".",".",".","2","8","."}
        ,{".",".",".","4","1","9",".",".","5"}
        ,{".",".",".",".","8",".",".","7","9"}
    };
    //Expected Output = True.
    bool Result = isValidSukodu(board);
    if(Result){
        std::cout<<"The Game board is Valid\n";
    }
    else{
        std::cout<<"The Game board is Invalid\n";
    }
    return 0;
}

