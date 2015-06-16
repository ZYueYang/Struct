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
//查找值，使用递归先序遍历二叉树
template<class T>
void Binary_Search_Tree<T>::Find(node<T> *head,T &x)
{
	f = false;
	if(head!=NULL)
	{
		if(head->data==x)
		{
			f = true;
		}
		Find(head->left,x);
		Find(head->right,x);	
	}
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
void Binary_Search_Tree<T>::Delete_Node(node<T> *head,T &x)
{
	node<T> *parent,*p,*Q;
//	Find(head,x);
	//如果为空，则退出
//	if(f==false)
//		return;
	//不为空时
	while(head!=NULL)
	{ 
		if(head->data==x)break;//head标记待删除结点
		parent = head; //得到的是要删除结点的父结点
		head = (head->data>x)?head->left:head->right;
		cout<<head->data<<endl;
	}
	cout<<"parent value:"<<parent->data<<endl;
	cout<<"head value :"<<head->data<<endl;
	 //要删除的结点为叶子结点
	if(head->left==NULL && head->right==NULL)
        {
		//区分是父亲结点的左孩子还是右孩子
		if(parent->left->data==x)
			parent->left=NULL;
		if(parent->right->data==x)
			parent->right=NULL;
		delete(head);
		return;
	}


	//要删除结点只存在一个孩子
	// 左孩子不为空，右孩子为空
	if(head->left!=NULL && head->right==NULL)	
	{
		if(parent->left->data==x)
			parent->left = parent->left->left;
		if(parent->right->data==x)
			parent->right = parent->right->left;
		delete(head);
		return;
	}
	//左孩子为空，右孩子不为空
	if(head->left==NULL && head->right!=NULL)
	{
		if(parent->left->data==x)
			parent->left = parent->left->right;
		if(parent->right->data==x)
			parent->right = parent->right->right;

		delete(head);
		return;
	}
	//要删除结点左右都不为空
	if(head->left!=NULL && head->right!=NULL)
	{
		if(parent->left->data==x)
		{
			p = head->right;
			while(head->left!=NULL && head->left->left!=NULL)
				p = p->left;
			if(p->left!=NULL)
			{	
				Q = p->left;
				Q->left = head->left;
				parent->left = Q;
				p->left = Q->right;
				Q->right==NULL;	
			}
			else
			{
				p->left = head->left;
				parent->left = p;
			}
		}

		if(parent->right->data==x)
		{
			p = head->right;
			while(head->left!=NULL && head->left->left!=NULL) 	
	       			p = p->left;
			if(p->left!=NULL)
			{	
				Q = p->left;          		
				Q->left = head->left; 	
				parent->right = Q;
				p->left = Q->right;		
				Q->right==NULL;	
	
			}	
			else
			{
				p->left = head->left;
				parent->right = p;
			}
		}
		delete(head);
		return;
	}
}
