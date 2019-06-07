 //Sources: https://github.com/kamal-choudhary/singly-linked-list/blob/master/Linked%20List.cpp
#include "classes.hpp"

int main()
{

	//::::::::::::::::::::: Welcome and Load Routine:::::::::::::::::::::::::::::::::
	cout << "Welcome to the Test app!" << endl;
	ArtistTypes artistDB;
	bool cont = true;
	int sent;

	while (cont) {
		cin.clear(); //Input stream clear
	
		cout << "Want to add an artist or List the artists? (Enter 1 for add, 2 for list, 3 for search, 4 for remove, or 9 for quit)" << endl;
		cin.clear(); //Input stream clear

		cin >> sent;
		cin.ignore(100, '\n');
		cin.clear(); //Input stream clear

	
		if (sent == 1) {
			artistDB.addAnArtist();

		}
		else if (sent == 2) {
			artistDB.listArtists();

		}
		else if (sent == 3) {

			artistDB.searchArtists();

		}
		else if (sent == 4) {
			artistDB.removeArtist();

		}
		else if (sent == 9) {
			break;
			cont = false;
		}
		else {
			cout << "Bad.  Enter something better." << endl;
			break;
		}
	}
	cout << "Closing Program" << endl;
	return 0;
}
