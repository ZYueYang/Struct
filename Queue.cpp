#include "Queue.h"
#include <iostream>
template <class T>

Queue<T>::Queue()
{
    Node<T> *node = new Node<T>;
    front = back = node;
    back->next = NULL;
}
template <class T>
void Queue<T>::create_queue(T &q)
{
     Node<T> *ptr = new Node<T>;
     ptr->info = q;
     ptr->next = NULL;
     back->next = ptr;
     back = ptr;
}
using namespace std;
template <class T>
T Queue<T>::print()
{
while(front!=back)
{
     cout <<"number is :"  <<front->next->info<<endl;
     front = front->next;
}
}
template <class T>
bool Queue<T>::isEmpty()
{
     if(front==back)
       return true;
     else return false;
}
template <class T>
void Queue<T>::push(T &q)
{
      Node<T> *ptr = new Node<T>;   
      ptr->info = q; 
      ptr->next = NULL;
      back->next = ptr;
      back = ptr;
}
template <class T> 
T Queue<T>::pop()
{
      T a = front->next->info;
      front->next = front->next->next;
      return a;
}

template <class T>
int Queue<T>::queue_length()
{
     int count=0;
     Node<T> *ptr=new Node<T>;
     ptr = front->next;
     while(ptr!=back)
     {
         count++;
         ptr = ptr->next;
     }
     count++;
     return count;
}

template <class T>
bool Queue<T>::in_queue(T &q)
{
     Node<T> *ptr=new Node<T>;
     ptr = front;
     do{
	   if(ptr->info = q)
               return true;
           else ptr = ptr->next;	

       }while(ptr->next==NULL); 
     return false;    	


}
