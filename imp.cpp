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
}


void ArtistTypes::listArtists() {
	cout << "List the Artists" << endl;
}
