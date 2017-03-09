#include <iostream>
#include <cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#define N 1005 
int dp[N],src[N];
int temp_max ;
int main(int argc, char** argv) {
	int n;
	cin>>n;
	memset(dp,0,sizeof(dp));
	for(int i =1 ; i <=n ; i++){
		cin>>src[i];
	}
	for(int i = 1; i<=n ;i ++){
		temp_max = 0;
		for (int j = 1; j<i ; j++){
			if(src[i]>src[j])
			temp_max = dp[j]>temp_max?dp[j]:temp_max;
			
		} 
		dp[i]=temp_max+1;
	}
	for (int j = 1; j<=n ; j++){
			temp_max = dp[j]>temp_max?dp[j]:temp_max;			
		} 
	cout<<temp_max<<endl;
	return 0;
}
