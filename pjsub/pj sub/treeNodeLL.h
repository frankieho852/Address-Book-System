#ifndef TREENODELL_H
#define TREENODELL_H
#include"node.h"
class treeNodeLL {
private:
	node* head;
public:

	treeNodeLL();
	void setHead(node* nHead);
	node* getHead();
	void inserNode(node * input);
	~treeNodeLL();

};
#endif