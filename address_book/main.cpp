
/************************************************
#
#      Filename: main.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-06 21:13:37
# Last Modified: 2020-06-06 22:40:35
#***********************************************/
#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib>
using namespace std;

const int kMax = 10;

struct Contacts
{
    string mName;
    int mSex;
    int mAge;
    int mPhoneNumber;
    string mAddress;
};

struct AddressBook
{
    vector<Contacts> mContacts;
};

int showMenu();

void addContacts(AddressBook& theAddrBook);

void displayContacts(const AddressBook& theAddrBook);

void deleteContacts(AddressBook& theAddrBook);


Contacts& searchContacts(const AddressBook& theAddrBook);

void changeContacts(AddressBook& theAddrBook);

void emptyAddressBook(AddressBook& theAddrBook);



int main(int argc, char *argv[])
{
    AddressBook myAddressBook;
    while(true)
    {
        int select = showMenu();
        switch(select)
        {
            case 1:             // Add a contacts
                addContacts(myAddressBook);
                break;
            case 2:             // List a contacts
                displayContacts(myAddressBook);
                break;
            case 3:             // Delete a contacts
                deleteContacts(myAddressBook);
                break;
            case 4:             // Search a contacts
                //searchContacts(myAddressBook);
                break;
            case 5:             // Change a contacts
                //changeContacts(myAddressBook);
                break;
            case 6:             // Empty the address book
                //emptyAddressBook(myAddressBook);
                break;
            case 0:             // Quite the address book
                cout << "Thank you" << endl;
                return 0;
            default:
                break;
        }
    }
    return 0;
}

int showMenu()
{
    int select = 0; 
    cout << "Address book" << endl;
    cout << "---------------------" << endl; 
    cout << "1) Add a contacts" << endl;
    cout << "2) List a contacts" << endl;
    cout << "3) Delete a contacts" << endl;
    cout << "4) Search a contacts" << endl;
    cout << "5) Change a contacts" << endl;
    cout << "6) Empty the address book" << endl;
    cout << "0) Quite the address book" << endl;
    cin >> select;
    return select;
}

void addContacts(AddressBook& theAddrBook)
{
    if(theAddrBook.mContacts.size() == kMax)
    {
        cout << "Address book is full" << endl;
        return ;
    }

    Contacts person;
    cout << "Please enter the name: ";
    cin >> person.mName;

    cout << "Please enter sex(man enter 1, women enter 2); ";
    cin >> person.mSex;

    cout << "Please enter age: ";
    cin >> person.mAge;

    cout << "Please enter phone number: ";
    cin >> person.mPhoneNumber;

    cout << "Please enter address: ";
    getline(cin, person.mAddress);
    getline(cin, person.mAddress);

    theAddrBook.mContacts.push_back(person);

    cout << "Add successed\n" << endl;
}

void displayContacts(const AddressBook& theAddrBook)
{
    int size = theAddrBook.mContacts.size();
    for(int loopIndex = 0; loopIndex < size; ++loopIndex)
    {
        cout << "name: " << theAddrBook.mContacts[loopIndex].mName << "\t";
        cout << "sex: " << (theAddrBook.mContacts[loopIndex].mSex ? "man" : "woman") << "\t";
        cout << "age: " << theAddrBook.mContacts[loopIndex].mAge << "\t";
        cout << "phone number: " << theAddrBook.mContacts[loopIndex].mPhoneNumber << "\t";
        cout << "address: " << theAddrBook.mContacts[loopIndex].mAddress << endl;
    }
}

void deleteContacts(AddressBook& theAddrBook)
{
    cout << "Who is you want to delete from your address book?" << endl;
    cout << "Please enter the name: ";
    string name;
    cin >> name;

    for(auto loopIndex = theAddrBook.mContacts.begin(); 
            loopIndex != theAddrBook.mContacts.end(); ++loopIndex)
    {
        if(loopIndex->mName == name)
        {
            theAddrBook.mContacts.erase(loopIndex);
            cout << "Delete successed" << endl;
            return ;
        }
    }

    cout << "Your address book is not " << name << endl;
}

Contacts& searchContacts(const AddressBook& theAddrBook);

void changeContacts(AddressBook& theAddrBook);

void emptyAddressBook(AddressBook& theAddrBook);
