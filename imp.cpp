#include "classes.hpp"

ArtistTypes::ArtistTypes() {
	count = 0;
	head = nullptr;
}

ArtistTypes::~ArtistTypes() {
	cout << "Destruct here" << endl;
}

Artist::Artist() {
 name = nullptr;
	rating = 0;
}

Artist::Artist(char nameArg[], double ratingArg) {
	int length; // variable declaration for determining length of arg.
	length = strlen(nameArg);
	name = new char[length + 1];
	strcpy(name, nameArg);
	rating = ratingArg;
}


const char * Artist::getName() {
	return name;
}
const double Artist::getRating() {
	return rating;
}

void ArtistTypes::addAnArtist() {
	cout << "Add an artist" << endl;
	char tName[arraySize];
	double tRating;
	node * curr;
	node * newNode;
	

	cout << "Enter an artist name: " << endl;
	cin.getline(tName, arraySize, '\n');
	cin.clear(); //Input stream clear
	cout << "Enter a rating: " << endl;
	cin >> tRating;	
	cin.clear(); //Input stream clear
	Artist tempArtist(tName, tRating);
	if (head == nullptr) {
		head = new node;
		head->artist = tempArtist;
	}
	else if (head != nullptr) {
		curr = head->link;
		while (curr->link != nullptr) {
			curr = curr->link;
		}
		if (curr->link == nullptr) {
			newNode = new node;
			newNode->artist = tempArtist;
			curr->link = newNode;
		}
	}

	//CONFUSION HERE AND IN OTHER PROJ
}


void ArtistTypes::listArtists() {
	cout << "List the Artists" << endl;
	cout << head->artist.getName() << endl; 
	cout << head->artist.getRating() << endl;
}
