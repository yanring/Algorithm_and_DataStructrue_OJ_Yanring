#include<cstdio>
#include<iostream>
#include<cstring>
#include <queue>
#include <sstream>
#include<time.h>
#include<math.h>
/* 	A*算法求解八数码
	author：颜子杰 
*/ 
using namespace std;
bool flag[999999999]; //可以用康拓展开来节省flag的内存消耗 
int target = 123456780;//目标状态 
string target_str = " 123456780";
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
	int G;
	int H; 
	matrix(){
		G=H=0;
	} 
	bool operator<(const matrix &b) const { // 重载<，优先队列需要 
//		return (H) > (b.H);
        return (G+H) > (b.G+b.H);
    }
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
//	void cal_H(){
//		int value = cal_val();
//		H = 0; 
//		int tmp_target = target;
//		for(int i = 1 ; i <= 9 ; i++){
//			if(value%10!=tmp_target%10)
//				H++;
//			tmp_target/=10;
//			value/=10;
//		}
//	}
	void cal_H(){
		int value = cal_val();
		H = 0; 
		int tmp_target = target;
		for(int i = 1 ; i <= 9 ; i++){
			int index = target_str.find('0'+mat[i]);
			H = abs(i/3-index/3)+abs(i%3-index%3);
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
priority_queue<matrix> q;
int main()
{
	matrix res;
	matrix tmp_mat;
	clock_t startTime,endTime;
	startTime = clock(); 
	freopen("1.txt","r",stdin);
	while(1){
		while (!q.empty()) q.pop();
		memset(flag,0,sizeof(flag));
		printf("Input your data：\n");
		for(int i=0;i<9;i++)
			scanf("%d",&tmp_mat.mat[i]);
		q.push(tmp_mat);
 		if(tmp_mat.mat[1]==9){
			
			endTime = clock();
			cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
			return 0;
		}
		while(!q.empty()){
			matrix tmp2 = q.top();
			matrix tmp3 = q.top();
			q.pop();
			stringstream ss;
			ss << tmp2.cal_val();
			string pre_val = ss.str();
			if(pre_val.length()==8){
				pre_val = "0"+ pre_val;
			}
			if(tmp2.cal_val() == target){
				res = tmp3;
				printf("success!\n");
				break;
			}
			if(tmp2.move_left()){
				tmp2.path = tmp2.path + pre_val;
				if(flag[tmp2.cal_val()]==0)	{
					tmp2.G++;
					tmp2.cal_H();
					q.push(tmp2);					
				}					
				flag[tmp2.cal_val()]=1;
			}
			tmp2 = tmp3;
			if(tmp2.move_right()){
				tmp2.path = tmp2.path + pre_val;
				if(flag[tmp2.cal_val()]==0){
					tmp2.G++;
					tmp2.cal_H();
					q.push(tmp2);					
				}
				flag[tmp2.cal_val()]=1;
			}
			tmp2 = tmp3;
			if(tmp2.move_down()){
				tmp2.path = tmp2.path + pre_val;
				if(flag[tmp2.cal_val()]==0){
					tmp2.G++;
					tmp2.cal_H();
					q.push(tmp2);					
				}
				flag[tmp2.cal_val()]=1;
			}
			tmp2 = tmp3;
			if(tmp2.move_up()){
				tmp2.path = tmp2.path + pre_val;
				if(flag[tmp2.cal_val()]==0){
					tmp2.G++;
					tmp2.cal_H();
					q.push(tmp2);					
				}
				flag[tmp2.cal_val()]=1;
			}	 
		}
		if(q.empty())
			cout<<"无解"<<endl;
		else{
			string path = res.path;
			int steps = 0;
			for(int i = 0 ; i < path.length();i++){
				cout<< path[i]<<" ";
				if(i%3==2)
					cout<<endl;
				if(i%9==8){
					cout<<endl;
					steps++;
				}
			}
			res.print();
			printf("A*算法最短通过%d 步到达\n",steps);
		}			
	}
	return 0;
}
