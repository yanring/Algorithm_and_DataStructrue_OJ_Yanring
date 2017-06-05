#include <iostream>
#include <stack> 
#include <cstring>
#include <map>
#include <cctype>
/*author : yanzijie */
using namespace std;
stack<bool> stack_val;
stack<char> stack_op;
map<char,int> priority_table;
void stack_pop(){//运算
	char op = stack_op.top();
	stack_op.pop();
	if(op=='-'){//取反单独处理 
		bool val1 = stack_val.top();
		stack_val.pop();
		stack_val.push(!val1);		
	}else{
		bool val1 = stack_val.top();
		stack_val.pop();
		bool val2 = stack_val.top();
		stack_val.pop();
		switch (op){
			case '&':stack_val.push(val1&&val2);break;
			case '|':stack_val.push(val1||val2);break;
			case '>':stack_val.push(val2?val1:1);break;
			case '=':stack_val.push((!val1&&!val2)||(val1&&val2));break;
		} 		
	}
}
bool cal(string expr){
	for(int i = 0; i<expr.length();i++){//符号与值入栈 
		if(expr[i]=='0'||expr[i]=='1'){
			stack_val.push(expr[i]-'0');
		}else{//出栈的规则类似于四则运算 
			if(priority_table[expr[i]]>priority_table[stack_op.top()]) 
				stack_op.push(expr[i]);
			else{
				stack_pop();
				i--;
			}
		}
	}
	while(stack_op.top()!='#'){
		stack_pop();
	}
	return stack_val.top();
}
void gen_expr(string original_expr,int index){
	
	while(!isalpha(original_expr[index])){
		if(index==original_expr.length()){
			for(int i = 0; i<original_expr.length();i++){
				if(original_expr[i]=='0'||original_expr[i]=='1'){
					cout<<original_expr[i]<<'\t';
				}
			}			
			cout<<cal(original_expr)<<endl;
			return;
		}
		index++; 
	}
	if(index<original_expr.length()){//dfs 
		original_expr[index]='0';
		gen_expr(original_expr,index);
		original_expr[index]='1';
		gen_expr(original_expr,index);
	}	
}
int main(int argc, char** argv) {
	stack_op.push('#');//初始化栈底 
	priority_table['-']=5;
	priority_table['&']=4;
	priority_table['|']=3;
	priority_table['>']=2;
	priority_table['=']=1;
	priority_table['#']=0;
	string expr;
	cin>>expr;
	for(int i = 0; i<expr.length();i++){
		if(isalpha(expr[i]))
			cout<<expr[i]<<'\t';
	}
	cout<<"result"<<endl;		
	gen_expr(expr,0);
	return 0;
}
