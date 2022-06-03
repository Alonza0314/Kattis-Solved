#include<iostream>
#include<stack>
using namespace std;

long long num,temp,maxi;
long long *mountains=nullptr;
stack<pair<long long,long long>> st;

int main()
{
    cin>>num;
    mountains=new long long[num];

    for(long long i=0;i<num;i++)
    {
        cin>>mountains[i];
    }
    maxi=0;
    
    for(int i=0;i<num;i++)
    {
        temp=mountains[i];
        while(st.size()>0)
        {
            pair<long long,long long> up=st.top();
            st.pop();
            temp=min(up.second,temp);
            if(up.first>mountains[i])
            {
                st.push(pair<long long,long long>(up.first,temp));
                maxi=max(maxi,mountains[i]-temp);
                break;
            }
            maxi=max(maxi,up.first-temp);
        }
        st.push(pair<long long,long long>(mountains[i],mountains[i]));
    }

    cout<<maxi;

    return 0;
}