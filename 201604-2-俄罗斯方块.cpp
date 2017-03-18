#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std; 
#define MAX 1077952576
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int matrix[20][20],sqare[5][5],col=0,row = 99;
int main(int argc, char** argv) {
	memset(matrix,0,sizeof(matrix));
	memset(sqare,0,sizeof(sqare));
	for(int x = 1; x<=15;x++){
		for(int y=1; y<=10;y++){
			cin>>matrix[x][y];
		}
	} 
	for(int x = 1; x<=4;x++){
		for(int y=1; y<=4;y++){
			cin>>sqare[x][y];
		}
	}
	cin>>col;
	for(int x = 1; x<=4;x++){
		for(int y=1; y<=4;y++){
			if(sqare[x][y]){
				int new_y = y+col-1;				
				int temp_x = 1;
				while(!matrix[temp_x][new_y]&&temp_x<=15){
					temp_x++;
				}
				int new_x = temp_x - x;
				row = min(row,new_x);
			}
		}
	}
	for(int x = 1; x<=4;x++){
		for(int y=1; y<=4;y++){
			matrix[row-1+x][col-1+y]+=sqare[x][y];
		}
	}
	for(int x = 1; x<=15;x++){
		for(int y=1; y<=10;y++){
			cout<<matrix[x][y]<<" ";
		}
		cout<<endl;
	} 
	return 0; 
}
