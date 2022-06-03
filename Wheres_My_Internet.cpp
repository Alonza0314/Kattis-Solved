#include<iostream>

using namespace std;

int num,line,temp_a,temp_b;
bool flag=true;
int *arr=nullptr;

int find(int x)
{
    if(arr[x]==x)
    {
        return x;
    }
    arr[x]=find(arr[x]);
    return arr[x];
}

void push(int a,int b)
{
    arr[find(a-1)]=find(b-1);
}

bool check(int a,int b)
{
    return find(a)==find(b);
}

int main()
{
    cin>>num>>line;
    arr=new int[num];
    for(int i=0;i<num;i++)
    {
        arr[i]=i;
    }
    for(int i=0;i<line;i++)
    {
        cin>>temp_a>>temp_b;
        push(temp_a,temp_b);
    }
    for(int i=1;i<num;i++)
    {
        if(!check(0,i))
        {
            cout<<i+1<<"\n";
            flag=false;
        }
    }
    if(flag)
    {
        cout<<"Connected\n";
    }


    return 0;
}