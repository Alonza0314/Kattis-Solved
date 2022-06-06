#pragma GCC optimization("unroll-loops","Ofast")
#include<iostream>
using namespace std;

int num;
bool flag;
string *arr=nullptr;

int main()
{
    cin>>num;
    arr=new string[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    flag=false;
    for(int i=0;i<num-1;i++)
    {
        if(arr[i].length()==arr[i+1].length())
        {
            if(arr[i].length()==1)
            {
                if(arr[i+1][0]!='9')
                {
                    arr[i][0]='9';
                    flag=true;
                    break;
                }
                else if(arr[i][0]!='0'&&arr[i+1][0]=='9')
                {
                    arr[i+1][0]='0';
                    flag=true;
                    break;
                }
                else if(arr[i][0]!='0'&&arr[i+1][0]!='9')
                {
                    arr[i]=arr[i+1][0]+1;
                    flag=true;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if(arr[i+1][0]!='9')
            {
                arr[i][0]='9';
                flag=true;
                break;
            }
            else if(arr[i][0]!='1'&&arr[i+1][0]=='9')
            {
                arr[i+1][0]='1';
                flag=true;
                break;
            }
            else if(arr[i][0]!='1'&&arr[i+1][0]!='9')
            {
                arr[i]=arr[i+1][0]+1;
                flag=true;
                break;
            }
            else
            {
                continue;
            }
        }
    }

    if(!flag)
    {
        cout<<"impossible\n";
    }
    else
    {
        for(int i=0;i<num;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

