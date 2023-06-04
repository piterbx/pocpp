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

    void makeOrder(int prodId);
public:
    Customer(std::string name, std::string surname, std::string email, double phoneNumber, std::string deliveryAddress, gender sex);
    ~Customer();
};

#endif // CUSTOMER_H
