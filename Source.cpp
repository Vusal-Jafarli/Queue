#include <iostream>
#include <cassert>

using namespace std;


template<typename T, int MAX = 10>
class Dequeue {
	T* arr = new T[MAX]{};
public:
	int front = -1;
	int rear = 0;
	Dequeue() = default;
	void push_front(T data);
	void push_rear(T data);
	void pop_front();
	void pop_rear();
	bool isFull();
	bool isEmpty();
	T get_front();
	T get_rear();
	T* get_data();
	template<typename T, int MAX>
	friend ostream& operator<<(ostream& print, Dequeue<T, MAX>& dq);

};

template<typename T, int MAX>
ostream& operator<<(ostream& print, Dequeue<T, MAX>& dq) {

	int i;
	for (i = dq.front; i != dq.rear; i = (i + 1) % MAX)
		cout << dq.get_data()[i]<<" ";
	cout << dq.get_data()[i];
	return print;

}

template<typename T, int MAX>
void Dequeue<T, MAX>::push_front(T data) {
	if (isFull()) {
		assert(!"Dequeue is Full");
	}
	if (isEmpty()) {
		front = 0;
		rear = 0;
	}
	else if (front == 0) {
		front = MAX - 1;
	}
	else {
		front -= 1;
	}
	arr[front] = data;

}

template<typename T, int MAX>
void Dequeue<T, MAX>::push_rear(T data) {
	if (isFull()) {
		assert(!"Dequeue is Full");
	}
	if (isEmpty()) {
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear + 1) % MAX;
	}
	arr[rear] = data;
}

template<typename T, int MAX>
void Dequeue<T, MAX>::pop_front() {
	if (isEmpty()) {
		assert(!"Dequeue is Empty");
	}
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else {
		front = (front + 1) % MAX;
	}
}

template<typename T, int MAX>
void Dequeue<T, MAX>::pop_rear() {
	if (isEmpty()) {
		assert(!"Dequeue is Empty");
	}
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (rear == 0) {
		rear = (rear + 1) % MAX;
	}
	else {
		rear--;
	}
}

template<typename T, int MAX>
bool Dequeue<T, MAX>::isFull() {
	return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

template<typename T, int MAX>
bool Dequeue<T, MAX>::isEmpty() {
	return (front == -1);
}

template<typename T, int MAX>
T Dequeue<T, MAX>::get_front() {
	if (isEmpty()) {
		assert(!"Dequeue is Empty");
	}
	return arr[front];
}

template<typename T, int MAX>
T Dequeue<T, MAX>::get_rear() {
	if (isEmpty()) {
		assert(!"Dequeue is Empty");
	}
	return arr[rear];
}

template<typename T, int MAX>
T* Dequeue<T, MAX>::get_data() {
	if (isEmpty()) {
		assert(!"Dequeue is Empty");
	}
	return arr;
}


void main()
{
	Dequeue<int> dq;
	dq.push_front(1);
	dq.push_front(3);
	dq.push_rear(8);
	dq.push_rear(5);
	dq.push_front(17);
	//dq.push_rear(6);
	//cout << dq.get_front() << endl;
	//cout << dq.get_rear() << endl;
	cout << dq;




}
//vc