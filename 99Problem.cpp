#include<iostream>

using namespace std;

int input,last2,up;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>input;
    if(input<=148){
        cout<<99;
        return 0;
    }
    last2=input%100;
    up=input/100;
    if(last2>48){
        cout<<up<<99;
    }
    else{
        cout<<up-1<<99;
    }

    return 0;
}