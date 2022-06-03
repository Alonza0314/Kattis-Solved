#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<long long,vector<long long>,greater<long long>> pq;

int test_case,num;
long long temp,num1,num2,temp_count;

int main()
{
    cin>>test_case;
    for(int i=0;i<test_case;i++)
    {
        cin>>num;
        temp_count=0;
        for(int i=0;i<num;i++)
        {
            cin>>temp;
            pq.push(temp);
        }
        while(pq.size()>1)
        {
            num1=pq.top();pq.pop();
            num2=pq.top();pq.pop();
            temp_count+=(num1+num2);
            pq.push(num1+num2);
        }
        cout<<temp_count<<"\n";
        pq.pop();
    }
    return 0;
}