#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int matrix[9];
int zero_pos;//空格的位置
int i,j;//所用到的变量
int step_count=0;//步数 
void print();
int find_zero()//判断空格位置
{
	step_count = 0;
	for(i=0;i<9;i++)
	{
		if(matrix[i]==0)
			return zero_pos = i;
	}
}
void switch_position(int x,int y)//交换x,y位置的两个数 
{
	print();
	swap(matrix[x],matrix[y]);
	zero_pos=y;
	step_count++;
}
void step1()
{
	if((matrix[2]!=0)&&matrix[2]!=1)
		return;
	else 
	{
		int move_direction1[8]={2,1,4,3,6,7,8,5};
		for(i=0;i<8;i++)
		{	
			if(move_direction1[i]==zero_pos)
			{
				while(matrix[2]==0||matrix[2]==1)
				{
					switch_position(move_direction1[i%8],move_direction1[(i+1)%8]);
					i++;
				}
				break;
			}
		}
	}
	return;
}
void step2()
{
	int move_direction2[8]={0,3,6,7,8,5,4,1};
	for(i=0;i<8;i++)
	{	
		if(move_direction2[i]==zero_pos)
		{
			while(matrix[0]!=1)
			{
				switch_position(move_direction2[i%8],move_direction2[(i+1)%8]);
				i++;
			}
			break;
		}
	}
}		
void step3()
{
	int move_direction3[8]={2,1,4,3,6,7,8,5};
	for(i=0;i<8;i++)
	{	
		if(move_direction3[i]==zero_pos)
		{
			while(matrix[1]!=2)
			{
				switch_position(move_direction3[i%8],move_direction3[(i+1)%8]);
				i++;
			}
			break;
		}
	}
}
void step4()
{	
	int move_direction4[6]={5,4,3,6,7,8};
	for(i=0;i<6;i++)
	{	
		if(move_direction4[i]==zero_pos)
		{
			while((matrix[4]!=3))
			{
				switch_position(move_direction4[i%6],move_direction4[(i+1)%6]);
				i=(i+1)%6;
			}
			while(zero_pos!=3)
			{
				switch_position(move_direction4[i%6],move_direction4[(i+5)%6]);
				i=(i+5)%6;
			}
			break;
		}
	}
}
void step5()
{
	int move_direction5[9]={3,0,1,4,5,2,1,0,3};
	i=0;
	do
	{
		switch_position(move_direction5[i],move_direction5[i+1]);
		i++;
	}
	while(zero_pos!=3);
}
void step6()
{
	int move_direction4[6]={5,4,3,6,7,8};
	for(i=0;i<6;i++)
	{
		if(move_direction4[i]==zero_pos)
		{
			while(matrix[5]!=4)
			{
				switch_position(move_direction4[i%6],move_direction4[(i+1)%6]);
				i++;
			}
			if(zero_pos==8)
				switch_position(8,7);
			break;
		}
	}
	return;
}
void step7()
{
	int move_direction7[4]={3,6,7,4};
	for(i=0;i<4;i++)
	{	
		if(move_direction7[i]==zero_pos)
		{
			while(matrix[4]!=5)
			{
				switch_position(move_direction7[i%4],move_direction7[(i+1)%4]);
				i=(i+1)%4;
			}
			while(zero_pos!=3)
			{
				switch_position(move_direction7[i%4],move_direction7[(i+3)%4]);
				i=(i+3)%4;
			}
			break;
		}
	}
}
void step8()
{
	int move_direction81[13]={3,0,1,2,5,4,7,8,5,2,1,0,3};
	i=0;
	do
	{
		switch_position(move_direction81[i],move_direction81[i+1]);
		i++;
	}
	while(zero_pos!=3);
}
void step9()
{
	int move_direction7[4]={3,6,7,4};
	for(i=0;i<4;i++)
	{
		if(move_direction7[i]==zero_pos)
		{
			while(matrix[7]!=6)
			{
				switch_position(move_direction7[i%4],move_direction7[(i+1)%4]);
				i=(i+1)%4;
			}	
			while(zero_pos!=4)
			{
				switch_position(move_direction7[i%4],move_direction7[(i+3)%4]);
				i=(i+3)%4;
			}
			break;
		}	
	}	
}
void print()
{
	for(j=0;j<9;j++)
	{
		if(matrix[j]==0)
			printf(" \t");
		else
			printf("%d\t",matrix[j]);
		if((j+1)%3==0)
		printf("\n");
	}
	printf("Step %d \n",step_count);
}

int main()
{
	while(1){
		printf("Input your data：\n");
		for(i=0;i<9;i++)
			scanf("%d",&matrix[i]);
		find_zero();
		step1();
		step2();
		step3();
		if(matrix[2]!=3)
		{
			step4();
			step5();
		}
		step6();
		if(matrix[8]!=5)
		{
			step7();
			step8();
		}
		step9();
		print();
		if(!((matrix[3]==8)&&(matrix[6]==7)))
				printf("Error！\n");		
	}
	return 0;
}

