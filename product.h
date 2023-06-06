#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product
{
    double code;
    std::string name;
    std::string description;
    float price;
    int quantity;
    float vat;
public:
    Product(double code, std::string name, std::string desc, float price, float vat, int quantity);

    void showProduct();

    double getCode();
    std::string getName();
    std::string getDescription();
    float getPrice();
    int getQuantity();
    float getVat();

    void setQuantity(int qty);
};

#endif // PRODUCT_H
