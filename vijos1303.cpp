#include <iostream>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main() {
	char input[121];
	int missle[21]={0};
	int dp[21]={0};
	int dp_times[21]={0};
	int i=1;
	int j=1;
	int k=1;
	int dp_max=0;
	int dp_times_max=0;
	cin>>input+1;
	while(input[i]!=0){
		if(input[i]==','){
			j++;
			i++;
			continue;
		}
		missle[j]*=10;
		missle[j]+=input[i]-'0';
		i++;
	}
	for(i = 1; i<=j ; i++){
//		cout<<missle[i]<<endl;
		dp_max=0;
		dp_times_max=0; 
		if(i == 1){
			dp[i]=1;
			dp_times[i]=1;
			continue;
		}
		for(k=1;k<i;k++){
				if(missle[k]<=missle[i]&&dp_times[k]>dp_times_max){
					dp_times_max=dp_times[k];
				}
				if(missle[k]>missle[i]&&dp[k]>dp_max){
					dp_max = dp[k];
				}
		}
		dp_times[i]=1+dp_times_max;
		dp[i]=dp_max+1;
//		if(missle[i]<=missle[i-1]){
//			dp[i]=dp[i-1]+1;
//			for(k=1;k<i;k++){
//				if(missle[k]<missle[i]&&dp_times[k]>dp_times_max){
//					dp_times_max=dp_times[k];
//				}
//			}
//			dp_times[i]=1+dp_times_max;
//		}
//		else if(missle[i]>missle[i-1]){
//			for(k = 1;k < i ; k++){
//				if(missle[k]>missle[i]&&dp[k]>dp_max){
//					dp_max = dp[k];
//				}
//			}
//			dp[i]=dp_max+1;
//			dp_times[i]=dp_times[i-1]+1;
//		}

}
	
	dp_max=0;
	dp_times_max=0;
	for(i = 1; i<=j ; i++){
		dp[i]>dp_max?dp_max=dp[i]:dp_max=dp_max;
		dp_times[i]>dp_times_max?dp_times_max=dp_times[i]:dp_max=dp_max;
				
	}
		
	cout<<dp_max<<","<<dp_times_max-1;
	return 0;

}
