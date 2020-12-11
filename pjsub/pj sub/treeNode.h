#ifndef TREENODE_H
#define TREENODE_H
#include<string>
#include "addressBook.h"
using namespace std;
class treeNode {
public:
	addressBook* addBook;		// for have the contact with the big data
	treeNode* parentNode;
	treeNode *sameNext;			//the next node with same data
	treeNode *leftNext;			//smaller than current node
	treeNode *rightNext;			//bigger than current node
	string data;
	int height;
	int numOfSame;			//how many num have same data
	treeNode() {
		sameNext = NULL;
		leftNext = NULL;
		rightNext = NULL;
		data = "NULL";
	}
	treeNode(treeNode* input) {		//input data(constr)
		addBook = input->addBook;
	}
	treeNode(string input, addressBook* nAddBook = NULL) {
		treeNode *sameNext = NULL;
		treeNode *leftNext = NULL;
		treeNode *rightNext = NULL;
		treeNode* parentNode = NULL;
		addBook = nAddBook;
		data = input;
	}
	void modify(string input) {		//change the data
		data = input;
	}
	void addRelation(addressBook* input)//add relation function
	{
		addBook = input;
	}

	void deleteByAddBook(treeNode* input) {//delete function
		treeNode* Temp = input;
		if (input->sameNext != NULL) {//delete same
			cout << "delete same" << endl;
			input = input->sameNext;

			Temp->addBook = input->addBook;
			Temp->sameNext = input->sameNext;
		}
		else if (input->parentNode == NULL) {
			if (input->leftNext != NULL) {
				input = input->leftNext;
				while (input->rightNext != NULL) {
					input = input->rightNext;
				}
			}
			else {
				input = input->rightNext;
				while (input->leftNext != NULL) {
					input = input->leftNext;
				}
			}
			if (Temp->leftNext->data == input->data)
				Temp->leftNext = input->leftNext;
			else if (Temp->rightNext->data == input->data)
				Temp->rightNext = input->rightNext;
			Temp->sameNext = input->sameNext;
			Temp->data = input->data;
			Temp->addBook = input->addBook;
			delete input;

		}
		else {
			if (input->rightNext == NULL && input->leftNext == NULL) {
				string data;
				if (Temp->parentNode->leftNext != NULL)
					data = Temp->parentNode->leftNext->data;
				if (Temp->data == data) {
					cout << "L" << endl;
					Temp->parentNode->leftNext = NULL;//linking the parent note to new childen
				}
				else {
					cout << "R" << endl;
					Temp->parentNode->rightNext = NULL;//linking the parent note to new childen
				}
				delete input;
				cout << "delete with no childen" << endl;
				return;
			}
			else if (input->rightNext != NULL && input->leftNext != NULL) {
				cout << "delete with two child" << endl;
				if (input->leftNext != NULL)
					input = input->leftNext;
				while (input->rightNext != NULL) {
					input = input->rightNext;
				}
				Temp->sameNext = input->sameNext;
				Temp->data = input->data;
				Temp->addBook = input->addBook;
				if (input == Temp->leftNext)
					Temp->leftNext = NULL;
				delete input;

			}
			else if (input->rightNext != NULL) {
				cout << "delete with right childen" << endl;
				input = input->rightNext;
				Temp->addBook = input->addBook;
				Temp->data = input->data;
				Temp->rightNext = input->rightNext;
				Temp->leftNext = input->leftNext;
				Temp->sameNext = input->sameNext;
				delete input;
			}
			else {
				cout << "delete with left childen" << endl;
				input = input->leftNext;
				Temp->addBook = input->addBook;
				Temp->data = input->data;
				Temp->rightNext = input->rightNext;
				Temp->leftNext = input->leftNext;
				Temp->sameNext = input->sameNext;
				delete input;
			}
		}
	}
};


#endif
#pragma once


