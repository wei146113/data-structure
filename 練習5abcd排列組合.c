#include <stdio.h>
#include <stdlib.h>

void perm(char*, int, int);
void mySwap(char*, int, int);

int main (){
	char list[80]={0};
	int i,n;
	
	printf("Input a number: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		list[i]='a'+i;
	
	perm(list, 0, n-1);
	
	return 0;
} 

void perm(char *list, int begin, int end)
{
	int i;
	if(begin==end)
	{
		for(i=0;i<=end;i++)
		{
			printf("%c",list[i]);
		}
		printf("\n");		
	}
	else
	{
		for(i=begin;i<=end;i++)
		{
			mySwap(list, i, begin);
			perm(list, begin+1, end);
			mySwap(list, i, begin);
		}
	}
}

void mySwap(char *list, int current, int begin)
{
	char temp;
	temp=list[current];
	list[current]=list[begin];
	list[begin]=temp;

	return;	
}
