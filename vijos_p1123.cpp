#include <iostream>
#include <cstring>
using namespace std;
int N;
int cards[200]; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int sum=0,avr,res=0;
	cin>>N;
	for (int i = 1 ; i <= N ; i++){
		cin>>cards[i];
		sum += cards[i];
	}
	avr = sum/N;
	int temp_sum=0; 
	for (int i = 1 ; i <= N ; i++){
		temp_sum = (avr+temp_sum) - cards[i];
		if(temp_sum){
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
