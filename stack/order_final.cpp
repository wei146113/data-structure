#include <stdio.h>
#include <stdlib.h>
#include "MyStack.h"

struct MyinOrder
{
	int itemcount;
	data item[MAX];
	data post[MAX];
	MyinOrder(char *filename);	
	void Show();
	void InToPost();
	void ShowPost();
	
};

int main(){
	
	MyinOrder in1("123.txt");
	in1.Show();
	in1.InToPost();
	in1.ShowPost();
	
	
	
	return 0;
} 

MyinOrder::MyinOrder(char *filename)
{
	itemcount=0;
	char s[80];
	FILE *fptr=fopen(filename,"r"); 
	while(!feof(fptr))
	{
		fgets(s,80,fptr);
		if(s[0]>='0'&&s[0]<='9')
		{
			item[itemcount].type=val;
			item[itemcount].value=atoi(s);		
		}
		else
		{
			item[itemcount].type=oper;
			item[itemcount].oper=s[0];
			if(s[0]=='+')
				item[itemcount].pre=add;
			else if(s[0]=='-')
				item[itemcount].pre=sub;
			else if(s[0]=='*')
				item[itemcount].pre=mult;
			else if(s[0]=='/')
				item[itemcount].pre=division;
		}
		itemcount++;		
	}
}

void MyinOrder::Show()
{
	int i;
	for(i=0;i<itemcount;i++)
	{
		if(item[i].type==val)
			printf("%d",item[i].value);
		else
			printf("%c", item[i].oper);
		
	}
	printf("\n");
}

void MyinOrder::InToPost()
{
	MyStack st;
	
	int i;
	int postcount=0;
	for(i=0;i<itemcount;i++)
	{
		if(item[i].type==val)
		{
			post[postcount]=item[i];
			postcount++;			
		}
		else
		{
			if(st.IsEmpty()==true)
				st.Push(item[i]);
			else
			{
				if(item[i].pre>st.a[st.top].pre)
					st.Push(item[i]);
				else
				{			
					do
					{ 
						post[postcount]=st.Pop();
						postcount++;
					}while(item[i].pre<=st.a[st.top].pre && 
										st.IsEmpty()!=true);
					st.Push(item[i]);
				}
			}
		}
	}
	while(st.IsEmpty()!=true)
	{
		post[postcount]=st.Pop();
		postcount++;		
	}
}
void MyinOrder::ShowPost()
{
	int i;
	for(i=0;i<itemcount;i++)
	{
		if(post[i].type==val)
			printf("%d",post[i].value);
		else
			printf("%c",post[i].oper);
		
	}
	printf("\n");
}
