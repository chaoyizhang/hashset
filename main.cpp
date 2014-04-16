#include<iostream>
#include<stdlib.h>
#include "HashSet.h"
using namespace std;
int main()
{
	CHashSet a;
	int i=0;
	while(i<500)
	{
		int j=rand()%10000;
		if(a.AddValue(j))
			cout<<"add "<<j<<" done!"<<endl;
		else
			cout<<"add "<<j<<" failes!"<<endl;
		j=rand()%10000;
		if(a.DeleteValue(j))
			cout<<"delete "<<j<<" done!"<<endl;
		else
			cout<<"delete "<<j<<" failes!"<<endl;
		j=rand()%10000;
		if(a.FindValue(j))
			cout<<"find "<<j<<endl;
		else
			cout<<"cannot find "<<j<<endl;
		i++;
	}
	a.List();
	CHashSet b;
	b=a;
	cout<<b.Size()<<endl;
	b.Clear();
	cout<<b.Size()<<endl;

	//b.List(77);


	return 0;
}