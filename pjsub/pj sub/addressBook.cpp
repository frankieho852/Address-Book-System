#include "addressBook.h"
#include"treeNode.h"

#include<iostream>

addressBook::addressBook(string data[15]) 			//big data is sum of 15 small data
{
	title = new treeNode();
	surname = new treeNode();
	gaivenName = new treeNode();
	dateOfBir = new treeNode();
	address = new treeNode();
	phoneNum = new treeNode();
	emailAdd = new treeNode();
	company = new treeNode();
	occupation = new treeNode();
	gender = new treeNode();
	city = new treeNode();
	state = new treeNode();
	zip = new treeNode();
	country = new treeNode();
	telephonecode = new treeNode();
	setData(data);

}

void addressBook::setData(string arr[15]) {		//set data function
	for (int i = 0; i < 15;i++) {
		if (arr[i] != "NULL")
			switch (i + 1) {
			case 1:
				title->data = arr[0];
				break;
			case 2:
				surname->data = arr[1];
				break;
			case 3:
				gaivenName->data = arr[2];
				break;
			case 4:
				gender->data = arr[3];
				break;
			case 5:
				dateOfBir->data = arr[4];
				break;
			case 6:
				address->data = arr[5];
				break;
			case 7:
				city->data = arr[6];
				break;
			case 8:
				state->data = arr[7];
				break;
			case 9:
				zip->data = arr[8];
				break;
			case 10:
				country->data = arr[9];
				break;
			case 11:
				telephonecode->data = arr[10];
				break;
			case 12:
				phoneNum->data = arr[11];
				break;
			case 13:
				emailAdd->data = arr[12];
				break;
			case 14:
				occupation->data = arr[13];
				break;
			case 15:
				company->data = arr[14];
				break;
			}
	}
}
void addressBook::addRelation(addressBook* input) {	//add relation function
	title->addRelation(input);
	surname->addRelation(input);
	gaivenName->addRelation(input);
	gender->addRelation(input);
	dateOfBir->addRelation(input);
	address->addRelation(input);
	city->addRelation(input);
	state->addRelation(input);
	zip->addRelation(input);
	country->addRelation(input);
	telephonecode->addRelation(input);
	phoneNum->addRelation(input);
	emailAdd->addRelation(input);
	occupation->addRelation(input);
	company->addRelation(input);
}


void addressBook::display() {				 // display function
	cout << title->data << endl;
	cout << surname->data << endl;
	cout << gaivenName->data << endl;
	cout << gender->data << endl;
	cout << dateOfBir->data << endl;
	cout << address->data << endl;
	cout << city->data << endl;
	cout << state->data << endl;
	cout << zip->data << endl;
	cout << country->data << endl;
	cout << telephonecode->data << endl;
	cout << phoneNum->data << endl;
	cout << emailAdd->data << endl;
	cout << occupation->data << endl;
	cout << company->data << endl;
	cout << endl;
}












