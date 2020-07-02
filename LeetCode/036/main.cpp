#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> board) {
        int square[9][9];
        bool check[10];
        int i,j;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                int num = board[i][j]-'0';
                if(num<1 || num>9){
                    square[i][j] = 0;
                }else{
                    square[i][j] = board[i][j]-'0';
                }
            }
        }
        // rows 
        for(i=0;i<9;i++){
            for(j=0;j<10;j++){
                check[j] = false;
            }
            for(j=0;j<9;j++){
                if(square[i][j] == 0){
                    continue;
                }
                if(!check[square[i][j]]){
                    check[square[i][j]] = true;
                }else{
                    return false;
                }
            }
        }
        // cols
        for(i=0;i<9;i++){
            for(j=0;j<10;j++){
                check[j] = false;
            }
            for(j=0;j<9;j++){
                if(square[j][i] == 0){
                    continue;
                }
                if(!check[square[j][i]]){
                    check[square[j][i]] = true;
                }else{
                    return false;
                }
            }
        }
        // 3x3
        for(i=0;i<9;i++){
            for(j=0;j<10;j++){
                check[j] = false;
            }
            for(j=0;j<9;j++){
                int x=(i/3)*3+(j/3);
                int y=(i%3)*3+(j%3);
                if(square[x][y] == 0){
                    continue;
                }
                if(!check[square[x][y]]){
                    check[square[x][y]] = true;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    const vector<vector<char>> square = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    cout<<s.isValidSudoku(square)<<endl;
}
