#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct node
{
	string key;
	int info;
	struct node *next;
	struct node *prev;
}*start;


class GenericList
{
public:
	void create(int value, string name);
	void append(int value, string name);
	void insert(int value, string name, int position);
	void del(int value);
	void find(string key);

	GenericList()
	{
		start = NULL;
	}
	~GenericList()
	{
		//delete list;
	}
};


int main()
{
	GenericList list;
	list.create(1,"first");
	list.append(2, "second");
	list.insert(111, "middle", 1);
	list.insert(112, "3/4", 2);
	list.del(112);
	list.find("middle");

	struct node *q;
	if (start == NULL)
	{
		cout << "Empty List" << endl;
		return 0;
	}
	q = start;
	cout << "The Doubley Linked List is :" << endl;
	while (q != NULL)
	{
		cout << q->info << " <-> ";
		q = q->next;
	}
	cout << "NULL" << endl;

	cin.get();
	return 0;
}


void GenericList::create(int value, string name)
{
	struct node *s, *temp;
	temp = new(struct node);
	temp->key = name;
	temp->info = value;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		s = start;
		while (s->next != NULL)
			s = s->next;
		s->next = temp;
		temp->prev = s;
	}
}


void GenericList::append(int value, string name)
{
	if (start == NULL)
	{
		cout << "First Create the list." << endl;
		return;
	}
	struct node *temp;
	temp = new(struct node);
	temp->prev = NULL;
	temp->key = name;
	temp->info = value;
	temp->next = start;
	start->prev = temp;
	start = temp;
	cout << "Element Inserted" << endl;
}


void GenericList::insert(int value, string name, int pos)
{
	if (start == NULL)
	{
		cout << "First Create the list." << endl;
		return;
	}
	struct node *temp, *q;
	int i;
	q = start;
	for (i = 0; i < pos - 1; i++)
	{
		q = q->next;
		if (q == NULL)
		{
			cout << "There are less than ";
			cout << pos << " elements." << endl;
			return;
		}
	}
	temp = new(struct node);
	temp->info = value;
	temp->key = name;
	if (q->next == NULL)
	{
		q->next = temp;
		temp->next = NULL;
		temp->prev = q;
	}
	else
	{
		temp->next = q->next;
		temp->next->prev = temp;
		q->next = temp;
		temp->prev = q;
	}
	cout << "Element Inserted" << endl;
}


void GenericList::del(int value)
{
	struct node *temp, *q;
	/*first element deletion*/
	if (start->info == value)
	{
		temp = start;
		start = start->next;
		start->prev = NULL;
		cout << "Element Deleted" << endl;
		free(temp);
		return;
	}
	q = start;
	while (q->next->next != NULL)
	{
		/*Element deleted in between*/
		if (q->next->info == value)
		{
			temp = q->next;
			q->next = temp->next;
			temp->next->prev = q;
			cout << "Element Deleted" << endl;
			free(temp);
			return;
		}
		q = q->next;
	}
	/*last element deleted*/
	if (q->next->info == value)
	{
		temp = q->next;
		free(temp);
		q->next = NULL;
		cout << "Element Deleted" << endl;
		return;
	}
	cout << "Element " << value << " not found" << endl;
}

void GenericList::find(string name)
{
	struct node  *temp;
	int x = 0;

	temp = start;
	while (temp->next != NULL)
	{
		if (temp->key == name)
		{
			cout << "The value within the key is: " << (temp->info) << endl;
			x = 1;
			break;
		}
		else
		{
			temp = temp->next;
		}
	}
	if (x == 0)
	{
		cout << "Key not found" << endl;
	}
	
}


