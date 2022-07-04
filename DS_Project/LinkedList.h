template <class T>
class Node
{
public:
	Node<T>* next;
	T value;

	Node();
	Node(T val);
};

template <class T>
class LinkedList
{
	int count;
public:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList();
	int Length();
	T At(int);
	void InsertAt(int, T);
	void Append(T);
	void DeleteAt(int);
	void Display();
	void UpdateAt(int, T);
	~LinkedList(void);
};

