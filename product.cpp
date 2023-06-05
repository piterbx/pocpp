#include "product.h"

Product::Product(double code, std::string name, std::string desc, float price, float vat)
    :code(code),name(name),description(desc),price(price),vat(vat)
{

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

void Product::setQuantity(int qty)
{
    quantity = qty;
}
