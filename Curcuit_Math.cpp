#include<iostream>
#include<map>
#include<stack>
using namespace std;

int num;
char TF,temp,temp_1,temp_2,sign;

map<char,char> table;
stack<char> st;

char mul(char a,char b)
{
    if(a=='t'&&b=='t')
    {
        return 't';
    }
    return 'f';
}
char add(char a,char b)
{
    if(a=='f'&&b=='f')
    {
        return 'f';
    }
    return 't';
}
char mi(char a)
{
    if(a=='t')
    {
        return 'f';
    }
    return 't';
}

int main()
{
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>TF;
        if(TF=='T')
        {
            table[char('A'+i)]='t';
        }
        else if(TF=='F')
        {
            table[char('A'+i)]='f';
        }
    }
    table['t']='t';
    table['f']='f';
    while(cin>>temp)
    {
        if(temp=='*')
        {
            temp_1=st.top();
            st.pop();
            temp_2=st.top();
            st.pop();
            st.push(mul(table[temp_1],table[temp_2]));
        }
        else if(temp=='+')
        {
            temp_1=st.top();
            st.pop();
            temp_2=st.top();
            st.pop();
            st.push(add(table[temp_1],table[temp_2]));
        }
        else if(temp=='-')
        {
            temp_1=st.top();
            st.pop();
            st.push(mi(table[temp_1]));
        }
        else
        {
            st.push(temp);
        }
        cin.get(sign);
        if(sign=='\n')
        {
            break;
        }
    }
    if(table[st.top()]=='t')
    {
        cout<<"T\n";
    }
    else if(table[st.top()]=='f')
    {
        cout<<"F\n";
    }
    return 0;
}