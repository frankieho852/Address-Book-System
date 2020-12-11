#ifndef NODE_H
#define NODE_H
#include<string>
#include "addressBook.h"
#include"treeNode.h"

using namespace std;
class node{

public:
	treeNode* a;
	addressBook* addBook;
	node* next;
	
	node(treeNode* input) {
		a = input;
		addBook = input->addBook;
	}
};

#endif
#pragma once

