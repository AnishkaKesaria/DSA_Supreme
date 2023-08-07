//TC - exponential
//4 to the power n

#include <bits/stdc++.h>
using namespace std;

void solveMaze(int arr[4][4], vector<vector<bool>> &visited, vector<string> &path, string output, int i, int j, int row, int col)
{
    if(arr[0][0]==0)
        return;

    if(i==row-1 && j==col-1)
    {
        path.push_back(output);
        return;
    }

    //Down
    if(i+1<row && arr[i+1][j]==1 && visited[i+1][j]!= true)
    {
        visited[i+1][j] = true;
        solveMaze(arr, visited, path, output + 'D', i+1, j, row, col);
        visited[i+1][j] = false;
    }

    //Left
    if(j-1>=0 && arr[i][j-1]==1 && visited[i][j-1]!= true)
    {
        visited[i][j-1] = true;
        solveMaze(arr, visited, path, output + 'L', i, j-1, row, col);
        visited[i][j-1] = false;
    }

    //Right
    if(j+1<col && arr[i][j+1]==1 && visited[i][j+1]!= true)
    {
        visited[i][j+1] = true;
        solveMaze(arr, visited, path, output + 'R', i, j+1, row, col);
        visited[i][j+1] = false;
    }

    //Up
    if(i-1>=0 && arr[i-1][j]==1 && visited[i-1][j]!= true)
    {
        visited[i-1][j] = true;
        solveMaze(arr, visited, path, output + 'U', i-1, j, row, col);
        visited[i-1][j] = false;
    }
    return;
}

int main()
{
    // int maze[3][3] = {{1,0,0},{1,1,0},{1,1,1}};
    int maze[4][4] = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    int row = 4;
    int col = 4;
    vector<vector<bool>> visited (row,vector<bool> (col,0));
    visited[0][0] = true;
    vector<string> path;
    string output = "";
    int i=0, j = 0;
    solveMaze(maze, visited, path, output, i, j, row, col);
    for(int k=0; k<path.size(); k++)
        cout<<path[k]<<" ";
    return 0;
}