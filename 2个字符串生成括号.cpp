#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int cnt=0;
stack<char> s; 
string left_str,right_str;
void print_s(){
	
}
void rec(bool left_str_or_right_str, int i, int j){
	bool pair = 0;
	
	if(!s.empty()&&left_str_or_right_str==0&&left_str[i]==')' && s.top()=='('){
		s.pop();
		pair=1;	
	}
	else if(!s.empty()&&left_str_or_right_str==1&&right_str[j]==')' && s.top()=='('){
		s.pop();
		pair=1;			
	}else{
		char pushed = left_str_or_right_str?right_str[j]:left_str[i];
		s.push(pushed);
	}
			
	if(i==left_str.size()-1 && j==right_str.size()-1&&s.empty()){
		cnt++;
	}
	
	if(i+1<left_str.size())
		rec(0,i+1,j);
	if(j+1<right_str.size())
		rec(1,i,j+1);
	
	if(pair)
		s.push('(');
	else 
		s.pop();
	
}
int main(int argc, char *argv[]) {
	left_str = "(()";
	right_str = "())";
	rec(0,0,-1);
	rec(1,-1,0);
	cout<<"result:"<<cnt;
	return 0;
}
