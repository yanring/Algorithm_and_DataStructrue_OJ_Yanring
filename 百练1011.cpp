#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N;
int L;
vector<int> anLength;
int anUsed[65];//是否被用过 
int i,j,k; 
int nLastStickNo;
bool Dfs(int R, int M){
//M是正在拼的缺的长度,R是剩的棍子数目 
	if(R==0&&M==0){
		return true;
	}
	if(M==0){//拼完一根 
		M=L;
		
	} 
	int StickNo=0;
	if(M!=L){
		StickNo=nLastStickNo+1;
	}
	for(int i=StickNo; i<N;i++){
		if(!anUsed[i]&&anLength[i]<=M){			
			if(i>0&&anLength[i]==anLength[i-1]&&!anUsed[i-1]){
				continue;
			} 	
			nLastStickNo = i;	 
			anUsed[i]=1;
			if(Dfs(R-1,M-anLength[i])){
				return true;
			}else{
				anUsed[i]=0;
			}
			if(M==L||anLength[i]==M){//剪枝,换每根棒子的第一节是没有意义的 
				return false;
			}
			
		}
	} 
	
	return false;
}
int main(int argc, char** argv) {
	while(1){
		cin>>N;
		if(N==0){
			break;
		}
		int nTotalLen = 0;
		anLength.clear(); 
		for(int i = 0 ; i < N ; i ++){
			int n;
			cin>>n;
			anLength.push_back(n);
			nTotalLen += anLength[i];
		}
		sort(anLength.begin(),anLength.end(),greater<int>());
		
		for(L = anLength[0] ; L <= nTotalLen / 2; L++){
			if (nTotalLen % L){
				continue;
			}
			memset(anUsed,0,sizeof(anUsed));
			if(Dfs(N,L)){
				cout<<L<<endl;
				break;
			}
		}
		if(L > nTotalLen / 2){
			cout<<nTotalLen<<endl;
		}
	}
	return 0;
}
