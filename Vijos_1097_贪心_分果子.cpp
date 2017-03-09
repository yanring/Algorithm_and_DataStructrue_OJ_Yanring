#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue> 
using namespace std;
int N,max_num,times=0; 
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	int temp1,temp2,temp_sum,sum=0;
	cin>>N;
	for(int i = 1 ; i<=N ; i++){
		cin>>temp1;
		q.push(temp1);
	}
	while(!q.empty()){
		temp1=q.top();
		q.pop();
		if(q.empty()){
			break;
		}
		temp2=q.top();
		q.pop();
		temp_sum=temp1+temp2;
		sum+=temp_sum;
		q.push(temp_sum);		
	}
	cout<<sum<<endl;
	return 0;	
} 
