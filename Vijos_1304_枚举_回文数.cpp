#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <sstream> 
#include <cmath>
using namespace std;
long long N,num,str,len=0;
long long reverse(long long num){
	string str;
	stringstream stream;
	stream<<num;
	str = stream.str();
	for(long long i = 0 ; i < str.length()/2;i++){
		swap(str[i],str[str.length()-1-i]);
	}
	stream.str("");//清空缓冲区 
	stream<<str;
	stream>>num;
	return num;
}
long long decode(long long number,long long N){
	long long index=0;
	long long res=0,temp;
	while(number/10){
		temp=number%10;
		res=res+temp*pow(N,index++);
		number/=10;
	}
	res=res+number*pow(N,index++);
	return res;
} 
long long encode(long long number,long long N){
	long long index=0;
	long long res=0,temp;
	while(number/N){
		temp=number%N;
		res=res+temp*pow(10,index++);
		number/=N;
	}
	res=res+number*pow(10,index++);
	return res;
}
bool check(long long number){
	stringstream stream;
	string str;
	bool flag = 1;
	stream<<number;
	str = stream.str();
	for(long long i = 0 ; i < str.length()/2;i++){
		if(str[i]!=str[str.length()-1-i]){
			flag = 0;
		}
	}
	return flag;
}

bool check16(long long number){
	stringstream stream;
	string str;
	bool flag = 1;
	stream<<hex<<number;
	str = stream.str();
	for(long long i = 0 ; i < str.length()/2;i++){
		if(str[i]!=str[str.length()-1-i]){
			flag = 0;
		}
	}
	return flag;
}
void add(long long number){
	if(check(number)){
		cout<<"STEP="<<len<<endl;
		return;
	}
	if(len>=25){
		cout<<"Impossible!"<<endl;
		return;
	}
	long long temp1,temp2,sum;
	temp1=decode(number,N);
	temp2=decode(reverse(number),N);
	sum = temp1+temp2;
	sum = encode(sum,N);
	len++;
	add(sum);
}
void add16(long long number){
	if(check16(number)){
		cout<<"STEP="<<len<<endl;
		return;
	}
	if(len>=30){
		cout<<"Impossible!"<<endl;
		return;
	}
	long long temp1,temp2,sum;
	temp1=number;
	string str;
	stringstream stream;
	stream<<hex<<number;
	str = stream.str();
	for(long long i = 0 ; i < str.length()/2;i++){
		swap(str[i],str[str.length()-1-i]);
	}

	stream.str("");//清空缓冲区 
	stream<<str;
	stream>>temp2;
	sum = temp1+temp2;
	len++;
//	cout<<hex<<sum<<" "<<len<<endl;
	add16(sum);
}
int main(){
	cin>>N; 
	if(N==16){
		cin>>hex>>num;
		add16(num);
	}else{
		cin>>num;
		add(num);
	}
//	cout<<"Impossible!"<<endl;
	return 0;	
} 
