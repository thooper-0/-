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
		cout<<"�������Ѿ������һ���������У��ٴ����뽫�ᵼ���ϴ����ݵĶ�ʧ���Ƿ�������ǣ�����1/������0����"<<endl;
		int tt;
		cin>>tt;
		switch(tt)
		{
		case 0:return head;
		case 1:head=NULL;length=0;break;
		}
	}
	cout<<"��������Ҫ������������У��Իس���������"<<endl;
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
		cout<<"���ѳɹ��޸���Ҫ�������������:D"<<endl
			<<endl;
	}
	return head;
}
void print(node *head,int &length)
{
	if(head==NULL)
	{
		cout<<"����û������һ���������У������Ƽ�����ȥ1."<<endl;
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
		cout<<"����û������һ���������У������Ƽ�����ȥ1."<<endl;
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
	cout<<"�������еĳ���Ϊ"<<length;
	while(add>0)
	{
		cout<<endl<<"ȡ����Ϊ��"<<add<<endl;
		for(i=0;i<add;i++)
		{
			cout<<"��";
			for(int d=i;d<length;d+=add)
			{
				cout<<a[d]->num<<' ';
			}
			cout<<"�ֳ�һ����в�������"<<endl;
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
		cout<<"�˴β���������Ϊ:"<<endl;
		for(p=head;p!=NULL;p=p->next)
		{
			cout<<p->num<<' ';
		}
		add=add/2;
		system("pause");
	}
	cout<<endl<<"���ս��Ϊ��"<<endl;
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
		cout<<"           ϣ������ľ�����ʾ           "<<endl
			<<"----------��ѡ����Ҫ���еĲ���----------"<<endl
			<<"          1��������޸��������С�       "<<endl
			<<"          2��ֻ���������             "<<endl
			<<"          3��������ʾ��               "<<endl
			<<"          4���˳���                     "<<endl
			<<"----------------------------------------"<<endl
			<<"���ѡ��";
		cin>>n;
		switch(n)
		{
		case 1:head=create(head,length);break;
		case 2:print(head,length);break;
		case 3:show(head,length);break;
		case 4:temp=0;break;
		default:cout<<"����ϸ�鿴��ϵͳ�Ĺ���ѡ�������ȷ��ѡ��лл��"<<endl;break;
		}
	}
	return 0;
}