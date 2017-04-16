#include <iostream>
#include <stack> 
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
stack<char> st;
void add(char c){
	if(c == ']'){
		if(st.top() == '['){			
			st.pop();
			return;
		}
		else
	}
}
int main(int argc, char** argv) {
	int N;
	cin>>N;
	char c;
	getchar();
	for(int i = 1; i<=N ; i++){
		memset(st,0,sizeof(st));
		while((c = getchar())!='\n'){
			add(c);
		}
	}
	return 0;
}
