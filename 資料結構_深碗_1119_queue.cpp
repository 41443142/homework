#include <iostream>
using namespace std;

template<class T>
class Chain;

template<class T>
class ChainNode {
	friend class Chain<T>;
public:
	ChainNode() {}
	ChainNode(const T& data) {
		this->data = data;
	}
	ChainNode(const T& data, ChainNode<T>* link) {
		this->data = data;
		this->link = link;
	}
private:
	T data;
	ChainNode<T>* link;
};
template<class T>
class Chain {
public:
	Chain() :front(nullptr), back(nullptr) {}
	~Chain();
	bool IsEmpty() const { return ((front && back) == 0); }
	void push(const T& theIndex);
	void pop();
	void Display();
	void D(ChainNode<T>* p);
	int Front();
	int Rear();
private:
	ChainNode<T>* front;
	ChainNode<T>* back;
	int size;
};
template<class T>
Chain<T>::~Chain() {
	while (front != nullptr)
	{
		ChainNode<T>* nextNode = front->link;
		delete front;
		front = nextNode;
	}
}
template<class T>
void Chain<T>::push(const T& theIndex)
{
	if (IsEmpty()) {
		front = new ChainNode<T>(theIndex, front);
		back = front;
		size++;
		return;
	}
	ChainNode<T>* pushNode = new ChainNode<T>(theIndex);
	back->link = pushNode;
	back = pushNode;
	size++;
}
template<class T>
void Chain<T>::pop()
{
	if (IsEmpty()) {
		cout << "Queue is empty.\n";
		return;
	}
	ChainNode<T>* popNode = front;
	front = front->link;
	delete popNode;
	popNode = 0;
	size--;
}
template<class T>
int Chain<T>::Front()
{
	if (IsEmpty()) {
		cout << "Queue is empty.\n";
		return -1;
	}
	return front->data;
}
template<class T>
int Chain<T>::Rear()
{
	if (IsEmpty()) {
		cout << "Queue is empty.\n";
		return -1;
	}
	return back->data;
}
template<class T>
void Chain<T>::D(ChainNode<T>* p)
{
	if (p == nullptr) return;
	D(p->link);
	cout << p->data << " -> ";
}
template <class T>
void Chain<T>::Display()
{
	D(front);
	cout << "Null" << endl;
}

int main()
{
	Chain<int>p1;
	int op;
	while (true)
	{
		cout << "============ Linked List Menu =================" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Front" << endl;
		cout << "4. Rear" << endl;
		cout << "5. IsEmpty" << endl;
		cout << "6. Display" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> op;
		switch (op)
		{
		case 1:
		{
			int a;
			cout << "Enter index: ";
			cin >> a;
			p1.push(a);
			break;
		}
		case 2:
		{
			p1.pop();
			break;
		}
		case 3:
		{
			cout << "Front:" << p1.Front() << endl;
			break;
		}
		case 4:
		{
			cout << "Rear:" << p1.Rear() << endl;
			break;
		}
		case 5:
		{
			if (p1.IsEmpty() == 1) cout << "yes" << endl;
			else cout << "no" << endl;
			break;
		}
		case 6:
		{
			p1.Display();
			break;
		}
		case 7:
		{
			return 0;
			break;
		}
		}
	}
	return 0;
}