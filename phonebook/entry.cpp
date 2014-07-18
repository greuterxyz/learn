//----------------- ENTRY.CPP -----------------

// Definition of class Entry for a phone directory.

#include <iostream>
#include <cstring>			// for strlen, strcpy
#include "entry.h"			// for class Entry

using namespace std;

//---------- Member functions ----------

Entry::Entry()
// This constructor for class Entry initializes the name, phone number,
// and room number to be blank strings.
{
   strcpy(name, " ");
   strcpy(phoneNumber, " ");
   strcpy(address, " ");
}

void Entry::Load()
// allows us to read in the data from the keyboard
{
   cout << "\nType name, followed by RETURN or ENTER: ";
   cin.getline(name, 20);		// Gets a name; discards newline.

   cout << "\nType phone number, followed by RETURN or ENTER: ";
   cin.getline(phoneNumber, 20);	// Gets a phone; discards newline.

   cout << "\nType address, followed by RETURN or ENTER: ";
   cin.getline(address, 20);		// Gets an address; discards newline.
}

void Entry::Show() const
{
   int i;
	
   cout << '\t' << name;		// Display name (after tabbing).
   // Display remaining blanks, so that data lines up on screen.
   for (i = strlen(name) + 1; i < 20; i++)
	cout.put(' ');
	
   cout << '\t' << phoneNumber;		// Display phone number.
   for (i = strlen(phoneNumber) + 1; i < 20; i++)
	cout.put(' ');
	
   cout << '\t' << address;			// Display address.
   cout << '\n';
}

const char* Entry::GetName() const
// Return the name part of an entry.
{
   return name; 
}
