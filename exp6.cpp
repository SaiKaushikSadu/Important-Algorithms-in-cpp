#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //Fractional Knapsack
    int capacity;
    int no_items;
    int curr_wt;
    int item;

    int used[10];
    float total_profit;

    int weight[10];
    int value[10];

    cout<<"Enter the capacity"<<endl;
    cin>>capacity;

    cout<<"Enter the no of items"<<endl;
    cin>>no_items;

    for(int i=0;i<no_items;i++){
        cout<<"Enter the weight"<<endl;
        cin>>weight[i];
        cout<<"Enter the value"<<endl;
        cin>>value[i];
    }

    for(int i=0;i<no_items;i++){
        used[i]=0;
    }

    curr_wt=capacity;

    while(curr_wt>0){
        item=-1;
        for(int i=0;i<no_items;i++){
            if((used[i]==0) && (item==-1)||(float) value[i]/weight[i]>(float) value[item]/weight[item])
                item=i;
        }

        used[item]=1;
        curr_wt-=weight[item];
        total_profit+=value[item];
        if(curr_wt>=0){
            cout<<"Added object "<<item+1<<"("<<value[item]<<"Rs ,"<<weight[item]<<" kg ) completely in bag . space left is "<<curr_wt<<endl;
        }
        else{
            int item_percent=(int) ((1+(float)curr_wt/weight[item])*100);
            cout<<"Added object "<<item_percent<<"("<<value[item]<<"Rs ,"<<weight[item]<<" kg ) completely in bag "<<endl;
            total_profit-=value[item];
            total_profit+=(1+(float)curr_wt/weight[item])*value[item];
        }
    }

    cout<<"Total profit is "<<total_profit<<endl;
    return 0;
}