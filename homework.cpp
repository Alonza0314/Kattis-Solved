#include<iostream>
using namespace std;
int first,second;
char sign;
int counting;
int main()
{
    counting=0;
    cin>>first;
    counting++;
    while(cin.get(sign)&&sign!='\n')
    {
        if(sign==';')
        {
            cin>>first;
            counting++;
        }
        else if(sign=='-')
        {
            cin>>second;
            counting=counting+(second-first);
        }
    }
    cout<<counting<<"\n";

    return 0;
}