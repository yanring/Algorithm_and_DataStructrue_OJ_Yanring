#include <iostream>
#include <cstring>
#include <algorithm>
//有入度的都不可能是第一个，所以要从没入度的开始,每次找到没入度的就把它从图中剔除,并更新整个图的入度,然后又从最小的点开始遍历没入度的点 
//注意有重边!! 
using namespace std;
int matrix[32][32];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N,M,t; 
int mark[102],mark_rudu[102],temp_rudu[102];
char ans[29];
int check_circle(int index){
	if(mark[index]==1){
		return 0;
	}
	if (mark[index]==-1){
		return -1;
	}
	mark[index]=-1;
	for(int i = 1; i<=N ; i++){
		if(matrix[index][i]){
			int temp = check_circle(i);
			if(temp==-1){
				return -1;
			}
		}			
	}
	mark[index]=1;
}
int check_rudu(){
	int temp=0,temp_out=0;
	for(int i= 1; i<=N ; i++){
		if(temp_rudu[i]==0)
			temp++;
		if(temp_rudu[i]==-1||temp_rudu[i])
			temp_out++;
	}
	memset(mark,0,sizeof(mark));
	for(int i =1 ; i<=N ;i++){
		if(check_circle(i)==-1){
			return -1;
		}
	}
	
	if(temp==1){
		return 1;
	}
	if((temp_out)==N){
		return -1;
	}
	if(temp>1){
		return 0;
	}
	
}
int topo_sort(int index){
	int num=0;
	int flag = 0;
	int t=1;
	memcpy(temp_rudu,mark_rudu,sizeof(mark_rudu));
	for(int k = 1; k <=N ; k ++){
		for(int i = 1; i<=N ; i++){
			int state = check_rudu();
			if(state==0){
				return 0;
			}
			if(state == -1){
				cout<<"Inconsistency found after "<<index<<" relations."<<endl;
				return -1;
			}
			if(temp_rudu[i]==0){				
//				cout<<"v"<<i<<" ";
				ans[t++] = i+64;
				temp_rudu[i]--;
				num++;
				for(int j = 1; j<=N;j++){
					if(matrix[i][j]){
						temp_rudu[j]-=matrix[i][j];
					}
				}
				break;
			}
		}
	}
	return num;
}

int main(int argc, char** argv) {
	while(1){		
		cin>>N>>M;
		if(N==0&&M==0)
			return 0;
		int res;
		int flag = 0;
		t = N;		
		memset(matrix,0,sizeof(matrix));
		memset(mark_rudu,0,sizeof(mark_rudu));
		if(N==1&&M==0){
			cout<<"Sorted sequence determined after "<<0<<" relations: A.\n";
			flag=1;
		}
		for(int i = 1; i<=M ; i++){
			int x,y;
			string str;
			cin>>str;
			if(flag == 1){
				continue;
			}
			x = str[0]-64;
			y = str[2]-64;
			matrix[x][y]++;
			mark_rudu[y]++;
			res = topo_sort(i);
			if(res==N){
				cout<<"Sorted sequence determined after "<<i<<" relations: ";
				for(int i = 1; i<=N ; i++){
					cout<<ans[i];
				}
				cout<<'.'<<endl;
				flag = 1;
			}
			if(res == -1){
				flag = 1;
			}
		}
		if(res==0&&flag==0){
			cout<<"Sorted sequence cannot be determined."<<endl;
		}
	}
	return 0;
}
