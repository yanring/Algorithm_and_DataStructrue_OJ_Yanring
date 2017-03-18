#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string str;
	
	int now=0,MAX=1,f_MAX=1,f_now=0;
	while(cin>>str){
		f_now = now = 0;
		f_MAX = MAX = 1;
		for(int i = 0 ; i < str.size() ; i++){
			if(str[i]=='d'){
				now++;
			}				
			else if(str[i]=='u'){
				if(str[i+1]=='u'){
					now--;
					while(str[i+1]=='u'){
						now--;
						i++;
					}						
				}					
				else if(str[i+1]=='d'){
					now++;
					i++;
				}
			}
			MAX = max(now,MAX);
		}
		for(int i = 0 ; i < str.size() ; i++){
			if(str[i]=='d'){
				f_now++;
			}				
			else if(str[i]=='u'){
				f_now--;
			}
			f_MAX = max(f_now,f_MAX);
		}
		cout<<f_MAX<<" => "<<MAX<<endl;
	} 
	return 0;
}
