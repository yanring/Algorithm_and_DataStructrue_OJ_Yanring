#include <iostream>
#include <cstring>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct box{
	int color;
	int len;
};
box box_list[205];
int score[201][201][201];

int click_box(int start, int end, int exlen){
	int best_score,temp;
	if(score[start][end][exlen]!=0){
		return score[start][end][exlen]; 
	}
	if(start == end){
		score[start][end][exlen] = (exlen+box_list[end].len)*(exlen+box_list[end].len);
		return score[start][end][exlen];
	}
	best_score = click_box(start,end-1,0)+(box_list[end].len+exlen)*(box_list[end].len+exlen);//第一种方法,直接消掉
	for(int i = end-1; i>=start;i--){
		if(box_list[i].color!=box_list[end].color){
			continue;
		}
		temp = click_box(start,i,exlen+box_list[end].len)+click_box(i+1,end-1,0);
		if(temp>best_score){
			best_score = temp;
		}			
	} 
	score[start][end][exlen] = best_score;
	return best_score;
}

int main(int argc, char** argv) {
	int test_num,box_num;
	cin>>test_num;
	for(int j = 1; j<=test_num ; j++){		
		cin>>box_num;
		int former_color=0,box_index=0,cur_color;
		for(int i = 1; i<=box_num;i++){
			cin>>cur_color;
			if(cur_color!=former_color){
				box_index++;
				box_list[box_index].color=cur_color;
				box_list[box_index].len=1;
				former_color=cur_color;
			}else{
				box_list[box_index].len++;
			}
		}
		memset(score,0,sizeof(score)); 
		cout<<"Case "<<j<<": "<<click_box(1,box_index,0)<<endl;
	}
	return 0;
}
