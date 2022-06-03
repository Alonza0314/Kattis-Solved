#include<iostream>
#include<map>
using namespace std;

int num,temp,counting;
map<int,int> table;
map<int,int>::iterator itt;

int main()
{
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>temp;
        table[temp]+=1;
    }
    temp=num;
    counting=0;
    for(itt=table.begin();itt!=table.end();itt++)
    {
        counting+=itt->second;
        temp=min(temp,itt->first-counting+num);
    }
    cout<<temp;

    return 0;
}