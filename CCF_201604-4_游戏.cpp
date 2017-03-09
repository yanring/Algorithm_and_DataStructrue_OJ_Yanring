#include <iostream>
#include <cstdio>
#include <cstring> 

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,m,t;
bool danger[210][210][210];
bool maze[210][210],new_maze[210][210];
int Min=1<<30,now=0;

void move(){
	int len = 0;
	while(maze[n][m]==0){
		for(int i = 1; i <=n ; i++){
			for(int j = 1; j<=m ; j++){
				if(maze[i][j]==1){//
					if(danger[i+1][j][len+1]==0){//没危险而且没走过
						new_maze[i+1][j]=1; 
					}
					if(danger[i][j+1][len+1]==0){//没危险而且没走过
						new_maze[i][j+1]=1; 
					}
					if(danger[i-1][j][len+1]==0){//没危险而且没走过
						new_maze[i-1][j]=1; 
					}
					if(danger[i][j-1][len+1]==0){//没危险而且没走过
						new_maze[i][j-1]=1; 
					}					
				}
			}
		}
		
		memcpy(maze,new_maze,sizeof(new_maze));
		memset(new_maze,0,sizeof(new_maze));
		len++;		
	}
	cout<<len<<endl;

}
int main(int argc, char** argv) {
	cin>>n>>m>>t;
	memset(danger,0,sizeof(danger));
	memset(maze,0,sizeof(maze));
	memset(new_maze,0,sizeof(new_maze));
	for(int i = 1 ; i <= t; i++){
		int x,y,a,b;
		cin>>x>>y>>a>>b;
		for(int j = a ; j<=b;j++)
			danger[x][y][j] = 1;
	}
	maze[1][1]=1;
	move();
	return 0;
}
