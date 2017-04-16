#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
struct road{
	int x,y,z;
	road(int _x,int _y,int _z){
		x = _x;
		y = _y;
		z = _z;
	}
	friend bool operator < (const road r1,const road r2){
		return r1.z>r2.z;
	}
};
int node[103];
int root;
int find_root(int x){
	int temp = node[x];
	if(!temp){
		root = x;
		return x;
	}else{
		find_root(temp);
		node[x]=root;
	}
}
int main(int argc, char** argv) {
	int N;
	while(1){
		priority_queue<road> roads;
		scanf("%d",&N);
		if(N<=0){
			break;
		}
		int sum=0;
		memset(node,0,sizeof(node));
		memset(mark,0,sizeof(mark));
		int x,y,z;
		for(int i = 1; i<=(N*(N-1)/2); i++){
			scanf("%d%d%d",&x,&y,&z);
			roads.push(road(x,y,z));
		}
		for(int i = 1; i<=N-1;){
			road temp_road = roads.top();
			roads.pop();
			find_root(temp_road.x);
			
			int x_root = root;
			find_root(temp_road.y);
			int y_root = root;
			if(x_root!=y_root){
				node[y_root]=x_root;
				sum+=temp_road.z;
				i++;
			}
		}
		cout<<sum<<endl;		
	}
	return 0;
}
