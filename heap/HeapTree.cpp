#include<stdio.h> 
#include<stdlib.h>
#define MAX 80
struct Queue
{
	int s[MAX];
	int front, rear;
	bool IsFull();
	bool IsEmpty();
	void Add(int);
	int Del();
	
	Queue()
	{
		front=-1;
		rear=-1;
	}
};
struct HeapTree
{
	int count;
	int node[MAX];
	HeapTree(const char*
	 filename);
	void Insert(int);
	void PrintArray();
	void DrawTree();
};
int MyPower(int, int);
void PrintSpace(int);

int main()
{
	HeapTree MyHeap("a.txt");
//	MyHeap.PrintArray();
	//MyHeap.DrawTree();
	MyHeap.Insert(21);
	//MyHeap.DrawTree();
	return 0;
}
HeapTree::HeapTree(const char*
 filename)
{
	FILE* fptr=fopen(filename,"r");
	int num;	
	count=1;
	for(int i=0;i<MAX;i++)
	{
		node[i]=0;
	}
	
	while(!feof(fptr))
	{
		fscanf(fptr,"%d",&num);
		
		Insert(num);
			
	}
}


void HeapTree::Insert(int num)
{
	printf("Insert number: %d\n",num);
	if(count==1)
	{
		node[count]	=num;
				
	}
	else
	{		
		int tmp=count;
		
		while(tmp>1)
		{			
			if(node[tmp/2]<num)
			{					
				node[tmp]=node[tmp/2];
				tmp=tmp/2;
			}
			else
				break;
		}
		node[tmp]=num;				
	}	
	count++;
	DrawTree();
}

void HeapTree::PrintArray()
{
	for(int i=1;i<count;i++)
	{
		printf("%d ",node[i]);
	}
	printf("\n");
}

bool Queue::IsEmpty()
{
	if(front==rear)
		return true;
	else
		return false; 
}

bool Queue::IsFull()
{
	if((rear+1)%MAX==front)
		return true;
	else
		return false;			
}

void Queue::Add(int index)
{
	if(IsFull() != true)
	{
		rear=(rear+1)%MAX;
		s[rear]=index;
	}
	else
		printf("The Queue is Full!!\n");
}

int Queue::Del()
{
	int index;
	if(IsEmpty()!=true)
	{
		front=(front+1)%MAX;
		index=s[front];
		return index;
	}
	else
		printf("The Queue is Empty!!\n");	
}

void HeapTree::DrawTree()
{
	
	Queue MyQueue;
	int tmp=NULL;
	int number=0;
	int Level=0; 
	int Height=4;
	
	if(count!=0)
	{
		MyQueue.Add(1);
		printf("\n");
		PrintSpace(MyPower(2,Height-Level));
		printf("%d",node[1]);		
		printf("\n");
		
	}
	Level++;
	
	while(MyQueue.IsEmpty()!=true)
	{
		tmp=MyQueue.Del();
		if((2*tmp)<count)
		{
			PrintSpace(MyPower(2,Height-Level));
			printf("%d", node[2*tmp]);
			PrintSpace(MyPower(2,Height-Level));
			printf("\b");	
			number++;		
			MyQueue.Add(2*tmp);			
		}
		if((2*tmp+1)<count)
		{
			PrintSpace(MyPower(2,Height-Level));
			printf("%d",node[2*tmp+1]);
			PrintSpace(MyPower(2,Height-Level));
			printf("\b");
			number++;			
			MyQueue.Add(2*tmp+1);
		}
		if(number==MyPower(2,Level))
		{
			printf("\n");
			number=0;
			Level++;
		}
	}
	printf("\n=============================\n");		
 
} 

int MyPower(int base, int expon)
{
	int result=1;
	for(int i=0;i<expon;i++)
	{
		result=result*base;
	}
	return result;
}

void PrintSpace(int num)
{
	for(int i=0;i<num;i++)
		printf(" ");
	return ;
}


