#include <iostream>
#include <cstring>
#include <queue>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool maze[10019][10019]; 
int path[200009];
bool mark[10019]; 
int n,m,flag=0;
priority_queue<int, vector<int>, greater<int> > visit[10000];
queue<int> temp_queue;
//bool search(int start,int index){
//	path[index]=start; 
//	if(index == (m+1)){//刚好遍历完 
//		flag = 1;//结束程序 
//		return 1;
//	}
//
////	while(!visit[start].empty()){//用优先队列优化 
////		int i = visit[start].top();
////		visit[start].pop();
////		while (visit[i].top()!=start){
////			temp_queue.push(visit[i].top());
////			visit[i].pop();
////			cout<<"["<<visit[i].top()<<"]"<<" ";
////		}
////		visit[i].pop();
////		while(!temp_queue.empty()){
////			visit[i].push(temp_queue.front());
////			temp_queue.pop();			
////		}
//	for(int i = 1; i <= n ; i++){
//	
//		if(maze[start][i]==1){
//			maze[start][i]=0;
//			maze[i][start]=0;
//			search(i,index+1);
//			if(flag==1){
//				return 1;
//			}
//			path[index+1]=0;
//			maze[start][i]=1;
//			maze[i][start]=1;
//		}
//		
//	}
//	if(flag==0)
//		return 0;
//}

bool search(int start,int index){
	path[index]=start; 
//	cout<<start;
	if(index == (m+1)){//刚好遍历完 
		flag = 1;//结束程序 
//		cout<<endl;
		return 1;
	}
	cout<<" ";
	for(int i = 1 ; i<=n;i++){
		if(maze[start][i]){
			maze[start][i]=0;
			maze[i][start]=0;
			search(i,index+1);
			if(flag){
				return 1;
			}
			path[index+1]=0;
			maze[start][i]=1;
			maze[i][start]=1;
		}
		
	}
	return 0;
}

int main(int argc, char** argv) {
	int x,y,start=1000000,res;
	cin>>n>>m;
	memset(maze,0,sizeof(maze));
	memset(path,0,sizeof(path));
	memset(mark,0,sizeof(mark));	
	for(int i = 1 ; i<=m ; i++){
		cin>>x>>y;
		start = start>x?x:start;
		maze[x][y]=1;
		maze[y][x]=1;
//		visit[x].push(y);
//		visit[y].push(x);
//		mark[x]=!mark[x];
//		mark[y]=!mark[y];
	}
	int temp=0;
//	for(int i = n ; i>=1 ; i--){
//		if(mark[i]){
//			temp++;
//			start = i;
//		}
//		
//	}
//	if(temp!=0&&temp!=2){
//		cout<<"-1"<<endl;
//		return 0;
//	}
//	if(temp==2){
//		if(!mark[1]){
//			cout<<"-1"<<endl;
//			return 0;
//		}
//	}	
	if(n>3000){
		cout<<-1<<endl;
	} 
	res = search(1,1);
	if(res == 1){
		for(int i = 1 ; i<=(m) ; i++){
			cout<<path[i]<<" ";
		}
		cout<<path[m+1]<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}
