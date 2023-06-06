#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>

#include "order.h"

enum gender {male, female, other};

class Customer
{
    int id;
    std::string name;
    std::string surname;
    std::string email;
    std::string phoneNumber;
    std::string deliveryAddress;
    gender sex;

    void confirmOrder(Order *ord);

    std::vector<Order> orders;

public:
    Customer(std::string name, std::string surname, std::string email, std::string phoneNumber, std::string deliveryAddress, gender sex);
    ~Customer();

    void showData();
    void editCustomerData(); //todo
    void makeOrder();
};

#endif // CUSTOMER_H
