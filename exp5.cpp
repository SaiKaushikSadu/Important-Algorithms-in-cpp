#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //Prims Algorithm (Minimum spanning tree)
    int current,totalvis,mincost,n;
    cout<<"Enter the no of nodes present in graph"<<endl;
    cin>>n;

    int weight[n][n];
    int dis[n];
    int vis[n];
    int pre[n];

    //input weight of edges
    cout<<"Enter the weights of the edges"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>weight[i][j];
        }
    }

    //default values
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
        vis[i]=0;
        pre[i]=0;
    }

    //current
    current=0;
    dis[current]=0;
    vis[current]=1;
    pre[current]=0;

    totalvis=1;

    //min distance calc.
    while(totalvis!=n){
        for(int i=0;i<n;i++){
            if(weight[current][i]!=0){
                if(vis[i]==0){
                    if(dis[i]>weight[current][i]){
                        dis[i]=weight[current][i];
                        pre[i]=current;
                    }
                }
            }
        }

        mincost=INT_MAX;

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(mincost>dis[i]){
                    mincost=dis[i];
                    current=i;
                }
            }
        }

        vis[current]=1;
        totalvis++;
    }

    mincost=0;
    for(int i=0;i<n;i++){
        mincost+=dis[i];
        cout<<"Node = "<<i<<" and predecessor is "<<pre[i]<<" and wt is "<<dis[i]<<" and current cost is "<<mincost<<endl;
    }

    cout<<"The minimum cost of spanning tree is "<<mincost<<endl;

    return 0;
}
