#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <cassert>
#include <cstring>
#include <locale>     
#include <cstddef>  
#include <fstream>  //to read file
#include "BinarySearchTree.h"
using namespace std;

int conflictflag=0,modifyflag=0,printflag=0;
BinarySearchTree :: BinarySearchTree() //constructor
{
	nullTree = true;
	leftTree = NULL;
	rightTree = NULL;
}

bool BinarySearchTree :: isEmpty() const
{
	return nullTree;
}

void BinarySearchTree :: getData(string &n,int &d,int &h)
{
	assert(!isEmpty());
	n=name;
	d=day;
	h=hour;
}

void BinarySearchTree :: add(string &n,const int &d,const int &h)
{
	if (nullTree)
	{
		nullTree = false;
		leftTree = new BinarySearchTree;
		rightTree = new BinarySearchTree;
		name = n;
		day = d;
		hour = h;
	}
	else if (d == day && h == hour )
    {
        conflictflag=1;
    }
	else if ( (d < day) || ( d== day && h<hour) )
    {
        leftTree->add(n,d,h); // add in left subtree
    }
	else if(d > day || (d == day && h>hour))
    {
        rightTree->add(n,d,h); // add in right subtree
    }
}

BinarySearchTree* BinarySearchTree :: retrieve(const int &d,const int &h)
{
	if (nullTree || (d == day && h == hour)) // return pointer to tree for which retrieve was called
		return this;
	else if ( (d < day) || ( d== day && h<hour) )
		return leftTree->retrieve(d,h); // recurse left
	else if (d > day || (d == day && h>hour))
		return rightTree->retrieve(d,h); // recurse right
}

BinarySearchTree* BinarySearchTree :: left()
{
	assert(!isEmpty());
	return leftTree;
}

BinarySearchTree* BinarySearchTree ::right()
{
	assert(!isEmpty());
	return rightTree;
}

void BinarySearchTree :: makeLeft(BinarySearchTree * T1)
{
	assert(!isEmpty());
	assert(left()->isEmpty());
	delete left(); // could be nullTree true, w/data
	leftTree = T1;
}

void BinarySearchTree :: makeRight(BinarySearchTree * T1)
{
	assert(!isEmpty());
	assert(right()->isEmpty());
	delete right();
	rightTree = T1;
}

BinarySearchTree* BinarySearchTree :: FindMin(BinarySearchTree* root)
{
	while(root->leftTree->leftTree != NULL) root = root->leftTree;
	return root;
}

BinarySearchTree* BinarySearchTree :: delet(BinarySearchTree * root,const int &d,const int &h)
{
    if(root == NULL)
    {
        return root;
    }
	else if((d < root->day) || ( d== root->day && h<root->hour))
	{
        root->leftTree = delet(root->leftTree,d,h);
	}
	else if((d > root->day) || (d == root->day && h>root->hour))
    {
        root->rightTree = delet(root->rightTree,d,h);
    }
	else
    {
		// Case 1:  No child
		if(root->leftTree->leftTree == NULL && root->rightTree->rightTree == NULL)
        {
			delete root;
			root = new BinarySearchTree;
		}
		//Case 2: One child
		else if(root->leftTree->leftTree == NULL)
		{
			BinarySearchTree *temp = root;
			root = root->rightTree;
			delete temp;
		}
		else if(root->rightTree->rightTree == NULL)
		{
			BinarySearchTree *temp = root;
			root = root->leftTree;
			delete temp;
		}
		// case 3: 2 children
		else
		{
			BinarySearchTree *temp = FindMin(root->rightTree);
			root->name = temp->name;
			root->day = temp->day;
            root->hour = temp->hour;
			root->rightTree = delet(root->rightTree,temp->day,temp->hour);
		}
	}
	return root;
}

string BinarySearchTree :: find(const int &d,const int &h)
{ //3amlha bt return string 3ashan sbb fakr feh le el mara el million
	BinarySearchTree * x =retrieve(d,h);
	if(x==NULL)
	{
		return "";
	}
	else
		return x->name;
}

void BinarySearchTree :: modify(string &n,const int &d,const int &h)
{
	BinarySearchTree * x =retrieve(d,h);
	if(x==NULL)
	{
	    modifyflag=1;
	}
	else
	{
		x->name=n;
	}
}

void BinarySearchTree :: print(BinarySearchTree * T1)
{
	extern ofstream opfile;
	string titlee="";
	int dayy,hourr;
	if (! T1->isEmpty())
	{
	    printflag=1;
		// traverse left child
		T1->print(T1->left());
		// visit tree
		T1->getData(titlee,dayy,hourr);
		opfile<<titlee<<' '<<dayy<<' '<<hourr<<endl;
		cout<<titlee<<' '<<dayy<<' '<<hourr<<endl;
        // traverse right child
		T1->print(T1->right());
	}
}
