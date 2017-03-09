#include <iostream>
using namespace std;//´øĞòºÅ,µİ¹é½â¾ö 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void hanoi(int n,char src,char mid,char dest,int index);
int main(int argc, char** argv) {
	int n;
	char src,mid,dest;
	cin>>n>>src>>mid>>dest; 
	hanoi(n,src,mid,dest,1);
	return 0;
}

void hanoi(int n,char src,char mid,char dest,int index){
	if(n == 1){
		cout<<index<<":"<<src<<"->"<<dest<<endl;
		return ;
	}
	
	hanoi(n-1,src,dest,mid,index);
	cout<<n<<":"<<src<<"->"<<dest<<endl;
	hanoi(n-1,mid,src,dest,index);
} 
