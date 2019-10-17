#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GroceryItem.h"
using namespace std;

class GroceryInventory {
private:
    vector<GroceryItem> _inventory;
    float _taxRate;

public:
    GroceryInventory();

    GroceryItem& getEntry(const string&);
    void addEntry(const string&, const int&, const float&, const bool&);
    float getTaxRate() const;
    void setTaxRate(const float&);

    void createListFromFile(const string&);
    float calculateUnitRevenue() const;
    float calculateTaxRevenue() const;
    float calculateTotalRevenue() const;

    GroceryItem& operator[](const int&);
};

void GroceryInventory::createListFromFile(const string& filename) {
    ifstream input_file(filename);

    if (input_file.is_open()) {
        cout << "Successfully opened file " << filename << endl;
        string name;
        int quantity;
        float unit_price;
        bool taxable;
        while (input_file >> name >> quantity >> unit_price >> taxable) {
            addEntry(name, quantity, unit_price, taxable);
        }
        input_file.close();
    } else {
        throw invalid_argument("Could not open file " + filename);
    }
}
