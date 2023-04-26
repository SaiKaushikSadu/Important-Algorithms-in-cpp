#include<bits/stdc++.h>
using namespace std;
#define n 5

int path[n][n];
int matrix[n][n];

void print(int matrix[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void printpath(int s,int v){
    if(v==s){
        cout<<s;
    }
    else if(path[s][v]==-1){
        cout<<"no path exists";
    }
    else{
        printpath(s,path[s][v]);
        cout<<"->";
        cout<<v;
    }
}

void warshall(int graph[][n]){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=graph[i][j];
            if(i==j){
                path[i][j]=-1;
            }
            else if(graph[i][j]==0){
                path[i][j]=-1;
            }
            else{
                path[i][j]=i;
            }
            
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][k]+matrix[k][j]<matrix[i][j]){
                   matrix[i][j]=matrix[i][k]+matrix[k][j];
                   path[i][j]=path[k][j];
                }
            }
        }
    }

    cout<<"Warshall matrix is"<<endl;
    print(matrix);
    cout<<"Path matrix is"<<endl;
    print(path);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            cout<<"The path from "<<i <<" to "<<j <<" is ";
            printpath(i,j);
            cout<<endl;
        }
    }

}

int main(){
    
    //Warshall ALgorithm
    int node;
    cout<<"Enter the no of nodes"<<endl;
    cin>>node;

    int graph[n][n];
    cout<<"Enter the weights "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    warshall(graph);
    
    return 0;
}