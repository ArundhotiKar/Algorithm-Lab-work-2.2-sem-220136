#include<bits/stdc++.h>
using namespace std;
int Knapsack(int n, vector<int>weight, vector<int>value,int cap)
{
    vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
    for(int i=1; i<=n; i++)
    {
        for(int w=0; w<=cap; w++)
        {
            if(weight[i-1]<=w)
            {
                dp[i][w]=max(dp[i-1][w], dp[i-1][w-weight[i-1]]+value[i-1]);
            }else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][cap];
}
int main()
{
    int n,cap;
    cout<<"Enter the number of item: ";
    cin>>n;
    cout<<"Enter the Capacity of total items: ";
    cin>>cap;
    vector<int>weight(n),value(n);
    cout<<"Enter weight & value of n items: \n";
    for(int i=0; i<n; i++)
    {
        cin>>weight[i]>>value[i];
    }
    
    cout << "Maximum value in Knapsack = " <<Knapsack(n,weight,value, cap);
}