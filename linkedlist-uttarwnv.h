#ifndef LINKEDLIST-UTTARWNV_H
#define LINKEDLIST-UTTARWNV_H
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class LinkedList
{
    public://public functions

        LinkedList();
        ~LinkedList();
        void printList();
        bool isEmpty();
        void ExecMergeSort();
        void add_array(int array[], int num);

    protected://protected functions

    struct Node
    {
        int data;
        Node* next;
    };

    Node* startptr;
    Node* lastptr;
    Node* newNode;
    void insertNode(int curr_data);
    Node* MergeSortedLists(Node* a, Node* b);
    void SplitList(Node* source, Node** frontRef, Node** backRef);
    void MergeSort(Node** headRef);
};

#endif
