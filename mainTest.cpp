 //Sources: https://github.com/kamal-choudhary/singly-linked-list/blob/master/Linked%20List.cpp
#include "classes.hpp"

int main()
{

	//::::::::::::::::::::: Welcome and Load Routine:::::::::::::::::::::::::::::::::
	cout << "Welcome to the Test app!" << endl;
	ArtistTypes artistDB;
	bool cont = true;
	int sent;

	while (cont) {
		cin.clear(); //Input stream clear
	
		cout << "Want to add an artist or List the artists? (Enter 1 for add, 2 for list or 9 for quit)" << endl;
		cin.clear(); //Input stream clear

		cin >> sent;
		cin.ignore(100, '\n');
		cin.clear(); //Input stream clear

	
		if (sent == 1) {
			artistDB.addAnArtist();

		}
		else if (sent == 2) {
			artistDB.listArtists();

		}
		else if (sent == 9) {
			break;
			cont = false;
		}
		else {
			cout << "Bad.  Enter something better." << endl;
			break;
		}
	}
	cout << "Closing Program" << endl;
	return 0;
}
//
//#include<iostream>
//using namespace std;
//struct node
//{
//	int data;
//	node *next;
//};
//class list
//{
//private:
//	node *head, *tail;
//public:
//	list()
//	{
//		head = NULL;
//		tail = NULL;
//	}
//	void createnode(int value)
//	{
//		node *temp = new node;
//		temp->data = value;
//		temp->next = NULL;
//		if (head == NULL)
//		{
//			head = temp;
//			tail = temp;
//			temp = NULL;
//		}
//		else
//		{
//			tail->next = temp;
//			tail = temp;
//		}
//	}
//	void display()
//	{
//		node *temp = new node;
//		temp = head;
//		while (temp != NULL)
//		{
//			cout << temp->data << "\t";
//			temp = temp->next;
//		}
//	}
//	void insert_start(int value)
//	{
//		node *temp = new node;
//		temp->data = value;
//		temp->next = head;
//		head = temp;
//	}
//	void insert_position(int pos, int value)
//	{
//		node *pre = new node;
//		node *cur = new node;
//		node *temp = new node;
//		cur = head;
//		for (int i = 1; i < pos; i++)
//		{
//			pre = cur;
//			cur = cur->next;
//		}
//		temp->data = value;
//		pre->next = temp;
//		temp->next = cur;
//	}
//	void delete_first()
//	{
//		node *temp = new node;
//		temp = head;
//		head = head->next;
//		delete temp;
//	}
//	void delete_last()
//	{
//		node *current = new node;
//		node *previous = new node;
//		current = head;
//		while (current->next != NULL)
//		{
//			previous = current;
//			current = current->next;
//		}
//		tail = previous;
//		previous->next = NULL;
//		delete current;
//	}
//	void delete_position(int pos)
//	{
//		node *current = new node;
//		node *previous = new node;
//		current = head;
//		for (int i = 1; i < pos; i++)
//		{
//			previous = current;
//			current = current->next;
//		}
//		previous->next = current->next;
//	}
//};
//int main()
//{
//	list obj;
//	obj.createnode(25);
//	obj.createnode(50);
//	obj.createnode(90);
//	obj.createnode(40);
//	cout << "\n--------------------------------------------------\n";
//	cout << "---------------Displaying All nodes---------------";
//	cout << "\n--------------------------------------------------\n";
//	obj.display();
//	cout << "\n--------------------------------------------------\n";
//	cout << "-----------------Inserting At End-----------------";
//	cout << "\n--------------------------------------------------\n";
//	obj.createnode(55);
//	obj.display();
//	cout << "\n--------------------------------------------------\n";
//	cout << "----------------Inserting At Start----------------";
//	cout << "\n--------------------------------------------------\n";
//	obj.insert_start(50);
//	obj.display();
//	cout << "\n--------------------------------------------------\n";
//	cout << "-------------Inserting At Particular--------------";
//	cout << "\n--------------------------------------------------\n";
//	obj.insert_position(5, 60);
//	obj.display();
//	cout << "\n--------------------------------------------------\n";
//	cout << "----------------Deleting At Start-----------------";
//	cout << "\n--------------------------------------------------\n";
//	obj.delete_first();
//	obj.display();
//	cout << "\n--------------------------------------------------\n";
//	cout << "-----------------Deleing At End-------------------";
//	cout << "\n--------------------------------------------------\n";
//	obj.delete_last();
//	obj.display();
//	cout << "\n--------------------------------------------------\n";
//	cout << "--------------Deleting At Particular--------------";
//	cout << "\n--------------------------------------------------\n";
//	obj.delete_position(4);
//	obj.display();
//	cout << "\n--------------------------------------------------\n";
//	system("pause");
//	return 0;
//}