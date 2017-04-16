#include <iostream>
#include <cstring> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Q;
struct node{
	public :
	int true_times,over_point;
	node(int _true_times,int _over_point){
		over_point =_over_point;
		true_times = _true_times;
	}
	friend bool operator <  (node num1,node num2){
		return num1.over_point<num2.over_point;
	}
};
int main2(int argc, char** argv) {
	cin>>Q;	
	for(int j = 1; j<=Q ;j++){
		int N,M,S,T,A[1009]={0},true_times=0,false_times=0;
		priority_queue<node> list;
		 cin>>N>>M>>S>>T;
		for(int i = 1; i<=N ;i++){
			cin>>A[i];
		}
		for(int i = 1; i<=N ;i++){
			int temp =ceil(A[i]/double(S));
			list.push(node(temp,temp*S-A[i]));
			true_times+=temp;
			
		}
		if(true_times>M){//impossible
			cout<<"No"<<endl;
			continue;
		}		
		while((true_times+false_times)<=M){					
			if(list.top().over_point >=(S-T)){
				node temp_node = list.top();
				if(list.empty()){
					break;
				} 
				list.pop();				
				int replace_times = temp_node.over_point/(S-T);
				if(temp_node.true_times<=replace_times){
					true_times -= temp_node.true_times;
					false_times += temp_node.true_times;
				}else{
					temp_node.over_point -= replace_times*(S-T);
					temp_node.true_times -= replace_times;
					true_times -= replace_times;
					false_times += replace_times;
					list.push(temp_node);
				}				
			}else{
				node temp_node = list.top();
				list.pop(); 
				int rest_times = M-(true_times+false_times);
				int add_false_times = ceil((S-temp_node.over_point)/double(T)); 
				if((rest_times+1)>=add_false_times&&temp_node.true_times>0){
					temp_node.over_point = temp_node.over_point+add_false_times*T-S;
					temp_node.true_times--; 
					true_times--;
					false_times += add_false_times;
					if(temp_node.true_times>0){
						list.push(temp_node);
					}
				}else{					
					break;
				}
			}
		}
//		cout<<1;
		cout<<true_times<<endl;
	}
	return 0;
}
