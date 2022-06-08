#include<iostream>
using namespace std;

string input1,input2;

int main(){
    cin>>input1>>input2;
    cout<<((input1.length()<input2.length()) ? "no":"go");
    return 0;
}