#ifndef SHOP_H
#define SHOP_H

#include "product.h"
#include "customer.h"

class Shop
{
    static Shop* shop;
    std::vector<Product> products;
    std::vector<Customer> customers;

    Shop();
public:
    static Shop *getShop();

    void addNewCustomer();
    void editCustomer();

    void makeOrder();
    void editOrder();

    void showCustomers();
    void showProducts();
    void showOrders();


    std::vector<Product> & getProducts();
    std::vector<Customer> & getCustomers();
};

#endif // SHOP_H
