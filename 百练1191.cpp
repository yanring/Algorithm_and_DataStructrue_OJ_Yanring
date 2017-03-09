#include <iostream>
#include <memory.h>
#include <math.h>
#include<iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int s[9][9];
int sum[9][9];
int res[15][9][9][9][9];
int calSum(int x1,int y1,int x2,int y2){
	return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}
int fun(int n,int x1,int y1,int x2,int y2){
	int a,b,c,d,e,t,MIN = 10000000;
	if (res[n][x1][y1][x2][y2] != -1){
		return res[n][x1][y1][x2][y2];
	}
	if (n==1){
		t = calSum(x1,y1,x2,y2);
		res[n][x1][y1][x2][y2]  = t*t;
		return res[n][x1][y1][x2][y2];
	}
	for(a = x1; a < x2 ; a++){
		c= calSum(a+1,y1,x2,y2);
		e = calSum(x1,y1,a,y2);
		t = min(fun(n-1,x1,y1,a,y2)+c*c,fun(n-1,a+1,y1,x2,y2)+e*e);
		if(MIN>t) MIN = t;
	}
	for(b = y1; b < y2 ; b++){
		c = calSum(x1,b+1,x2,y2);
		e = calSum(x1,y1,x2,b);
		t = min(fun(n-1,x1,y1,x2,b)+c*c,fun(n-1,x1,b+1,x2,y2)+e*e);
		if(MIN>t) MIN = t;
	}
	res[n][x1][y1][x2][y2] = MIN;
	return MIN;
}
int main(int argc, char** argv) {
	int n,rowsum;
	cin>>n;            
	memset(res,-1,sizeof(res));
	memset(sum,0,sizeof(sum));
	for(int i=1; i<=8; i++)
        for(int j=1,rowsum = 0; j<=8; j++){
        	cin>>s[i][j];
        	rowsum += s[i][j];
        	sum[i][j] = sum[i-1][j]+rowsum;
		}
	
	double result = n*fun(n,1,1,8,8)-sum[8][8]*sum[8][8]; 
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<sqrt(result/(n*n))<<endl;
	return 0;

	

			
	return 0;
}
