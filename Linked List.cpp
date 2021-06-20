#include <iostream>
using namespace std;
template <class T>
class LinkedList
{
private:
	int numberElems = 0;
	class Node
	{
	private:
		T* value = new T;

	public:
		Node* ptrNext;
		Node* ptrPrev;
		void setValue(T* value)
		{
			if (value == nullptr)
			{
				cout << "Value can't be nullptr" << endl;
				return;
			}
			this->value = value;
		}
		T getValue()
		{
			if (value == nullptr)
			{
				cout << "Value is nullptr" << endl;
				return 0;
			}
			return *value;
		}
	};
	Node* headNode = new Node;
	Node* tailNode = new Node;
public:

	bool isEmpty()
	{
		if (headNode->ptrNext == nullptr)
			return true;
		else
			return false;
	}
	void addBack(T* value)
	{
		Node* tmpPrevNode = new Node;
		if (isEmpty())
		{
			headNode->ptrNext = new Node;
			headNode->ptrNext->setValue(*&value);
			tailNode = headNode->ptrNext;
			tailNode->ptrPrev = headNode;
			numberElems++;
			return;
		}
		Node* node = new Node;
		tailNode->ptrNext = new Node;
		tailNode->ptrNext->setValue(*&value);
		tmpPrevNode = tailNode;
		tailNode = tailNode->ptrNext;
		tailNode->ptrPrev = tmpPrevNode;
		numberElems++;
	}
	void addFromIndex(T* value, int index)
	{
		if (index < 0 || index > numberElems)
		{
			cout << "Index out of '-R-' or '-L-' bounds";
			return;
		}
		Node* node = new Node;
		Node* tmpNode = new Node;
		if (index <= numberElems / 2)
		{
			node = headNode;
			for (int i = 0; i < index; i++)
			{
				node = node->ptrNext;
			}
		}
		else
		{
			node = tailNode;
			for (int i = numberElems - 1; i >= index; i--)
			{
				node = tailNode->ptrPrev;
			}
		}
		tmpNode->setValue(*&value);
		tmpNode->ptrPrev = node;
		tmpNode->ptrNext = node->ptrNext;
		node->ptrNext = tmpNode;
		node->ptrNext->ptrNext->ptrPrev = node->ptrNext;
	}
	void addFront(T* value)
	{
		if (isEmpty())
		{
			cout << "goo" << endl;
			headNode->ptrNext = new Node;
			headNode->ptrNext->setValue(*&value);
			tailNode = headNode->ptrNext;
			headNode->ptrPrev = new Node;
			numberElems++;
			return;
		}
		cout << "boo" << endl;
		Node* node = new Node;
		node->setValue(*&value);
		node->ptrNext = headNode->ptrNext;
		headNode->ptrNext = node;
		headNode->ptrNext->ptrNext->ptrPrev = headNode->ptrNext;
		numberElems++;
	}
	T get(int i)
	{
		Node* node = new Node;
			node = headNode->ptrNext;
			for (unsigned int j = 0; j < i; j++)
				node = node->ptrNext;
			return node->getValue();
	}
	void show()
	{
		Node* node = new Node;
		node = headNode;
		while (node->ptrNext)
		{
			node = node->ptrNext;
			cout << node->getValue() << endl;
			
		}
	}
	void show_inverse()
	{
		Node* node = new Node;
		node = tailNode;
		while (node)
		{
			cout << node->getValue() << endl;
			node = node->ptrPrev;
		}
	}
};
int main()
{
	LinkedList<int> list;
	int the_fisrt = 1;
	int the_second = 17;
	int the_third = 9;
	int the_fourth = 5;
	int the_fifth = 12;
	cout << "hello" << endl;
	list.addFront(&the_fourth);
	list.addFront(&the_fisrt);
	list.addBack(&the_third);
	list.addBack(&the_second);
	list.addFront(&the_fourth);
	list.addFront(&the_fisrt);
	list.addBack(&the_third);
	list.addBack(&the_second);
	list.addFromIndex(&the_fifth, 3);
	list.addFromIndex(&the_fourth, 7);
	list.addFromIndex(&the_fifth, 3);
	list.addFromIndex(&the_fifth, 3);
	cout << "the 10th node value is " << list.get(10) << endl;
	cout << "the 5th node value is " << list.get(5) << endl;
	cout << "list:" << endl;
	list.show();
	cout << "inverse:" << endl;
	list.show_inverse();
	return 0;
}