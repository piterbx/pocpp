#include "product.h"

Product::Product(double code, std::string name, std::string desc, float price, float vat, int quantity)
    :code(code),name(name),description(desc),price(price),vat(vat),quantity(quantity)
{

}

void Product::showProduct()
{
    std::cout << "Product: " << this->code << " Name: " << this->name
              << " Description: " << this->description << " Price: " << this->price
              << " Vat: " << this->vat << std::endl;
}

double Product::getCode()
{
    return code;
}

std::string Product::getName()
{
    return name;
}

std::string Product::getDescription()
{
    return description;
}

float Product::getPrice()
{
    return price;
}

int Product::getQuantity()
{
    return quantity;
}

float Product::getVat()
{
    return vat;
}

void Product::setQuantity(int qty)
{
    quantity = qty;
}
