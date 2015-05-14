#ifndef _Stack_h_
#define _Stack_h_
#define stack_size 100
template <class T>
class stack
{
    public:
		stack();
        void push(T &a);
		T	pop();	      
		bool isEmpty();
		void print();
    private:
		int top;
		T data[stack_size];   		

};




#endif
