#include "classes.hpp"

ArtistTypes::ArtistTypes() {
	count = 0;
	head = NULL;
	tail = NULL;
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

// Operator Overload - WORKING
Artist & Artist::operator=(const Artist& otherArtist) {
	name = otherArtist.name;
	rating = otherArtist.rating;
	return *this;
}

 const char * Artist::getName() {
	return name;
}
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
		//tail = newArtist;
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

}

void ArtistTypes::removeArtist() {

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
