#include <iostream>
using namespace std;
int main() {
//	int con[1001][1001];
//	int size[1001][1001];
	int con[100][100];
	int size[100][100];
	int n,m;
	int max_v=0;
	int i = 1;int j;
	cin>>n>>m;
	for(i = 1; i <= n ; i++ )
	{
		for(j = 1 ; j <= m ; j++)
			  cin>>con[i][j];
	}
	for(i = 1; i <= n ; i++ )
	{
		for(j = 1 ; j <= m ; j++){
			if(con[i][j]==0)
			continue;			 
			size[i][j]=min(size[i-1][j],min(size[i][j-1],size[i-1][j-1]))+1;
			if(max_v < size[i][j]){
				max_v = size[i][j];
			}
  
		}			  
	}
	cout<<max_v;
	return 0;
}

