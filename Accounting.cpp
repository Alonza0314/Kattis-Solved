#include<iostream>
#include<unordered_map>
using namespace std;
int n,t,model;
int ind,money;
string command;
unordered_map<int,int> table;
unordered_map<int,int>::iterator itt;

int main()
{
    cin>>n>>t;
    model=0;
    for(int i=0;i<t;i++)
    {
        cin>>command;
        if(command=="SET")
        {
            cin>>ind>>money;
            table[ind]=money;
        }
        else if(command=="PRINT")
        {
            cin>>ind;
            itt=table.find(ind);
            if(itt!=table.end())
            {
                cout<<table[ind]<<"\n";
            }
            else
            {
                cout<<model<<"\n";
            }
        }
        else//RESTART
        {
            table.clear();
            cin>>model;
        }
    }
    return 0;
}