#include<stdlib.h>
#include<iostream>
#include "HashSet.h"
using namespace std;
//构造函数，模的默认参数为100
CHashSet::CHashSet(int m):num(0),mod(m)
{
	m_node=new Node*[mod];
	if(m_node!=NULL)
	{
		for(int i=0;i<mod;++i)
		{
			m_node[i]=NULL;
		}
	}
}
//重载赋值操作符
CHashSet& CHashSet::operator=(const CHashSet& hashset)
{
	if(this==&hashset)
		return *this;
	for(int i=0;i<mod;++i)//先清空原有内容
	{
		Node *temp=m_node[i];
		while(temp!=NULL)
		{
			Node *p=temp;
			temp=temp->next;
			delete p;
		}
	}
	delete [] m_node;
	num=hashset.num;//同时复制指针与所指向的地址，有两份
	mod=hashset.mod;
	m_node=new Node*[mod];
	if(m_node!=NULL)
	{
		for(int i=0;i<mod;++i)
		{
			Node *p=hashset.m_node[i];
			if(p!=NULL)
			{
				m_node[i]=new Node;
				m_node[i]->m_key=p->m_key;
				m_node[i]->next=NULL;
			}
			else
			{
				m_node[i]=NULL;
				continue;
			}
			p=p->next;
			Node *q=m_node[i];
			while(p!=NULL)
			{
				q->next=new Node;
				q=q->next;
				q->m_key=p->m_key;
				q->next=NULL;
				p=p->next;
			}
		}				
	}
	return *this;
}
//调用赋值操作符定义拷贝构造函数
CHashSet::CHashSet(const CHashSet& hashset)
{
	m_node=NULL;
	*this=hashset;
}
CHashSet::~CHashSet()
{
	if(m_node!=NULL)
	{
		for(int i=0;i<mod;++i)
		{
			Node *temp=m_node[i];
			while(temp!=NULL)
			{
				Node *p=temp;
				temp=temp->next;
				delete p;
			}
			m_node[i]=NULL;
		}
		delete [] m_node;
		m_node=NULL;
	}
}
//增加元素，每一个散列值得元素按大小关系升序排列
//在删除查找时方便
bool CHashSet::AddValue(int value)
{
	int index=value%mod;
	if(index<0)
		index=-index;
	if(m_node[index]==NULL)
	{
		m_node[index]=new Node;
		m_node[index]->m_key=value;
		m_node[index]->next=NULL;
		num++;
		return true;
	}
	else
	{
		Node *p=m_node[index];
		Node *q=NULL;
		while(p!=NULL)
		{
			if(p->m_key==value)
				return false;
			if(p->m_key<value)
			{
				q=p;
				p=p->next;
			}
			else
			{
				if(q!=NULL)
				{
					q->next=new Node;
					if(q->next!=NULL)
					{
						q->next->m_key=value;
						q->next->next=p;
						num++;
						return true;
					}
				}
				else
				{
					q=new Node;
					q->m_key=value;
					q->next=p;
					m_node[index]=q;
					num++;
					return true;
				}
			}
		}
		q->next=new Node;
		if(q->next!=NULL)
		{
			q->next->m_key=value;
			q->next->next=NULL;
			num++;
			return true;		
		}
	}
	return false;
}
bool CHashSet::DeleteValue(int value)
{
	int index=value%mod;
	if(index<0)
		index=-index;
	Node *p=m_node[index];
	Node *q=NULL;
	while(p!=NULL)
	{
		if(p->m_key==value)
		{
			if(q==NULL)
			{
				if(p->next==NULL)
				{
					delete m_node[index];
					m_node[index]=NULL;
					num--;
					return true;
				}
				else
				{
					Node *temp=m_node[index];
					m_node[index]=m_node[index]->next;
					delete temp;
					num--;
					return true;
				}
			}
			else
			{
				q->next=p->next;
				delete p;
				num--;
				return true;
			}
		}
		else if(p->m_key<value)
		{
			q=p;
			p=p->next;
		}
		else
			break;
	}

	return false;
}
bool CHashSet::IsEmpty()
{
	if(num==0)
		return true;
	else
		return false;

}
bool CHashSet::FindValue(int value)
{
	int index=value%mod;
	if(index<0)
		index=-index;	
	Node *p=m_node[index];
	while(p!=NULL)
	{
		if(p->m_key==value)
		{
			return true;
		}
		else if(p->m_key<value)
		{
			p=p->next;
		}
		else
			break;
	}
	return false;

}
int CHashSet::Size()
{
	return num;
}
bool CHashSet::Clear()
{
	num=0;
	for(int i=0;i<mod;++i)
	{
		Node *temp=m_node[i];
		while(temp!=NULL)
		{
			Node *p=temp;
			temp=temp->next;
			delete p;
		}
		m_node[i]=NULL;
	}
	return true;

}
void CHashSet::List(int t)
{
	if(t==-1)
	{
		for(int i=0;i<mod;++i)
		{
			Node* p=m_node[i];
			while(p!=NULL)
			{
				cout<<p->m_key<<" ";
				p=p->next;
			}
			if(m_node[i]!=NULL)
				cout<<endl;
		}
	}
	else if(t>=mod)
		cout<<"exceed the range"<<endl;
	else
	{
		Node* p=m_node[t];
		while(p!=NULL)
		{
			cout<<p->m_key<<" ";
			p=p->next;
		}
		if(m_node[t]!=NULL)
			cout<<endl;
	}

}
