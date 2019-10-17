#pragma once

#ifndef INCLUDE_LINKEDLIST


template<typename T>
class LStack
{
public:
	LStack();
	~LStack();
	void Push(T x);
	void Pop();
	T Top();
	bool Empty();
	int Size();
private:
	struct node
	{
		T data;
		node *next;
	};
	node *top;
	int StackSize;
};
template<typename T>
LStack<T>::LStack()
{
	top = nullptr;
	StackSize = 0;
}
template<typename T>
LStack<T>::~LStack()
{
	while (top) {
		node *d = top;
		top = top->next;
		delete d;
		StackSize--;
	}
}
template<typename T>
void LStack<T>::Push(T x) {
	node *p = new node;
	if (p == NULL)
		return;
	p->data = x;
	p->next = top;
	top = p;
	StackSize++;
	return;
}
template<typename T>
void LStack<T>::Pop() {
	node *d = top;
	top = top->next;
	delete d;
	StackSize--;
	return;
}
template<typename T>
T LStack<T>::Top() {
	return top->data;
}
template<typename T>
bool LStack<T>::Empty() {
	return top == nullptr;
}
template<typename T>
int LStack<T>::Size() {
	return StackSize;
}


#endif // !INCLUDE_LINKEDLIST
