#include "shop.h"
#include "file.h"

Shop* Shop::shop = nullptr;

Shop::Shop()
{
    //products = File::dataFromTxt();
}

Shop *Shop::getShop()
{
    if(shop==nullptr) shop = new Shop();
    return shop;
}

std::vector<Product> &Shop::getProducts()
{
    return products;
}

std::vector<Customer> &Shop::getCustomers()
{
    return customers;
}

