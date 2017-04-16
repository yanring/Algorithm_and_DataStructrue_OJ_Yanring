#include <iostream>
#include <cstring>
#include <cstdio> 
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int S,N,M;
int v[4];
bool mark[101][100][100];
struct node{
	public:
	int now[4];
	node(int a,int b,int c,int t){
		now[1]=a;
		now[2]=b;
		now[3]=c;
		now[0]=t;
	}	
	node pour(int from,int to){
		int new_v[4];
		memcpy(new_v,now,sizeof(now));
		if(v[to]-new_v[to]<new_v[from]){
			new_v[from] -= (v[to]-new_v[to]);
			new_v[to] = v[to];			
		}else{
			new_v[to] +=new_v[from];
			new_v[from]=0;
		}
		return node(new_v[1],new_v[2],new_v[3],new_v[0]+1);
	}
};
int main(int argc, char** argv) {
	while(scanf("%d%d%d",&S,&N,&M)){
		memset(mark,0,sizeof(mark)); 
		queue<node> q;
		if(S+N+M==0){
			return 0;
		}
		if(S&1){
			puts("NO");
			continue;
		}
		v[1]=S;v[2]=N;v[3]=M;		
		q.push(node(S,0,0,0));
		int times = 0;
		int flag = 2;
		while(!q.empty()&&flag){
			node temp_node = q.front();
			q.pop();
			for(int i = 1 ; i <= 3 ;i++){
				if(temp_node.now[i]==S>>1){
					if(flag == 1)
						printf("%d\n",temp_node.now[0]);
					temp_node.now[i]=0;
					while(!q.empty()) q.pop();
					q.push(temp_node);
					flag --;
					i = 4; 
					continue;
				}else if(temp_node.now[i]){
					for(int j = 1; j<=3 ;j++){
						if(i!=j&&temp_node.now[j]<v[j]){
							node new_node =  temp_node.pour(i,j);
							if(mark[new_node.now[1]][new_node.now[2]][new_node.now[3]]==0){
								mark[new_node.now[1]][new_node.now[2]][new_node.now[3]] = 1;
								q.push(new_node);
							}								
						}
					}
				}
			}
		}
		if (flag)
			puts("NO");		
	}
	return 0;
}
