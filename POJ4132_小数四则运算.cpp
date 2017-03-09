#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std; 
string str;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
	else if(op=='*'||op=='/')
		return true;
	else if(top_op=='(')
		return true;
	else 
		return false;
}
int main(int argc, char** argv) {
	double temp_num;
	int start = 0 , end = 0;
	cin >> str;
	operator_stack op_stack;
	number_stack num_stack;
	for(int i = 0; i<str.length();i++){
		if(start == 0 && ((str[i]<='9'&&str[i]>='0'||str[i]=='.'))){
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
	cout<<setprecision(2) <<std::fixed <<num_stack.pop()<<endl;
	return 0;
}