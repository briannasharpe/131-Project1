#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GroceryItem.h"
#include <string>

using namespace std;

class GroceryInventory {
private:
    vector<GroceryItem> _inventory;
    float _taxRate;

public:
    // Constructor
    GroceryInventory() {
		_taxRate = 0;
	}
    
	// Declaration
    //Getters and Setters
    GroceryItem& getEntry(const string&);
    void addEntry(const string& n, const int& q, const float& up, const bool& t);
    float getTaxRate() const;
    void setTaxRate(const float& tr);
    
    //Import File function
    void createListFromFile(const string& filename);
    
    //Calculations
    float calculateUnitRevenue() const;
    float calculateTaxRevenue() const;
    float calculateTotalRevenue() const;

    // Overloaded Operators
    GroceryItem& operator[](const int&);
    
};

//Implementation
//Getters and Setters

//getEntry looks for name of item in inventory, if name of item is found return grocery item, if not throw an error
GroceryItem& GroceryInventory::getEntry(const string& n) {
	for(int i = 0; i < _inventory.size(); i++) {
		if(_inventory[i].getName() == n) {
			return _inventory[i];
		} //if
	} //for
	throw invalid_argument(n + "is not a valid item name");
} //getEntry

void GroceryInventory::addEntry(const string& n, const int& q, const float& up, const bool& t) {
	GroceryItem g(n, q, up, t);
	_inventory.push_back(g); //adds in item to the end of the vector
}

float GroceryInventory::getTaxRate() const {
	return _taxRate;
}

void GroceryInventory::setTaxRate(const float& tr) {
	_taxRate = tr;
}

//Import File function
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

//Calculations
float GroceryInventory::calculateUnitRevenue() const {
	float unitRev = 0;
	float temp = 0;
	for(int i = 0; i < _inventory.size(); i++) {
		temp = _inventory[i].getQuantity() * _inventory[i].getUnitPrice();
		unitRev += temp;
	} //for
	return unitRev;
} //calculateUnitRevenue

float GroceryInventory::calculateTaxRevenue() const {
	float taxRev = 0;
	float temp = 0;
	for(int i = 0; i < _inventory.size(); i++) {
		if (_inventory[i].isTaxable() == true) {
			temp = (getTaxRate() / 100) * _inventory[i].getQuantity() * _inventory[i].getUnitPrice();
			taxRev += temp;
		} //if
	} //for
	return taxRev;
} //calculateTaxRevenue

float GroceryInventory::calculateTotalRevenue() const {
	float totalRev = 0;
	totalRev = calculateUnitRevenue() + calculateTaxRevenue();
	return totalRev;
} //calculateTotalRevenue
