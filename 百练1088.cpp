#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std; 
#define max_H 20002
int maze[520][520];
int dp[520][520];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int DP(int i,int j){
	if(dp[i][j]>0){
		return dp[i][j];
	}
	int p,q,r,s;  
    p=q=r=s=0;  
    if(maze[i][j]>maze[i-1][j])  
    {  
        p=DP(i-1,j);  
    }  
    if(maze[i][j]>maze[i][j-1])  
    {  
        q=DP(i,j-1);  
    }  
    if(maze[i][j]>maze[i+1][j])  
    {  
        r=DP(i+1,j);  
    }  
    if(maze[i][j]>maze[i][j+1])  
    {  
        s=DP(i,j+1);  
    }  
    int MAX=0;  
    if(p>MAX)MAX=p;  
    if(q>MAX)MAX=q;  
    if(r>MAX)MAX=r;  
    if(s>MAX)MAX=s;  
    return dp[i][j]=MAX+1;  
	
}
int main(int argc, char** argv) {
	int col,row,i,j,max,temp;
	while(~scanf("%d%d",&row,&col)){	
//	cin>>row>>col;
	memset(maze,0x3f,sizeof(maze)); 
	memset(dp,0,sizeof(dp));
	for(i=1;i<=row;i++){
		for(j=1;j<=col;j++){
			cin>>maze[i][j];
		}
	} 
	max=-1;
	for(i=1;i<=row;i++){
		for(j=1;j<=col;j++){
			DP(i,j);		
		}
	}
	for(i=1;i<=row;i++){
		for(j=1;j<=col;j++){
			if(dp[i][j]>max)max=dp[i][j];
		}
	} 
	cout<<max<<endl;
	}
	return 0;
}
