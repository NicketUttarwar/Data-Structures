#ifndef UTTARWNVQUEUE_H
#define UTTARWNVQUEUE_H
#include<iostream>

using namespace std;

class bankQueue//new class
{
private:
    struct newEvent//new strucutre
    {
        int arrival;//in each node
        int transaction;
        newEvent *Next; // Pointer to the next newEvent
    };


	newEvent *newptr;
	newEvent *currentptr;
	newEvent *head;

    int numItems = 0;

    int i=0;
    int depart[6];
    int remain[6];
    int wait[6];

public:

    bankQueue();
    ~bankQueue();
    void enqueue(int, int);
    void Read();
    int Depart(int,int);
    void Time();
    void People();
};

#endif
