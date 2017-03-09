#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int oil[10009];
int y[10009];
void sort(int lb,int ub){
	int m=lb;
	if(lb>=ub){
		return;
	}
	for(int i = lb+1;i<=ub;i++){
		if(y[i]>=y[lb]){
			continue;
		}else if(y[i]<y[lb]){
			m++;
			swap(y[i],y[m]);
		}
	} 
	swap(y[lb],y[m]);
	sort(lb,m-1);
	sort(m+1,ub);
}
int main(int argc, char** argv) {
	int n,temp,place,total=0;
	cin>>n;
	for(int i = 1 ; i<=n;i++){
		scanf("%d",&temp);
		scanf("%d",&y[i]);
	}
	sort(1,n);
	place = y[(n-1)/2 + 1];
	for(int i = 1 ; i<=n;i++){
		total+=abs(y[i]-place);
	}
	cout<<total<<endl;
	return 0;
}
