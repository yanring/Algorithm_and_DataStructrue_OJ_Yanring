#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Privilege {
	public:
	string name;
	int level;
	Privilege(string in_name,int in_level){
		name=in_name;
		level=in_level;
	}
	Privilege(){
	}
	void read(){
		cin>>name;
		if(name[name.length()-2]==':'){
			level = name[name.length()-1]-'0';
			name = name.substr(0,name.length()-2);
		}else{
			level = -1;
		}
	} 
};
struct Role {
	string name; 
	int num_privileges;
	Privilege privileges[12];
	int i;
	void read(){
		cin>>name;
		cin>>num_privileges;
		for(i = 1; i <=num_privileges;i++){
			privileges[i].read();
		}
	}
};
int num_privileges,num_roles,num_users,num_tests;
Role roles[102];
struct User {
	string name;
	int num_role;
	int j;
//	Privilege privileges[102];
	Role User_roles[11];
	void read(){
		cin>>name;
		cin>>num_role;
//		cout<<name<<" "<<num_role<<endl;
		Role temp_role;
		string temp_role_name;
		for(int j = 1; j <=num_role;j++){
			cin>>temp_role_name;
//			cout<<"role:"<<temp_role_name<<endl;
			User_roles[j] = find_role(temp_role_name);
//			for(int j = 1 ; j<=temp_role.num_privileges;j++){
//				add_privilege();
//			}
		}
		
	}
	int k;
	Role find_role(const string &role_name){
//		cout<<role_name<<"233"<<endl;
		for (k = 1; k<=num_roles ; k++){
			if(roles[k].name == role_name){
				return roles[k];
			}
		}
		cout<<"error"<<endl; 
		return roles[101];
	}

};
User users[102];
void test(){
	string user_name;
	cin>>user_name;
	User temp_user;
	Privilege temp_pri;
	int max_level=-2,flag=0;
	for(int i = 1 ; i<=num_users;i++){
		if(users[i].name == user_name){
			temp_user = users[i];
			break;
		}
	}
	temp_pri.read();
	for(int i = 1; i<=temp_user.num_role;i++){
		for(int j = 1; j<=temp_user.User_roles[i].num_privileges;j++){
			if(temp_user.User_roles[i].privileges[j].name==temp_pri.name){
				if(temp_user.User_roles[i].privileges[j].level>max_level){
					max_level=temp_user.User_roles[i].privileges[j].level;//记录最大的权限
					 
				}
			}
		}
	}
	if(max_level==-2||max_level<temp_pri.level){
		cout<<"false"<<endl;
		return; 
	}
	if(temp_pri.level!=-1){
		cout<<"true"<<endl;
		return;
	}
	if(temp_pri.level==-1&&temp_pri.level==max_level){
		cout<<"true"<<endl;
		return;
	}
	if(temp_pri.level==-1){
		cout<<max_level<<endl;
	}
//	if(max_level==-1&&)
//	cout<<temp_user.User_roles[1].name<<endl;
}
int main(int argc, char** argv) {
	int i;
	int temp_level;
	char tempchar;
	string temp_pri_name;
	Role s;
	Privilege original_privileges[102];
	
	cin>>num_privileges;
	for(int i = 1; i<=num_privileges;i++){
		original_privileges[i].read();
//		cout<<original_privileges[i].name<<endl;
	}
	cin>>num_roles;
	for(int i = 1; i<=num_roles;i++){
		roles[i].read();
	}
	
//	for(i = 1; i<=num_roles;i++){
//		cout<<roles[i].privileges[1].name<<endl;
//	}

	cin>>num_users;
	for(int i = 1; i<=num_users;i++){
		users[i].read();
	}
//	for(int i = 1; i<=num_users;i++){
//		cout<<users[i].User_roles[1].name;
//	}	
	cin>>num_tests;

	for(int i = 1; i<=num_tests;i++){
		test();
	} 
	return 0;
}

