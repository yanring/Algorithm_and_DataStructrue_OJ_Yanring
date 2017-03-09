#include <iostream>
using namespace std;

struct student{
    char name[30],g,w;
    int q,b,p;
}a[120];

int main(){
    int n,sum[120]={0},maxw=-1,num,total=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i].name>>a[i].q>>a[i].b>>a[i].g>>a[i].w>>a[i].p;
    for(int i=1;i<=n;i++){
        if(a[i].q>80&&a[i].p>=1)
            sum[i]+=8000;
        if(a[i].q>85&&a[i].b>80)
            sum[i]+=4000;
        if(a[i].q>90)
            sum[i]+=2000;
        if(a[i].q>85&&a[i].w=='Y')
            sum[i]+=1000;
        if(a[i].b>80&&a[i].g=='Y')
            sum[i]+=850;
    }
    for(int i=1;i<=n;i++){
        total+=sum[i];
        if(sum[i]>maxw){
            num=i;
            maxw=sum[i];
        }
    }    
    cout<<a[num].name<<endl<<sum[num]<<endl<<total;
    return 0;
}
