// Description of Program 
//First I took a txt file as named Database.txt in wich all the data stored of the books 
// then I read them form the file and stored them in the instaces of the class "LibraryBook"
// and I allow the user to search the book on ISBN,Author and Title, its up to him to decide
// also I checked out book to Person on matching ISBN number and if alreday checkedout then a meassage display
// and I returned successfuly on ISBN matching and if already rturned then message display
// Fine Calculation:
// I took assumption for fine calculation like if someone checked out the book ahe he didn`t yet
// returned and someone other also want it then Rs.2 fine will be charged to first person who 
// checked out and so on. It is assuming as the after checking out book no other is wanting this
// book if someone other go to checked out the book it means the Due date has gone 
// I add User friendly interface  for the testing anyone can test much time unless he choose 
// to exit on 5 choice
#include <iostream>
#include <fstream>   // for .txt file to read data from it 
#include <string>
using namespace std;
class LibraryBook
{
private:
    string title;
    int ISBN;
    string author;
    bool bookCheckoutFlag;
    string borrower;
    int finePerDay;
    int totalFine;
    int days;

public:
    LibraryBook()
    {
        title = "";
        ISBN = 0;
        author = "";
        bookCheckoutFlag = false;
        borrower = "";
        finePerDay = 0;
        totalFine = 0;
        days = 0;
    }
    void readFromFile(ifstream &f1)
    {
        f1 >> title;
        f1 >> ISBN;
        f1 >> author;
        cout << "\nBook in the library\n";
        cout << "Title \t    ISBN \t     Author\n";
        cout << title << "\t" << ISBN << "\t" << author;
    }
    void checkingBook(string name)
    {
        if (bookCheckoutFlag == false)
        {
            setBorrower(name);
            cout << "Book checked out to a: " << getBorrower() <<" With properties: \n";
            cout << "Title " << getTitle() << endl;
            cout << "ISBN numbr " << getISBN() << endl;
            cout << "Author Name " << getAuthor() << endl;
            bookCheckoutFlag = true;
        }
        else
        {
            // if one has checkedout some specific book and someother wanted it then fine be added as 1 one day per member
            days++;
            
            cout << " Sorry! this book has already been checked out to someone other borrwer name: " << getBorrower() << "who didn't yet returned";
        }
    }
    void Fine()
    {
        setFine(days);
    }
    void returnBook(int num)
    {

        if (bookCheckoutFlag == true)
        {
            cout << "\nBook has been returned successfully! with properties\n";
            cout << "Title " << getTitle() << endl;
            cout << "ISBN numbr " << getISBN() << endl;
            cout << "Author Name " << getAuthor() << endl;
            Fine();
            if (getFine() > 0)
                        cout << "please pay fine of Rs." << getFine() << " at counter\n";
                    else
                        cout << "You have no fine to pay! ";
            

            bookCheckoutFlag = false;
        }
        else
        {
            cout << "book has already been returned or never been checked out!!\n";
        }
    }
    void setFine(int daysAfterDue)
    {
        finePerDay = 2;
        totalFine = 2 * daysAfterDue;
    }
    int getFine() const
    {
        return totalFine;
    }
    string getTitle() const
    {
        return title;
    }

    int getISBN() const
    {
        return ISBN;
    }

    string getAuthor() const
    {
        return author;
    }
    void setBorrower(string name)
    {
        borrower = name;
    }
    string getBorrower()
    {
        return borrower;
    }
};
int main()
{
    ifstream f1("CODSOFT_Database.txt", ios::in);
    LibraryBook *b;
    b = new LibraryBook[10];
    int i = 0;
    if (f1.fail())
    {
        cout << "File does not exist" << endl;
    }
    else
    {
        while (i < 10)
        {
            b[i].readFromFile(f1);
            i++;
        }
    }

    f1.close();

    cout << "\n\n------------------------------------------------------------" << endl;
    cout << "||                                                         ||" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "||                                                         ||" << endl;
    cout << "||               LIBRARY MANGEMENT SYSTEM                  ||" << endl;
    cout << "||                                                         ||" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "||                                                         ||" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n\n";
    int choice;
    do
    {

        cout << "\nEnter 1 to search the book\n";
        cout << "Enter 2 to check the book to borrower\n";
        cout << "Enter 3 to check if the record updated after the book returns\n";
        cout << "Enter 4 to check fine for due books\n";
        cout << "Enter 5 to exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        string name;
        string titleName;
        int d;
        int n;
        int v, w, s;
        string bName;
        // ifstream f2("Borrower.txt", ios::in); // Borrowers Database
        switch (choice)
        {
        case 1:

            cout << "On what basis you want t search the book\n";
            cout << "1. On ISBN number\n2.On title name\n3.On Author name\n";

            cout << "Enter choice for it: ";
            cin >> d;

            if (d == 1)
            {
                cout << "Enter ISBN number to search book:";
                cin >> n;
                for (int i = 0; i < 10; i++)
                {
                    if (b[i].getISBN() == n)
                    {
                        cout << "Book is available\n";
                        cout << "Title " << b[i].getTitle() << endl;
                        cout << "ISBN numbr " << b[i].getISBN() << endl;
                        cout << "Author Name " << b[i].getAuthor() << endl;
                        break;
                    }
                }
                cout << " Not found ";
            }
            else if (d == 2)
            {
                cout << "Enter title name to search book:";
                cin >> titleName;
                for (int i = 0; i < 10; i++)
                {
                    if (b[i].getTitle() == titleName)
                    {
                        cout << "Book is available\n";
                        cout << "Title " << b[i].getTitle() << endl;
                        cout << "ISBN numbr " << b[i].getISBN() << endl;
                        cout << "Author Name " << b[i].getAuthor() << endl;
                        break;
                    }
                }
                cout << " Not found ";
            }
            else if (d == 3)
            {
                cout << "Enter Author name to search book:";
                cin >> name;
                for (int i = 0; i < 10; i++)
                {
                    if (b[i].getAuthor() == name)
                    {
                        cout << "Book is available\n";
                        cout << "Title " << b[i].getTitle() << endl;
                        cout << "ISBN numbr " << b[i].getISBN() << endl;
                        cout << "Author Name " << b[i].getAuthor() << endl;
                        break;
                    }
                }
                cout << " Not found ";
            }
            break;

        case 2:
            cout << "\nEnter Name of the borrowr: ";
            cin >> bName;
            int j;
            cout << "\nEnter ISBN number of the book: ";
            cin >> j;
            v = 0;
            while (v < 10)
            {
                if (b[v].getISBN() == j)
                {
                    b[v].checkingBook(bName);
                    break;
                }
                v++;
            }

            break;
        case 3:

            cout << "enter the isbn number of th book to returned: ";
            int mi;
            cin >> mi;
            w = 0;
            while (w < 10)
            {
                if (b[w].getISBN() == mi)
                {

                    b[w].returnBook(mi);
                    break;
                }
                w++;
            }

            break;
        case 4:
            cout << "enter the isbn number of th book to know what fine one should hv to give for it: ";
            int mo;
            cin >> mo;
            s = 0;
            while (s < 10)
            {
                if (b[s].getISBN() == mo)
                {
                    b[s].Fine();
                    if (b[s].getFine() > 0)
                        cout << "please pay fine of Rs." << b[s].getFine() << " at counter\n";
                    else
                        cout << "You have no fine to pay! ";

                    break;
                    s++;
                }
            }

            break;
        case 5:
            cout << "Quiting Program!!";
            break;
        }
    }
        while (choice != 5);
        return 0;
    
}
