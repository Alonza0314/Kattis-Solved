#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int num,times;
int counting=0;
int dp[50];

struct unit
{
    int money;
    int waiting_times;
};
vector<unit> arr;

bool cmp(unit a,unit b)
{
    return a.waiting_times<b.waiting_times;
}

int main()
{
    cin>>num>>times;
    arr.resize(num);
    for(int i=0;i<num;i++)
    {
        cin>>arr[i].money>>arr[i].waiting_times;
    }
    sort(arr.begin(),arr.end(),cmp);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<num;i++)
    {
        for(int j=times;j>0;j--)
        {
            if(arr[i].waiting_times>=j-1)
            {
                dp[j]=max(dp[j],dp[j-1]+arr[i].money);
            }
            counting=max(dp[j],counting);
        }
    }
    
    cout<<counting;
    return 0;
}