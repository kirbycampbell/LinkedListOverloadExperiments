
#include "classes.hpp"

int main()
{

	//::::::::::::::::::::: Welcome and Load Routine:::::::::::::::::::::::::::::::::
	cout << "Welcome to the Test app!" << endl;
	ArtistTypes artistDB;
	bool cont = true;
	char sent;

	while (cont) {
		cin.clear(); //Input stream clear
	
		cout << "Want to add an artist or List the artists? (Enter A or L or Q for quit)" << endl;
		cin.clear(); //Input stream clear

		cin.get(sent);
		cin.ignore(100, '\n');
		cin.clear(); //Input stream clear

	
		if (sent == 'a') {
			artistDB.addAnArtist();

		}
		else if (sent == 'l') {
			artistDB.listArtists();

		}
		else if (sent == 'q') {
			break;
			cont = false;
		}
		else {
			cout << "Bad.  Enter something better." << endl;
		}
	}
	cout << "Closing Program" << endl;
	return 0;
}