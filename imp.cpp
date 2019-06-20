#include "classes.hpp"

// ArtistTypes Constructor
ArtistTypes::ArtistTypes() {
	count = 0;
	head = NULL;
}

ArtistTypes::~ArtistTypes() {
	Node * listLocation = new Node;
	listLocation = head;
	Node * temp = new Node;
	// Delete Each list item from memory
	listLocation = head;
		if (listLocation != NULL) { 
			temp = listLocation; 
			temp = temp->link;
			head = temp->link;
			delete listLocation;
			listLocation = temp;
		}
}


Artist::Artist() {
	name = NULL;
	rating = 0;
}

// When new Artist is created, assign args to pointers
Artist::Artist(char nameArg[], double ratingArg) {
	int length; // Checks length of arg
	length = strlen(nameArg);
	name = new char[length + 1];
	strcpy(name, nameArg);
	rating = ratingArg;
}

// Operator Overload - WORKING
Artist & Artist::operator=(const Artist& otherArtist) {
	name = new char[strlen(otherArtist.name) + 1];
	strcpy(name, otherArtist.name);
	rating = otherArtist.rating;
	return *this;
}

// Name getter
 const char * Artist::getName() {
	return name;
}
 // Rating Getter
 const double Artist::getRating() {
	return rating;
}

// This Showcases how to add a node
void ArtistTypes::addNode(Artist artist) {
	// Set up temp node variable & assign it's artist to function arg.
	Node *newArtist = new Node;
	newArtist->artist = artist;
	newArtist->link = NULL;
	Node * curr = new Node;
	Node * prev = new Node;

	// If no nodes exist connect head to first node
	if (head == NULL) {
		head = newArtist;
	}
	// Sort nodes and add appropriately
	else if (strcmp(newArtist->artist.getName(), head->artist.getName()) < 0) {
		newArtist->link = head;
		head = newArtist;
	}
	else {
		prev = head;
		curr = head->link;
		while (curr != NULL) {
			if (strcmp(newArtist->artist.getName(), curr->artist.getName()) < 0) { // While new Item is greater than Curr
				prev->link = newArtist;
				newArtist->link = curr;
				break;
			}
			else {
				prev = curr; // assign prev's link to newItem
				curr = curr->link;
			}
		}
		if (curr == NULL) {
			prev->link = newArtist;
		}
	}
	
}


void ArtistTypes::searchArtists() {
	Node * listLocation = new Node;
	bool endOfList = false;
	bool found = false;
	listLocation = head;
	char artist[arraySize];

	cout << "Enter the artist name you would like to search for: " << endl;
	cin.getline(artist, '\n');
	cout << "Searching for " << artist << ": " << endl;
	while (!endOfList) { // While traversing var isnt NULL
		// If the current list location is EQUAL TO ENTERED ARTIST NAME...
		if (strcmp(listLocation->artist.getName(), artist) == 0) {
			cout << "Found!" << endl;
			cout << listLocation->artist.getName() << " ::: " << "Rating: ";
			cout << listLocation->artist.getRating() << endl;
			endOfList = true;
			found = true;
		}
		// If list is over...
		else if (listLocation->link == NULL) {
			endOfList = true;
		}
		// If no match, and list not over - go to next item.
		else if (listLocation->link != NULL) {
			listLocation = listLocation->link;
		}
	}
	// If nothing found - say this.
	if (!found) {
		cout << "Nothing found by that name, try again..." << endl;
	}
}

void ArtistTypes::removeArtist() {
	Node * listLocation = new Node;
	Node * temp = new Node;
	Node * prev = new Node;
	bool endOfList = false;
	bool found = false;
	listLocation = head;
	char artist[arraySize];

	cout << "Enter the artist name you would like to Delete from DB: " << endl;
	cin.getline(artist, '\n');

	while (!endOfList) { 
		// If head is the one to remove
		if (strcmp(head->artist.getName(), artist) == 0) {
			cout << "Found.....Deleting!" << endl;
			temp = head;
			head = head->link;
			delete temp;
			endOfList = true;
			found = true;
		}
		// If some other item in the list is the one to remove
		else if (strcmp(listLocation->artist.getName(), artist) == 0) {
			cout << "Found.....Deleting!" << endl;
			prev->link = listLocation->link;
			delete listLocation;
			endOfList = true;
			found = true;
		}
		// If nothing is found...
		else {
			if (listLocation->link == NULL) {
				endOfList = true;
			}
			// Keep traversing
			else if (listLocation->link != NULL) {
				prev = listLocation;
				listLocation = listLocation->link;
			}
		}

	}
	// If nothing found...
	if (!found) {
		cout << "Nothing found by that name, try again..." << endl;
	}
}

void ArtistTypes::listArtists() {
	// Declare location variable for traversing
	Node * listLocation = new Node;
	bool endOfList = false;
	listLocation = head;
	cout << "List the Artists" << endl;

	while (!endOfList) { // While traversing var isnt NULL
		cout << "Artist: ";
		// Output name and rating
		cout << listLocation->artist.getName() << " ::: " << "Rating: ";
		cout << listLocation->artist.getRating() << endl;
		// This makes listLocation traverse
		if (listLocation->link == NULL) {
			endOfList = true;
		}
		else if (listLocation->link != NULL) {
			listLocation = listLocation->link;

		}
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
