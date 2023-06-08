#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>

#include "order.h"

enum gender {male, female, other, none};

class Customer
{
    int id;
    std::string name;
    std::string surname;
    std::string email;
    std::string phoneNumber;
    std::string deliveryAddress;
    gender sex;

    std::map<int,int> cart; //prodId, quantity

    std::vector<Order> orders;

public:
    Customer(std::string name, std::string surname, std::string email, std::string phoneNumber, std::string deliveryAddress, gender sex);
    ~Customer();

    int getId();
    std::vector<Order> &getOrders();

    void showData();
    void editCustomerData(std::string newName, std::string newSurname, std::string newEmail, std::string newPhoneNumber, std::string newDeliveryAddress, gender newSex); //todo

    void showOrders();
    void makeOrder();
    void editOrder(int id);

    void addToCart(int prodId, int qty);
};

#endif // CUSTOMER_H
