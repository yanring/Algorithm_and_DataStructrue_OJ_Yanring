#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
char str[100];
int N=0;
int maze[11][11];
int test[10]={0,1,2,3,4,5,6,7,8,9};
bool flag = 1;
void check(int x1, int y1,int x2, int y2){
	int check_test[10];
	int temp = 0 ;
	memcpy(check_test,test,sizeof(test)); 
	for(int i = x1; i <= x2; i++){
		for(int j = y1 ; j <= y2 ; j++){
			check_test[maze[i][j]]=0;
		}
	}
	for(int i = 1; i <= 9 ; i++){
		temp+=check_test[i];
	}
	if(temp){
		flag = 0;
	}
}
int main(){
	cin>>N;
	for(int k = 1; k<=N; k++){//±éÀú 
		flag = 1;
		for(int i =1 ;i<=9;i++){
			for(int j = 1; j<=9 ; j++){
				cin>>maze[i][j];
			}
		}
		for(int i = 1; i<=9 ;i++){
			check(k,1,k,9);
			check(1,k,9,k);
		}
		for(int i = 0 ; i<=2;i++){
			check(i*3+1,1,(i+1)*3,3);
			check(i*3+1,4,(i+1)*3,6);
			check(i*3+1,7,(i+1)*3,9);
		}
		if(flag == 1){
			cout<<"Right"<<endl;
		}else{
			cout<<"Wrong"<<endl;
		}
		
	}
	return 0;	
}  
