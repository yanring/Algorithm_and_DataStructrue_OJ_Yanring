#include <cstdio>  
#include <cstring>  
#include <queue>  
#include <iostream>  
#include <cstdlib>  
#include <cmath>  
#include <algorithm>
using namespace std;  
#define MAXL 1000005  
#define INF 1<<31  
struct node{  
    int x,f;  
    node(int xx=0,int ff=0):x(xx),f(ff){}  
    bool operator<(const node &x) const {  
        return f>x.f;  
    }  
};  
priority_queue<node> q; 
int n,l,a,b;
int cowThere[MAXL],F[MAXL];
node top_node;
int main(){
	int i,j,up_bound,low_bound;
	memset(cowThere,0,sizeof(cowThere)); 
	cin>>n>>l>>a>>b;

	for(i = 1 ; i<=l ;i++){
		F[i]=INF;
	}
	for(i = 1; i <= n; i++){
		
		cin>>up_bound>>low_bound;
		for(j = up_bound+1;j<low_bound;j++) cowThere[j]=1;		
	}
	a <<= 1;
    b <<= 1;	
	for(i = a; i<= b; i+=2){
		if(!cowThere[i]){
			F[i]=1;
//			cout<<i<<" ";
			if(i<=b+2-a){
				q.push(node(i,1));
			}
		}
	}

	for(i = b+2; i<=l ; i+=2){
		if(!cowThere[i]){
			while(!q.empty()){
				top_node = q.top();
				if(top_node.x<i-b){
					q.pop();
				}else{
					break;
				}
			}
			if(!q.empty()){
				F[i]=top_node.f+1;
//				cout<<i<<" "<<top_node.f<<" ";
			}
			
		}
		if(F[i-a+2]!=INF)
			q.push(node(i-a+2,F[i-a+2]));
	}
	if(F[l] == INF){
		cout<<-1<<endl;
	}else{
		cout<<F[l]<<endl;
	}
//	for(i = 1 ; i<=l ;i++){
//		cout<<F[i]<<" ";
//	}
	return 0;
} 
