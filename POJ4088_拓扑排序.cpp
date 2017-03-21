#include <iostream>
#include <cstring>
#include <algorithm>
//有入度的都不可能是第一个，所以要从没入度的开始,每次找到没入度的就把它从图中剔除,并更新整个图的入度,然后又从最小的点开始遍历没入度的点 
//注意有重边!! 
using namespace std;
int matrix[102][102];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N,M,topo[102],t; 
int mark[102],mark_rudu[102];

int main(int argc, char** argv) {
	cin>>N>>M;
	t = N;
	memset(mark,0,sizeof(mark));
	memset(matrix,0,sizeof(matrix));
	memset(mark_rudu,0,sizeof(mark_rudu));
	for(int i = 1; i<=M ; i++){
		int x,y;
		cin>>x>>y;
		matrix[x][y]++;
		mark_rudu[y]++;
	}
	for(int k = 1; k <=N ; k ++){
		for(int i = 1; i<=N ; i++){
			if(mark_rudu[i]==0){
				cout<<"v"<<i<<" ";
				mark_rudu[i]--;
				for(int j = 1; j<=N;j++){
					if(matrix[i][j]){
						mark_rudu[j]-=matrix[i][j];
					}
				}
				break;
			}
		}
	}
	
	cout<<endl;
	return 0;
}
