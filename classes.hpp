#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>


using namespace std;


const int arraySize = 128; // Declares Global Constant
class Artist {
	char * name;
	double rating;

public:
	Artist();
	Artist(char[], double);
	Artist & operator=(const Artist &otherArtist);
	const char * getName();
	const double getRating();

};

struct Node {
	Artist artist;
	Node * link;
};

class ArtistTypes {
	Node *head, *tail;
	int count;

public:
	ArtistTypes();
	void addNode(Artist artist);
	void addAnArtist();
	void listArtists();
	void searchArtists();
	void removeArtist();
	~ArtistTypes();
};