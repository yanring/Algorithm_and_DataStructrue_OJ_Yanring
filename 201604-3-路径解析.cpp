#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std; 
#define MAX 1077952576
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N;
vector<string> init_address,now_address; 
vector<string> decode(string str){
	vector<string> temp;
	string temp_name; 
	for(int i = 1 ; i < str.size(); i++){
		if(str[i]=='/'){
			if(temp_name!=""){
				if(temp_name == ".."){
					if(!temp.empty())
						temp.erase(temp.end());
					temp_name = "";
				}else if(temp_name == "."){
					temp_name = "";
				}else{
					temp.push_back(temp_name);
					temp_name = "";
				}				
			}			
		}else{
			temp_name+=str[i];
		}			
	} 
	if(temp_name!="")
		temp.push_back(temp_name);
	return temp;
}
vector<string> decode_xiangdui(string str){
	vector<string> temp = init_address;
	string temp_name; 
	for(int i = 0 ; i < str.size(); i++){
		if(str[i]=='/'){
			if(temp_name!=""){
				if(temp_name == ".."){
					if(!temp.empty())
						temp.erase(temp.end());
					temp_name = "";
				}else if(temp_name == "."){
					temp_name = "";
				}else{
					temp.push_back(temp_name);
					temp_name = "";
				}				
			}			
		}else{
			temp_name+=str[i];
		}			
	}
	if(temp_name!="")
		temp.push_back(temp_name);
	return temp;
}
void output(vector<string> address){
	for(vector<string>::iterator i = address.begin();i!=address.end();i++){
		cout<<'/'<<*i;
	}
	if(address.empty()){
		cout<<'/';
	}
	cout<<endl;
}
int main(int argc, char** argv) {
	cin>>N;
	string str;
	char str2[2000];
	cin>>str;
	getchar();
	init_address = decode(str);
	
	for(int i = 1; i<= N ; i++){
		getline(cin,str);
		if(str[0]=='/'){//绝对路径 
			now_address = decode(str); 
			output(now_address);
		}else{//相对路径 
			now_address = decode_xiangdui(str); 
			output(now_address);
		} 
	}
	return 0; 
}
