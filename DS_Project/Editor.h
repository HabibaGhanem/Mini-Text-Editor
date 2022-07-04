#pragma once
#include<string>
using namespace std;

class Node
{
public:
	string text;
	Node* next;

	Node();
	Node(string value);

};
class Editor
{
		Node* head;
		Node* tail;
		int size;

	public:
		Editor();
		void append(string val);
		void writefile();
		
};

