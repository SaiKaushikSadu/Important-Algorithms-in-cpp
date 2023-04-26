#include<bits/stdc++.h>
using namespace std;
int main(){

    //Selection Sort
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

    int pos;
    int temp;
    for(int i=0;i<n;i++){
        pos=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[pos]){
                pos=j;
            }
        }
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;

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
