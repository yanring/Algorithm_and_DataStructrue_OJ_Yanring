#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
#define MAX 1077952576
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N,M,sum=0;
int sale[1009];
int main(int argc, char** argv) {
	cin>>N;
	for(int i = 1; i<=N ; i++){
		cin>>sale[i];
	}
	for(int i = 2; i<=N-1 ; i++){
		if(sale[i]>sale[i-1]&&sale[i]>sale[i+1]||sale[i]<sale[i-1]&&sale[i]<sale[i+1]){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0; 
}
