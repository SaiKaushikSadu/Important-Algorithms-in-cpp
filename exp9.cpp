#include<bits/stdc++.h>
using namespace std;
#define N 8

void printBoard(int board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]){
                cout<<"Q ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

int isValid(int board[N][N],int row,int col){
    int i,j;

    for(int i=0;i<N;i++){
        if(board[row][i]){
            return 0;
        }
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]){
            return 0;
        }
    }
    for(i=row,j=col;i<N && j>=0;i++,j--){
        if(board[i][j]){
            return 0;
        }
    }
    return 1;
}

int solveNqueen(int board[N][N],int col){
    if(col>=N){
        return 1;
    }
    for(int i=0;i<N;i++){
        if(isValid(board,i,col)){
            board[i][col]=1;
            if(solveNqueen(board,col+1)){
                return 1;
            }
            board[i][col]=0;
        }
    }
    return 0;
}

int soln(){
    int n;
    cout<<"Enter the the value of N"<<endl;
    cin>>n;

    int board[N][N];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }

    if(solveNqueen(board,0)==0){
        cout<<"Solution doesn't exist"<<endl;
        return 0;
    }
    else{
        printBoard(board);
        return 1;
    }
    
}

int main(){
    
    //N queen prblm
    soln();
    
    return 0;
}