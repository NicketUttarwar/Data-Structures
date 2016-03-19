#include "Lab5Uttarwnv.h"
#include <iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;

void IntBinaryTree::Setup()//sets all the pointers to equal one another
{
    TreeNode *newNode;//setting up a new node
    newNode = new TreeNode;
    newNode->number = 1;//number for simplifying grid location
    newNode->left = newNode->right = NULL;

    p1 = newNode;//easier for li=ocating the node from outside
    previousptr = newNode;
    root = newNode;

    newNode = new TreeNode;//1 right is 2
    newNode->number = 2;
    newNode->left = newNode->right = NULL;

    p2=newNode;
    currentptr = newNode;
    previousptr->right = currentptr;

    newNode = new TreeNode;//1 left is 4
    newNode->number = 4;
    newNode->left = newNode->right = NULL;

    p4=newNode;
    currentptr = newNode;
    previousptr->left = currentptr;

    previousptr = newNode;

    newNode = new TreeNode;//4 right is 5
    newNode->number = 5;
    newNode->left = newNode->right = NULL;

    p5=newNode;
    currentptr = newNode;
    previousptr->right = currentptr;

    newNode = new TreeNode;//4 left is 7
    newNode->number = 7;
    newNode->left = newNode->right = NULL;

    p7=newNode;
    currentptr = newNode;
    previousptr->left = currentptr;

    previousptr = root->right;//2 left is 5
    currentptr = root->left;
    currentptr = currentptr->right;
    previousptr->left = currentptr;

    newNode = new TreeNode;//2 right is 3
    newNode->number = 3;
    newNode->left = newNode->right = NULL;

    p3=newNode;
    currentptr = newNode;
    previousptr->right = currentptr;

    previousptr = root->left;//5 right is 6
    previousptr = previousptr->right;

    newNode = new TreeNode;
    newNode->number = 6;
    newNode->left = newNode->right = NULL;

    p6=newNode;
    currentptr = newNode;
    previousptr->right = currentptr;

    previousptr = root->right;//3 left is 6
    previousptr = previousptr->right;
    previousptr->left = currentptr;

    previousptr = root->left;//7 right is 8
    previousptr = previousptr->left;
    newNode = new TreeNode;
    newNode->number = 8;
    newNode->left = newNode->right = NULL;

    p8=newNode;
    currentptr = newNode;
    previousptr->right = currentptr;

    previousptr = root->right;//5 left is 8
    previousptr = previousptr->left;
    previousptr->left = currentptr;

    newNode = new TreeNode;//6 left is 9
    newNode->number = 9;
    newNode->left = newNode->right = NULL;

    p9=newNode;
    currentptr = newNode;
    previousptr = root->right;
    previousptr = previousptr->right;
    previousptr = previousptr->left;
    previousptr->left = currentptr;

    previousptr = root->left;//8 right is 9
    previousptr = previousptr->left;
    previousptr = previousptr->right;
    previousptr->right = currentptr;


}

void IntBinaryTree::DestroySubTree(TreeNode *nodePtr)//destroys sub trees
{
   if (nodePtr)
   {
      if (nodePtr->left)
         DestroySubTree(nodePtr->left);
      if (nodePtr->right)
         DestroySubTree(nodePtr->right);
      delete nodePtr;
   }
}

int IntBinaryTree::User()//fn for user entry
{
    cout<<"Enter the number where you want to play\n\n";
    Show();
    cout<<"\n";
    cin>>x;

    if(x>=1&&x<=9)//safety net
    {
    return x;
    }
    else
    {
        cout<<"Ther number you entered is incorrect. Enter one of the following numbers\n";
        User();
    }

}

