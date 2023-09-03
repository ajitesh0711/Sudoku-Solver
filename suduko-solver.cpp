#include<bits/stdc++.h>
using namespace std;
bool  isSafe(vector<vector<char>>&board,int row,int col,char value,int n)
{
        for(int i=0;i<n;i++){
            if(board[row][i]==value)
            { 
                return false;
            }
            if(board[i][col]==value)
            { 
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==value)
            {
                return false;
            }
        }
        return true;
}
    bool solve(vector<vector<char>>&board){
        int n=board.size();
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(board[row][col]=='.')
                {
                    for(char i='1';i<='9';i++)
                    {
                        if(isSafe(board,row,col,i,n))
                        {
                            board[row][col]=i;
                            bool isSolutionPossible=solve(board);
                            if(isSolutionPossible)
                            {
                                return true;
                            }
                            else
                            {
                                board[row][col]='.';
                            }
                        }
                    }
                    return false; 
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        bool possible = solve(board);
        return ;
    }
    int main()
    {
        vector<vector<char>>board;
        for(int x=0;x<9;x++)
        {
            vector<char>t;
            for(int y=0;y<9;y++)
            {
                char ch;
                cin>>ch;
                t.push_back(ch);
            }
            board.push_back(t);
        }
        solveSudoku(board);
        for(int x=0;x<9;x++)
        {
            for(int y=0;y<9;y++)
            {
                cout<<board[x][y]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }