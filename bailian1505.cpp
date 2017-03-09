#include <iostream>
#include <cstring>
#include <stdio.h> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int b,m;
int books[510];
bool marks[510];
long long total;
bool check(int pages_lim){
	memset(marks,0,sizeof(marks));
	int temp_total=0,temp_m = m-1;
	for(int i = b; i >= 1; i--){
		if(temp_total + books[i] > pages_lim){
			if(temp_m<=0){
	 			return false;
			}
			temp_m--;
			marks[i]=1;//在i的前面插一个标记
	 		temp_total=0;
	 		i++;
	 		
		}else{
			temp_total+=books[i];
		}
	}

	return true;
}
bool refind(int pages_lim){
	memset(marks,0,sizeof(marks));
	int temp_total=0,temp_m = m-1;
	for(int i = b; i >= 1; i--){
		if(temp_total + books[i] > pages_lim){
			if(temp_m<=0){
	 			return false;
			}
			temp_m--;
			marks[i]=1;//在i的前面插一个标记
	 		temp_total=0;
	 		i++;
	 		
		}else{
			temp_total+=books[i];
		}
	}
//	cout<<pages_lim<<endl;
	if(temp_m>0){
	//按规则重新放斜杠
 		temp_m=m-1;
		memset(marks,0,sizeof(marks));
		temp_total=0;			  
		for(int i = b; i>=1; i--){
			if(temp_total + books[i] > pages_lim){
				marks[i]=1;//在i的前面插一个标记
		 		temp_total=0;
		 		temp_m--;
		 		i++;
			}
			else{
				temp_total+=books[i];
			}
		}
		for(int i = 1; i<=b&&temp_m>0;i++){
			if(marks[i]==1){
				continue;
			}
			temp_m--;
			marks[i]=1;
		}	
	
	}
	return true;
}
void find(){
	int lb,ub;
	lb = total / m -1;
	ub = total;
	while((lb+1)<ub){
		int mid = (lb+ub-1)/2 +1;
		if(check(mid)){
			ub=mid;
		}else{
			lb=mid;
		}
	}
	refind(ub);
}

int main(int argc, char** argv) {
	int N;
	cin>>N;
	for(int k = 1 ; k <= N ; k++){
		cin>>b>>m;
//		m--;
		memset(books,0,sizeof(books));
		total = 0 ; 
		for(int i = 1; i <= b ; i++){
			scanf("%d",&books[i]);
			total +=  books[i];
		
		}
		

		find();
		for(int i = 1; i < b ; i++){
			
			cout<<books[i]<<" ";
			if(marks[i]==1){
				cout<<"/ ";
			}
		}
		cout<<books[b]<<endl;
	}
	return 0;
}
