#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string>
#define MAXIN 75
char board[MAXIN+2][MAXIN+2]={' '};
int minstep,w,h,to[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool mark[MAXIN+2][MAXIN+2];
using namespace std;
void Search(int now_x,int now_y,int end_x,int end_y,int step,int f);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//int main(int argc, char** argv) {//我写的输入,有错误 
//	int row_len,col_len,x,y,i,j,x1,y1,x2,y2;
//	char card[MAXIN+2];
//	string str;
//	int count=1,Boardnum=1;
//	while(1){ 
//		cin>>col_len>>row_len;
//		if(col_len+row_len==0){
//			break;
//		}
//		w=col_len;
//		h=row_len;
//		printf("Board #%d:\n", Boardnum);
//		getchar();
//		for(i=1;i<=row_len;i++){
//			getline(cin,str);
//			for(j=1;j<=col_len;j++){
//				//cout<<i<<j<<endl;
//				board[i][j]=str[j-1];
//				//cout<<"读入一行"<<str<<endl; 
//			
//			}
//		}
//
////		for(i=1;i<=row_len;i++){
////			for(j=1;j<=col_len;j++){
////				cout<<board[i][j];
////				//cout<<"读入一行"<<str<<endl; 
////			
////			}
////			cout<<endl;
////		}
//	//	cout<<233<<board[2][2];
//		while(1){
//			cin>>x1>>y1>>x2>>y2;
//			if (x1+y1+x2+y2==0){
//				break;
//			}
//			 
//			minstep=1000000;
//			memset(mark, false, sizeof(mark));
//			Search(x1,y1+1,x2,y2,1,0);
//			Search(x1+1,y1,x2,y2,1,1);
//			Search(x1,y1-1,x2,y2,1,2);
//			Search(x1-1,y1,x2,y2,1,3);
//			//cout<<minstep<<endl;
//			if(minstep < 100000)printf("Pair %d: %d segments.\n", count, minstep);
//			else printf("Pair %d: impossible.\n", count);
//			count++;
//		}
//		cout<<endl;
//		count=0;
//		for(i=1;i<=row_len;i++){
//			for(j=1;j<=col_len;j++){
//				//cout<<i<<j<<endl;
//				board[i][j]=' ';			
//			}
//		}
//	}
//	
//	return 0;
//}
int main(int argc, char** argv) {//正确的输入 
	int i,j,x1,y1,x2,y2,b=0,p;
    while(scanf("%d %d",&w,&h)==2&&w&&h){
        p=0;
        for(i=0;i<77;i++)
            board[i][0]=board[0][i]=' ';
        for(i=1;i<h+1;i++){
            getchar();
            for(j=1;j<w+1;j++)
                board[i][j]=getchar();
        }
        for(i=0;i<w+1;i++)
            board[h+1][i+1]=' ';
        for(i=0;i<h+1;i++)
            board[i+1][w+1]=' ';


        printf("Board #%d:\n",++b);
        while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2)==4&&x1){
            memset(mark,0,sizeof(mark));
            minstep=9999;
            Search(x1,y1+1,x2,y2,1,0);
			Search(x1+1,y1,x2,y2,1,1);
			Search(x1,y1-1,x2,y2,1,2);
			Search(x1-1,y1,x2,y2,1,3);
            if(minstep==9999)
            printf("Pair %d: impossible.\n",++p);
            else printf("Pair %d: %d segments.\n",++p,minstep);
        }
    printf("\n");
    }
	
	return 0;
}
void Search(int now_x,int now_y,int end_x,int end_y,int step,int f){
	if(step>minstep){
		return;
	}
	if(!(now_x>-1&&now_y>-1&&now_x<w+2&&now_y<h+2)){
		//cout<<"越界";
		return;
	} 
	if(now_x==end_x&&now_y==end_y&&step<minstep&&board[now_y][now_x]=='X'){
		minstep=step;
		return;
	}
//	cout<<step<<board[now_y][now_x]<<mark[now_y][now_x]<<now_x<<now_y<<endl;
//	if(now_x==0&&now_y==2){
//		bool test;
//		test = (board[now_y][now_x]==' ');
//		cout<<"hahah"<<int(board[now_y][now_x])<<test<<endl;
//	}
	
	if((board[now_y][now_x]==' '||board[now_y][now_x]=='\0')&&mark[now_y][now_x]==false){
		int temp_f=0;
		
		for(temp_f=0;temp_f<=3;temp_f++){
			int new_x = now_x + to[temp_f][0]; //得到新的位置
			int new_y = now_y + to[temp_f][1];
			mark[now_y][now_x]=true;
//			if(new_x==0&&new_y==2){
//				cout<<"hahah"<<endl;
//			}
			if(temp_f!=f){
				Search(new_x,new_y,end_x,end_y,step+1,temp_f);
			}else{
				Search(new_x,new_y,end_x,end_y,step,temp_f);
			}
			mark[now_y][now_x]=false;
		}
	} 

}
