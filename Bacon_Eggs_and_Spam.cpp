#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int number;
string name,food;
char sign;
map<string,vector<string>> table;
map<string,vector<string>>::iterator itt;

bool cmp(string a,string b)
{
    return a<b;
}

int main()
{
    while (cin>>number&&number!=0)
    {
        for(int i=0;i<number;i++)
        {
            cin>>name;
            while(cin.get(sign)&&sign!='\n')
            {
                cin>>food;
                table[food].push_back(name);
            }
        }
        for(itt=table.begin();itt!=table.end();itt++)
        {
            cout<<itt->first<<" ";
            sort(begin(itt->second),end(itt->second),cmp);
            for(int i=0;i<itt->second.size();i++)
            {
                cout<<itt->second[i]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        table.clear();
    }
    
    return 0;
}