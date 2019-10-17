#pragma once
#include <iostream>
#include <string>
using namespace std;

class GroceryItem {
private:
    string _name;
    int _quantity;
    float _unitPrice;
    bool _taxable;

public:
	// default constructor
    GroceryItem(){
        _name = "";
        _quantity = 0;
        _unitPrice = 0;
        _taxable = false;
    }

	GroceryItem(const string& n, const int& q, const float& up, const bool& t) {
		_name = n;
		_quantity = q;
		_unitPrice = up;
		_taxable = t;
	}
	
	// Declaration
	// function headers
    string getName() const;
    void setName(const string& n);
    int getQuantity() const;
    void setQuantity(const int& q);
    float getUnitPrice() const;
    void setUnitPrice(const float& up);
    bool isTaxable() const;
    void setTaxable(const bool& t);
};

//Function Definitions
string GroceryItem::getName() const {
	return _name;
}

void GroceryItem::setName(const string& n) {
	_name = n;
}

int GroceryItem::getQuantity() const {
	return _quantity;
}

void GroceryItem::setQuantity(const int& q) {
	_quantity = q;
}

float GroceryItem::getUnitPrice() const {
	return _unitPrice;
}

void GroceryItem::setUnitPrice(const float& up) {
	_unitPrice = up;
}

bool GroceryItem::isTaxable() const {
	return _taxable;
}

void GroceryItem::setTaxable(const bool& t) {
	_taxable = t;
}
