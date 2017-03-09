#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int K,N,R,S,D,L,T;
struct Road{
	int d,L,t;
}; 
vector<vector<Road> > cityMap(110);
int minLen = 1<<30;//当前最优长度
int totalLen;
int totalCost;
int visited[110];
int minL[110][10100];
int minLens[110];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Dfs(int s){
	if(s == N){
		minLen = min(minLen,totalLen);
		return;//到达终点 
	}
	for(int i = 0 ; i < cityMap[s].size();i++){
		int d = cityMap[s][i].d;
		if(! visited[d]){
			int len = totalLen + cityMap[s][i].L;
			int cost = totalCost + cityMap[s][i].t;
			if(minL[d][cost]<len||cost>K||len>minLen){
				continue;
			}
			minL[d][cost] = min(minL[d][cost],len); 
			totalLen += cityMap[s][i].L;
			totalCost += cityMap[s][i].t;
			visited[d] = 1;
			Dfs(d);
			totalLen -= cityMap[s][i].L;//递归完成后还原全局变量 
			totalCost -= cityMap[s][i].t;
			visited[d] = 0;
		}
		
	} 
}
int main(int argc, char** argv) {
	cin>>K>>N>>R;
	for(int i = 0; i<R ; i++){
		int s;
		Road r;
		cin >> s >> r.d >> r.L >> r.t;
		if(s != r.d){//如果没有闭圈 
			cityMap[s].push_back(r); 
		}
	}
	memset(minL,0x7f,sizeof(minL));
	memset(visited,0,sizeof(visited));
	totalLen = totalCost =0;
	visited[1] = 1;
	Dfs(1); 
	cout<<minLen<<endl;
	return 0;
}
