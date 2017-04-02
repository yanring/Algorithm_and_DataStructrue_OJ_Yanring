#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std; 
bool mark[1000000];
int n;
void cal_yinshu(long long val){
	int temp_max = (val);
	for(int i = 2 ; i<= temp_max ; i++){
		for(int j = 2; j*i<=temp_max ; j++){
			mark[j*i]=0;
		}
	}
}
int main(int argc, char** argv) {
	memset(mark,1,sizeof(mark));
	cin>>n;
	cal_yinshu(n);
	
	for(int i = 2; i<=n;i++){
		if(!mark[i])
			continue;
		for(int j = i;j<=n;j++){
			if(!mark[j]||i+j!=n)
				continue;
			else
				cout<<i<<" "<<j<<endl;
				return 0; 
		}
	}
	return 0;
}
