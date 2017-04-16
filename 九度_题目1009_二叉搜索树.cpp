#include <iostream>
#include<cstring>
#include <cstdio>
using namespace std; 
int origin[1025],cmp[1025],num[11],len;
void read(){
	string str;
	cin>>str;
	len = str.length();
	char temp;
	for(int i = 1 ; i<=len ; i++){
		num[i] = str[i-1]-'0';
	}	
}
void build_origin(){
	for(int i = 1 ;i <= len ; i++){
		int index = 1;
		while(origin[index]!=-1){ 
			if(num[i]<origin[index]){
				index*=2; 
			}else{
				index = index*2+1;
			} 
		}
		origin[index] = num[i];
	}
}
void build_cmp(){
	memset(cmp,-1,sizeof(cmp));
	for(int i = 1 ;i <= len ; i++){
		int index = 1;
		while(cmp[index]!=-1){ 
			if(num[i]<cmp[index]){
				index*=2; 
			}else{
				index = index*2+1;
			} 
		}
		cmp[index] = num[i];
	}
}
int main(int argc, char** argv) {
	int n = 0;
	while(scanf("%d",&n)!=EOF&&n!=0){
		memset(origin,-1,sizeof(origin));
		memset(num,0,sizeof(num));
		len = 0;
		read();
		build_origin();
		for(int i = 1 ; i<= n ; i++){
			read();
			build_cmp(); 
			int judge = 1;
			int res = memcmp(origin,cmp,sizeof(cmp)); 
			if(res == 0){
				puts("YES");
			}else{
				puts("NO");
			}
		}		
	}
	return 0;
}
