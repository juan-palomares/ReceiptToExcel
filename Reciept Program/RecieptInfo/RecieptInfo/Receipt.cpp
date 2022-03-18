#include <iostream>
#include "Receipt.h"

using namespace std;

void getInfo(Receipt arr[], unsigned &n)
{
    n++;
    cin.ignore();
    cout << "Enter the name of the store you made your purchase: ";
    getline(cin, arr[n].store_);
    cout << "Enter the day of the purchase(mm/dd/yyyy): ";
    cin >> arr[n].date_;
    cout << "Enter the total of the purchase: ";
    cin >> arr[n].total_;
}

void editInfo(Receipt arr[], unsigned n)
{
    cin.ignore();
    cout << "Enter the name of the store you made your purchase: ";
    getline(cin, arr[n].store_);
    cout << "Enter the day of the purchase(mm/dd/yyyy): ";
    cin >> arr[n].date_;
    cout << "Enter the total of the purchase: ";
    cin >> arr[n].total_;
}

void sortReceipts(Receipt arr[], unsigned n)
{
    for(int j = 0; j < n; j++)
    {
        bool sorted = false;
        for(int i = j; i > 0 && !sorted; i--)
        {
            if(arr[i].store_ < arr[i-1].store_)
            {
                swap(arr[i],arr[i-1]);
            }
            else
            {
                sorted = true;
            }
        }
    }
}

double getTotal(Receipt arr[], unsigned n)
{
    double total = 0;
    for(int i = 0; i < n; i++)
    {
        total += arr[i].total_;
    }
    return total;
}
