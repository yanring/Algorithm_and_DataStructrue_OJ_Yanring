#include <iostream>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	double x,y;
	node(int _x,int _y):x(_x),y(_y){
	}
};
struct arc{
	int a,b;
	double val;
	arc (int _a,int _b,double _val):a(_a),b(_b),val(_val){	} 
	arc(){	}
	friend bool operator < (arc arc1,arc arc2){
		return arc1.val<arc2.val;
	}
};
vector<arc> edge;
vector<node> node_list;
int node_root[103];
double cal_dis(node node1,node node2){
	return sqrt((node1.x-node2.x)*(node1.x-node2.x)+(node1.y-node2.y)*(node1.y-node2.y));
}
void genarate_arc(node temp_node,int index){
	for(int i = 1 ; i <= index-1 ; i++){
		edge.push_back(arc(i,index,cal_dis(node_list[i],node_list[index])));
	}
}
int root(int index){
	int temp = node_root[index];
	if(temp==0){
		return index;
	}else{
		int temp_root = root(temp);
		node_root[index] = temp_root;
		return temp_root;
	}
}
int main(int argc, char** argv) {
	
	int N;
//	cin>>N;
	while(cin>>N){
		double x,y,sum=0;
		memset(node_root,0,sizeof(node_root));
		edge.clear();
		node_list.clear(); 
		node_list.push_back(node(0,0));
		edge.push_back(arc(0,0,-1));
		
		for(int i = 1; i<=N ; i++){
			cin>>x>>y;
			node temp_node(x,y);
			node_list.push_back(temp_node);
			genarate_arc(temp_node,i);
		}
		
		sort(edge.begin(),edge.end());
		for(int i = 1,j = 1; i <=N-1;j++ ){
			int a_root = root(edge[j].a);
			int b_root = root(edge[j].b);
			if(a_root!=b_root){
				node_root[a_root] = b_root;
				i++;
				sum+=edge[j].val;
			}
				
		}
		cout<<fixed<<setprecision(2)<<sum<<endl;
	}
	
//	cout<<edge[1].a<<edge[1].b<<edge[1].val<<endl;
	return 0;
}
