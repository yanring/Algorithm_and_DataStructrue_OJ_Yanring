#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxN=105,inf=0x3f3f3f3f;//���105��

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct arc{
	int id,dis,toll;
	arc(int _id,int _dis,int _toll):id(_id),dis(_dis),toll(_toll){}
};
struct node{
	int id,dis,res;
	node(int _id,int _dis,int _res):id(_id),dis(_dis),res(_res){}
	bool operator < (const node &b) const{
		if (dis!=b.dis) return dis>b.dis;//����Խ�̵��ŵ�Խǰ 
		return res<b.res;//���������ͬ,ʡǮ�����ǰ�� 
	}
};
int K,N,R,dis[maxN];
vector<vector<arc> > g(maxN);//����ͼ
void read()
{
	scanf("%d%d%d",&K,&N,&R);
	while (R--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		g[a].push_back(arc(b,c,d));//����ͼ
	}
}
int bfs(){
	
} 
int main() {
	read();
	printf("%d\n",bfs());
	return 0;
	return 0;
}
