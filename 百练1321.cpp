#include <iostream>
#include <cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int size,num; 
int matrix[10][10];
int total_plans=0;
bool flag[10];//记录哪些列被用了 
bool Dfs(int extra_line,int left_num,int start_line){
	int line_offset;
	if(left_num == 0){
		total_plans++;
		return true;
	}
	for(int line_offset = 0;line_offset<=extra_line;line_offset++){
		for(int i = 1 ; i <= size ; i++){
			if(flag[i]==false && matrix[start_line+line_offset][i]==0){
				flag[i]=true;
				Dfs(extra_line-line_offset,left_num-1,start_line+1+line_offset);
				flag[i]=false;
			}
		}
	}
}
int main(int argc, char** argv) {
	char temp_char;
	while(1){
		cin>>size>>num;
		if(size==-1&&num==-1){
			break;
		}
		for(int i = 1; i <= size; i++){
			for(int j = 1; j <= size; j++){
				cin>>temp_char;
				if(temp_char == '.'){
					matrix[i][j]=1;
				}
			}
		}
		int extra_line = size - num;
		Dfs(extra_line,num,1);
		cout<<total_plans<<endl;
		total_plans = 0;
		memset(matrix,0,sizeof(matrix));
		memset(flag,0,sizeof(flag));
	}
	return 0;
}
