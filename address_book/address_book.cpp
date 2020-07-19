
/************************************************
#
#      Filename: main.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-06-06 21:13:37
# Last Modified: 2020-07-18 15:46:03
#***********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
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

void searchContacts(const AddressBook& theAddrBook);

void changeContacts(AddressBook& theAddrBook);

void emptyAddressBook(AddressBook& theAddrBook);

void displayPerson(const Contacts& person);


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
                searchContacts(myAddressBook);
                break;
            case 5:             // Change a contacts
                changeContacts(myAddressBook);
                break;
            case 6:             // Empty the address book
                emptyAddressBook(myAddressBook);
                break;
            case 0:             // Quite the address book
                cout << "Thank you" << endl;
                return 0;
            default:
                break;
        }

        cout << "Please enter key to continue..." << endl;
        cin.get();
        cin.get();

        system("clear");
    }
    return 0;
}

int showMenu()
{
    int select = 0; 
    cout << "\nAddress book" << endl;
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

    cout << "Add successed" << endl;
}

void displayContacts(const AddressBook& theAddrBook)
{
    for(auto loopIndex = theAddrBook.mContacts.begin(); 
            loopIndex != theAddrBook.mContacts.end(); ++loopIndex)
    {
        displayPerson(*loopIndex);
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

void searchContacts(const AddressBook& theAddrBook)
{
    cout << "Who is you want to search from your address book?" << endl;
    cout << "Please enter the name: ";
    string name;
    cin >> name;

    for(auto loopIndex = theAddrBook.mContacts.begin(); 
            loopIndex != theAddrBook.mContacts.end(); ++loopIndex)
    {
        if(loopIndex->mName == name)
        {
            displayPerson(*loopIndex);
            return ;
        }
    }

    cout << "There is not " << name << " in your address book." << endl;

}

void changeContacts(AddressBook& theAddrBook)
{
    cout << "Who is you want to change from your address book?" << endl;
    cout << "Please enter the name: ";
    string name;
    cin >> name;

    for(auto loopIndex = theAddrBook.mContacts.begin(); 
            loopIndex != theAddrBook.mContacts.end(); ++loopIndex)
    {
        if(loopIndex->mName == name)
        {
            cout << "Please enter the name: ";
            cin >> loopIndex->mName;

            cout << "Please enter sex(man enter 1, women enter 2); ";
            
            cin >> loopIndex->mSex;

            cout << "Please enter age: ";
            cin >> loopIndex->mAge;

            cout << "Please enter phone number: ";
            cin >> loopIndex->mPhoneNumber;

            cout << "Please enter address: ";
            getline(cin, loopIndex->mAddress);

            return ;
        }
    }
    cout << "There is not " << name << " in your address book." << endl;
}

void emptyAddressBook(AddressBook& theAddrBook)
{
    theAddrBook.mContacts.clear();
}

void displayPerson(const Contacts& person)
{
    cout << "name: " << person.mName << "\t";
    cout << "sex: " << (person.mSex ? "man" : "woman") << "\t";
    cout << "age: " << person.mAge << "\t";
    cout << "phone number: " << person.mPhoneNumber << "\t";
    cout << "address: " << person.mAddress << endl;
}


