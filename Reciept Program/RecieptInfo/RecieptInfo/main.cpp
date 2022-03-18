#include <iostream>
#include <iomanip>
#include <fstream>
#include "Receipt.h"

using namespace std;

string Menu();

int main()
{
    unsigned static int MAX = 9999;
    unsigned nReceipts = 0;
    string store = "STORE", date = "DATE", t = "TOTAL";
    double total;
    unsigned ReceiptNum;
    Receipt r[MAX];
    ofstream output;
    int choice = NULL;
    
    output.open("Receipts.csv");
    output << store << "," << date << "," << t << endl;
    
    cout << "This program will ask you to enter receipt information and out output the information on an excel file.";
    cout << "\nPRESS ENTER TO START";
    cin.get();
    
    cout << Menu();
    
    do{
        cin >> choice;
        switch(choice)
        {
            case 0:
                cout << Menu() << endl;
                break;
            case 1:
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Option 1~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                getInfo(r, nReceipts);
                cout << "Would you like to enter another receipt? Press 1 if yes or 0 if you would like to return to the menu.";
                break;
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            case 2:
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Option 2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                for(int i = 1; i < nReceipts + 1; i++)
                {
                    cout << "Receipt #" << i << endl;
                    cout <<"Store" << setw(5) << r[i].store_ << "\nDate" << setw(5) << r[i].date_ << "\nTotal" << setw(5) << r[i].total_ << endl;
                }
                cout << Menu();
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                break;
            case 3:
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Option 3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                cout << "If you do not know what receipt number you would like to edit press 0 otherwise press 1: " << endl;
                cin >> ReceiptNum;
                if(ReceiptNum == 0)
                {
                    cout << Menu() << endl;
                    break;
                }
                cout << "Enter the number receipt you would like to edit: " << endl;
                cin >> ReceiptNum;
                editInfo(r,ReceiptNum);
                cout << Menu();
                break;
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            case 4:
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Option 4~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                sortReceipts(r, nReceipts);
                cout << "Calculating total amount spent. . ." << endl;
                for(int i = 0; i < nReceipts; i++)
                {
                    store = r[i].store_;
                    date = r[i].date_;
                    total = r[i].total_;
                    output << store << "," << date << "," << total << endl;
                }
                total = getTotal(r, nReceipts);
                cout << "Total amount spent is $" << total << endl;
                output << "\nTotal amount spent is $" << total << endl;
                cout << "Thank you for using ReceiptTracker. Goodbye." << endl;
                break;
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            }
    }while(choice != 4);
    
    output.close();
    return 0;
}

string Menu()
{
    string menu = "1. Enter receipt\n2. Display all receipt information\n3. Edit receipt information\n4. Exit\n";
    return menu;
}
