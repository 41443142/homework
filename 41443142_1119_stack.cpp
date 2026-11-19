#include <iostream>
using namespace std;

template<class T>
class Chain;

template<class T>
class ChainNode {
	friend class Chain<T>;
public:
	ChainNode(){}
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
	Chain():first(nullptr){}
	~Chain();
	bool IsEmpty() const { return first == nullptr; }
	void push(const T& theIndex);
	void pop();
	void Display();
	int top();
private:
	ChainNode<T>* first;
	int size;
};
template<class T>
Chain<T>::~Chain() {
	while (first!=nullptr)
	{
		ChainNode<T>* nextNode = first->link;
		delete first;
		first = nextNode;
	}
}
template<class T>
void Chain<T>:: push(const T& theIndex)
{
	if (IsEmpty()) {
		first = new ChainNode<T>(theIndex, first);
		//first->data = theIndex;
		size++;
		return;
	}
	ChainNode<T>* pushNode = new ChainNode<T>(theIndex);
	pushNode->link = first;
	first = pushNode;
	size++;
}
template<class T>
void Chain<T>::pop()
{
	if (IsEmpty()) {
		cout << "Stack is empty.\n";
		return;
	}
	ChainNode<T>* popNode = first;
	first = first->link;
	delete popNode;
	popNode = 0;
	size--;
}
template<class T>
int Chain<T>::top()
{
	if (IsEmpty()) {
		cout << "Stack is empty.\n";
		return -1;
	}
	return first->data;
}
template <class T>
void Chain<T>::Display()
{
	ChainNode<T>* p = first;
	while (p != 0)
	{
		cout << p->data << "->";
		p = p->link;
	}
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
		cout << "3. Top" << endl;
		cout << "4. IsEmpty" << endl;
		cout << "5. Display" << endl;
		cout << "6. Exit" << endl;
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
			cout << "Top" << p1.top() << endl;
			break;
		}
		case 4:
		{
			if (p1.IsEmpty() == 1) cout << "yes" << endl;
			else cout << "no" << endl;
			break;
		}
		case 5:
		{
			p1.Display();
			break;
		}
		case 6:
		{
			return 0;
			break;
		}
		}
	}
	return 0;
}