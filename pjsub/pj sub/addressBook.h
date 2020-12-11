#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include<iostream>
#include<string>
class treeNode;
using namespace std;
class addressBook {
private:


public:
	treeNode* title;     			//data of address
	treeNode* surname;			
	treeNode* gaivenName;
	treeNode* dateOfBir;
	treeNode* address;
	treeNode* phoneNum;
	treeNode* emailAdd;
	treeNode* company;
	treeNode* occupation;
	treeNode* gender;
	treeNode* city;
	treeNode* state;
	treeNode* zip;
	treeNode* country;
	treeNode* telephonecode;
	addressBook* next;


	addressBook(string data[15]);		//.cpp	

	void setData(string arr[15]);

	void addRelation(addressBook * input);

	void display();

};
#endif

