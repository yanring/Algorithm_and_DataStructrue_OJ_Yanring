#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
#define MAX 1077952576
short roads[10009][10009];
int new_roads[10009],temp[10009];
bool mark[10009];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N,M;
void dijkstra(){
	memset(temp,1<<6,sizeof(temp));
	memset(new_roads,1<<6,sizeof(new_roads));
	int index=1;
	temp[index]=0;
	for(int i = 1; i<=N;i++){
		for(int j = 1; j<=N ; j++){//update
			if(!mark[j]&&(temp[index]+roads[index][j])<=temp[j]&&roads[index][j]<new_roads[j]){
				temp[j] = temp[index]+roads[index][j];
				new_roads[j]=roads[index][j];
			}
		}
		index = 0;
		for(int j = 1; j<=N ; j++){
			if(mark[j]==0&&temp[j]<temp[index])
				index = j;
		}
		mark[index]=1;
	}
}
int main(int argc, char** argv) {
	scanf("%d%d",&N,&M);
	memset(roads,1<<6,sizeof(roads));
	for(int i = 1 ; i <= M ; i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(roads[x][y]>z)
			roads[x][y] = roads[y][x] = z;
		if(i<=N)
			roads[i][i]=0;
	}
	dijkstra();
	int sum = 0;
	for(int i = 2; i<=N;i++){
		sum+=new_roads[i];
	}
	cout<<sum<<endl;
	return 0;
}