void IntBinaryTree::Load(int x, char C)//loads a choice into a slot
{
    currentptr = root;
    if(x==1||x==2||x==3)//finding row
    {
         currentptr=root;
    }
    else if(x==4||x==5||x==6)//finding row
    {
        currentptr = currentptr->left;
    }
    else if(x==7||x==8||x==9)//finding row
    {
        currentptr = currentptr->left;
        currentptr = currentptr->left;
    }

    while(currentptr!=NULL)
    {
        if(currentptr->number==x)//finding column
        {
            previousptr = currentptr;

          if(EmptyCheck(currentptr)==false)//checks to see if empty
          {
              cout<<"\nThe slot is already filled\n\n";
              Load(User(),'X');
          }
           else
           {currentptr->value=C;
            entryptr = currentptr;
           }
        }
        currentptr = currentptr->right;
    }

    Show();
    cout<<"\n\n";

}

void IntBinaryTree::Show()//displays entire grid
{
    currentptr=root;

    while(currentptr->right!=NULL)
    {
        if(currentptr->value=='X'||currentptr->value=='O')//checking
            {
            cout<<currentptr->value<<" | ";
            }
        else
        {
            cout<<currentptr->number<<" | ";
        }
            currentptr=currentptr->right;
    }

            if(currentptr->value=='X'||currentptr->value=='O')
            {
                cout<<currentptr->value;
            }
        else
        {
            cout<<currentptr->number;
        }
    cout<<endl<<"----------"<<endl;

    currentptr=root;
    currentptr=currentptr->left;
    while(currentptr->right!=NULL)
    {
        if(currentptr->value=='X'||currentptr->value=='O')
            {
            cout<<currentptr->value<<" | ";
            }
        else
        {
            cout<<currentptr->number<<" | ";
        }
            currentptr=currentptr->right;
    }

            if(currentptr->value=='X'||currentptr->value=='O')
            {
                cout<<currentptr->value;
            }
        else
        {
            cout<<currentptr->number;
        }
    cout<<endl<<"----------"<<endl;

    currentptr=root;
    currentptr=currentptr->left;
    currentptr=currentptr->left;
    while(currentptr->right!=NULL)
    {
        if(currentptr->value=='X'||currentptr->value=='O')
            {
            cout<<currentptr->value<<" | ";
            }
        else
        {
            cout<<currentptr->number<<" | ";
        }
            currentptr=currentptr->right;
    }

            if(currentptr->value=='X'||currentptr->value=='O')
            {
                cout<<currentptr->value;
            }
        else
        {
            cout<<currentptr->number;
        }
}

int IntBinaryTree::Comp()//computer generated response
{
    if(entryptr==p1)
    {
        if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p3)==true)
        {
            return 3;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p7)==true)
        {
            return 7;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }

    }
    if(entryptr==p2)
    {
        if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p3)==true)
        {
            return 3;
        }
        else if(EmptyCheck(p1)==true)
        {
            return 1;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p7)==true)
        {
            return 7;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }
    }
    if(entryptr==p3)
    {
        if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p1)==true)
        {
            return 1;
        }
        else if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p7)==true)
        {
            return 7;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }

    }
    if(entryptr==p4)
    {
        if(EmptyCheck(p1)==true)
        {
            return 1;
        }
        else if(EmptyCheck(p7)==true)
        {
            return 7;
        }
        else if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p3)==true)
        {
            return 3;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }
    }
    if(entryptr==p5)
    {
        if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p3)==true)
        {
            return 3;
        }
        else if(EmptyCheck(p1)==true)
        {
            return 1;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }
        else if(EmptyCheck(p7)==true)
        {
            return 7;
        }
    }
    if(entryptr==p6)
    {
        if(EmptyCheck(p3)==true)
        {
            return 3;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }
        else if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p1)==true)
        {
            return 1;
        }
        else if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        }
    }
    if(entryptr==p7)
    {
        if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p1)==true)
        {
            return 1;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p3)==true)
        {
            return 3;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }
    }
    if(entryptr==p8)
    {
        if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }
        else if(EmptyCheck(p7)==true)
        {
            return 7;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p1)==true)
        {
            return 1;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p3)==true)
        {
            return 3;
        }
    }
    if(entryptr==p9)
    {
        if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p1)==true)
        {
            return 1;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p3)==true)
        {
            return 3;
        }
        else if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p7)==true)
        {
            return 7;
        }
    }
}

