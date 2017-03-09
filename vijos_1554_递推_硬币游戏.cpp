#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
//正面是1,但是相当于位运算0,反面是2,但是相当于位运算1
using namespace std;
int coin[200009],res[200009],temp[200009];
long long T;
int N=0;
void cal_xor(long long offset){
	int start=0;
	memset(temp,0,sizeof(res));
	int flag = offset&1;
	offset = offset % (2*N);
//	int temp;
	if(flag==0){
		start=res[0]>0?0:1;
	}else if(flag==1){
		start=res[0]>0?1:0;
	}
	for(int i = start ; i < 2*N ; i+=2){
		int lb = (i-offset+2*N)%(2*N);
		int ub = (i+offset)%(2*N);
		temp[i] = ((res[lb]-1) xor (res[ub]-1))+1;

	}
	memcpy(res,temp,sizeof(res));

}
int main(){
	cin>>N>>T;
	memset(coin,0,sizeof(coin));
	memset(res,0,sizeof(res));
	for(int k = 0; k<N; k++){//遍历 
		cin>>coin[2*k];
		if(coin[2*k]==2){
			
		} 
	}
	long long  offset = T;
	memcpy(res,coin,sizeof(coin));
	int index = 0;
	while(offset){
		if(offset&1){//算一次 
			long long arg = pow(2,index);
			cal_xor(arg);
		}
		index =index+1;
		offset=offset>>1;
	}

	for(int k = 0; k<2*N; k++){//遍历 
		cout<<res[k]<<" ";
	}
	cout<<endl;
	return 0;	
}  
