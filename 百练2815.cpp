#include <iostream>
#include <cstring>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int R,C;
int rooms[60][60];
int color[60][60];
int maxRoomArea = 0, roomNum = 0; 
int roomArea;
int Dfs(int i,int k){
	if (color[i][k]!=0){
		return 0;
	}
	color[i][k] = 1;
	roomArea ++;
	if((rooms[i][k] & 1) == 0) Dfs(i,k-1);
	if((rooms[i][k] & 2) == 0) Dfs(i-1,k);
	if((rooms[i][k] & 4) == 0) Dfs(i,k+1);
	if((rooms[i][k] & 8) == 0) Dfs(i+1,k);
	
	return 0;
}
int main(int argc, char** argv) {
	cin >> R >> C;
	for(int i = 1; i<=R ; i++){
		for(int j = 1; j<=C ; j++){
			cin>> rooms[i][j];
		}
	}
	memset(color,0,sizeof(color));
	for(int i = 1; i<=R ; i++){
		for(int j = 1; j<=C ; j++){
			if(color[i][j]==0){//进入新房 
				roomNum++; 
				roomArea = 0;//初始化房间大小
			 	Dfs(i,j);
			 	maxRoomArea = roomArea>maxRoomArea?roomArea:maxRoomArea;			 	
			}						   							  			  
			
		}
	}
	cout<<roomNum<<endl;
	cout<<maxRoomArea<<endl;
	return 0;
}
