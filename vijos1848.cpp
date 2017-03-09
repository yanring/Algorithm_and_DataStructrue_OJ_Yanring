#include <iostream>
using namespace std;


int main() {
	int max,num;
	cin >>max>>num;
	int times = 0 ;
	int i = 0;
	int j;
	for(i;i<=max;i++)
	{
		for(j=i;j>0;){
			if(j%10==num)
			times++;
			j=j/10;
		}
	}
	cout << times;

	return 0;
}
