#include "product.h"

Product::Product(double code, std::string name, std::string desc, float price, float vat, int quantity)
    :code(code),name(name),description(desc),price(price),vat(vat),quantity(quantity)
{

}

void Product::showProduct()
{
    std::cout << "Product: " << this->code << std::endl
              << "Name: " << this->name << std::endl
              << "Description: " << this->description << std::endl
              << "Price: " << this->price << std::endl
              << "Vat: " << this->vat << std::endl << std::endl;
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
