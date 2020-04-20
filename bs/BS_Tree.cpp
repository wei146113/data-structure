#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 80
struct Node
{
	int data;
	Node* llink;
	Node* rlink; 
};

struct BS_Tree
{
	Node* head;
	int totalNum;
	BS_Tree()
	{
		head=NULL;
		totalNum=0;
	}
	void Insert(int);
	Node* Modified_Search(int);
	void Level_Traversal();
	void Draw_Tree();
	
	
};

struct Queue
{
	Node* s[MAX];
	int front, rear;
	bool IsFull();
	bool IsEmpty();
	void Add(Node*);
	Node* Del();
	
	Queue()
	{
		front=-1;
		rear=-1;
	}
};

int MyPower(int, int);
void PrintSpace(int);

int main()
{
	int i=0;
	BS_Tree myTree;
	srand(time(0));
	
	for(i=0;i<8;i++)
	{
		int tmp=rand()%90+10;
		printf("Insert %d\n",tmp);
		myTree.Insert(tmp);
		myTree.Draw_Tree();
		printf("\nLevelOrder: ");
		myTree.Level_Traversal();
		system("pause")	;
	}
	return 0;
}

void BS_Tree::Insert(int num)
{
	Node *tmp= (Node *)malloc(sizeof(Node));
	tmp->data=num;
	tmp->llink=NULL;
	tmp->rlink=NULL;
	Node *parent=Modified_Search(num);
	if(parent==NULL)
		head=tmp;
	else
	{
		if(parent->data>num)
			parent->llink=tmp;
		else
			parent->rlink=tmp;
	}
	totalNum++;
}



Node* BS_Tree::Modified_Search(int num)
{
	Node* parent=head;
	Node* tmp=head;
	while(tmp!=NULL)
	{
		if(num==tmp->data)
		{		
			printf("number has existed!\n");
			exit(-1);
		}
		else
		{
			parent=tmp;
			if(num>tmp->data)
				tmp=tmp->rlink;
			else
				tmp=tmp->llink;			
		}
	}
	return parent;
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

void Queue::Add(Node* ptr)
{
	if(IsFull() != true)
	{
		rear=(rear+1)%MAX;
		s[rear]=ptr;
	}
	else
		printf("The Queue is Full!!\n");
}

Node* Queue::Del()
{
	Node* ptr;
	if(IsEmpty()!=true)
	{
		front=(front+1)%MAX;
		ptr=s[front];
		return ptr;
	}
	else
		printf("The Queue is Empty!!\n");	
}

void BS_Tree::Level_Traversal()
{
	Queue MyQueue;
	Node* tmp=NULL;
	
	if(head!=NULL)
	{
		MyQueue.Add(head);		
		printf("%d ",head->data);
	}
	
	while(MyQueue.IsEmpty()!=true)
	{
		tmp=MyQueue.Del();
		if(tmp->llink!=NULL)
		{
			printf("%d ", tmp->llink->data);
			MyQueue.Add(tmp->llink);
		}
		if(tmp->rlink!=NULL)
		{
			printf("%d ",tmp->rlink->data);
			MyQueue.Add(tmp->rlink);
		}
	}
	printf("\n");
		
}

void BS_Tree::Draw_Tree()
{
	
	Queue MyQueue;
	Node* tmp=NULL;
	int count=0;
	int count1=0;
	int Level=0; 
	int Height=5;
	
	
	if(head!=NULL)
	{
		MyQueue.Add(head);
		printf("\n");
		PrintSpace(MyPower(2,Height-Level));
		printf("%d",head->data);		
		printf("\n");
		count1++;
	}
	Level++;
	
	while(count1<totalNum)
	{
		tmp=MyQueue.Del();
		if(tmp!=NULL)
		{
			if(tmp->llink!=NULL)
			{
				PrintSpace(MyPower(2,Height-Level));
				printf("%d", tmp->llink->data);
				PrintSpace(MyPower(2,Height-Level));
				printf("\b\b");
				count++;
				count1++;
				MyQueue.Add(tmp->llink);
			}
			else
			{
				PrintSpace(MyPower(2,Height-Level));			
				PrintSpace(MyPower(2,Height-Level));			
				count++;				
				MyQueue.Add(NULL);
			}
			
			if(tmp->rlink!=NULL)		
			{
				PrintSpace(MyPower(2,Height-Level));
				printf("%d",tmp->rlink->data);
				PrintSpace(MyPower(2,Height-Level));
				printf("\b\b");
				count++;
				count1++;
				MyQueue.Add(tmp->rlink);
			}
			else
			{
				PrintSpace(MyPower(2,Height-Level));			
				PrintSpace(MyPower(2,Height-Level));
				
				count++;
				MyQueue.Add(NULL);
			}
		}
		else
		{
				PrintSpace(MyPower(2,Height-Level));			
				PrintSpace(MyPower(2,Height-Level));
				count++;
				MyQueue.Add(NULL);
				PrintSpace(MyPower(2,Height-Level));			
				PrintSpace(MyPower(2,Height-Level));
				count++;		
				MyQueue.Add(NULL);
		}
		
		if(count==MyPower(2,Level))
		{
			printf("\n\n");
			count=0;
			Level++;
		}
	}		
 
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



