#include<iostream>
using namespace std;

int num,sw,temp,orien,dx,dy,sizes,hull_s;
struct unit{
    int x;
    int y;
}*arr=nullptr,*hull=nullptr,first;

int orientation(unit *z,unit *a,unit *b){
    temp=(a->y-z->y)*(b->x-a->x)-(a->x-z->x)*(b->y-a->y);
    return (temp>0)-(temp<0);
}
int dist_q(unit*z,unit *a){
    dx=z->x-a->x;
    dy=z->y-a->y;
    return dx*dx-dy*dy;
}
int angle_cmp(const void* a,const void *b){
    unit*_a=(unit*)a;
    unit*_b=(unit*)b;
    orien=orientation(&first,_a,_b);
    return orien ? orien:dist_q(&first,_a)-dist_q(&first,_b);
}

void graham_scan(){
    hull=new unit[num];
    hull_s=3;
    for(int i=0;i<3;i++){
        hull[i]=arr[i];
    }
    for(int i=3;i<num;i++){
        while(orientation(&hull[hull_s-2],&hull[hull_s-1],&arr[i])>=0){
            hull_s--;
        }
        hull[hull_s++]=arr[i];
    }
    cout<<hull_s<<"\n";
    for(unit*itt=&hull[0];itt<=&hull[hull_s-1];itt++){
        cout<<itt->x<<" "<<itt->y<<"\n";
    }
}

int main(){
    while(cin>>num){
        arr=new unit[num];
        
        sw=0;
        for(int i=0;i<num;i++){
            cin>>arr[i].x>>arr[i].y;
            if(i>0&&arr[i].x==arr[sw].x&&arr[i].y==arr[sw].y){
                i--;
                num--;
                continue;
            }
            if(arr[i].y<arr[sw].y||(arr[i].y)==arr[sw].y&&arr[i].x<arr[sw].x){
                sw=i;
            }
        }
        if(sw!=0){
            arr[sw].x^=arr[0].x^=arr[sw].x^=arr[0].x;
            arr[sw].y^=arr[0].y^=arr[sw].y^=arr[0].y;
        }
        first=arr[0];

        qsort(arr+1,num-1,sizeof(unit),angle_cmp);

        sizes=1;
        for(int i=1;i<num;i++){
            while(i<num-1&&!orientation(&arr[0],&arr[i],&arr[i+1])){
                i++;
            }
            arr[sizes].x=arr[i].x;
            arr[sizes].y=arr[i].y;
            sizes++;
        }
        num=sizes;

        if(num<3){
            cout<<num<<"\n";
            for(unit*itt=&arr[0];itt<=&arr[num-1];itt++){
                cout<<itt->x<<" "<<itt->y<<"\n";
            }
        }
        else{
            graham_scan();
        }
    }
    return 0;
}