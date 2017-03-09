#include <iostream>
#include <cstring> 

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N;
int ori_char[1009];
int maze[1009][1009];
int value[1009][1009];
int index[1009];
int val[1009][1009];


int main(int argc, char** argv) {
	cin>>N;
	memset(val,127,sizeof(val));
	memset(maze,127,sizeof(maze));
	for(int i = 1; i<=N;i++){
		cin>>ori_char[i];
		maze[1][i] = ori_char[i];
		val[1][i] = 0;
	}
	
	for(int i = 2; i<=N;i++){//长i,从j开始 
		for(int j = 1; j<=(N-(i-1)); j++){
			for(int k = 1; k <= i-1 ; k++){//val是总分,maze是结点分 
				int temp = val[k][j]+val[i-k][j+k]+maze[k][j]+maze[i-k][j+k];
//				if(k!=1)
//					temp+=maze[k][j];
//				if((i-k)!=1)
//					temp+=maze[i-k][j+k];
				if(val[i][j]>temp){
					maze[i][j]=maze[k][j]+maze[i-k][j+k];
					val[i][j]=temp;
				}
			}
		}
	}
	cout<<val[N][1]<<endl;
//	cout<<maze[2][4]<<endl;
	return 0;
}
