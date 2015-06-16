#include "binary_search_tree.cpp"

#include <iostream>
#define MAX 5
using namespace std;

int main()
{
	int i=0;
	int j=0;
	int a=5,b=4;
	int d = 7;
	int c[MAX]={8,7,12,3,2};
	Binary_Search_Tree<int> t(a);
	while(i<MAX)
	{
	t.create_tree(c[i],t.head);
	i++;
	}
	t.Find(t.head,j);
  	if(t.f == true)
	{
		cout<<"查找的值存在"<<endl;
	}
	if(t.f == false)
	{
		cout<<"查找的值不存在"<<endl;
	}
	t.LDRtree(t.head);
	t.Delete_Node(t.head,c[0]);
	t.LDRtree(t.head);
	//cout<<"删除后的中序"<<endl;
	//t.LDRtree(t.head);
 	//t.Insert_BST(t.head,j);
	//int depte=t.Depth(t.head);
	//cout<<"depth :"<<depte<<endl;
	//t.Insert(t.head,b);
	//t.LDRtree(t.head);
}
