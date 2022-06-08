#include<iostream>
#include<cstring>
#include<vector>
#define maximum 100001
using namespace std;

int dog_pack_num,bun_pack_num,total_dog=0,total_bun=0;
int*dog_pack,*bun_pack;
int temp_dog,temp_bun,output=maximum,total;
vector<int> dog,bun;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>dog_pack_num;
    dog_pack=new int[dog_pack_num];
    for(int*itt=&dog_pack[0];itt<=&dog_pack[dog_pack_num-1];itt++){
        cin>>*itt;
        total_dog+=*itt;
    }
    cin>>bun_pack_num;
    bun_pack=new int[bun_pack_num];
    for(int*itt=&bun_pack[0];itt<=&bun_pack[bun_pack_num-1];itt++){
        cin>>*itt;
        total_bun+=*itt;
    }

    dog.resize(total_dog+1,maximum);
    dog[0]=0;
    bun.resize(total_bun+1,maximum);
    bun[0]=0;
    
    for(int*dog_itt=&dog_pack[0];dog_itt<=&dog_pack[dog_pack_num-1];dog_itt++){
        for(int i=total_dog;i-*dog_itt>=0;i--){
            temp_dog=i-*dog_itt;
            if(dog[temp_dog]!=maximum){
                dog[i]=min(dog[i],dog[temp_dog]+1);
            }
        }
    }
    for(int*bun_itt=&bun_pack[0];bun_itt<=&bun_pack[bun_pack_num-1];bun_itt++){
        for(int i=total_bun;i-*bun_itt>=0;i--){
            temp_bun=i-*bun_itt;
            if(bun[temp_bun]!=maximum){
                bun[i]=min(bun[i],bun[temp_bun]+1);
            }
        }
    }

    total=(total_dog<total_bun) ? total_dog:total_bun;

    for(int i=1;i<total+1;i++){
        if(dog[i]+bun[i]<output){
            output=dog[i]+bun[i];
        }
    }
    if(output==maximum){
        cout<<"impossible";
    }
    else{
        cout<<output;
    }

    return 0;
}