#include<iostream>
#include<vector>
#define maximum 2<<28
using namespace std;

int testcase,price,n,coin;
vector<int> vec;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>testcase;
    while(testcase--){
        cin>>price>>n;
        vec.resize(10001,maximum);
        vec[0]=0;
        for(int i=0;i<n;i++){
            cin>>coin;
            for(int j=10000-coin;j>=0;j--){
                vec[j+coin]=min(vec[j]+1,vec[j+coin]);
            }
        }
        for(int i=price;i<10001;i++){
            if(vec[i]!=maximum){
                cout<<i<<" "<<vec[i]<<"\n";
                break;
            }
        }
        vec.clear();
    }

    return 0;
}