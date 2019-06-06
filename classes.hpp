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
	const char * getName();
	const double getRating();
	//Artist & operator=(Artist &otherArtist);
};

struct node {
	Artist artist;
	node * link;
};

class ArtistTypes {
	node * head;
	node * next;
	int count;

public:
	ArtistTypes();
	void addAnArtist();
	void listArtists();
	~ArtistTypes();
};