#include<iostream>
#include<vector>
using namespace std;

string str;
vector<char> vec;

int main()
{
    cin>>str;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!='<')
        {
            vec.push_back(str[i]);
        }
        else
        {
            vec.pop_back();
        }
    }
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i];
    }
    cout<<"\n";

    return 0;
}