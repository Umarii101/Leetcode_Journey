#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board){
    std::unordered_map<int , std::unordered_set<char>> rows;
    std::unordered_map<int , std::unordered_set<char>> columns;
    std::unordered_map<int , std::unordered_set<char>> subBoards;
    //Checking All the Rows First. 
    for(int r = 0; r<9;r++){//Since Sudoku board has 9 Rows.
        for(int c =0; c<9;c++){//Sudoku Board has 9 columns.
                char val = board[r][c];//Select The value.
                if(board[r][c] == '.'){
                    continue;
                }
                if (rows[r].count(val)>0){
                    std::cout<<"The Rows are Not valid for this Board.\n";
                    return false;//Since The value exists in our row already. Hence the Sudoku Board is Incorrect.
                } 
                rows[r].insert(val);//This means that the value is unique, Lets add it to our Rows Map.

                if(columns[c].count(val)>0){
                    std::cout<<"The Columns are not valid for this Board.\n";
                    return false;
                }
                columns[c].insert(val);
        }

    }
    
    return true;
}

int main(){
    std::vector<std::vector<char>> board = {
         {'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'5','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}
    };
    //Expected Output = True.
    bool Result = isValidSudoku(board);
    if(Result){
        std::cout<<"The Game board is Valid\n";
    }
    else{
        std::cout<<"The Game board is not Valid\n";
    }
    return 0;
}

