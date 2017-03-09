#include <iostream>
using namespace std;
int times = 0 ;
int N; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void search(int InStack,int Left){
	if(InStack==0&&Left==0){
		times++;
		return;
	}
	if(InStack>0){
		search(InStack-1,Left);
	}
	if(Left>0){
		search(InStack+1,Left-1);
	}
}
int main(int argc, char** argv) {
	cin>>N;
	search(0,N);
	cout<<times<<endl; 
	return 0;
}
