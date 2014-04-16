#ifndef _HASHSET_H
#define _HASHSET_H
typedef struct Node
{
	int m_key;
	Node *next;
}Node;
class CHashSet
{
private:
	int num;
	int mod;
	Node **m_node;
public:
	CHashSet(int m=100);
	~CHashSet();
	CHashSet(const CHashSet&);
	CHashSet& operator=(const CHashSet&);
	CHashSet& operator+(Complex &);
	bool AddValue(int value);
	bool DeleteValue(int value);
	bool FindValue(int value);
	bool IsEmpty();
	bool Clear();
	int Size();
	void List(int t=-1);
};
#endif