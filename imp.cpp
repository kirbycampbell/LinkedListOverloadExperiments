#include "classes.hpp"

ArtistTypes::ArtistTypes() {
	count = 0;
	head = NULL;
	//head->link = next;

}

ArtistTypes::~ArtistTypes() {
	cout << "Destruct here" << endl;
}

Artist::Artist() {
 //name = NULL;
	rating = 0;
}

Artist::Artist(char nameArg[], double ratingArg) {
	int length; // variable declaration for determining length of arg.
	length = strlen(nameArg);
	name = new char[length + 1];
	strcpy(name, nameArg);
	rating = ratingArg;
}

//Artist & Artist::operator=(Artist & otherArtist) {
//	//Artist newArtist = new Artist;
//	//newArtist = otherArtist;
//	return otherArtist;
//}



const char * Artist::getName() {
	return name;
}
const double Artist::getRating() {
	return rating;
}

// This Showcases how to add a node
void ArtistTypes::addNode(Artist artist) {
	// Set up temp node variable & assign it's artist to function arg.
	node * temp = new node;
	temp->artist = artist;
	temp->link = NULL;
	// Assign tempSorter to head
	node * tempSorter = new node;
	tempSorter->artist = head->artist;
	tempSorter->link = NULL;

	bool posFound = false;


	// If no nodes exist connect head to first node
	if (head == NULL) {
		head = temp;
		tail = temp;
		temp->link = NULL;
	}
	// Sort nodes and add appropriately
	else {
		while (!posFound) {
			if (strcomp(tempSorter->artist.getName(), temp->artist.getName()) < 0) {
				tempSorter = tempSorter->link;

			}
		}
		tail->link = temp;
		tail = temp;
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
	node * listLocation = new node;
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
