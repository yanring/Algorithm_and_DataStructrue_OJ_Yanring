#include <iostream>
using namespace std;
int main() {
	int a[101][1001];
	int t,m;
	int value[101],time[101];
	int i = 1;
	int j;
	cin>>t>>m;
	for(i = 1; i <= m ; i++ )
	{
		cin>>time[i]>>value[i];
	}
	for(i = 1; i <= m ; i++){
		for( j = 1; j <= t ; j++)
		{
			if(j>=time[i])
				a[i][j]=max(a[i-1][j],a[i-1][j-time[i]]+value[i]);
			else
				a[i][j]=a[i-1][j];
		}
	}
	cout<<a[m][t];
	return 0;
}
