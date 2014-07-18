//----------------- ENTRY.H -----------------

// Declarations for class Entry for a phone directory

class Entry
{
public:
   Entry();				// initializes all values to blanks
   void Load();				// load data into an Entry
   void Show() const;			// display an entry to the screen
   const char* GetName() const;		// returns name in an entry
	
private:
   char name[20];			// A name is 20 characters,
   char phoneNumber[20];		// so is a phone number,
   char address[20];			// and so is an address.
};
