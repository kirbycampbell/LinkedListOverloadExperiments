#include "classes.hpp"

ArtistTypes::ArtistTypes() {
	count = 0;
	//head = NULL;
	//next = NULL;
	//head->link = next;
	//next = nullptr;
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

void ArtistTypes::addAnArtist() {
	cout << "Add an artist" << endl;
	char tName[arraySize];
	double tRating;
	node * curr = new node;
	node * newNode;
	curr = head;

	cout << "Enter an artist name: " << endl;
	cin.getline(tName, arraySize, '\n');
	cin.clear(); //Input stream clear
	cout << "Enter a rating: " << endl;
	cin >> tRating;	
	cin.clear(); //Input stream clear

	Artist tempArtist(tName, tRating);
	if (head == NULL) {
		head = new node;
		head->link = NULL;
		head->artist = tempArtist;
	}
	else if (head != NULL) {
		curr = head->link;
		while (curr != NULL) {
			curr = curr->link;
		}
		if (curr == NULL) {
			newNode = new node;
			newNode->artist = tempArtist;
			newNode->link = NULL;
			curr = newNode;
		}
	}
}


void ArtistTypes::listArtists() {
	node * listLocation = new node;
	listLocation = head;
	cout << "List the Artists" << endl;
	cout << listLocation->link->artist.getName() << " ::: " << "Rating: ";
	cout << listLocation->link->artist.getRating() << endl;
	//while (listLocation != NULL) {
	//	cout << "Artist: ";
	//	cout << listLocation->artist.getName() << " ::: " << "Rating: ";
	//	cout << listLocation->artist.getRating() << endl;
	//	if (listLocation->link != NULL) {
	//		listLocation = listLocation->link;

	//	}
	//	else {
	//		break;
	//	}
	//}

}
