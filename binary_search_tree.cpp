#include "binary_search_tree.h"

#include <iostream>
using namespace std;

template <class T>
Binary_Search_Tree<T>::Binary_Search_Tree(T &a)
{
	head = new node<T>;
	head->data = a;
	head->left = NULL;
	head->right = NULL;
}
template <class T>
void Binary_Search_Tree<T>::create_tree(T &a,node<T> *head)
{	
	node<T> *h = head;
	if(h->data>a)
	{
		if(h->left!=NULL)
		{
			h = h->left;
			create_tree(a,h);
		}
		else
		{
			node<T> *new_node = new node<T>;
			new_node->data=a;
			new_node->left=new_node->right=NULL;
			h->left = new_node;
		}
	}
	else
	{
		if(h->right!=NULL)
		{
			h = h->right;
			create_tree(a,h);
		}
		else
		{
			node<T> *new_node = new node<T>;
			new_node->data=a;
			new_node->left=new_node->right=NULL;
			h->right=new_node;
		}
	}
}
template <class T>
void Binary_Search_Tree<T>::LDRtree(node<T> *head)
{
	if(head!=NULL)
	{
		LDRtree(head->left);
		cout<<head->data<<endl;
		LDRtree(head->right);
	}	
}
template <class T>
void Binary_Search_Tree<T>::DLRtree(node<T> *head)
{
	if(head!=NULL)
	{
		cout<<head->data<<endl;
		DLRtree(head->left);
		DLRtree(head->right);
	}
}
template<class T>
void Binary_Search_Tree<T>::LRDtree(node<T> *head)
{
	if(head!=NULL)
	{
		LRDtree(head->left);
		LRDtree(head->right);
		cout<<head->data;
	}
}

template<class T>
int Binary_Search_Tree<T>::Depth(node<T> *head)
{
	if(head==NULL)
		return 0;
	int Left = 1;
	int Right =1;
	Left+= Depth(head->left);
	Right+= Depth(head->right);
        return  Left>Right?Left:Right;
 
}

template<class T>
node<T>* Binary_Search_Tree<T>::Insert(node<T> *head,T &x)
{
	//创建一个节点，存放x
	node<T> *p =new node<T>;
	p->left =p->right=NULL;
	p->data = x;
	if(head==NULL)
		return head=p;
	else if(x<head->data)
		head->left = Insert(head->left,x);
	else
		head->right = Insert(head->right,x);

	return head;
	
}

template<class T>
void Binary_Search_Tree<T>::Insert_BST(node<T> *head,T &x)
{
	node<T> * p = new node<T>;
	p->left=p->right=NULL;
	p->data = x;	
	if(head==NULL)
		head = p;
	while(head->left!=p && head->right!=p)
	{
		if(x<head->data)
		{
			if(head->left)
				head = head->left;
			else head->left=p;
		}
		else
		{
			if(head->right)
				head = head->right;
			else head->right = p;
		}

	}	
}
template<class T>
void Binary_Search_Tree<T>::Delete(node<T> *head)
{



}
