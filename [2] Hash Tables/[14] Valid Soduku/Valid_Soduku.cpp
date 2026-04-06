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

                //Need to create logic to detect 9 '3x3'SubBoxes in The board and keep track of which SubBox We are in Right now.
                int current_SubBox;
                if(r<=2 && c<=2){//Since R and C  initialized from 0.
                    current_SubBox = 1;
                }
                if(r<=2 && c>=2 && c<=5){
                    current_SubBox = 2;
                }
                if(r<=2 && c>=5 && c<=8){
                    current_SubBox = 3;
                }
                if(r>2 && r<=5 && c<=2){
                    current_SubBox = 4;
                }
                if(r>2 && r<=5 && c>2 && c<=5){
                    current_SubBox = 5;
                }
                if(r>2 && r<=5 && c>5 && c<=8){
                    current_SubBox = 6;
                }
                if(r>5 && r<=8 && c<=2){
                    current_SubBox = 7;
                }
                if(r>5 && r<=8 && c>2 && c<=5){
                    current_SubBox = 8;
                }
                if(r>5 && r<=8 && c>5 && c<=8){
                    current_SubBox = 9;
                }
                if(subBoards[current_SubBox].count(val)>0){
                    std::cout<<"The SubBoard Number : ["<<current_SubBox<<"] is not Valid.\n";
                    return false;//Since this Value Already Exists in our SubBoard.
                }
                subBoards[current_SubBox].insert(val);//OtherWise Lets Add The Value To the SubBoard.
        }
    }
    return true;
}

int main(){
    std::vector<std::vector<char>> board = {
         {'5','3','.',  '.','7','.',    '.','.','.'}
        ,{'6','.','.',  '1','9','5',    '.','.','.'}
        ,{'.','9','8',  '.','.','.',    '.','6','.'}

        ,{'8','.','.',  '.','6','.',    '.','.','3'}
        ,{'4','.','.',  '8','.','3',    '.','.','1'}
        ,{'7','.','.',  '.','2','8',    '.','.','6'}

        ,{'.','6','.',  '.','.','.',    '2','8','.'}
        ,{'.','.','.',  '4','1','9',    '.','.','5'}
        ,{'.','.','.',  '.','8','.',    '.','7','9'}
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

