#include<iostream>
#include<stack>
using namespace std;

int num;
char sign;
char* input=nullptr;

stack<char> st;

int main()
{
    cin>>num;
    cin.get(sign);
    input=new char[num];
    for(int i=0;i<num;i++)
    {
        cin.get(input[i]);
    }
    for(int i=0;i<num;i++)
    {
        if(input[i]==' ')
        {
            continue;
        }
        if(input[i]=='('||input[i]=='['||input[i]=='{')
        {
            st.push(input[i]);
        }
        else
        {
            if(input[i]==')')
            {
                if(st.empty()||st.top()!='(')
                {
                    cout<<") "<<i<<"\n";
                    return 0;
                }
                else
                {
                    st.pop();
                }
            }
            else if(input[i]==']')
            {
                if(st.empty()||st.top()!='[')
                {
                    cout<<"] "<<i<<"\n";
                    return 0;
                }
                else
                {
                    st.pop();
                }
            }
            else if(input[i]=='}')
            {
                if(st.empty()||st.top()!='{')
                {
                    cout<<"} "<<i<<"\n";
                    return 0;
                }
                else
                {
                    st.pop();
                }
            }
        }
    }
    cout<<"ok so far\n";

    return 0;
}