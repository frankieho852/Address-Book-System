#ifndef TREE_H
#define TREE_H
#include "treeNode.h"
#include<string>
#include<iostream>
//#include"treeNodeLL.h"
using namespace std;
class tree
{
public:
	treeNode* head;					//node head
	tree() { head = NULL; }
	string defineData(treeNode * input);			//set data
	void setHead(treeNode * nHead);			//set head
	treeNode * getHead();					//return head
	treeNode* rotateZigZig(treeNode * parentNode, string direction);	//rotate function
	treeNode * rotateZigZag(treeNode * parentNode, string direction);	//rotate function
	treeNode* addNode(treeNode* newNode, treeNode* currNode = NULL);	//add function
	void dis(treeNode * input = NULL);			//display function

	void output(string & store, int i = 0, treeNode * input = NULL);



	int compareBigger(string a, string b, int num = 0);	//compare function
	int high(treeNode* currNode);
	treeNode* search(string input);			//search function
	treeNode* modifly(treeNode * input, string modData);	//chande data function
	void deleteNode(treeNode * deleteNode, treeNode * currNode = NULL);//delete function

};
#endif
#pragma once


