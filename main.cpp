#include "binary_search_tree.cpp"

#include <iostream>
#define MAX 5
using namespace std;

int main()
{
	int i=0;
	int j=0;
	int a=5,b=4;
	int c[MAX]={8,7,12,3,2};
	Binary_Search_Tree<int> t(a);
	while(i<MAX)
	{
	t.create_tree(c[i],t.head);
	i++;
	}
	t.LDRtree(t.head);		
 	t.Insert_BST(t.head,j);
	int depte=t.Depth(t.head);
	cout<<"depth :"<<depte<<endl;
	t.Insert(t.head,b);
	t.LDRtree(t.head);
}
