#include<iostream>
#include<list>
using namespace std;

int num;
char temp;
list<char> output;
list<char>::iterator itt,itt_mi;

int main()
{
    cin>>num;
    cin.get(temp);
    for(int i=0;i<num;i++)
    {
        itt=output.begin();
        while(cin.get(temp)&&temp!='\n')
        {
            if(temp=='<')
            {
                itt_mi=itt;
                itt_mi--;
                if(itt_mi==--output.begin())
                {
                    continue;
                }
                output.erase(itt_mi);
            }
            else if(temp=='[')
            {
                itt=output.begin();
            }
            else if(temp==']')
            {
                itt=output.end();
            }
            else
            {
                output.insert(itt,temp);
            }
        }
        for(auto i:output)
        {
            cout<<i;
        }
        cout<<"\n";
        output.clear();
    }

    return 0;
}