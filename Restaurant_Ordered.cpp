#include<iostream>
#include<vector>

using namespace std;

int menu_num,order_num,order;
int*menu;
vector<int> table(30001,-1);
vector<int> output;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>menu_num;
    menu=new int[menu_num+1];
    for(int*itt=&menu[1];itt<=&menu[menu_num];itt++){
        cin>>*itt;
    }

    table[0]=0;
    for(int i=1;i<=menu_num;i++){
        for(int j=0;j<=30000-menu[i];j++){
            if(table[j]>-1){
                if(table[j+menu[i]]==-1){
                    table[j+menu[i]]=i;
                }
                else{
                    table[j+menu[i]]=-2;
                }
            }
            else if(table[j]==-2){
                table[j+menu[i]]=-2;
            }
        }
    }

    cin>>order_num;
    while(order_num--){
        cin>>order;
        switch(table[order]){
            case -1:{
                cout<<"Impossible\n";
                break;
            }
            case -2:{
                cout<<"Ambiguous\n";
                break;
            }
            default:{
                while(order>0){
                    output.push_back(table[order]);
                    order-=menu[table[order]];
                }
                for(vector<int>::iterator itt=output.end()-1;itt>=output.begin();itt--){
                    cout<<*itt<<" ";
                }cout<<"\n";
            }
        }
        output.clear();
    }

    return 0;
}