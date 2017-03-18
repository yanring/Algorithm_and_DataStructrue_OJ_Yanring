#include <iostream>
#include <cstring>
#include <map> 
#include <queue>
#include <stack> 
#define MAX 1077952576
using namespace std;
int N,Q,R;
string dest[40],path[40];
map<string,int> string2int;
int roads[40][40],temp[40],mark[40],former[40],former_matrix[40][40];//temp用来存最近距离 
stack<int> ans;
//void print_path(int); 
//void update_temp(string node){
//	int index = string2int[node];
//	for(int i = 1 ; i<=N ; i++){
//		if((roads[index][i]+temp[index])<temp[i]&&mark[i]==0){		
//			temp[i] = (roads[index][i]+temp[index]);
//			former[i] = index;
////			cout<<"test"<<temp[i]<<endl;
//		}
//	}
//	mark[index] = 1;//这个点已经加入 
//} 
//int pick_node(int add_node_index){
//	int index = 0;
//	int min_len = MAX;
//	for(int i = 1 ; i <= N ; i++){
//		if(temp[i]<min_len&&mark[i]==0){
//			index = i;
//			min_len = temp[i]; 
//		}
//	}
//	return index;
//}
//void build_path(string start,string end){
//	memset(temp,1<<6,sizeof(temp));
//	memset(mark,0,sizeof(mark));
//	memset(former,0,sizeof(former));
//	temp[string2int[start]]=0;
//	update_temp(start);
////	cout<<start;
//	int add_node_index = pick_node(string2int[start]);
//	while(add_node_index>0){
//		update_temp(dest[add_node_index]);
////		cout<< dest[add_node_index];
//		if(dest[add_node_index]==end){
//			print_path(add_node_index);
//			return;
//		}			
//		add_node_index = pick_node(add_node_index);
//	}
//	print_path(string2int[end]);	
//}                                                                                                                                           
void print_path(int end_index){
	ans.push(end_index);
	int former_index = former[end_index];
	while(former_index!=0){
		ans.push(former_index);
		former_index = former[former_index];
	}
	int start,next;
	start = ans.top();
	ans.pop();
	cout<<dest[start];
	while(!ans.empty()){
		next = ans.top();
		ans.pop();
		cout<<"->"<<"("<<roads[start][next]<<")"<<"->";
		cout<<dest[next];
		start = next;
	} 
	cout<<endl;
}
void print_path_floyd(){
	int start,next;
	start = ans.top();
	ans.pop();
	cout<<dest[start];
	while(!ans.empty()){
		next = ans.top();
		ans.pop();
		cout<<"->"<<"("<<roads[start][next]<<")"<<"->";
		cout<<dest[next];
		start = next;
	} 
	cout<<endl;
}
void build_path_v2(string start,string end){
	memset(temp,1<<6,sizeof(temp));
	memset(mark,0,sizeof(mark));
	memset(former,0,sizeof(former));
	int i = string2int[start];
	temp[string2int[start]]=0;
	mark[string2int[start]]=1;
	for(int k = 1; k<N; k++){//update 
		for(int j = 1; j<=N ; j++){
			if(mark[j]==0&&(temp[j]>(roads[i][j]+temp[i]))){
				temp[j]=roads[i][j]+temp[i];
				former[j] = i;
			}
		}
		i=0;
		for(int j = 1; j<=N ; j++)//找最近的点 
			if(mark[j]==0&&temp[j]<temp[i])
				i=j;
		mark[i]=1; 
	} 
	print_path(string2int[end]);	
}
void build_path_floyd(int start,int end){
	int mid;
	if(start == end){
		if(!ans.empty()){
			if(ans.top()!=start){
				ans.push(start); 
				
			}else{
				return;
			}
			
		}else{
			ans.push(start); 
		}
		return;
	}
	if(former_matrix[start][end]){		
		mid = former_matrix[start][end];
		build_path_floyd(mid,end);
		build_path_floyd(start,mid);						
			
	}else{		
		build_path_floyd(end,end);
		build_path_floyd(start,start);
		return;
	}
}
void floyd(){
	for(int k = 1 ; k <= N ; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j<=N; j++){
				if((roads[i][k]+roads[k][j])<roads[i][j]&&roads[i][k]!=MAX){
					roads[i][j] = roads[j][i] = (roads[i][k]+roads[k][j]);
					former_matrix[i][j] = former_matrix[j][i] = k;
				}
			}
		}
	}
}
int main(int argc, char** argv) {
	cin>>N;
	memset(roads,1<<6,sizeof(roads));
	for(int i = 1; i <= N ; i++){
		cin>>dest[i];
		string2int[dest[i]]=i;
		roads[i][i]=0;
	}
	cin>>Q;
	for(int i = 1; i <= Q; i++){
		string start,end;
		int len;
		cin>>start>>end>>len;
		if(roads[string2int[start]][string2int[end]]>len&&roads[string2int[end]][string2int[start]]>len){
			roads[string2int[start]][string2int[end]]=roads[string2int[end]][string2int[start]]=len;
		}
	}
	floyd();
	cin>>R;
	for(int i = 1; i<= R ; i++){
		string start,end;
		cin>>start>>end;
//		build_path_v2(start,end);// build_path_v2为精简版的代码 
		build_path_floyd(string2int[start],string2int[end]);
		print_path_floyd();
	} 
	return 0;
}
//int main(int argc, char** argv) {//dijkstra 
//	cin>>N;
//	memset(roads,1<<6,sizeof(roads));
//	for(int i = 1; i <= N ; i++){
//		cin>>dest[i];
//		string2int[dest[i]]=i;
//	}
//	cin>>Q;
//	for(int i = 1; i <= Q; i++){
//		string start,end;
//		int len;
//		cin>>start>>end>>len;
//		if(roads[string2int[start]][string2int[end]]>len&&roads[string2int[end]][string2int[start]]>len){
//			roads[string2int[start]][string2int[end]]=roads[string2int[end]][string2int[start]]=len;
//		}
//	}
//	cin>>R;
//	for(int i = 1; i<= R ; i++){
//		string start,end;
//		cin>>start>>end;
//		build_path_v2(start,end);// build_path_v2为精简版的代码 
//		
//	} 
//	return 0;
//}
