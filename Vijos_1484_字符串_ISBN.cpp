#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
char str[100];
int sum=0;
int main(){
	for(int i = 1; i<=13;i++){
		str[i]=getchar();
	}
//	cin>>str+1;
	sum+=(str[1]-'0')*1;
	sum+=(str[3]-'0')*2;
	sum+=(str[4]-'0')*3;
	sum+=(str[5]-'0')*4;
	sum+=(str[7]-'0')*5;
	sum+=(str[8]-'0')*6;
	sum+=(str[9]-'0')*7;
	sum+=(str[10]-'0')*8;
	sum+=(str[11]-'0')*9;
	sum = sum%11;
	if(sum==str[13]-'0'||sum==10&&str[13]=='X'){
		cout<<"Right"<<endl;
	}else{
		if(sum==10){
			str[13]='X';
			
		}else{
			str[13]='0'+sum;
		}
		cout<<str+1<<endl;
	}
	return 0;	
} 
