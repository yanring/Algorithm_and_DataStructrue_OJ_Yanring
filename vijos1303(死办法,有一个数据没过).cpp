#include <iostream>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
char input[121];
int note[21][21]={0};
int occupied[21]={0};
int main1() {
	int missle[21]={0};
	int dp[21]={0};
	int i=1;
	int j=1;
	int k=1;
	int loop_times=0;
	int index=1;
	int max_index=0 ;
	int dp_max=0;
	int first_num=0;
	int occupied_num=0;	
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
	while(occupied_num<j){
		for(i = 1; i<=j ; i++){
	//		cout<<missle[i]<<endl;
			if(occupied[i]==1){
				continue;
			}
			dp_max=0;
			if(i == 1){
				dp[i]=1;
				note[i][i]=1;
				continue;
			}
			if(missle[i]<=missle[i-1]){
				for(k = 1;k < i ; k++){
					if(missle[k]>missle[i]&&dp[k]>dp_max){
						dp_max = dp[k];
						max_index = k;
					}
				}
				note[i][i]=1;
				dp[i]=dp_max+1;
				//cout<<note[i][i];
				for (index = 1; index < i ; index++){
					note[i][index] = note[i-1][index];
				}
			}
			else if(missle[i]>missle[i-1]){
				for(k = 1;k < i ; k++){
					if(missle[k]>missle[i]&&dp[k]>dp_max){
						dp_max = dp[k];
						max_index = k;
					}
				}
				note[i][i]=1;
				dp[i]=dp_max+1;
				for (index = 1; index < i ; index++){
					note[i][index] = note[max_index][index];
				}
			}
		}
		dp_max=0;
		max_index=0;
		for(i = 1; i<=j ; i++){
			dp[i]>dp_max?dp_max=dp[i],max_index=i:dp_max=dp_max;
					
		}
		//cout<<dp_max;
		for(i = 1; i<=20 ; i++){
			//cout<<note[max_index][i]<<endl;
			occupied[i]+=note[max_index][i];
			occupied_num +=note[max_index][i];		
			dp[i]=0;
		}
		memset(note,0,sizeof(note));
	//	for(i = 1 ; i <=20 ; i++){
	//		cout<<note[2][i]<<endl;
	//	}
		loop_times++;
		if(loop_times ==1){
			first_num = dp_max;
		}
	}
	cout<<first_num<<","<<loop_times-1;
	return 0;

}
