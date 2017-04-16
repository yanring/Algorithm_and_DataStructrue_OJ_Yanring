#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>


using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main(int argc, char** argv) {
	int N;
	while(scanf("%d",&N)!=EOF){
		priority_queue < int ,vector<int>, greater<int> > q;
		int sum = 0;
		for(int i = 1; i<=N ; i++){
			int temp;
			scanf("%d",&temp);
			q.push(temp);
		}
		for(int i = 1 ; i<= N-1 ;i++){
			int num1 = q.top();
			q.pop();
			int num2 = q.top();
			q.pop();
			sum+=num1+num2;
			q.push(num1+num2);
		}
		cout<<sum<<endl;
	}
	return 0;
}
