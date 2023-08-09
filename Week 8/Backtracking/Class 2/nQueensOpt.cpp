#include <bits/stdc++.h>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> uperLeftDCheck;
unordered_map<int,bool> bottomRightDCheck;

void printSolution(vector<vector<int>> board, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}

bool isSafe(int row, int col, vector<vector<int>> board, int n)
{
    if(rowCheck[row]==true)
        return false;

    if(bottomRightDCheck[row+col]==true)
        return false;

    if(uperLeftDCheck[n-1+col-row]==true)
        return false;

    return true;

    //curr row
    // int j = col;
    // while(j>=0)
    // {
    //     if(board[row][j]==1)
    //         return false;
    //     j--;
    // }
    // if(row[j]==true)
    //     return false;

    //curr col
    // int i = row;
    // while(i>=0)
    // {
    //     if(board[i][col]==1)
    //         return false;
    //     i--;
    // }

    //upper diagonal
    // int i = row;
    // j = col;
    // while(i>=0 && j>=0)
    // {
    //     if(board[i][j]==1)
    //         return false;
    //     i--;
    //     j--;
    // }

    // //lower diagonal
    // i = row;
    // j = col;
    // while(i<n && j>=0)
    // {
    //     if(board[i][j]==1)
    //         return false;
    //     i++;
    //     j--;
    // }

    // return true;
}

void solve(vector<vector<int>> board, int col, int n)
{
    // cout<<col<<" "<<endl;
    if(col>=n)
    {
        printSolution(board,n);
        return;
    }

    //1 case hum, aaki recursion
    //har column me place krne ka try kro

    for(int row=0; row<n; row++)
    {
        // cout<<row<<" "<<endl;
        if(isSafe(row,col, board, n))
        {
            board[row][col] = 1;
            rowCheck[row] = true;
            bottomRightDCheck[row+col] = true;
            uperLeftDCheck[n-1+col-row] = true;
            // cout<<row<<" "<<col<<endl;
            solve(board, col+1, n);
            board[row][col] = 0;
            rowCheck[row] = false;
            bottomRightDCheck[row+col] = false;
            uperLeftDCheck[n-1+col-row] = false;
        }
    }
    return;
}

int main()
{
    int n = 6;
    vector<vector<int>> board(n, vector<int> (n,0));
    int col = 0;
    solve(board, col, n);
    return 0;
}