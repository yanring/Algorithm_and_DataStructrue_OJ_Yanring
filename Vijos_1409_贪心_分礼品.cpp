#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int N,max_num,times=0; 
int val[30020];
void sort(int lb,int ub){
	if(lb>=ub){
		return;
	}
	int m = lb;
	for(int i = lb+1; i <= ub ;i++){
		if(val[i]<val[lb]){
			m++;
			swap(val[i],val[m]);			
		}
	}
	swap(val[lb],val[m]);
	sort(lb,m-1);
	sort(m+1,ub);
}
int main(){
	cin>>max_num>>N;
	int low=1,up=N;
	for(int i = 1; i <= N ; i++){
		cin>>val[i];
	}
	sort(1,N);
	while(low<=up){
		if((val[low]+val[up])<=max_num){
			low++;
			up--;
			times++;
		}else{
			up--;
			times++;
		}
	}
	cout<<times<<endl;
	return 0;	
} 
