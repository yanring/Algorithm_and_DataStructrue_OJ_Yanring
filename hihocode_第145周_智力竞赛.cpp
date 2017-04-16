#include <iostream>
#include <cstring> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 16843009 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Q,N,M,S,T,c[1009][1009],A[1009];
int main(int argc, char** argv) {
	cin>>Q;	
	for(int z = 1; z<=Q ;z++){
		memset(c,1,sizeof(c));
		memset(A,0,sizeof(A));
        scanf("%d %d %d %d", &N, &M, &S, &T);
        for(int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
		for(int i = 0 ; i<=M ; i++)
			c[0][i]=0;
		for(int i = 1; i<=N ;i++){
			for(int j = 0 ; j<=M; j++){
				for(int x=0;x <=((A[i]-1)/S + 1) ;x++){//X为对几道题
					int rest = A[i] - x*S,p=0;
					if(rest>0)
						p = (rest-1)/T+1;					 
					if(j>=(x+p)&&c[i-1][j-x-p]<MAX)
						c[i][j] = min(c[i][j],c[i-1][j-x-p]+x);
				}
			}
		}
		int MIN = MAX;
		for(int i = 0 ; i<= M ;i++)
			MIN = min(MIN,c[N][i]);
		if(MIN<MAX)
			cout<<MIN<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
