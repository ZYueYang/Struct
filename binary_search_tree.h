#ifndef _binary_search_tree_h_
#define _binary_search_tree_h_
template <class T>
struct node{
	T data;
	node *left;
	node *right;

};
template <class T>
class Binary_Search_Tree{
public:
	void create_tree(T &a ,node<T> *head);
	Binary_Search_Tree(T &a);
	//中序遍历二叉树,递归实现
	void LDRtree(node<T> *head);
	//递归先序遍历二叉树
	void DLRtree(node<T> *head);
	//递归后序遍历二叉树
	void LRDtree(node<T> *head);
	//递归计算深度
	int Depth(node<T> *head);
	//查找值为x的结点
	void Find(node<T> *head,T &x);
	//递归插入一个节点
	node<T>* Insert(node<T> *head,T &x);
	//非递归插入一个节点
	void Insert_BST(node<T> *head,T &x);
	//删除一个节点
 	void Delete_Node(node<T> *head,T &x); 
	struct node<T> *head;
        bool f; //用来判断要查找的值是否在二叉树中，默认为flase
};


#endif
