#include <iostream>
#include <string.h>
using namespace std; 
string string1,string2;
void search(string str1,string str2){
	char root = str1[0];
	int root_index = str2.find(root);
	int len = str2.length()-1-root_index;
	if(str1.length()>1){
	search(str1.substr(1,root_index),str2.substr(0,root_index));
	search(str1.substr(root_index+1,len),str2.substr(root_index+1,len));	
	}
	if(root>='A'&&root<='Z')
		cout<<root;	
}
int main(int argc, char** argv) {
	while(cin>>string1){
		cin>>string2;
		search(string1.substr(0,string1.length()),string2.substr(0,string1.length()));
		cout<<endl;
	}
	return 0;
}
