#include <iostream>
using namespace std;//´øĞòºÅ,µİ¹é½â¾ö
void hanoi(int n,char src,char mid,char dest);
int main(int argc, char** argv) {
	int n;
	char src,mid,dest;
	cin>>n>>src>>mid>>dest; 
	hanoi(n,src,mid,dest);
	return 0;
}

void hanoi(int n,char src,char mid,char dest){
	if(n == 1){
		cout<<n<<":"<<src<<"->"<<dest<<endl;
		return ;
	}
	
	hanoi(n-1,src,dest,mid);
	cout<<n<<":"<<src<<"->"<<dest<<endl;
	hanoi(n-1,mid,src,dest);
} 
