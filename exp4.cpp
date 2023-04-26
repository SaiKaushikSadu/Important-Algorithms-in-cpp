#include<bits/stdc++.h>
using namespace std;

int c=0;

void merge(int a[],int l,int r,int mid){
    
    int n1,n2,i,j,k;
    n1=mid-l+1;
    n2=r-mid;
    int L[n1],R[n2];
    for(i=1;i<=n1;i++) L[i]=a[l+i-1];
    for(j=1;j<=n2;j++) R[j]=a[mid+j];

    
    L[n1+1]=INT_MAX;
    R[n2+1]=INT_MAX;

    i=1;
    j=1;
    for(k=l;k<=r;k++){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
    }
}

void merge_sort(int a[],int l,int r){   
    c++;
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        merge(a,l,r,mid);
    }

}


int main(){
    
    //Merge sort
    int n;
    cout<<"Enter the number of elements you need in array:"<<endl;
    cin>>n;

    int a[n];
    cout<<"Enter the elements"<<endl;
    for(int i=1;i<=n;i++) cin>>a[i];

    cout<<"The inital unsorted array is:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<a[i]<< " ";
    }
    cout<<endl;

    merge_sort(a,1,n);

    cout<<"The final sorted array :"<<endl;
    for(int i=1;i<=n;i++){
        cout<<a[i]<< " ";
    }

    cout<<endl;
    cout<<"The no of times the merge function called is: "<<c<<endl;
    
    return 0;
}

