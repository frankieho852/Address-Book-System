#include"tree.h"
#include"treeNode.h"
#include<iostream>
using namespace std;
inline int max(int L, int R) {
	if (L<R)
		return R;
	else
		return L;
}
string tree::defineData(treeNode* input) {	//define data function
	string result="";
	if (input = NULL)
		return result;
	else
		return input->data;
}
void tree::setHead(treeNode* nHead) {		//set head
	head = nHead;
}
treeNode* tree::getHead() {			//get head
	return head;
}
treeNode* tree::rotateZigZig(treeNode* parentNode, string direction) {//rotate function
	//cout << "rotate zigzig" << endl;
	treeNode* currNode = NULL;
	if (direction == "R") {
		currNode = parentNode->rightNext;
		parentNode->rightNext = currNode->leftNext;
		if(currNode->leftNext)
			currNode->leftNext->parentNode=parentNode;
		currNode->leftNext = parentNode;
		currNode->parentNode = parentNode->parentNode;
		parentNode->parentNode = currNode;
		parentNode->height = max(high(parentNode->leftNext), high(parentNode->rightNext)) + 1;
		currNode->height = max(currNode->leftNext->height, currNode->rightNext->height) + 1;
		if (currNode->rightNext->height - currNode->leftNext->height == 2)
			currNode = rotateZigZag(currNode, "L");
		if (currNode->rightNext->height - currNode->leftNext->height == -2)
			currNode = rotateZigZag(currNode, "L");
	}
	else {
		currNode = parentNode->leftNext;
		parentNode->leftNext = currNode->rightNext;
		if(currNode->rightNext)
			currNode->rightNext->parentNode=parentNode;
		currNode->rightNext = parentNode;
		currNode->parentNode = parentNode->parentNode;
		parentNode->parentNode = currNode;
		parentNode->height = max(high(parentNode->leftNext), high(parentNode->rightNext)) + 1;
		currNode->height = max(high(currNode->rightNext), high(currNode->leftNext)) + 1;
		if (high(currNode->leftNext) - high(currNode->rightNext) == 2)
			currNode = rotateZigZag(currNode, "R");
		if (high(currNode->leftNext) - high(currNode->rightNext) == -2)
			currNode = rotateZigZag(currNode, "R");
	}
	if (parentNode == head) {
		setHead(currNode);
		//cout << "set head again" << endl;
	}
	return currNode;
}
treeNode* tree::rotateZigZag(treeNode* parentNode, string direction) {//rotate function
	//cout << "rotate zigzag" << endl;
	treeNode* currNode = NULL;
	if (direction == "R") {
		currNode = parentNode->rightNext->leftNext;

		parentNode->rightNext->leftNext = currNode->rightNext;

		
		currNode->rightNext = parentNode->rightNext;
		parentNode->rightNext->parentNode = currNode;

		parentNode->rightNext = currNode->leftNext;
		currNode->leftNext = parentNode;

		currNode->parentNode = parentNode->parentNode;
		parentNode->parentNode = currNode;
		currNode->rightNext->parentNode = currNode;

		parentNode->height = max(high(parentNode->leftNext), high(parentNode->rightNext)) + 1;
		currNode->rightNext->height= max(high(currNode->rightNext->rightNext), high(currNode->rightNext->leftNext)) + 1;
		currNode->height= max(high(currNode->rightNext), high(currNode->leftNext)) + 1;
	}
	if (direction == "L") {
		currNode = parentNode->leftNext->rightNext;

		parentNode->leftNext->rightNext = currNode->leftNext;

		currNode->leftNext = parentNode->leftNext;
		parentNode->leftNext->parentNode = currNode;

		parentNode->leftNext = currNode->rightNext;
		currNode->rightNext = parentNode;

		currNode->parentNode = parentNode->parentNode;
		parentNode->parentNode = currNode;
		currNode->leftNext->parentNode = currNode;

		parentNode->height = max(high(parentNode->leftNext), high(parentNode->rightNext)) + 1;
		currNode->leftNext->height = max(high(currNode->leftNext->rightNext), high(currNode->leftNext->leftNext)) + 1;
		currNode->height = max(high(currNode->rightNext), high(currNode->leftNext)) + 1;
	}
	if (parentNode == head)
		setHead(currNode);
	return currNode;
}
treeNode* tree::addNode(treeNode* newNode, treeNode* currNode) {	// add node function
	//may improve
	if (head == NULL) {
		setHead(newNode);
		cout << "set head" << endl;
		return newNode;

	}
	if (currNode == NULL) {
		currNode = head;
	}
	treeNode* pNode = currNode;
	int result;
	result = compareBigger(newNode->data, currNode->data, 0);
	if (result == 0) {//when result equal NULL, mean the same
		currNode = currNode->sameNext;    	//link to same and break
		pNode->sameNext = newNode;	//change newNode to LLNode
		newNode->sameNext = currNode;
		return pNode;
	}
	if (result == 1) {
		// cout << "pass through " << currNode->data << endl;
		int LChildrenHeight;
		if (currNode->leftNext == NULL)
			LChildrenHeight = -1;
		else
			LChildrenHeight = currNode->leftNext->height;

		if (currNode->rightNext == NULL) {//base case
			currNode->rightNext = newNode;
			newNode->parentNode = currNode;
			currNode->height = max(LChildrenHeight, 0) + 1;
			return currNode;
		}
		else {
			currNode->rightNext = addNode(newNode, currNode->rightNext);
			currNode->rightNext->parentNode = currNode;
			currNode->height = max(LChildrenHeight, currNode->rightNext->height) + 1;
			if (currNode->rightNext->height - LChildrenHeight == 2)
				if (compareBigger(newNode->data, currNode->rightNext->data, 0) == 1)
					currNode = rotateZigZig(currNode, "R");//sigo
				else
					currNode = rotateZigZag(currNode, "R");//double
			else if (currNode->rightNext->height - LChildrenHeight == -2) {
				return currNode;
			}
			return currNode;
		}
	}
	else if (result == -1) {
		int RChildrenHeight;
		if (currNode->rightNext == NULL)
			RChildrenHeight = -1;
		else
			RChildrenHeight = currNode->rightNext->height;
		if (currNode->leftNext == NULL) {//base case
			currNode->leftNext = newNode;
			newNode->parentNode = currNode;
			currNode->height = max(RChildrenHeight, 0) + 1;
			return currNode;
		}
		else {
			currNode->leftNext = addNode(newNode, currNode->leftNext);
			currNode->leftNext->parentNode = currNode;
			currNode->height = max(RChildrenHeight, currNode->leftNext->height) + 1;
			if (currNode->leftNext->height - RChildrenHeight == 2)
				if (compareBigger(newNode->data, currNode->leftNext->data, 0) == -1)
					currNode = rotateZigZig(currNode, "L");
				else
					currNode = rotateZigZag(currNode, "L");
			else if (currNode->leftNext->height - RChildrenHeight == -2) {
				return currNode;
			}
			return currNode;
		}
	}
}
void tree::dis(treeNode* input) {//display function
	if (input == NULL)
		input = head;

	if (input->leftNext) {
		dis(input->leftNext);
	}
	treeNode*currNode = input;
	while (currNode->sameNext!=NULL) {
		addressBook* localion = currNode->addBook;
		cout << localion->title->data << "\t";
		cout << localion->surname->data << "\t";
		cout << localion->gaivenName->data << "\t";
		cout << localion->dateOfBir->data << "\t";
		cout << localion->address->data << "\t";
		cout << localion->phoneNum->data << "\t";
		cout << localion->emailAdd->data << "\t";
		cout << localion->company->data << "\t";
		cout << localion->occupation->data << "\t";
		cout << localion->gender->data << "\t";
		cout << localion->city->data << "\t";
		cout << localion->state->data << "\t";
		cout << localion->zip->data << "\t";
		cout << localion->company->data << "\t";
		cout << localion->telephonecode->data;
		cout << endl;
		currNode = currNode->sameNext;
	}
	if (input->rightNext)
		dis(input->rightNext);
	return;
}

