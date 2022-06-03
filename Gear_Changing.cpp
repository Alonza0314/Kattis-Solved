#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
double p,real_p;
double *c=nullptr;
double *d=nullptr;
double *ca=nullptr;
int ss,indexx=0;


int main()
{
    cin>>n>>m>>p;
    ss=n*m;
    c=new double[n];
    d=new double[m];
    ca=new double[ss];
    real_p=1+p/100;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>d[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ca[indexx]=c[i]/d[j];
            indexx++;
        }
    }
    sort(ca,ca+ss);
    for(int i=1;i<ss;i++)
    {
        if(ca[i]>ca[i-1]*real_p)
        {
            cout<<"Time to change gears!";
            return 0;
        }
    }
    cout<<"Ride on!";

    return 0;
}