#include<iostream>
#include<sstream>
#include<string>

using namespace std;
int record_start,record_end;
unsigned long long output;
string line,sub_line;

bool check(char j)
{
    if(j=='0'||j=='1'||j=='2'||j=='3'||j=='4'||j=='5'||j=='6'||j=='7'||j=='8'||j=='9'||j=='a'||j=='b'||j=='c'||j=='d'||j=='e'||j=='f'||j=='A'||j=='B'||j=='C'||j=='D'||j=='E'||j=='F')
    {
        return true;
    }
    return false;
}

int main()
{
    while(cin>>line)
    {
        for(int i=0;i<line.length();i++)
        {
            if(i!=line.length()-2&&line[i]=='0'&&(line[i+1]=='x'||line[i+1]=='X'))
            {
                record_start=i+2;
                for(int j=i+2;j<line.length();j++)
                {
                    if(check(line[j]))
                    {
                        record_end=j;
                    }
                    else
                    {
                        break;
                    }
                }
                sub_line=line.substr(record_start-2,(record_end-record_start+3));
                cout<<sub_line<<" ";
                stringstream temp;
                temp<<hex<<sub_line;
                temp>>output;
                cout<<output<<"\n";
            }
        }
    }
    return 0;
}