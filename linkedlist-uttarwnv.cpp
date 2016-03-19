#include "linkedlist-uttarwnv.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

LinkedList::LinkedList()//constructor
{
    startptr = lastptr = newNode = NULL;
}

LinkedList::~LinkedList()//destructor
{

}

void LinkedList::insertNode(int curr_data) //adds a new node
{

    if (startptr == NULL)//checks where to add node
    {
        startptr = new Node;
        startptr->data = curr_data;
        startptr->next = NULL;
        lastptr = startptr;
    }
    else
    {
        newNode = new Node;
        newNode->data = curr_data;
        newNode->next = NULL;
        lastptr->next = newNode;
        lastptr = newNode;
    }
}

void LinkedList::printList()//prints the entire list
{
    cout << "--------------------\n";
    Node* curr_ptr;
    curr_ptr = startptr;
    if (curr_ptr == NULL)//empty check
    {
        cout << "The list is empty\n";
        return;
    }
    else
    {
        while(curr_ptr != NULL)
        {
            cout << curr_ptr->data << endl;
            curr_ptr = curr_ptr->next;
        }
    }
    return;
}



bool LinkedList::isEmpty()//Empty Check
{
    if (startptr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void LinkedList::MergeSort(Node** headRef)//mergesort algorithm
{
  Node* head = *headRef;//head finder
  Node* a;//node for calculation
  Node* b;//node for calculation

  if ((head == NULL) || (head->next == NULL))//checker
  {
    return;
  }

  SplitList(head, &a, &b);//else contine

  MergeSort(&a);//sending through the address of the node
  MergeSort(&b);

  *headRef = MergeSortedLists(a, b);
  return;
}

LinkedList::Node* LinkedList::MergeSortedLists(Node* a, Node* b)//mergesort algoritm
{
  Node* result = NULL;

  if (a == NULL)//alternate return
     return(b);
  else if (b==NULL)
     return(a);

  if (a->data <= b->data)//checker
  {
     result = a;
     result->next = MergeSortedLists(a->next, b);//calling mergesort
  }
  else
  {
     result = b;
     result->next = MergeSortedLists(a, b->next);//calling mergesort
  }
  return(result);
}

void LinkedList::SplitList(Node* source, Node** frontRef, Node** backRef)//splits list for sorting
{
  Node* fast;
  Node* slow;
  if (source==NULL || source->next==NULL)//checjer
  {
    *frontRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;

    while (fast != NULL)//loops
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;//finally sends to null
  }
}


void LinkedList::ExecMergeSort()//calls the address
{
    MergeSort(&startptr);//calling the code pointers
    return;
}

void LinkedList::add_array(int arraylist[], int num)//new array addition
{
    for (int i = 0; i < num; ++i)//loop
    {
        insertNode(arraylist[i]);//inserts array as a node
    }
}
