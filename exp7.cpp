#include<bits/stdc++.h>
using namespace std;

string a;
string b;
char dm[30][30];
int matrix[30][30];

void print(int i,int j){
    if(i==0 || j==0){
        return;
    }
    if(dm[i][j]=='D'){
        print(i-1,j-1);
        cout<<a[i-1];
    }
    else if(dm[i][j]=='T'){
        print(i-1,j);
    }
    else{
        print(i,j-1);
    }
}

void lcs(int m,int n){

    for(int i=0;i<=n;i++){
        matrix[i][0]=0;
    }

    for(int i=0;i<=m;i++){
        matrix[0][i]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                matrix[i][j]=matrix[i-1][j-1]+1;
                dm[i][j]='D';
            }
            else if(matrix[i][j-1]>matrix[i-1][j]){
                matrix[i][j]=matrix[i][j-1];
                dm[i][j]='L';
            }
            else{
                matrix[i][j]=matrix[i-1][j];
                dm[i][j]='T';
            }
        }
    }

    cout<<"Length of lcs is "<<matrix[m][n]<<endl;

    cout<<"The LCS matrix "<<endl;
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"The direction matrix "<<endl;
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<dm[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    
    //Longest common subsequence
    int m;
    int n;

    cout<<"Enter the string A"<<endl;
    cin>>a;
    cout<<"Enter the string B"<<endl;
    cin>>b;

    m=a.size();
    n=b.size();

    lcs(m,n);
    cout<<"The Longest commmon subsequence is: "<<endl;
    print(m,n);
    
    return 0;
}

