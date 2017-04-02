#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std; 
int cal_yinshu(long long val){
	int temp_max = (int)sqrt(val);
	int temp = 0;
	for(int i = 2 ; i<= temp_max ; i++){
		while(!(val%i)){
			temp++;
			val = val/i;
			if(val%i){
				++temp *= cal_yinshu(val);
				return temp;
			}
		}
	}
	if(val > 1)
		return 2;
	return 1;	
}
int main(int argc, char** argv) {
	long long i , j , k ;
	cin>>i>>j;
	k = __gcd(i,j);
	int fenmu = cal_yinshu(i)*cal_yinshu(j);
	int fenzi = cal_yinshu(k);
	k = __gcd(fenmu,fenzi);
	fenmu = fenmu/k;
	fenzi = fenzi/k;
	cout<<fenmu<<" "<<fenzi<<endl;
	return 0;
}
