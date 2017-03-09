#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
class Seats{
		
	public:
		int number;
		int tic_left;
		Seats(int number_start){
			number = number_start;
			tic_left = 5;
		}
		bool buy(int n){
			if(tic_left>=n){
				for(int i = 0; i<n-1 ; i++){
					cout<<number+(5-tic_left)+i<<" ";
				}
				cout<<number+(5-tic_left)+n-1<<endl;
				tic_left-=n;
				return true;
			}else{
				return false;
			}
		}
}; 

int N,buy_num;
Seats* seats[21];
void buy_left(int n){
	for(int i = 1; i<=20 ; i++){
		seats[i] = new Seats((i-1)*5+1);
	}
}
int main(){
	cin>>N;
	for(int i = 1; i<=20 ; i++){
		seats[i] = new Seats((i-1)*5+1);
	}
	for(int i = 1; i<=N ; i++){
		cin>>buy_num;
		int j = 1;
		while(!seats[j]->buy(buy_num)){
			j++;
			if(j>20){
				buy_left(buy_num);
				}
			}
		}
		
	}
	return 0;	
}  
