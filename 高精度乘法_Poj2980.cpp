#include <iostream>
#include <cstring>
using namespace std;  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int len1=0,len2=0,res[402],num1[201],num2[201],temp_res[402],temp_jinwei[202];
void read(){
	string str1,str2;
	cin>>str1>>str2;
	len1 = str1.length();
	len2 = str2.length();
	for(int i = len1 ; i >= 1 ; i--){
		num1[len1-i+1] = str1[i-1]-'0';
	}
	for(int i = len2 ; i >= 1 ; i--){
		num2[len2-i+1] = str2[i-1]-'0';
	}
}
void BigMulSmall(int SmallNum,int index){//num1乘一个小数 ,index 是这个数后面有几个0 
	int temp_num=0,jinwei=0;
	memset(temp_jinwei,0,sizeof(temp_jinwei));
	memset(temp_res,0,sizeof(temp_res));
	for(int i = 1 ; i <= len1 ; i++){
		temp_num = num1[i]*SmallNum;
		temp_res[i+index] = temp_num%10;
		temp_jinwei[i+1] = temp_num/10;
	}
	for(int i = 2 ; i <= (len1+1) ; i++){
		temp_res[i+index] = temp_res[i+index]+temp_jinwei[i]+jinwei;
		if(temp_res[i+index]>=10){
			temp_res[i+index] = temp_res[i+index] % 10;
			jinwei = 1;
		}else{
			jinwei = 0;
		}
	}
	
}
void res_add_temp_res(){
	int len=0,jinwei=0;
	for(int i = 401 ; i >= 1 ; i --){
		if(res[i]||temp_res[i]){
			len = i;
			break;
		}
	}
	for(int i = 1; i <= (len+1) ; i++){
		res[i] = temp_res[i] + res[i] + jinwei;
		if(res[i]>=10){
			jinwei = res[i]/10;
			res[i] = res[i]%10;
		}else{
			jinwei = 0;
		}
	}
} 
void mul(){
//	for(int i = 1; i <= len2 ; i++){
//		BigMulSmall(num2[i],i-1);
//		res_add_temp_res();
//	}
	int jinwei = 0;
	for(int i = 1; i<=len1; i++){
		jinwei = 0;
		for(int j = 1; j<=len2;j++){
			res[i+j-1] = res[i+j-1]+num1[i]*num2[j]+jinwei;
			jinwei = res[i+j-1]/10;
			res[i+j-1] = res[i+j-1]%10;
		}
		res[i+len2]=jinwei;
	}
}
int main(int argc, char** argv) {
	memset(res,0,sizeof(res));
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));
	read();
//	BigMulSmall(4,2);
	mul();
	int len=1;
	for(int i = 401 ; i >= 1 ; i --){
		if(res[i]){
			len = i;
			break;
		}
	}
	for(int i = len ; i >=1 ; i--){
		cout<<res[i];
	}
	cout<<endl;
	return 0;
}



/*#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	char	a1[300], b1[300];
	int	a[300], b[300], c[601], lena, lenb, lenc, x, i, j;
	memset( a, 0, sizeof(a) );
	memset( b, 0, sizeof(b) );
	memset( c, 0, sizeof(c) );
	gets( a1 ); gets( b1 );
	lena = strlen( a1 ); lenb = strlen( b1 );
	for ( i = 0; i <= lena - 1; i++ )
		a[lena - i] = a1[i] - 48;
	for ( i = 0; i <= lenb - 1; i++ )
		b[lenb - i] = b1[i] - 48;
	for ( i = 1; i <= lena; i++ )
	{
		x = 0;
		for ( j = 1; j <= lenb; j++ )
		{
			c[i + j - 1]	= a[i] * b[j] + x + c[i + j - 1];
			x		= c[i + j - 1] / 10;
			c[i + j - 1]	%= 10;
		}
		c[i + lenb] = x;
	}
	lenc = lena + lenb;
	while ( (c[lenc] == 0) && (lenc > 1) )
		lenc--;
	for ( i = lenc; i >= 1; i-- )
		cout << c[i];
	cout << endl;
}*/
