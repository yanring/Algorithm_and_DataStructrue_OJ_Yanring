#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double num[100009],dp_min[100009],dp_max[100009];
int N; 
double MAX=0;
int main(int argc, char** argv) {
	while(scanf("%d",&N)!=EOF){
		MAX=-1;
		memset(num,0,sizeof(num));
		memset(dp_min,0,sizeof(dp_min));
		memset(dp_max,0,sizeof(dp_max));
		for(int i = 1; i<=N ; i++){
			scanf("%lf", &num[i]);
		}
		dp_min[0]=dp_max[0]=1; 
		for(int i = 1; i<=N ; i++){
				dp_max[i]=max(max(num[i],dp_max[i-1]*num[i]),dp_min[i-1]*num[i]);
				dp_min[i]=min(min(num[i],dp_max[i-1]*num[i]),dp_min[i-1]*num[i]);

			if(dp_max[i]>MAX)
				MAX = dp_max[i];			
		}
		int t = (int)MAX;
		if(MAX < 0) {
			puts("-1");
		} else {
			if(MAX == t)
			printf("%d\n",t);
			else printf("%.2f\n",MAX);
		}  
//		if(MAX<0){
//			cout<<-1<<endl;
//		}else if(MAX-int(MAX)>=1e-5)
//			cout<<fixed<<setprecision(2)<<MAX<<endl;
//		else{
//			cout<<fixed<<setprecision(0)<<MAX<<endl;
//		}		
	}
	return 0;
}
