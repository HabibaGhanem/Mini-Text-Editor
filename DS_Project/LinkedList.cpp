#include "LinkedList.h"
#include<iostream>
#include <assert.h>


using namespace std;

template <class T>
Node<T>::Node()
{
	value = 0;
	next = NULL;
}

template <class T>
Node<T>::Node(T val)
{
	value = val;
	next = NULL;
}

template <class T>
LinkedList<T>::LinkedList(void)
{
	head = tail = NULL;
	count = 0;
}

template <class T>
int LinkedList<T>::Length()
{
	return count;
}

template <class T>
void LinkedList<T>::Append(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (head == NULL)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}

template <class T>
T LinkedList<T>::At(int pos)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->value;
}

template <class T>
void LinkedList<T>::InsertAt(int pos, T val)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	Node<T>* newNode = new Node<T>(val);
	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;

		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	count++;
}

template <class T>
void LinkedList<T>::DeleteAt(int pos)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	if (pos == 0)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		Node<T>* del = tmp->next;
		tmp->next = del->next;
		delete del;
		if (pos == count - 1)
			tail = tmp;
	}
	count--;
}

template <class T>
void LinkedList<T>::Display() {
	Node<T>* temp = head;
	while (temp != NULL) {
		cout << temp->value;
		cout << endl;
		temp = temp->next;
	} 
}
template <class T>
void LinkedList<T>::UpdateAt(int line_pos, T newdata) {
	int pos = 0;
		if (line_pos + 1 > Length()) {
			cout << "This line doesn't exist \n ";
		}

		else {
			Node<T>* tmp = head;
			while (tmp!= NULL) {
				if (pos == line_pos) {
					tmp->value = newdata;

				}

				tmp = tmp->next;
				pos++;
			}
		}
	
	
}

template <class T>
LinkedList<T>::~LinkedList(void)
{

}
