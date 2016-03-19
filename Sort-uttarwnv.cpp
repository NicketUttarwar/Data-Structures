#include "Sort-uttarwnv.h"
#include <algorithm>
#include <string>
using namespace std;

Sort::Sort()//constructor
{

}

Sort::~Sort()//destructor
{

}

void Sort::merge(int theArray[], int first, int mid, int last)//merge sort
{
   int tempArray[100999];//temporary

   int first1 = first;//setting
   int last1  = mid;
   int first2 = mid + 1;//finds optimum location
   int last2  = last;


   int index = first1;//setting at head
   for (; (first1 <= last1) && (first2 <= last2); ++index)//chacking
   {
      if (theArray[first1] < theArray[first2])//chacking
      {  tempArray[index] = theArray[first1];
         ++first1;//preceding increment
      }
      else
      {  tempArray[index] = theArray[first2];
         ++first2;//preceding increment
      }
   }

   for (; first1 <= last1; ++first1, ++index)
     {
         tempArray[index] = theArray[first1];
     }

   for (; first2 <= last2; ++first2, ++index)
     {
         tempArray[index] = theArray[first2];
     }

   for (index = first; index <= last; ++index)
     {
         theArray[index] = tempArray[index];
     }
}

void Sort::mergesort(int theArray[], int first, int last)//mergesort function
{
   if (first < last)//checks
   {
      int mid = (first + last)/2;//finds the actual mid point
      mergesort(theArray, first, mid);//recursion
      mergesort(theArray, mid+1, last);

      merge(theArray, first, mid, last);//calls merfe after recursion
   }
}

void Sort::bubbleSort(int theArray[], int n)//bubble sort function
{
   bool sorted = false;//setting

   for (int pass = 1; (pass < n) && !sorted; ++pass)//loop
   {
      sorted = true;
      for (int index = 0; index < n-pass; ++index)//nested loop
      {
         int nextIndex = index + 1;
         if (theArray[index] > theArray[nextIndex])//checking
         {
            swap(theArray[index], theArray[nextIndex]);//switches the two for optimum results
            sorted = false;
         }
      }
   }
}

void Sort::insertionSort(int theArray[], int n)//insertion sort funciton
{
   for (int unsorted = 1; unsorted < n; ++unsorted)
   {
      int nextItem = theArray[unsorted];
      int loc = unsorted;

      for (;(loc > 0) && (theArray[loc-1 ]> nextItem);
            --loc)
         theArray[loc] = theArray[loc-1];

      theArray[loc] = nextItem;
   }
}


void Sort::choosePivot(int theArray[], int first, int last)//finds pivot point
{
    int pivot = (first+last)/2;
    swap(theArray[first], theArray[pivot]);
    return;
}

void Sort::partition(int theArray[],int first, int last, int& pivotIndex)
{
   choosePivot(theArray, first, last);//calls previous function
   int pivot = theArray[first];

   int lastS1 = first;
   int firstUnknown = first + 1;

   for (; firstUnknown <= last; ++firstUnknown)//loop
   {

      if (theArray[firstUnknown] < pivot)//checks
      {
         ++lastS1;
         swap(theArray[firstUnknown], theArray[lastS1]);
      }
   }

   swap(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;
}


void Sort::quicksort(int theArray[], int first, int last)//quicksort functoin
{
   int pivotIndex;

   if (first < last)//checks
   {
      partition(theArray, first, last, pivotIndex);//calls previous function

      quicksort(theArray, first, pivotIndex-1);//recursion
      quicksort(theArray, pivotIndex+1, last);
   }
}

