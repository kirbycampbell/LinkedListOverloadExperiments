#include "classes.hpp"

ArtistTypes::ArtistTypes() {
	count = 0;
	head = NULL;
	tail = NULL;
	//head->link = next;

}

ArtistTypes::~ArtistTypes() {
	cout << "Destruct here" << endl;
}

Artist::Artist() {
 name = NULL;
	rating = 0;
}

Artist::Artist(char nameArg[], double ratingArg) {
	int length; // variable declaration for determining length of arg.
	length = strlen(nameArg);
	name = new char[length + 1];
	strcpy(name, nameArg);
	rating = ratingArg;
}


Artist & Artist::operator=(const Artist& otherArtist) {
	name = otherArtist.name;
	rating = otherArtist.rating;
	return *this;
}

 char * Artist::getName() {
	return name;
}
 double Artist::getRating() {
	return rating;
}

// This Showcases how to add a node
void ArtistTypes::addNode(Artist artist) {
	// Set up temp node variable & assign it's artist to function arg.
	Node *temp = new Node;
	temp->artist = artist;
	temp->link = NULL;
	// Assign tempSorter to head
	//node * tempSorter = new node;
	//tempSorter = head;

	//bool posFound = false;

	// If no nodes exist connect head to first node
	if (head == NULL) {
		head = temp;
		tail = temp;
		temp = NULL;
	}
	// Sort nodes and add appropriately
	else {
		tail->link = temp;
		tail = temp;
		//// Need to keep tail assigned to the end
		//while (!posFound) {
		//	if (strcmp(tempSorter->artist.getName(), temp->link->artist.getName()) < 0) { // If head is less than new node
		//		tempSorter = tempSorter->link; // move head to next node - which moves futher down the list
		//	} else if (
		//		(strcmp(tempSorter->artist.getName(), temp->artist.getName()) < 0) // If sorter is less than temp
		//		&& // ****************************************************************** AND
		//		(strcmp(tempSorter->link->artist.getName(), temp->artist.getName()) > 0)) // If Sorter's next is greater
		//	{ // Then the spot has been found
		//		temp->link = tempSorter->link; // link new node to the next list item
		//		tempSorter->link = temp; // link the previous list item to the new node
		//		posFound = true; // exit the while loop
		//	}
		//	else if (
		//		(strcmp(tempSorter->artist.getName(), temp->artist.getName()) < 0) // If sorter is less than temp
		//		&& // ****************************************************************** AND
		//		(tempSorter->link == NULL)) // If at end of list
		//	{ // Then the spot has been found
		//		tempSorter->link == temp;// link the previous list item to the new node
		//		posFound = true; // exit the while loop
		//	}

		//}

	}
}

void ArtistTypes::addAnArtist() {
	cout << "Add an artist" << endl;
	// Temp Variable Assignments
	char tName[arraySize];
	double tRating;

	// Grabbing User data
	cout << "Enter an artist name: " << endl;
	cin.getline(tName, arraySize, '\n');
	cin.clear(); //Input stream clear
	cout << "Enter a rating: " << endl;
	cin >> tRating;	
	cin.clear(); //Input stream clear

	// Create new Artist, and add to linked list
	Artist tempArtist(tName, tRating);
	addNode(tempArtist);
}






void ArtistTypes::listArtists() {
	// Declare location variable for traversing
	Node * listLocation = new Node;
	listLocation = head;
	cout << "List the Artists" << endl;

	while (listLocation != NULL) { // While traversing var isnt NULL
		cout << "Artist: ";
		// Output name and rating
		cout << listLocation->artist.getName() << " ::: " << "Rating: ";
		cout << listLocation->artist.getRating() << endl;
		// This makes listLocation traverse
		if (listLocation->link != NULL) {
			listLocation = listLocation->link;

		}
		else {
			break;
		}
	}

}
