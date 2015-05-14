#include "stack.h"
#include <iostream>
using namespace std;

template<class T>
stack<T>::stack()
{
	top = -1;
	T data[stack_size]={0};
}

template<class T>
void stack<T>::push(T &a)
{
	if(top!=stack_size-1)
		{
			top++;
			data[top]=a;
		}
  	else cout<<"stack is full"<<endl;

}

template <class T>
T stack<T>::pop()
{	T a;
	if(top!=-1)
	{
		a = data[top];
   		top--;
		return a;
	}
	else cout<< "stack is Empty"<<endl;
}
template <class T>
bool stack<T>::isEmpty()
{
	if(top==-1)
		return true;
	else return false;

}
template<class T>
void stack<T>::print()
{
	while(top!=-1)
		cout<<"number :"<<data[top--]<<endl;

}
