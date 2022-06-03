#include<iostream>
using namespace std;

int rows,columns,counting=0;
int temp_x,temp_y;
char table[100][100];

int arr[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

bool check(int x,int y)
{
    if(x<0||x>=rows||y<0||y>=columns||table[x][y]=='.')
    {
        return false;
    }
    return true;
}

void dfs(int x,int y)
{
    table[x][y]='.';
    for(int i=0;i<8;i++)
    {
        temp_x=x+arr[i][0];
        temp_y=y+arr[i][1];
        if(check(temp_x,temp_y))
        {
            dfs(temp_x,temp_y);
        }
    }
}

int main()
{
    cin>>rows>>columns;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin>>table[i][j];
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(table[i][j]=='#')
            {
                dfs(i,j);
                counting++;
            }
        }
    }
    cout<<counting<<"\n";
    return 0;
}