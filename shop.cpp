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

    showCustomers();
}

void Shop::editCustomer()
{
    int id;
    Customer *tmp = nullptr;
    showCustomers();
    std::cout << std::endl << "enter customer id: ";
    std::cin >> id;
    for(Customer &c : customers) if(c.getId() == id) tmp = &c;

    if(tmp) {
        std::string name, surname, email, deliveryAddress, phoneNumber;
        int selectGender;
        std::cout << std::endl << "Editing existing customer: " << std::endl << "enter new name [n = no change]: ";
        std::cin >> name;
        std::cout << "enter new surname [n = no change]: ";
        std::cin >> surname;
        std::cout << "enter new email [n = no change]: ";
        std::cin >> email;
        std::cout << "enter new phone number [n = no change]: ";
        std::cin >> phoneNumber;
        std::cout << "enter new default delivery address [n = no change]: ";
        std::cin >> deliveryAddress;
        std::cout << "enter new gender (0=male, 1=female, 2=other) [3 = no change]: ";
        std::cin >> selectGender;
        std::cout << std::endl;
        tmp->editCustomerData(name, surname, email, phoneNumber, deliveryAddress, static_cast<gender>(selectGender));
    } else addNewCustomer();
}

void Shop::makeOrder()
{
    int id;
    Customer *tmp = nullptr;
    std::cout << "as who? type customer id: ";
    std::cin >> id;
    for(Customer &c : customers) tmp = &c;
    if(tmp!=nullptr){
        bool decisionAddMore = true;
        while(decisionAddMore){
            showProducts();
            int prodId, qty;
            std::cout << "select product, type id: ";
            std::cin >> prodId;
            std::cout << "quantity: ";
            std::cin >> qty;

            tmp->addToCart(prodId, qty);
            std::cout << "[0] = confirm order, [1] = add more products" << std::endl << "choice: ";
            std::cin >> decisionAddMore;
        }

        int selectPayMethod;
        std::cout << "select payment method (0=transfer 1=blik): ";
        std::cin >> selectPayMethod;
    } else std::cout << "customer not found" << std::endl;
}

void Shop::showCustomers()
{
    for(Customer &c : customers) c.showData();
}

void Shop::showProducts()
{
    for(Product &p : products) p.showProduct();
}

std::vector<Product> &Shop::getProducts()
{
    return products;
}

std::vector<Customer> &Shop::getCustomers()
{
    return customers;
}

