#include <iostream>
using namespace std;
class Node
{
	private:
		int data;
		Node *next;
	public:
		Node(int data,Node *next=NULL)
		{
			setData(data);
			setNext(next);
		}
		void setData(int data)
		{
			this->data=data;
		}
		void setNext(Node *next)
		{
			this->next=next;
		}
		int getData()
		{
			return this->data;
		}
		Node* getNext()
		{
			return this->next;
		}
};

class LinkedList
{
	private:
		Node *head;
	public:
		LinkedList()
		{
			head=NULL;
		}
		LinkedList(Node *head)
		{
			this->head=head;
		}
		bool isEmpty()
		{
			return (head=NULL);
		}
		void insertAtBeginning(int val)
		{
			if(isEmpty())
			{
				Node *temp=new Node(val);
				head=new Node(val);
			}
			else
			{
				Node *temp=new Node(val);
				temp->setNext(head);
				head=temp;
			}
		}
		bool removeFromBeginning()
		{
			if(isEmpty())
			{
				return false;
			}
			else
			{
				Node *temp=head->getNext();
				delete head;
				head=temp;
				return true;
			}
		}
		int getLength()
		{
			int count=1;
			Node *temp=head;
			while(temp!=NULL)
			{
				temp=temp->getNext();
				count++;
			}
			return count;
		}
			Node* getFirstElement()
		{
			if(!isEmpty())
			{
				return head;
			}
		}
		void print()
		{
			Node *temp=head;
			while(temp!=NULL)
			{
				cout<<temp->getData()<<endl;
				temp=temp->getNext();
			}
		}
};

class Stack
{
	private:
		LinkedList l1;
		int size;
	public:
		void setSize(int size)
	{
		this->size = size;
	}
	int getSize()
	{
		return size;
	}
	Stack(int size)
	{
		setSize(size);
	}
	bool push(int val)
	{
		if (!(isFull()))
		{
			l1.insertAtBeginning(val);
			return true;
		}
		else
		{
			cout << "\nStack is Full";
			return false;
		}
	}
	Node* pop()
	{
		if (!(isEmpty()))
		{
			Node* data = l1.getFirstElement();
			l1.removeFromBeginning();
			return data;
		}
		else
		{
			cout << "\nStack is Empty.";
		}
	}
	bool isEmpty()
	{
		return (l1.isEmpty()) ? true : false;
	}
	bool isFull()
	{
		int length = l1.getLength();
		return (length == size) ? true : false;
	}
	Node* getTop()
	{
		if (!(l1.isEmpty()))
		{
			return l1.getFirstElement();
		}
		else
		{
			cout << "\nStack is Empty.";
		}
	}
	void printStack()
	{
		l1.print();
	}
};

int main()
{
	Stack s1(20);
	s1.push(9);
	s1.setSize(20);
	s1.getSize();
	s1.getTop();
	s1.isEmpty();
	s1.isFull();
	s1.pop();
	s1.printStack();
	return 0;
}
	
