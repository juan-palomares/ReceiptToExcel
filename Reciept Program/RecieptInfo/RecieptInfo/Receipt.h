#include <iostream>

using namespace std;

struct Receipt
{
    string store_;
    string date_;
    double total_;
};

void getInfo(Receipt arr[], unsigned &n);

void editInfo(Receipt arr[], unsigned n);

void sortReceipts(Receipt arr[], unsigned n);

double getTotal(Receipt arr[], unsigned n);
