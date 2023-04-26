#include<bits/stdc++.h>
using namespace std;

int c;

void soln(int in,int target,vector<int>&nums,vector<vector<int>> &ans,vector<int> sub){
    if(target==0){
        ans.push_back(sub);
        return;
    }
    c++;
    for(int i=in;i<nums.size();i++){
        if(i>in && nums[i]==nums[i-1]) continue;
        if(nums[i]>target) break;
        sub.push_back(nums[i]);
        soln(i+1,target-nums[i],nums,ans,sub);
        sub.pop_back();
    }
}

int main(){
    
    //Sum of subset
    vector<int> nums;

    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }

    int target;
    cout<<"Enter the target element"<<endl;
    cin>>target;

    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    soln(0,target,nums,ans,vector<int>());

    cout<<"Subsets are:"<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"No of calls to subset function is "<<c<<endl;

    return 0;
}

