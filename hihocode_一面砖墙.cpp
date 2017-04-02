#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map < int , int > hash_map;
int MAX=0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N,M;
int main(int argc, char** argv) {
	scanf("%d",&N);
	for(int i = 1; i<=N;i++){
		scanf("%d",&M);
		int sum=0,temp;
		for(int j = 1; j<M ; j++){
			scanf("%d",&temp);
			sum+=temp;
			if(hash_map.count(sum)){
				hash_map[sum]++;
			}else{
				hash_map[sum]=1;
			}
		}
		scanf("%d",&temp);
	}
	for(map<int,int>::iterator it=hash_map.begin();it!=hash_map.end();it++){
		MAX = MAX>it->second?MAX:it->second;
	}
	cout<<N-MAX<<endl;
	return 0;
}
