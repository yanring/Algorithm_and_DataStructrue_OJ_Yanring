#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
int N,num[2000],max_num; 
int main(){
	cin>>N;
	cin>>num[1];
	for(int i = 2; i<=N ; i++){
		cin>>num[i];
		max_num=abs(num[i]-num[i-1])>max_num?abs(num[i]-num[i-1]):max_num;
	}
	cout<<max_num<<endl;
	return 0;	
}  
