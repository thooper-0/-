#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct node
{
	int num;
	node *next;
}node;
int dddd=0;
node *create(node *head,int &length)
{
	if(dddd==1)
	{
		cout<<"您本身已经输入过一次整数序列，再次输入将会导致上次数据的丢失，是否继续（是，输入1/否，输入0）："<<endl;
		int tt;
		cin>>tt;
		switch(tt)
		{
		case 0:return head;
		case 1:head=NULL;length=0;break;
		}
	}
	cout<<"请输入需要排序的整数序列（以回车结束）："<<endl;
	int c;
	node *p1,*p2=NULL;
	while(cin>>c)
	{
		p1=(node*)malloc(sizeof(node));
		p1->num=c;
		length++;
		if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		if(cin.get()=='\n')break;
	}
	p2->next=NULL;
	if(head!=NULL)
	{
		dddd=1;
		cout<<"你已成功修改需要排序的整数数组:D"<<endl
			<<endl;
	}
	return head;
}
void print(node *head,int &length)
{
	if(head==NULL)
	{
		cout<<"您还没有输入一组整数序列，这里推荐您先去1."<<endl;
		return ;
	}
	node **a,*p,*temp=new node,*head2=NULL,*p1,*p2=NULL;
	int i=0,add=length/2,j,k;
	a=new node*[length];
	for(p=head;p!=NULL;p=p->next)
	{
		p1=(node*)malloc(sizeof(node));
		p1->num=p->num;
		if(head2==NULL)
			head2=p1;
		else
			p2->next=p1;
		p2=p1;
	}p2->next=NULL;
	for(p=head2;p!=NULL;p=p->next)
	{
		a[i]=p;
		i++;
	}
	while(add>0)
	{
		for(i=0;i<add;i++)
		{
			for(j=i+add;j<length;j+=add)
			{
				temp->num=a[j]->num;
				for(k=j-add;k>=0;k-=add)
				{
					if(a[k]->num>temp->num)
					{
						a[k+add]->num=a[k]->num;
						if(k-add<0)
						{
							a[k]->num=temp->num;
						}
					}
					else
					{
						a[k+add]->num=temp->num;
						break;
					}
				}
			}
		}
		add=add/2;
	}
	for(p=head2;p!=NULL;p=p->next)
	{
		cout<<p->num<<' ';
	}
	cout<<endl;
}
void show(node *head,int &length)
{
	if(head==NULL)
	{
		cout<<"您还没有输入一组整数序列，这里推荐您先去1."<<endl;
		return ;
	}
	node **a,*p,*temp=new node;
	int i=0,add=length/2,j,k;
	a=new node*[length];
	for(p=head;p!=NULL;p=p->next)
	{
		a[i]=p;
		i++;
	}
	cout<<"整数序列的长度为"<<length;
	while(add>0)
	{
		cout<<endl<<"取增量为："<<add<<endl;
		for(i=0;i<add;i++)
		{
			cout<<"将";
			for(int d=i;d<length;d+=add)
			{
				cout<<a[d]->num<<' ';
			}
			cout<<"分成一组进行插入排序"<<endl;
		}
		for(i=0;i<add;i++)
		{
			for(j=i+add;j<length;j+=add)
			{
				temp->num=a[j]->num;
				for(k=j-add;k>=0;k-=add)
				{
					if(a[k]->num>temp->num)
					{
						a[k+add]->num=a[k]->num;
						if(k-add<0)
						{
							a[k]->num=temp->num;
						}
					}
					else
					{
						a[k+add]->num=temp->num;
						break;
					}
				}
			}
		}
		cout<<"此次插入排序结果为:"<<endl;
		for(p=head;p!=NULL;p=p->next)
		{
			cout<<p->num<<' ';
		}
		add=add/2;
		system("pause");
	}
	cout<<endl<<"最终结果为："<<endl;
	for(p=head;p!=NULL;p=p->next)
	{
		cout<<p->num<<' ';
	}
	cout<<endl;
}
int main()
{
	int n,length=0,temp=1;
	node *head=NULL;
	while(temp)
	{
		cout<<"           希尔排序的具体演示           "<<endl
			<<"----------请选择您要进行的操作----------"<<endl
			<<"          1、输入或修改整数序列。       "<<endl
			<<"          2、只排序并输出。             "<<endl
			<<"          3、排序并演示。               "<<endl
			<<"          4、退出。                     "<<endl
			<<"----------------------------------------"<<endl
			<<"你的选择：";
		cin>>n;
		switch(n)
		{
		case 1:head=create(head,length);break;
		case 2:print(head,length);break;
		case 3:show(head,length);break;
		case 4:temp=0;break;
		default:cout<<"请仔细查看本系统的功能选项，做出正确的选择谢谢。"<<endl;break;
		}
	}
	return 0;
}