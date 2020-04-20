#include<stdio.h>
#include<stdlib.h>

#define MAX 80
enum mytype{val, oper};
enum precedence {
	add=0,
	sub=0,
	mult=1,
	division=1
};
struct data
{
	mytype type;
	int value;
	char oper;
	precedence pre;
};

struct MyStack
{
	int top;
	data a[MAX]; 
	bool IsEmpty();
	bool IsFull();
	void Push(data da);
	data Pop();
	data Top();
	
	MyStack()
	{
		top=-1;
	}
};


bool MyStack::IsEmpty()
{	
	if(top==-1)
		return true;
	else
		return false;	
}

bool MyStack::IsFull()
{
	if(top==MAX-1)
		return true;
	else
		return false;
}

void MyStack::Push(data da)
{
	if(IsFull()==true)
		printf("Stack is full. Cannot Push any element.\n");
	else
	{
		top++;
		a[top]= da;
	}	
}

data MyStack::Pop()
{
	if(IsEmpty()==true)
	{
		printf("Stack is Empty. Cannot pop any element.\n");
	}
	
	else
	{
		return a[top--];
	}
}
data MyStack::Top() 
{
	if(IsEmpty()==true) 
		printf("The STACK is empty") ; 
	else
		return a[top] ;
}

