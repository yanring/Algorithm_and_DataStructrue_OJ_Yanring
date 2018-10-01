#include<cstdio>
#include<iostream>
#include<cstring>
#include <queue>
#include <sstream>
using namespace std;
bool flag[999999999]; 
/*
	bfs求解八数码
	author:颜子杰 
*/ 
int find_zero(int mat[])
{
	for(int i=0;i<9;i++)
	{
		if(mat[i]==0)
			return  i;
	}
}
class matrix{
	public :
	int mat[9];
	string path; 
	bool move_right(){
		int zero_index = find_zero(mat);
		if(zero_index%3!=2){
			swap(mat[zero_index],mat[zero_index+1]);
			return 1;
		}
		return 0;
	}
	bool move_left(){
		int zero_index = find_zero(mat);
		if(zero_index%3!=0){
			swap(mat[zero_index],mat[zero_index-1]);
			return 1;
		}
		return 0;
	}
	bool move_up(){
		int zero_index = find_zero(mat);
		if(zero_index>=3){
			swap(mat[zero_index],mat[zero_index-3]);
			return 1;
		}
		return 0;
	}
	bool move_down(){
		int zero_index = find_zero(mat);
		if(zero_index<=5){
			swap(mat[zero_index],mat[zero_index+3]);
			return 1;
		}
		return 0;
	}
	void print()
	{
		for(int j=0;j<9;j++)
		{
			if(mat[j]==0)
				printf("0 ");
			else
				printf("%d ",mat[j]);
			if((j+1)%3==0)
			printf("\n");
		}
	}
	int cal_val(){
		int value = 0;
		for(int i = 0; i <= 8 ;i++){
			value = value * 10 + mat[i];
		}
		return value;
	}
};
queue<matrix> q;
int main()
{
	matrix tmp_mat;
	while(1){
		printf("Input your data：\n");
	 	while (!q.empty()) q.pop();
	 	memset(flag,0,sizeof(flag));
		for(int i=0;i<9;i++)
			scanf("%d",&tmp_mat.mat[i]);
		q.push(tmp_mat);
		while(!q.empty()){
			matrix tmp2 = q.front();
			stringstream ss;
			ss << tmp2.cal_val();
			string pre_val = ss.str();
			if(pre_val.length()==8)//保存路径,这样比较省空间 
				pre_val = "0"+ pre_val;
			if(tmp2.cal_val() == 123456780){
				printf("success!\n");
				break;
			}
			if(tmp2.move_left()){
				tmp2.path = tmp2.path + pre_val;
				if(flag[tmp2.cal_val()]==0)				
					q.push(tmp2);
				flag[tmp2.cal_val()]=1;
			}
			tmp2 = q.front();
			if(tmp2.move_right()){
				tmp2.path = tmp2.path + pre_val;
				if(flag[tmp2.cal_val()]==0)	
					q.push(tmp2);
				flag[tmp2.cal_val()]=1;
			}
			tmp2 = q.front();
			if(tmp2.move_down()){
				tmp2.path = tmp2.path + pre_val;
				if(flag[tmp2.cal_val()]==0)	
					q.push(tmp2);
				flag[tmp2.cal_val()]=1;
			}
			tmp2 = q.front();
			if(tmp2.move_up()){
				tmp2.path = tmp2.path + pre_val;
				if(flag[tmp2.cal_val()]==0)	
					q.push(tmp2);
				flag[tmp2.cal_val()]=1;
			}
			q.pop();
		}
		if(q.empty())
			printf("无解\n");
		else{
			matrix tmp2 = q.front();
			string path = tmp2.path;
			int steps = 1;
			for(int i = 0 ; i < path.length();i++){
				cout<< path[i]<<" ";
				if(i%3==2)
					cout<<endl;
				if(i%9==8){
					cout<<endl;
					steps++;
				}
			}
			tmp2.print();
			printf("最短通过%d步\n",steps);
		}	
	}
	return 0;
}
