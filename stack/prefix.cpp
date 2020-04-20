#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef enum {op, value} mytype ;
int operation(int,int,char);
struct data
{
	mytype type ;
	int value ;
	char oper ;
};

struct express
{
	int count;
	data item[80];
	express(char*);
	void Show();
};

struct mystack
{
	data a[MAX] ;
	int top ;

	bool IsEmpty() ;
	bool IsFull() ;
	void Push(data da) ;
	data Pop() ;
	data Top() ;
};
bool mystack::IsEmpty()
{
	if(top == -1)
		return true ;
	else
		return false ;
}
bool mystack::IsFull()
{
	if(top == MAX - 1)
		return true ;
	else
		return false ;
}
void mystack::Push(data da)
{
	if(IsFull())
		printf("The STACK is full") ;
	else
		a[++top] = da ;
}
data mystack::Pop()
{
	if(IsEmpty())
		printf("The STACK is empty") ;
	else
		return a[top--] ;
}
data mystack::Top()
{
	if(IsEmpty())
		printf("The STACK is empty") ;
	else
		return a[top] ;
}


int main()
{
	//¥Dµ{¦¡
	express myexp("123.txt");
	myexp.Show();
	system("PAUSE");
	return 0;
}

express::express(char* filename)
{
	FILE *fptr;
	fptr=fopen(filename, "r");
	count=0;
	char s[80];
	while(!feof(fptr))
	{
		fgets(s, 80, fptr);
		if(s[0]<='9'&& s[0]>='0')
		{
			item[count].type=value;
			item[count].value=atoi(s);
		}
		else
		{
			item[count].type=op;
			item[count].oper=s[0];			
		}
		count++;
	}

}

void express::Show()
{
	for(int i=0;i<count;i++)
	{
		if(item[i].type==value)
			printf("%d",item[i].value);
		else
			printf("%c", item[i].oper);
	}
	printf("\n");
}
