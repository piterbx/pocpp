#include <memory>

#include "shop.h"
#include "file.h"
#include "customer.h"

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

void Shop::addNewCustomer()
{
    std::string name, surname, email, deliveryAddress, phoneNumber;
    int selectGender;
    std::cout << std::endl << "Adding new customer: " << std::endl << "enter name: ";
    std::cin >> name;
    std::cout << "enter surname: ";
    std::cin >> surname;
    std::cout << "enter email: ";
    std::cin >> email;
    std::cout << "enter phone number: ";
    std::cin >> phoneNumber;
    std::cout << "enter default delivery address: ";
    std::cin >> deliveryAddress;
    std::cout << "enter your gender: (0=male, 1=female, 2=other): ";
    std::cin >> selectGender;
    std::cout << std::endl;

    std::unique_ptr<Customer> client = std::make_unique<Customer>(name, surname, email, phoneNumber, deliveryAddress, static_cast<gender>(selectGender));

    this->customers.push_back(*client);

    for(Customer &c : customers) c.showData();
}

std::vector<Product> &Shop::getProducts()
{
    return products;
}

std::vector<Customer> &Shop::getCustomers()
{
    return customers;
}

