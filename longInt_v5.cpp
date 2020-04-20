#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
 
 struct LongInt{
 	int MyInt[MAX];
 	int IntLen;
 	bool IsPositive;
 	LongInt();
 	LongInt(int);
 	bool Compare(LongInt);
// 	bool operator>(LongInt); 	
 	void operator=(int);
 	void Show();
 	LongInt Add(LongInt);
 	LongInt operator+(LongInt);
 	LongInt operator+(int);

 	LongInt Sub(LongInt);
 	LongInt operator-(LongInt);
 	LongInt operator-(int);
 };
 
 int main(){
 	
 	srand(time(NULL));
 	LongInt a,b,c,d;
 	
 	a.Show();
 	b=11114;
 	b.Show();
// 	if(a.Compare(b)==true)
// 	{
// 		printf("a>=b\n");
//	}
//	else
//	{
//		printf("a<b\n");
//	}
	c=20005;
	c.Show();
	d=b.Add(c);
	d.Show();
	d=b+c;
	d.Show();
	d=b+20005;
	d.Show();
	d=b.Sub(c);
	d.Show();
	d=b-c;
	d.Show();
	d=b-20005;
	d.Show();
 	return 0;
}

LongInt::LongInt(){
	int i;
	for(i=0;i<MAX;i++)
	{
		MyInt[i] = 0;
	}
	IsPositive=true;
	for(i=0;i<MAX-1;i++)
	{
		MyInt[i] = rand()%10;
	}
}
void LongInt::Show(){
	int i;
	if(IsPositive)
		printf("+");
	else
		printf("-");
	for(i=MAX-1;i>=0;i--)
	{
		printf("%d",MyInt[i]);
	}
	printf("\n");
}
bool LongInt::Compare(LongInt b){
	int i;
	for(i=MAX-1;i>=0;i--){
		if(MyInt[i] > b.MyInt[i])
			return true;
		else if(MyInt[i] < b.MyInt[i])
			return false;
	}
	return true;
}
void LongInt::operator=(int num){
	int i;
	for(i=0;i<MAX;i++)
	{
		MyInt[i] = 0;
	}
	i=0;
	while(num!=0){
		MyInt[i]=num%10;
		num = num/10;
		i++;
	}
}
LongInt LongInt::Add(LongInt b){
	LongInt tmp;
	int i;
	for(i=0;i<MAX;i++){
		tmp.MyInt[i]=MyInt[i]+b.MyInt[i];
	}
	for(i=0;i<MAX;i++){
		if(tmp.MyInt[i] >= 10)
		{
			tmp.MyInt[i]%=10;
			tmp.MyInt[i+1]++;
		} 
	}
	return tmp;
}
LongInt LongInt::operator+(LongInt b){
	return this->Add(b);
}
LongInt LongInt::operator+(int num){
	LongInt tmp,b;
	b=num;
	tmp = this->Add(b);
	return tmp;
}
LongInt LongInt::Sub(LongInt b){
	LongInt tmp,tmpa,tmpb;
	int i;
	if(this->Compare(b)){
		tmp.IsPositive=true;
		tmpa=*this;
		tmpb=b;	
	}
	else
	{
		tmp.IsPositive=false;
		tmpa=b;
		tmpb=*this;
    }
    for(i=0;i<MAX;i++){
    	tmp.MyInt[i] = tmpa.MyInt[i] - tmpb.MyInt[i];
	}
	for(i=0;i<MAX;i++){
		if(tmp.MyInt[i] < 0)
		{
			tmp.MyInt[i]+=10;
			tmp.MyInt[i+1]--;
		}
	}
    return tmp;
}
LongInt LongInt::operator-(LongInt b){
	return this->Sub(b);
}
LongInt LongInt::operator-(int num){
	LongInt tmp,b;
	b=num;
	tmp = this->Sub(b);
	return tmp;
}

