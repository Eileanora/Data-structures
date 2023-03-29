// Doubly LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Node
{
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data)
	{
		this->data = data;
		next = NULL;
		prev = NULL;
	}
	~Node()
	{
		delete next;
		delete prev;
	}
};


class DoublyLinkedList
{
public: 
	Node* head;
	Node* tail;
	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	// insert
	void insert_back(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	void print()
	{
		Node* curr = head;
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
	}

	~DoublyLinkedList()
	{
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		delete head;
		delete tail;
	}
};


int main()
{
	DoublyLinkedList* list = new DoublyLinkedList();
	list->insert_back(1);
	list->insert_back(2);
	list->insert_back(3);
	list->insert_back(4);
	list->insert_back(5);
	list->insert_back(6);
	list->insert_back(7);
	list->insert_back(8);
	list->insert_back(9);
	list->insert_back(10);
	list->print();
}