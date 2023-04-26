#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //Insertion Sort
    int a[100];
    int n;

    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;

    cout<<"Enter the numbers:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Unsorted array is :";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    for(int i=0;i<n;i++){
        int key=a[i];
        int j=i-1;

        while(key<a[j] && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;

        //Each iteration
        cout<<endl;
        cout<<i+1<<" iteration: ";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }

    }

    cout<<endl;
    cout<<"Sorted array is :";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}