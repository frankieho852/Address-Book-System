#include "treeNode.h"
#include "treeNodeLL.h"
using namespace std;

treeNodeLL::treeNodeLL() {        //constr
	head = NULL;
}
void treeNodeLL::setHead(node* nHead) {//set head
	head = nHead;
}
node* treeNodeLL::getHead() {		//get head
	return head;
}
void treeNodeLL::inserNode(node* input) {    //inser
	if (input == NULL)
		return;
	else {
		if (head == NULL)
			setHead(input);
		input->next = head->next;
		head->next = input;
	}
}


treeNodeLL :: ~treeNodeLL() {         //delstr
	node* currNode;
	currNode = head;
	node* sameNextNode = NULL;
	while (currNode != NULL) {
		sameNextNode = currNode->next;
		delete currNode;
		currNode = sameNextNode;
	}
}