void tree::output(string& store, int i, treeNode * input) {//output function
	if (input == NULL)
		input = head;
	i = 0;
	if (input->leftNext) {
		cout << input->data << endl;
		output(store,i, input->leftNext);
	}
	treeNode*currNode = input;
	if (currNode->sameNext) {
		addressBook* localion = input->addBook;
		store=store + localion->title->data + "\t" + localion->surname->data + "\t" + localion->gaivenName->data + "\t" + localion->dateOfBir->data + "\t" + localion->address->data + "\t" + localion->phoneNum->data + "\t" + localion->emailAdd->data + "\t" + localion->company->data + "\t" + localion->occupation->data + "\t" + localion->gender->data + "\t" + localion->city->data + "\t" + localion->state->data + "\t" + localion->zip->data + "\t" + localion->company->data + "\t" + localion->telephonecode->data+"\n";
		currNode = currNode->sameNext;
		i++;
	}
	if (input->rightNext)
		output(store,i,input->rightNext);
	return;
}


int tree::compareBigger(string a, string b, int num) {// compare
	int i = num;
	if (int(a[i]) > int(b[i]))
		return 1;
	else if (int(a[i]) < int(b[i])) {
		return -1;
	}
	else if (a == b)
		return 0;//the same
	else if (i >= a.length() && i <= b.length()) {
		return -1;
	}
	else if (i >= b.length() && i <= a.length())
		return 1;
	else {
		i++;
		return compareBigger(a, b, i);
	}
}
int tree::high(treeNode * currNode)
{
	if (currNode == NULL)
		return -1;
	else
		return currNode->height;
}
treeNode* tree::search(string input) {			//search function
	treeNode* currNode = head;
	int compare;
	treeNode* result = NULL;
	compare = compareBigger(input, currNode->data);
	while (compare != 0) {
		if (compare == 1) {
			currNode = currNode->rightNext;
		}
		else if (compare == -1) {
			currNode = currNode->leftNext;
		}
		compare = compareBigger(input, currNode->data);
	}
	return currNode;
}
/*treeNodeLL* tree::seach(string input[9], int choose) {
treeNodeLL* result = NULL;
string data = input[choose];
treeNode* first = search(data);
while (first) {
if (first->addBook->compare(input, choose) == true)
result->inserNode(first);
}
return result;
}*/
treeNode* tree::modifly(treeNode*input,  string modData) {
	treeNode* result = new treeNode(input);
	result->data = modData;
	deleteNode(input);
	addNode(result);
	return result;
}

