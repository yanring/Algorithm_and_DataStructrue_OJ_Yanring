#include <iostream>
#include <cstring>

bool puzzle[6][8];
bool temp_puzzle[6][8];
bool pressed[6][8];
using namespace std;	 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void press(int i,int j){
	pressed[i][j]=1;
	temp_puzzle[i][j-1] = !temp_puzzle[i][j-1];
	temp_puzzle[i][j] = !temp_puzzle[i][j];
	temp_puzzle[i][j+1] = !temp_puzzle[i][j+1];
	temp_puzzle[i-1][j] = !temp_puzzle[i-1][j];
	temp_puzzle[i+1][j] = !temp_puzzle[i+1][j];
}
void flip_first_line(int code){
	if(code%2==1){
		press(1,6);
	}
	if((code/2)%2==1){
		press(1,5);
	}
	if((code/4)%2==1){
		press(1,4);
	}
	if((code/8)%2==1){
		press(1,3);
	}
	if((code/16)%2==1){
		press(1,2);
	}
	if((code/32)%2==1){
		press(1,1);
	}
} 

int bfs(){
	for(int code = 0 ; code <= 63 ; code++){
		memcpy(temp_puzzle,puzzle,sizeof(puzzle));
		flip_first_line(code);
		
		for(int row = 1; row <= 4; row ++){
			for(int col = 1 ;  col <= 6; col++){
				if (temp_puzzle[row][col]==1){
					press(row+1,col);
				}
			}
		}

		if((temp_puzzle[5][1]+temp_puzzle[5][2]+temp_puzzle[5][3]+temp_puzzle[5][4]+temp_puzzle[5][5]+temp_puzzle[5][6])==0){
			
			return 1;	
		}
		memset(pressed,0,sizeof(pressed));
	}
	return 0;
}
int main(int argc, char** argv) {
	int times;
	cin>>times;
	for(int l = 1 ; l <= times ; l++){
		memset(pressed,0,sizeof(pressed));
		for (int i = 1 ; i <= 5 ; i++){
			for (int j = 1 ; j <= 6 ; j++){
				cin>>puzzle[i][j];
			}
		}
		memcpy(temp_puzzle,puzzle,sizeof(puzzle));
		if(bfs()){
			cout<<"PUZZLE #"<<l<<endl;
			for (int i = 1 ; i <= 5 ; i++){
				for (int j = 1 ; j <= 6 ; j++){
					cout<<pressed[i][j];
					if(j==6){
						cout<<endl;
					}else{
						cout<<' ';
					}
				}
			}
		}
	}
	return 0;
}
