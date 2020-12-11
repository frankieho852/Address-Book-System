#include<string>
#include<iostream>
#include"tree.h"
#include"treeNode.h"
#include "addressBook.h"
#include"node.h"
#include "treeNodeLL.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <iostream>     // std::cout
#include <algorithm>    // std::min
#include <windows.h>
#include <ctime>
#include <time.h> 
#include<sstream>
using namespace std;

void userread(string Fname, string Location, tree*&treestore) {
	cout << "Import the vaild location with your txt.file and the file name(E.g.C:\\xxxx\\xxxx\\Desktop\\your file.txt)" << endl;
	string location;
	cout << "Location:";
	cin.ignore();
	getline(cin, Location);
	cout << "File name: ";// Imsert the file by input the location and name to find the txt.file 
	//cin.ignore();		   // and use getline to read data
	getline(cin, Fname);

	location = Location + Fname;
	cout << Location + Fname << endl;
	const char *str = location.c_str();
	ifstream myfile(location);
	string line;
	clock_t startTime = clock();	// After read the file, it pop up a clock to count the duration of reading file
	while (getline(myfile, line))
	{
		string record[15];
		stringstream ss(line);
		for (int i = 0; i < 15; i++) {
			getline(ss, record[i], '\t');
			// use add function		//  Show the number of data it already read
		}
		addressBook* pA = new addressBook(record);		// add the record to the pointer of the avl tree
		pA->addRelation(pA);						// Each different criteria distributed to treestore
		treestore[0].addNode(pA->title);
		treestore[1].addNode(pA->surname);
		treestore[2].addNode(pA->gaivenName);
		treestore[3].addNode(pA->gender);
		treestore[4].addNode(pA->dateOfBir);
		treestore[5].addNode(pA->address);
		treestore[6].addNode(pA->city);
		treestore[7].addNode(pA->state);
		treestore[8].addNode(pA->zip);
		treestore[9].addNode(pA->country);
		treestore[10].addNode(pA->telephonecode);
		treestore[11].addNode(pA->phoneNum);
		treestore[12].addNode(pA->emailAdd);
		treestore[13].addNode(pA->occupation);
		treestore[14].addNode(pA->company);
	}
	myfile.close();
	clock_t endTime = clock();
	cout << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

void copyFile(string Cname, string CLocation, string nstr) {
	/*char* str = new char[nstr.length()+2];
	int i = 0;
	for (;i < nstr.length();i++)
	{
	str[i] = nstr[i];
	}str[i + 1] = '\n';*/
	const char *str = nstr.c_str();
	cout << "Import the save file location with the new txt.file and the new file name(E.g.C:\\xxxx\\xxxx\\Desktop\\your new file.txt)" << endl;
	string location;
	cout << "Location:";			//Import or copy the saved record write into a new file
	cin.ignore();					//by enter the txt.file location
	std::getline(cin, CLocation);
	cout << "File name: ";
	cin.ignore();
	std::getline(cin, Cname);
	location = CLocation + Cname;
	cout << location << endl;
	ofstream copy(location);
	cout << strlen(str) << endl;
	copy.write(str, strlen(str));
	copy.close();
}

int Begining() {
	system("cls");
	int choice;
	do {
		cout << "Address book" << endl;
		cout << "1. Insert a new record." << endl;				//User can through enter a txt file location and filename to insert records 
		cout << "2. Insert a batch of new records." << endl;	//in their own pc file location
		cout << "3. Modify an existing record" << endl;			//User can modify the record after saving and searching the record you want to modify
		cout << "4. Search record with various criteria" << endl; //User can search the existing record by your inserted file through input the search words and its designated criteria
		cout << "5. Delete an existing record" << endl;			//User can delete the existing record which after modify or searching in which two are already save in tree node 
		cout << "6. Print all entries" << endl;					//User can choose whether their want to print out the modify,searching or all record in file if want to show that
		cout << "7. Exit" << endl;
		cout << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
		if (choice<1 || choice>7) {
			cout << "Wrong input, Please input again!" << endl;
			system("pause");
			system("cls");
			return Begining();
		}
	} while (choice < 1 || choice>7);
	return choice;
}

bool Nextpage(int choice, treeNode**& store, tree*& treestore, treeNodeLL& searchResult) {
	system("cls");
	switch (choice) {
	case 1:
	{		// insert new record function by adding txtfile and put it to treenode for save 
		int choice1;
		cout << "1. insert a new record" << endl;
		cout << "2. Go to home page" << endl;
		cout << endl;
		cout << "Please enter your choice: ";
		cin >> choice1;
		if (choice1 == 1) {
			string record[15];
			cout << "Please import your record: " << endl;
			for (int i = 0; i < 15; i++) {
				cin.ignore();
				getline(cin, record[i]);
				// use add function
			}
			clock_t startTime = clock();
			addressBook* pA = new addressBook(record);
			pA->addRelation(pA);
			treestore[0].addNode(pA->title);
			treestore[1].addNode(pA->surname);
			treestore[2].addNode(pA->gaivenName);
			treestore[3].addNode(pA->gender);
			treestore[4].addNode(pA->dateOfBir);
			treestore[5].addNode(pA->address);
			treestore[6].addNode(pA->city);
			treestore[7].addNode(pA->state);
			treestore[8].addNode(pA->zip);
			treestore[9].addNode(pA->country);
			treestore[10].addNode(pA->telephonecode);
			treestore[11].addNode(pA->phoneNum);
			treestore[12].addNode(pA->emailAdd);
			treestore[13].addNode(pA->occupation);
			treestore[14].addNode(pA->company);
			clock_t endTime = clock();
			cout << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		}
		if (choice1 > 2 || choice1 < 1)
		{
			cout << "Wrong input, Please input again!" << endl;
			system("pause");
			system("cls");
			return Nextpage(3, store, treestore, searchResult);
		}
		else {
		}
	}
	system("pause");
	system("cls");
	break;
	case 2:
	{
		int choice2;
		cout << "1. Insert a batch of new records." << endl;//Insert a batch of new records at useread function
		cout << "2. Go to home page" << endl;					// insert new record function
		cout << endl;
		cout << "Please enter your choice: ";
		cin >> choice2;
		if (choice2 == 1) {
			string fname, location, data;
			userread(fname, location, treestore);
		}
		if (choice2 > 2 || choice2 < 1)
		{
			cout << "Wrong input, Please input again!" << endl;
			system("pause");
			system("cls");
			return Nextpage(2, store, treestore, searchResult);
		}
		else {

		}
		// get the string in the file to node
		// call read function
		// use add function write into txt file
	}
	system("pause");
	system("cls");
	break;
	case 3:
		//3. Modify an existing record
	{
		int choice3;
		int cinput[15];				//For choosing the criteria
		string searchword[15];		// user can input searching word for finding the existing record in deesignated criteria they choose
		do {
			cout << "Address book" << endl;
			cout << "1. Modify existing datas by searing results" << endl;
			cout << "2. Go to Home Page" << endl;
			cout << endl;
			cout << "Please enter your choice: ";
			cin >> choice3;
			if (choice3 > 2 || choice3 < 1)
			{
				cout << "Wrong input, Please input again!" << endl;
				system("pause");
				system("cls");
				return Nextpage(3, store, treestore, searchResult);
			}
			else if (choice3 == 1) {
				if (searchResult.getHead() == NULL)
					Nextpage(4, store, treestore, searchResult);
				system("cls");

				cout << "------------------------------------------------" << endl;
				cout << "Criteria below: " << endl;
				cout << "------------------------------------------------" << endl;
				cout << " 1. Title           2. Surname          3.Gaiven Name" << endl;
				cout << " 4. Gender	         5. Birthday         6. Address " << endl;
				cout << " 7. City		     8. State	         9. Zip Code" << endl;
				cout << "10. Country        11.Telephonecode    12. Phone Number " << endl;
				cout << "13. Email Address  14.Ooccupation      15.Company " << endl;
				cout << "------------------------------------------------" << endl;
				cout << endl;
				cout << "Please choose one criteria for modify the existing record:(Input number) " << endl;


				cin >> cinput[0];
				if (cinput[0] < 0 || cinput[0]>15) {			//Prevent the out range of input number 
					cout << "Wrong input number!" << endl;			
					system("pause");
					return Nextpage(3, store, treestore, searchResult);		//If occurs, return the saving record back to Nextpage
				}

				cout << "Please enter the words for modifdy record!" << endl;

				cin >> searchword[0];

				if (searchResult.getHead() != NULL) {
					node*currNode = searchResult.getHead();
					while (currNode != NULL) {
						switch (cinput[0]) {
						case 1:
							treestore[cinput[0] - 1].modifly(currNode->addBook->title, searchword[0]);
							break;
						case 2:
							treestore[cinput[0] - 1].modifly(currNode->addBook->surname, searchword[0]);
							break;
						case 3:
							treestore[cinput[0] - 1].modifly(currNode->addBook->gaivenName, searchword[0]);
							break;
						case 4:
							treestore[cinput[0] - 1].modifly(currNode->addBook->gender, searchword[0]);
							break;
						case 5:
							treestore[cinput[0] - 1].modifly(currNode->addBook->dateOfBir, searchword[0]);
							break;
						case 6:
							treestore[cinput[0] - 1].modifly(currNode->addBook->address, searchword[0]);
							break;
						case 7:
							treestore[cinput[0] - 1].modifly(currNode->addBook->city, searchword[0]);
							break;
						case 8:
							treestore[cinput[0] - 1].modifly(currNode->addBook->state, searchword[0]);
							break;
						case 9:
							treestore[cinput[0] - 1].modifly(currNode->addBook->zip, searchword[0]);
							break;
						case 10:
							treestore[cinput[0] - 1].modifly(currNode->addBook->country, searchword[0]);
							break;
						case 11:
							treestore[cinput[0] - 1].modifly(currNode->addBook->telephonecode, searchword[0]);
							break;
						case 12:
							treestore[cinput[0] - 1].modifly(currNode->addBook->phoneNum, searchword[0]);
							break;
						case 13:
							treestore[cinput[0] - 1].modifly(currNode->addBook->emailAdd, searchword[0]);
							break;
						case 14:
							treestore[cinput[0] - 1].modifly(currNode->addBook->occupation, searchword[0]);
							break;
						case 15:
							treestore[cinput[0] - 1].modifly(currNode->addBook->company, searchword[0]);
							break;

						}
					}
				}
				cout << "Record modified!" << endl;
			}
			else {
			}
		} while (choice3 < 1 || choice3 > 2);
	}
	system("pause");
	system("cls");
	break;

	case 4:
	{					// For selected the criteria,select and doing motify and save it to node
		int choice4;
		int select[15];
		string words[15];
		do {
			cout << "Address book" << endl;
			cout << "1. Searching various criteria" << endl;
			cout << "2. Go to Home Page" << endl;
			cout << endl;
			cout << "Please enter your choice: ";
			cin >> choice4;
			if (choice4 > 2 || choice4 < 1)
			{
				cout << "Wrong input, Please input again!" << endl;
				system("pause");
				system("cls");
				return Nextpage(4, store, treestore, searchResult);
			}
			else if (choice4 == 1) {
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Criteria below: " << endl;
				cout << "------------------------------------------------" << endl;
				cout << "1. Title           2. Surname           3.Gaiven Name" << endl;
				cout << "4.  Gender	        5. Birthday          6. Address " << endl;
				cout << "7. City		    8. State	         9. Zip Code" << endl;
				cout << "10. Country        11. Telephonecode    12. Phone Number " << endl;
				cout << "13. Email Address  14.Ooccupation       15.Company " << endl;
				cout << "------------------------------------------------" << endl;
				cout << "Please choose one criteria for modify the existing record:(Input number) " << endl;
				int i = 0;

				cin >> select[0];
				if (select[i] < 0 || select[i]>15) {
					cout << "Wrong input number!" << endl;
					system("pause");
					return Nextpage(4, store, treestore, searchResult);
				}


				cout << "The data you want to search:(input words) " << endl;
				cin >> words[0];
				clock_t startTime = clock();
				treeNode* first = treestore[select[0] - 1].search(words[0]);

				if (first != NULL) {
					addressBook* a;
					treeNode* currNode = first;
					while (currNode) {
						a = currNode->addBook;
						node* newNode = new node(currNode);
						searchResult.inserNode(newNode);
						currNode = currNode->sameNext;
						cout << a->title->data << " " << a->surname->data << endl;
					}cout << "Record search!" << endl;
				}
				else {
					cout << "the record not find" << endl;
				}
				clock_t endTime = clock();
				cout << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
			}
			else {
			}
		} while (choice4 < 1 || choice4 > 2);
		// Search record with various criteria
	}
	system("pause");
	system("cls");
	break;

	case 5:
	{			// The record already save can be delete.
		int choice5;
		int recordchoose;
		int cinput;
		string coloumn;
		int confirm;
		do {
			cout << "Address book" << endl;
			cout << "1. Delete records by searching record" << endl;
			cout << "2. Go back to homepage" << endl;
			cout << endl;
			cout << "Please enter your choice: ";
			cin >> choice5;
			if (choice5 > 2 || choice5 < 1)
			{
				cout << "Wrong input, Please input again!" << endl;
				system("pause");
				system("cls");
				return Nextpage(5, store, treestore, searchResult);
			}
			else if (choice5 == 1)
			{
				if (searchResult.getHead() == NULL)
					Nextpage(4, store, treestore, searchResult);
				cout << "Do you confirm delete this record?? [Yes:(1) NO:(0)]" << endl;
				cin >> confirm;
				if (confirm < 0 || confirm >1) {
					cout << "Wrong input number!" << endl;
					system("pause");
					return Nextpage(5, store, treestore, searchResult);
				}
				else if (confirm = 1) {
					if (searchResult.getHead() == NULL)
						Nextpage(4, store, treestore, searchResult);
					node* currNode = searchResult.getHead();
					while (currNode != NULL) {
						treestore[0].deleteNode(currNode->addBook->title);
						treestore[1].deleteNode(currNode->addBook->surname);
						treestore[2].deleteNode(currNode->addBook->gaivenName);
						treestore[3].deleteNode(currNode->addBook->gender);
						treestore[4].deleteNode(currNode->addBook->dateOfBir);
						treestore[5].deleteNode(currNode->addBook->address);
						treestore[6].deleteNode(currNode->addBook->city);
						treestore[7].deleteNode(currNode->addBook->state);
						treestore[8].deleteNode(currNode->addBook->zip);
						treestore[9].deleteNode(currNode->addBook->country);
						treestore[10].deleteNode(currNode->addBook->telephonecode);
						treestore[11].deleteNode(currNode->addBook->phoneNum);
						treestore[12].deleteNode(currNode->addBook->emailAdd);
						treestore[13].deleteNode(currNode->addBook->occupation);
						treestore[14].deleteNode(currNode->addBook->company);
						delete currNode->addBook;
						currNode = currNode->next;
					}
					cout << "Record already delete!" << endl;
				}
				else {

				}
				// use delete function
			}
			else {

			}
		} while (choice5 < 1 || choice5 > 2);
		system("pause");
		system("cls");
		break;
	}

	case 6:
	{			// The function of print out all record in txtfile and the saved record which are modified or searched 
		int choice6;
		do {
			cout << "Address book" << endl;
			//cout << "Confirm print this record? (1:Yes, 2:No, 3.Go back to homepage)" << endl;
			cout << "1. Print all entries " << endl;
			cout << "2. Show all entries in a new txt file" << endl;
			cout << "3. Go back to homepage" << endl;
			cout << endl;
			cout << "Please enter your choice: ";
			cin >> choice6;
			if (choice6 > 3 || choice6 < 1)
			{
				cout << "Wrong input, Please input again!" << endl;
				system("pause");
				system("cls");
				return Nextpage(6, store, treestore, searchResult);
			}
			else if (choice6 == 1)
			{
				int ch;
				cout << "------------------------------------------------" << endl;
				cout << "1. Title           2. Surname           3.Gaiven Name" << endl;
				cout << "4.  Gender	        5. Birthday          6. Address " << endl;
				cout << "7. City		    8. State	         9. Zip Code" << endl;
				cout << "10. Country        11. Telephonecode    12. Phone Number " << endl;
				cout << "13. Email Address  14.Ooccupation       15.Company " << endl;
				cout << "------------------------------------------------" << endl;
				cout << "Please choose one criteria for printing all entries record:(Input number) " << endl;
				cin >> ch;
				treestore[ch - 1].dis();// use print function
			}
			else if (choice6 == 2)
			{
				cout << "txt file loading..." << endl;
				// outputtxt();
				string Cname, CLocation;
				string output;
				treestore[0].output(output);
				copyFile(Cname, CLocation, output);
			}
			else {
			}
		} while (choice6 < 1 || choice6 > 3);
		system("pause");
		system("cls");
		break;
	}
	case 7:
	{exit(0);
	break;
	}
	default:
	{cout << "Your enter a wrong number!" << endl;
	system("pause");
	Begining();
	}
	}
	return false;
}

int main() {
	treeNode** store = new treeNode*[15];
	tree* treestore = new tree[15];
	treeNodeLL searchResult;
	bool quit;
	do {
		system("cls");
		quit = Nextpage(Begining(), store, treestore, searchResult);
	} while (!quit);
	system("pause");
	return 0;
}