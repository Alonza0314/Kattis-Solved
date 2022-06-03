#include<iostream>
using namespace std;
int times;
int main()
{
    cin>>times;
    int *arr=new int[times];
    for(int i=0;i<times;i++)
    {
        cin>>arr[i];
    }
    for(int i=times-1;i>=0;i--)
    {
        cout<<arr[i]<<"\n";
    }

    return 0;
}