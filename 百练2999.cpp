#include <iostream>  
#include <cstring> 
#include<stdio.h>
#include <algorithm>
using namespace std;
#define max(a, b)  (((a) > (b)) ? (a) : (b))
#define N 202
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//class LongestSubstring {
//public:
//    int findLongest(string s1, int n, string s2, int m) {
//        
//		int matrix[n+1][m+1];
//		int i,j;
//		int max=0; 
//		memset(matrix, 0, sizeof(matrix)); 	
//		for(int i=0;i<n;i++)  
//	      {  
//	            if(isupper(s1[i]))  
//	                  s1[i]=tolower(s1[i]);  
//	      }  
//	      for(int i=0;i<m;i++){ 
//	            if(isupper(s2[i]))  
//	                  s2[i]=tolower(s2[i]);  
//	      }  
//		for(i=1;i<=n;i++){
//			for(j=1;j<=m;j++){
//				if(s1[i-1]==s2[j-1]){				 
//					matrix[i][j]=matrix[i-1][j-1]+1;
//					if(matrix[i][j]>max){
//						max = matrix[i][j];
//					}				
//				}
//			}
//		}
//		return max;
//    }
//};

int main() {
	char s1[N],s2[N];
	int matrix[N][N];
	int i,j,len1,len2;
	int max=0;
	while(scanf("%s%s",s1,s2)!=EOF){	
//		cin>>s1>>s2;
		max = 0;
		memset(matrix, 0, sizeof(matrix)); 	
//		for(int i=0;i<strlen(s1);i++)  
//	      {  
//	            if(isupper(s1[i]))  
//	                  s1[i]=tolower(s1[i]);  
//	      }  
//	      for(int i=0;i<strlen(s2);i++){ 
//	            if(isupper(s2[i]))  
//	                  s2[i]=tolower(s2[i]);  
//	      }  

//		cout<<strlen(s2)<<strlen(s1)<<endl;  
		len1=strlen(s1);
		len2=strlen(s2);
		for(i=1;i<=len1;i++){
			for(j=1;j<=len2;j++){
				if(s1[i-1]==s2[j-1])				 
					matrix[i][j]=matrix[i-1][j-1]+1;
				else
					matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
			}
		}
		cout<<matrix[len1][len2]<<endl;
		
	}
//	LongestSubstring test; 
//	cout<<test.findLongest("1AB2345CD",9,"12345EF",7);
	return 0;
	
}

