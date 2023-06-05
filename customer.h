#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>

#include "order.h"

enum gender {male, female, other};

class Customer
{
    static int nrOfCustomers;

    int id;
    std::string name;
    std::string surname;
    std::string email;
    double phoneNumber;
    std::string deliveryAddress;
    gender sex;

    std::vector<Order> orders;

public:
    Customer(std::string name, std::string surname, std::string email, double phoneNumber, std::string deliveryAddress, gender sex);
    ~Customer();

    void editCustomerData(); //todo
    void makeOrder();
};

#endif // CUSTOMER_H
