#include<bits/stdc++.h>
using namespace std;

int c=0;

int partition(int a[],int l,int r){
    int pivot=a[r];
    int i=(l-1);

    int temp;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;

    return (i+1);

}

void quick_sort(int a[],int l,int r){
    c++;
    int p;
    if(l<r){
        p=partition(a,l,r);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,r);
    }
}

int main(){
    
    //Quick Sort
    int a[100];
    int n;
    cout<<"Enter the no of elements: "<<endl;
    cin>>n;

    cout<<"Unsorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    quick_sort(a,0,n-1);

    cout<<"Sorted array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;

    cout<<"No of times the quick sort called is "<<c<<endl;
    
    return 0;
}