void tree::deleteNode(treeNode* delNode, treeNode* currNode) {
	//may improve

	if (head == NULL) {//for no any data in the tree
		cout << "There is not any dtat" << endl;
		return;
	}
	if (currNode == NULL) {//for first time
		currNode = head;
	}

	treeNode* pNode = currNode;//set parent node for next time call(recousive)
	int result;
	result = compareBigger(delNode->data, currNode->data, 0);

	if (result == 0) {//when result equal NULL, mean the same
					  //base case
		cout << "delete" << endl;
		delNode->deleteByAddBook(delNode);
		return;
	}
	else if (result == 1) {
		if (currNode->rightNext == NULL) {//base case
			cout << "no this data" << endl;
			return;
		}
		else {
			deleteNode(delNode, currNode->rightNext);
			currNode->height = max(high(currNode->leftNext), high(currNode->rightNext)) + 1;
			//compareBigger(defineData(delNode), defineData(currNode->rightNext), 0) == 1;
			if (high(currNode->leftNext) - high(currNode->rightNext) == 2)
				if (currNode->leftNext->leftNext != NULL)
					currNode = rotateZigZig(currNode, "L");
				else
					currNode = rotateZigZag(currNode, "L");
			return;
		}
	}
	else if (result == -1) {
		if (currNode->leftNext == NULL) {//base case
			cout << "no this data" << endl;
			return;
		}
		else {
			deleteNode(delNode, currNode->leftNext);
			currNode->height = max(high(currNode->rightNext), high(currNode->leftNext)) + 1;
			if (high(currNode->rightNext) - high(currNode->leftNext) == 2) {
				if (currNode->rightNext->rightNext != NULL)
					currNode = rotateZigZig(currNode, "R");
				else
					currNode = rotateZigZag(currNode, "R");
			}
			return;
		}
	}return;
}
/*treeNode* tree::deleteNode(treeNode* input ) {//can imprave, hold same or not;
treeNode* Temp = input;//if any one need to delete plase call like:parent->left =delete(parent->left)
if (input->sameNext != NULL) {
input = input->sameNext;
input->rightNext = Temp->rightNext;
input->leftNext = Temp->leftNext;
input->height = Temp->height;
input->numOfSame--;
}
else {
if (input->rightNext == NULL && input->leftNext == NULL) {
delete input;
return NULL;
}
else if (input->rightNext != NULL && input->leftNext != NULL) {
while (input->leftNext = NULL) {
input = input->leftNext;
}
Temp->sameNext = input->sameNext;
Temp->data = input->data;
delete input;
return Temp;
}
else if (input->rightNext != NULL) {
input = input->rightNext;
delete Temp;
}
else {
input = input->leftNext;
delete Temp;
}
}
return input;
}*/

