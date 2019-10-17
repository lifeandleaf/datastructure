#pragma once
#ifndef  INCLUDE_STACK_HEAD
#define INCLUDE_STACK_HEAD
#include <iostream>

using namespace std;

#define MAX_SIZE 1111111

template <class T> class Stack
{
private:
	int top;
	T *box;
public:
	Stack();
	void Push(T x);//push an element
	void Pop();//pop an element
	bool Empty();//if this stack is empty
	int  Size();//the size of this stack
	T    Top();//the top of this stack
	~Stack();
};

template <class T> Stack<T>::Stack()
{
	box = new T[MAX_SIZE];
	top = 0;
}

template <class T> Stack<T>::~Stack()
{
	delete box;
	top = 0;
}

template <class T> void Stack<T>::Push(T x) {
	if (top > MAX_SIZE)
		return;
	box[top++] = x;
	return;
}

template <class T> void Stack<T>::Pop() {
	if (top) {
		top--;
	}
	return;
}

template <class T> bool Stack<T>::Empty() {
	return top == 0;
}

template <class T> int Stack<T>::Size() {
	return top;
}

template <class T> T Stack<T>::Top() {
	if (top) {
		return box[top - 1];
	}
	return box[0];
}


#endif // ! INCLUDE_STACK_HEAD
