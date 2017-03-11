#include <iostream>
#include <cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int heap[100009];
int len = 0;
void shift_down(int index){
	heap[0] = heap[index];
	int i = index;
	int j = index*2;
	while(j<=len){
		if(j<=len-1&&(heap[j]>heap[j+1])){
			j++;
		}
		if(heap[0]>heap[j]){
			heap[i]=heap[j];
			i = j;
			j = i*2;
		}
		else break;
	}
	heap[i] = heap[0];
}
void shift_up(int index){
	int i = index;
	int j = index/2;
	while(j>=1){
		if(heap[i]<heap[j]){
			swap(heap[i],heap[j]);
			i = j;
			j = i/2;
		}
		else break;
	}
}
void build_heap(){
	for(int i = len/2;i>0;i--){
		shift_down(i);
	}
}
void insert(int num){
	heap[len+1]=num;
	len++;
	shift_up(len);
}
void delete_top(){
	cout<<heap[1]<<endl;
	heap[1]=heap[len];
	len--;
	shift_down(1);
} 
int main(int argc, char** argv) {
	int N,type,temp;
	cin>>N;
	memset(heap,0,sizeof(heap));
	for(int i = 1; i<=N ;i++){
		cin>>type;
		if(type==1){
			cin>>temp;
			insert(temp); 
		}else{
			delete_top();			
		}
	} 
	return 0;
}
