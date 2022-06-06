#include<iostream>
#include<vector>
#include<string>
using namespace std;

int num,steps,cut_num,cal;
int counting=0;
bool flag;
string temp,tempt;
vector<string> arr;

int main()
{
    cin>>num>>steps;
    for(int i=0;i<steps;i++)
    {
        cin>>temp;
        if(temp=="undo")
        {
            cin>>cut_num;
            for(int i=0;i<cut_num;i++)
            {
                arr.pop_back();
            }
        }
        else
        {
            arr.push_back(temp);
        }
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i][0]!='-')
        {
            cal=stoi(arr[i]);
            counting+=cal;
        }
        else
        {
            tempt=arr[i].substr(1,arr[i].length()-1);
            cal=stoi(tempt);
            counting-=cal;
        }
        counting%=num;
    }
    if(counting>=0)
    {
        cout<<counting<<"\n";
    }
    else
    {
        cout<<counting+num<<"\n";
    }

    arr.clear();
    return 0;
}