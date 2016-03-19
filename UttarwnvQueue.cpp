#include "UttarwnvQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;

bankQueue::bankQueue()//constructor
{
   head = newptr = currentptr = NULL;
}

bankQueue::~bankQueue()//destructor
{

}

void bankQueue::enqueue(int a, int t)//adds new numbers to the list
{
    currentptr=head;
    newptr = new newEvent;
    newptr->arrival = a;
    newptr->transaction = t;
    newptr->Next=NULL;

    if(head==NULL)//cheking
    {
        head = newptr;//pointing
    }
    else
	{
	currentptr = head ;
	while(currentptr->Next != NULL) //traversing list using current pointer as a tracker
	{
	    currentptr = currentptr->Next;
    }

    currentptr->Next = newptr;          //links the new node
	}


    numItems++;//tracker for node number
    currentptr=head;
    cout<<numItems<<" -> "<<setw(4)<<newptr->arrival<<" "<<setw(4)<<newptr->transaction<<"\n";//printing all the values from file

}

void bankQueue::Read()//function to read the file
{
    int first, second;
    ifstream infile;
	string word=""; //reads a word
	infile.open("Text.txt",ios::in);//opening file
	if(infile.is_open())
	{
    cout<<"# "<<"Arrival "<<"Departure\n\n";// heading for printing done in Enqueue()
	while(! infile.eof())//retreiving the data from the file
	{
    getline(infile,word,' ');
    first = atoi(word.c_str());

	if(first<0&&first>500)//number value checker
    {
        cout<<"number is too high \n";
    }

//	cout<<first<<"\t";
	getline(infile,word);
    second = atoi(word.c_str());

	if(second<0&&second>500)//number value checker
    {
        cout<<"number is too high \n";
    }

//	cout<<second<<endl;
    enqueue(first,second);
    Depart(first,second);

	}
	}
}

int bankQueue::Depart(int a, int t)
{
    if(head = NULL)
    {
        cout<<"Enqueue not functional\n";
    }

    depart[i] = a+t;
    if(depart!=0)
    {
    depart[2]++;
    depart[5]++;
    }
    remain[i] = depart[i]-t;
    wait[i] = remain[i]-a;



 //   cout<<endl<<depart[i]<<endl<<endl;

    i++;

    return 0;


}

void bankQueue::Time()
{
    currentptr = head;
    if(head==NULL)
    {
        head = newptr;
    }
    else
	{
	currentptr = head ;                //traversing list using current pointer as a tracker
	while(currentptr->Next != NULL)
	{
	    currentptr = currentptr->Next;
    }

    currentptr->Next = newptr;          //links the new node
	}


    int j;
    double Sum=0;
    for(j=0;j<=5;j++)
    {
        Sum+= wait[j];
    }
    Sum = Sum/6;

    cout<<"\nAverage wait time for each person is: "<<Sum<<" min"<<endl;//printing
}

void bankQueue::People()
{
    currentptr = head;
    if(currentptr==NULL)//checker
    {
        cout<<"There is an error\n";//error checker
    }
    else
    {
        int j;
        double Sum=0;
        for(j=0;j<=5;j++)
        {
            Sum+= wait[j]+1;
        }

        Sum=Sum/6;

        cout<<"\nAverage number of people in the queue is: "<<Sum<<" min"<<endl<<endl;//printing
    }


}













