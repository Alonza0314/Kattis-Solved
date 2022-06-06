#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct unit{
    bool leave=false;
    int neighbors_num=0;
    int neighbors_leaft=0;
    vector<int> vec;
}*arr=nullptr;
int c,p,x,l;
int a,b,que_front;
queue<int> que;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cin>>c>>p>>x>>l;
    arr=new unit[c+1];
    while(p--){
        cin>>a>>b;
        arr[a].neighbors_num++;
        arr[a].neighbors_leaft++;
        arr[a].vec.push_back(b);
        arr[b].neighbors_num++;
        arr[b].neighbors_leaft++;
        arr[b].vec.push_back(a);
    }
    arr[l].leave=true;
    for(auto itt:arr[l].vec){
        arr[itt].neighbors_leaft--;
        que.push(itt);
    }
    while(!que.empty()){
        que_front=que.front();
        que.pop();
        if(arr[que_front].leave){
            continue;
        }
        if(arr[que_front].neighbors_leaft<=arr[que_front].neighbors_num/2){
            arr[que_front].leave=true;
            for(auto itt:arr[que_front].vec){
                arr[itt].neighbors_leaft--;
                que.push(itt);
            }
        }
    }
    if(arr[x].leave){
        cout<<"leave\n";
    }
    else{
        cout<<"stay\n";
    }

    return 0;
}