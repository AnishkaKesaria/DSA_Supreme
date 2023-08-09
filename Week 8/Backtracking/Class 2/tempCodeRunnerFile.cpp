int i = row;
    while(i>=0)
    {
        if(board[i][col]==1)
            return false;
        i--;
    }