#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<vector<int>>dis;
int n=4;
void TSP(int start)
{
    vector<bool>visited(n,false);
    vector<int>path;
    int MinCost=0,current=start;

    path.push_back(current);
    visited[current]=true;
    for(int i=1; i<n; i++)
    {
        int nearest=-1,minDis=INF;
        for(int j=0; j<n; j++)
        {
            if(!visited[j] && dis[current][j]<minDis)
            {
                minDis=dis[current][j];
                nearest=j;
            }
        }
        if(nearest==-1) break;

        visited[nearest]=true;
        path.push_back(nearest);
        MinCost+=minDis;
        current=nearest;
    }
    MinCost+=dis[current][start];
    path.push_back(start);

    cout<<"Optimal Path: ";
    for(int i: path) cout<<i<<" ";
    cout<<"\nOptimal Cost: "<<MinCost<<"\n";
}

int main()
{
    dis={
          {0,10,15,20},
          {10,0,35,25},
          {15,35,0,30},
          {20,25,30,0}
        };
        TSP(0);

}