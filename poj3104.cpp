#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long cloth[100000 + 16];
long long dry_speed;
int n;
long long find_time(long long low,long long up){
	long long temp_cloth;
	long long days=0;
	while((low+1)<up){
		days=0;
		long long mid = (low+up)/2;
		for (int i = 1; i <= n ; i++){
			temp_cloth = cloth[i]-mid;
			if(temp_cloth>0){
			days+=(temp_cloth-1)/(dry_speed-1)+1;			
				
			}
		}
		if(days>mid){
			low = mid;
		}else{
			up  = mid;
		}
	}
	return up; 
}

int main(int argc, char** argv) {
	long long temp=0;
	cin>>n;
	for (int i = 1; i <= n ; i++){
		scanf("%d", &cloth[i]);
//		cin>> cloth[i];
		temp=cloth[i]>temp?cloth[i]:temp;
	}
	cin>>dry_speed;
	if(dry_speed>1){
		int ans;
		ans = find_time(0,temp);
		cout<<ans<<endl;
	}else{
		cout<<temp<<endl;
	}
//	printf("%d\n", solve());
	return 0;
}
