#include <iostream>
#include <cstring>
using namespace std;
char score_borad[60000];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void cal_11(int len){
	int w_score=0,l_score=0,w_total=0,l_total=0;
	for(int i = 1; i <= len ; i++){
		switch(score_borad[i]){
			case 'W':w_score++;break;
			case 'L':l_score++;break;
		}			
		if(w_score>=11&&(w_score>=(l_score+2))){
			w_total++;
			cout<<w_score<<":"<<l_score<<endl;
			w_score=0;l_score=0;
		}else if(l_score>=11&&(l_score>=(w_score+2))){
			l_total++;
			cout<<w_score<<":"<<l_score<<endl;
			w_score=0;l_score=0;
		}
	}
	cout<<w_score<<":"<<l_score<<endl;
}
void cal_21(int len){
	int w_score=0,l_score=0,w_total=0,l_total=0;
	for(int i = 1; i <= len ; i++){
		switch(score_borad[i]){
			case 'W':w_score++;break;
			case 'L':l_score++;break;
		}			
		if(w_score>=21&&(w_score>=(l_score+2))){
			w_total++;
			cout<<w_score<<":"<<l_score<<endl;
			w_score=0;l_score=0;
		}else if(l_score>=21&&(l_score>=(w_score+2))){
			l_total++;
			cout<<w_score<<":"<<l_score<<endl;
			w_score=0;l_score=0;
		}
	}
	cout<<w_score<<":"<<l_score<<endl;	
}
int main(int argc, char** argv) {
	char temp_char;
//	int w_score,l_score,w_total,l_total;
	int index = 1; 
	while((temp_char=getchar())!='E'){
		if(temp_char=='W'){
			score_borad[index]='W';
			index++;
		}else if(temp_char=='L'){
			score_borad[index]='L';
			index++;
		}
	}
	cal_11(index-1);
	cout<<endl;
	cal_21(index-1);
	return 0;
}
