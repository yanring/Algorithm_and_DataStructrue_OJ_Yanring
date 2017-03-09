#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
using namespace std; 
char str[200];
class operator_stack{
	char op[10001];
	int top ;
	public:	
	operator_stack(){
		op[0]='#';
		top = 0;
	}
	char pop(){
		return op[top--];
	}
	void push(char c){
		op[++top]=c;
	}
	char top_op(){
		return op[top];
	}
	 
};
class number_stack{
	double num[10001];
	int top ;
	public:	
	number_stack(){
		num[0]=0;
		top = 0;
	}
	double pop(){
		return num[top--];
	}
	void push(double c){
		num[++top]=c;
	}
};
double str2double(int start,int end){
	double res = 0;
	int DotPos = end;
	for(int i = start ; i <= end ; i++){
		if(str[i]=='.'){
			DotPos = i;
			continue;
		}
		res = res+(str[i]-'0');
		res*=10;
	}
	res/=10;
	res = res / pow(10,end-DotPos);
	return res;
}
double cal(char op,double num1,double num2){
	switch(op){
		case '*':return num1*num2;
		case '+':return num1+num2;
		case '/':return num1/num2;
		case '-':return num1-num2;
	}
	return 99999999; 
}
bool cmp_op(char op, char top_op){//
	if(top_op=='#')
		return true;
	else if(op==')'&&top_op=='(')
		return true;
	else if(op=='(')
		return true;
	else if(op=='*'||op=='/'||op=='^')
		return true;
	else if(top_op=='(')
		return true;
	else 
		return false;
}
double exp2num(string str){
	double temp_num;
	int start = 0 , end = 0;
	operator_stack op_stack;
	number_stack num_stack;
	for(int i = 0; i<str.length();i++){
		if(((str[i]<='Z'&&str[i]>='A'||str[i]<='z'&&str[i]>='a'))){
			srand(str[i]);
			num_stack.push(rand());
		}else if(start == 0 && ((str[i]<='9'&&str[i]>='0'||str[i]=='.'))){
			start = i;
			end = i;
			i++;
			while((str[i]<='9'&&str[i]>='0'||str[i]=='.')&&i<str.length()){
				end++;
				i++;
			}
			num_stack.push(str2double(start,end));
			start = end = 0;
			i--;
			continue;
		}else if(str[i]=='	'||str[i]==' '){
			continue;
		}else{
			char op = str[i];
			char top_op = op_stack.top_op();
			while(!cmp_op(op,top_op)){
				temp_num=cal(op_stack.pop(),num_stack.pop(),num_stack.pop());
				num_stack.push(temp_num);
				top_op = op_stack.top_op();
			}
			if(op==')'){
				op_stack.pop();
			}else{
				op_stack.push(op);
			}
		}
	}
	while(op_stack.top_op()!='#'){
		temp_num=cal(op_stack.pop(),num_stack.pop(),num_stack.pop());
		num_stack.push(temp_num);
	}
	return num_stack.pop();
}
int main(int argc, char** argv) {
	int N;
	cin>>N;
	getchar();
	double num1,num2;
	for(int i = 1; i<=N ;i++){
		gets(str);
//		gets(str);
		num1 = exp2num(str);
		gets(str);
		num2 = exp2num(str);
		if(num1 == num2){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
}
