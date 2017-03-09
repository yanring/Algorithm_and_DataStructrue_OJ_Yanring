#include <iostream>
int num[20001];
using namespace std; 
int main() {
	int input[101];
	int i,j;
	int m;
	int times=0;
	cin>>m;
	for(i = 1; i<=m;i++){
		cin>>input[i];
		num[input[i]]=1;
	}
	for(i = 1; i<=m;i++){
		for(j = 1;j<=m;j++ ){
			if(i==j){
				continue;
			}
			if(num[input[i]+input[j]]==1){
				num[input[i]+input[j]]=2;
			}			
		}
	}
	for(i = 0; i<=10001;i++){
		if(num[i]==2){
			times++;
		}
	}
	cout<<times;
}
