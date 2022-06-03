#include<iostream>
#include<vector>
using namespace std;

int num,temp;
vector<int> vec;

int main()
{
    cin>>num;
    vec.resize(num,0);

    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cin>>temp;
            vec[i]|=temp;
        }
    }
    for(auto i:vec)
    {
        cout<<i<<" ";
    }

    return 0;
}