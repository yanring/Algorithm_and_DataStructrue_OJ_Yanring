#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;
int maze[56][56][56];
bool mark[56][56][56];
int dirc[7][4] = {{0,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1},{0,-1,0,0},{0,0,-1,0},{0,0,0,-1}};
struct pos{
	int x,y,z,t;
	pos(int _x,int _y ,int _z,int _t):x(_x),y(_y),z(_z),t(_t){};
}; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int a,b,c,K,T;
	scanf("%d",&K);	
	for(int z = 1; z<=K ; z++){
		scanf("%d %d %d %d",&a,&b,&c,&T);
		queue<pos> list;
//		list.size();
		memset(maze,1,sizeof(maze));
		memset(mark,0,sizeof(mark));
		for(int i = 1; i<=a ; i++){
			for(int j = 1; j<=b ; j++){
				for(int k = 1 ; k <=c ; k++){
					int temp;					
					scanf("%d",&maze[i][j][k]);
				}
			}
		}
		if(maze[a][b][c]==1||a+b+c-3>T){
			cout<<"-1"<<endl;
			continue;
		}
		pos start(1,1,1,0);
		mark[1][1][1] =1;
		list.push(start);
		int time = 0;
		bool flag = 1;	
		while(flag){
			if(list.empty()){
				printf("-1\n");
				flag = 0;
				continue;
			}
			pos temp_pos = list.front();
			list.pop();
			if(temp_pos.t>T){
				printf("-1\n");
				flag = 0;
				continue;
			}
			if(temp_pos.x==a&&temp_pos.y==b&&temp_pos.z==c){
				printf("%d\n",temp_pos.t);
				flag = 0;
				continue;
			}			
			for(int i = 1; i<=6 ; i++){
				int new_x,new_y,new_z,new_t;
				new_x = temp_pos.x + dirc[i][1];
				new_y = temp_pos.y + dirc[i][2];
				new_z = temp_pos.z + dirc[i][3];
				new_t = temp_pos.t +1;
				
				if(maze[new_x][new_y][new_z]==0&&mark[new_x][new_y][new_z]==0){
					list.push(pos(new_x,new_y,new_z,new_t));
					mark[new_x][new_y][new_z] = 1;
					
				}
									
			}
		}
	}
	return 0;
}
