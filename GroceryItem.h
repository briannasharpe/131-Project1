#pragma once

#include <string>
using namespace std;

class GroceryItem {
private:
    string _name;
    int _quantity;
    float _unitPrice;
    bool _taxable;

public:
    GroceryItem();
    GroceryItem(const string& n, const int& q, const float& p, const bool& t);

    string getName() const;
    void setName(const string&);
    int getQuantity() const;
    void setQuantity(const int&);
    float getUnitPrice() const;
    void setUnitPrice(const float&);
    bool isTaxable() const;
    void setTaxable(const bool&);

};



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

void GroceryItem::setUnitPrice(const float& u) {
  _unitPrice = u;
}

bool GroceryItem::isTaxable() const {
  _taxable = false; // ?
}

void GroceryItem::setTaxable(const bool& t) {

}
