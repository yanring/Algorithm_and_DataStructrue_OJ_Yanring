#include <iostream>
#include <cstring>

bool puzzle[6][6];
bool temp_puzzle[6][6];
bool pressed[6][6];
int total_times =0;
int min_times = 17;
using namespace std;	 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void press(int i,int j){
	pressed[i][j]=1;
	total_times++;
	temp_puzzle[i][j-1] = !temp_puzzle[i][j-1];
	temp_puzzle[i][j] = !temp_puzzle[i][j];
	temp_puzzle[i][j+1] = !temp_puzzle[i][j+1];
	temp_puzzle[i-1][j] = !temp_puzzle[i-1][j];
	temp_puzzle[i+1][j] = !temp_puzzle[i+1][j];
}
void flip_first_line(int code){
	if(code%2==1){
		press(1,4);
	}
	if((code/2)%2==1){
		press(1,3);
	}
	if((code/4)%2==1){
		press(1,2);
	}
	if((code/8)%2==1){
		press(1,1);
	}

} 

int bfs_black(){
	for(int code = 0 ; code <= 15 ; code++){
		memcpy(temp_puzzle,puzzle,sizeof(puzzle));
		flip_first_line(code);
		
		for(int row = 1; row <= 3; row ++){
			for(int col = 1 ;  col <= 4; col++){
				if (temp_puzzle[row][col]==1){
					press(row+1,col);
				}
			}
		}

		if((temp_puzzle[4][1]+temp_puzzle[4][2]+temp_puzzle[4][3]+temp_puzzle[4][4])==0){
			min_times = min(min_times,total_times);
		}
		//memset(pressed,0,sizeof(pressed));
		total_times = 0;
	}
	return 0;
}

int bfs_white(){
	for(int code = 0 ; code <= 15 ; code++){
		memcpy(temp_puzzle,puzzle,sizeof(puzzle));
		flip_first_line(code);
		
		for(int row = 1; row <= 3; row ++){
			for(int col = 1 ;  col <= 4; col++){
				if (temp_puzzle[row][col]==0){
					press(row+1,col);
				}
			}
		}

		if((temp_puzzle[4][1]+temp_puzzle[4][2]+temp_puzzle[4][3]+temp_puzzle[4][4])==4){
			//memset(pressed,0,sizeof(pressed));
			min_times = min(min_times,total_times);
			
		}
		total_times = 0 ;
		memset(pressed,0,sizeof(pressed));
	}
	return 0;
}
int main(int argc, char** argv) {
	int times,ans1,ans2;
	char c; 
	times = 1;
	for(int l = 1 ; l <= times ; l++){
		memset(pressed,0,sizeof(pressed));
		for (int i = 1 ; i <= 4 ; i++){
			for (int j = 1 ; j <= 4 ; j++){
				cin>>c;
				if(c == 'w'){
					puzzle[i][j] = 1;
				}
			}
		}
		ans1 = bfs_white();
		total_times= 0 ;
		memset(pressed,0,sizeof(pressed));
		ans2 = bfs_black();
		if(min_times == 17){
			cout<<"Impossible"<<endl;
			return 0; 
		}
		cout<<min_times<<endl;
	}
	return 0;
}