bool IntBinaryTree::EmptyCheck(TreeNode *checkptr)//checks if slot is empty
{
    if(checkptr->value=='X'||checkptr->value=='O')
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool IntBinaryTree::WinCheck()//checks if the user or comp has won
{
    if(p1->value=='X'&&p2->value=='X'&&p3->value=='X')
    {
        return true;
    }
    else if(p4->value=='X'&&p5->value=='X'&&p6->value=='X')
    {
        return true;
    }
    else if(p7->value=='X'&&p8->value=='X'&&p9->value=='X')
    {
        return true;
    }
    else if(p1->value=='X'&&p4->value=='X'&&p7->value=='X')
    {
        return true;
    }
    else if(p2->value=='X'&&p5->value=='X'&&p8->value=='X')
    {
        return true;
    }
    else if(p3->value=='X'&&p6->value=='X'&&p9->value=='X')
    {
        return true;
    }
    else if(p1->value=='X'&&p5->value=='X'&&p9->value=='X')
    {
        return true;
    }
    else if(p7->value=='X'&&p5->value=='X'&&p3->value=='X')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void IntBinaryTree::Back()//Pushes back the responses and redoes the game
{
    cout<<"You won. Now I'm gonna re do my move.\n\n";
    //currentptr->value='\0';
    if(previousptr->value=='X'||previousptr->value=='O')
    {
      //  previousptr->value='\0';//sets the slot to null
    }

    previousptr->value='O';
    //previousptr->value=CompSecond();//enters a new location valur
    cout<<endl;
    Show();
    cout<<endl<<endl;
}
/*
int IntBinaryTree::CompSecond()//generates secondary comp response
{
    int random;
    random = rand() %9+1;//random between 1&9

    switch(random)//switch case
    {
        case 1:
        if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        break;

        case 2:if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p1)==true)
        {
            return 1;
        }
        else if(EmptyCheck(p3)==true)
        {
            return 3;
        }
        else if(EmptyCheck(p5)==true)
        {
            return 5;
        } break;

        case 3:if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        } break;

        case 4:if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p7)==true)
        {
            return 7;
        }
        else if(EmptyCheck(p1)==true)
        {
            return 1;
        } break;

        case 5:if(EmptyCheck(p7)==true)
        {
            return 7;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }
        else if(EmptyCheck(p1)==true)
        {
            return 1;
        }
        else if(EmptyCheck(p3)==true)
        {
            return 3;
        }
        else if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }

        case 6:if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p2)==true)
        {
            return 2;
        }
        else if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }
        else if(EmptyCheck(p3)==true)
        {
            return 3;
        } break;

        case7:if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p4)==true)
        {
            return 4;
        }break;

        case 8:if(EmptyCheck(p4)==true)
        {
            return 4;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        }
        else if(EmptyCheck(p7)==true)
        {
            return 7;
        }
        else if(EmptyCheck(p9)==true)
        {
            return 9;
        }
        else if(EmptyCheck(p5)==true)
        {
            return 5;
        } break;

        case 9:if(EmptyCheck(p5)==true)
        {
            return 5;
        }
        else if(EmptyCheck(p8)==true)
        {
            return 8;
        }
        else if(EmptyCheck(p6)==true)
        {
            return 6;
        } break;

        default: cout<<"A problem  occured\n";break;
    }

}
*/
bool IntBinaryTree::Full()//checks to see if grid is full
{
    if((p1->value=='X'||p1->value=='O')&&(p2->value=='X'||p2->value=='O')&&(p3->value=='X'||p3->value=='O')&&(p4->value=='X'||p4->value=='O')&&(p5->value=='X'||p5->value=='O')&&(p6->value=='X'||p6->value=='O')&&(p7->value=='X'||p7->value=='O')&&(p8->value=='X'||p8->value=='O')&&(p9->value=='X'||p9->value=='O'))
    {
        return true;
    }
    else
    {
        return false;
    }
}






