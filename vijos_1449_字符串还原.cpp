#include <iostream>
#include <cstring>
//#include <algorithm.h>

using namespace std;
int N,flag=1;
char code[4][20010];
int val[4][20010];
int cal_dis(char a, char b){
	int dis;
	dis = a-b;
	if(dis<0){
		dis = -dis;
	}
	if(dis>13){
		dis = 26-dis;
	}
	return dis;
}
int str_equal(int* str1,int* str2){
	int flag=1;
	for(int i = 1 ; i<= N ;i++){
		if(str1[i]==str2[i]){
			continue;
		}else{
			flag=0;
			break;
		}
	}
	return flag;
}
int main(){
	int temp1=0,temp2=0,res=2;
	cin>>N;
	for(int i = 1; i<=3 ;i++){
			cin>>&code[i][1];
	}

	for(int i = 1; i<=3 ;i++){//算相邻字符的差 
		for(int j = 1; j<=N-1 ; j++){
			val[i][j]=code[i][j+1]-code[i][j];
			if(j==N){
				val[i][j]=code[i][1]-code[i][j];
			}
			if(val[i][j]<0){
				val[i][j] = (26+val[i][j]);
			}
		}
	}

	for(int j = 1; j<=N-1 ; j++){
		if(val[1][j]==val[2][j]&&val[2][j]==val[3][j]){
			
		}else{
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		int ab,ac,bc=0;
		ab = cal_dis(code[1][1],code[2][1]);
		ac = cal_dis(code[1][1],code[3][1]);
		bc = cal_dis(code[2][1],code[3][1]);
		if(ab==ac){
			res=1;
		}else if(ab==bc){
			res=2;
		} else if(ac==bc){
			res=3;
		}
	}else{		
		if(str_equal(val[1],val[2])){
			temp1 = 1;temp2 = 2;
		}
		if(str_equal(val[2],val[3])){
			temp1 = 2;temp2 = 3;
		}
		if(str_equal(val[1],val[3])){
			temp1 = 1;temp2 = 3;
		}
	
		res = 6-temp1-temp2;//排除2个一样的 
	}

	for(int i = N ; i>=1 ; i--){
		cout<<code[res][i];
	} 
	cout<<endl;
	return 0;	
} 
