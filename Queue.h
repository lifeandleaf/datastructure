#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MAX_SIZE_Q 1111111

template <typename T > 
class Queue
{
public:
	Queue();
	~Queue();
	void Push(T x);
	void Pop();
	T Front();
	bool Empty();
	int Size();

private:
	int head, tail;
	T *box;
};
template<typename T> 
Queue< T >::Queue()
{
	box = new T[MAX_SIZE_Q];
	head = tail = 0;
}

template <typename T > 
Queue< T >::~Queue()
{
	delete box;
	head = tail = 0;
}

template <typename T> 
void Queue<T>::Push(T x) {
	box[tail] = x;
	tail++;
	return;
}

template <typename T > 
void Queue<T>::Pop() {
	if (head < tail)
		head++;
	return;
}

template<typename T>
T Queue<T>::Front() {
	if (head < tail) {
		return box[head];
	}
	return box[0];
}

template<typename T>
bool Queue<T>::Empty() {
	return head == tail;
}

template<typename T>
int Queue<T>::Size() {
	return tail - head;
}


#endif // QUEUE_H_INCLUDED
