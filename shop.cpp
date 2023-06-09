#include <memory>

#include "shop.h"
#include "file.h"

Shop* Shop::shop = nullptr;

Shop::Shop()
{
    File::dataFromCsv("C:\\Users\\Piotrek\\Desktop\\Projekt zaliczeniowy\\files\\products.csv", products);
    File::dataFromCsv("C:\\Users\\Piotrek\\Desktop\\Projekt zaliczeniowy\\files\\customers.csv", customers);
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
    fflush(stdin);
    getline(std::cin, deliveryAddress);
    std::cout << "enter your gender: (0=male, 1=female, 2=other): ";
    std::cin >> selectGender;
    if(selectGender>3 || selectGender<0) selectGender = 2;
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
        fflush(stdin);
        getline(std::cin, deliveryAddress);
        std::cout << "enter new gender (0=male, 1=female, 2=other) [3 = no change]: ";
        std::cin >> selectGender;
        if(selectGender>3 || selectGender<0) selectGender = 2;
        std::cout << std::endl;
        tmp->editCustomerData(name, surname, email, phoneNumber, deliveryAddress, static_cast<gender>(selectGender));
    } else {
        std::cout << "customer not found" << std::endl;
        addNewCustomer();
    }
}

void Shop::makeOrder()
{
    int id;
    Customer *tmp = nullptr;
    std::cout << "as who? type customer id: ";
    std::cin >> id;
    for(Customer &c : customers) if(tmp->getId()==id) tmp = &c;
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
        std::cout << "ordered" << std::endl << std::endl;
    } else std::cout << "customer not found" << std::endl;
}

void Shop::editOrder()
{
    int id, qty;
    std::string decide;
    Customer *tmp = nullptr;
    std::cout << "as who? type customer id: ";
    std::cin >> id;
    for(Customer &c : customers) tmp = &c;
    if(tmp!=nullptr){
        tmp->showOrders();
        if(tmp->getOrders().size()>0){
            std::cout << "type order id: ";
            std::cin >> id;
            Order *ord = nullptr;
            for(Order &o : tmp->getOrders()) ord = &o;
            if(ord->getId()==id) {
                std::cout << "editing order:" << std::endl;
                std::cout << "add products? [y/n]: ";
                std::cin >> decide;
                if(decide=="y"){
                    std::cout << "type product id: ";
                    std::cin >> id;
                    std::cout << "quantity: ";
                    std::cin >> qty;
                }
                tmp->addToCart(id, qty);

            } else std::cout << "wrong order id" << std::endl;
        } else {
            std::cout << "no orders found" << std::endl;
        }
    } else std::cout << "customer not found" << std::endl;
}

void Shop::showCustomers()
{
    for(Customer &c : customers) c.showData();
}

void Shop::showProducts()
{
    if(products.size()>0) for(Product &p : products) p.showProduct();
    else std::cout << "no products found" << std::endl;
}

void Shop::showOrders()
{
    if(customers.size()>0){
        for(Customer &c : customers){
            std::cout << std::endl << "Customer id: " << c.getId() << std::endl;
            if(c.getOrders().size()>0){
                for(Order &o : c.getOrders()) o.showOrder();
            } else std::cout << "no orders" << std::endl << std::endl;
        }
    } else std::cout << "no customers found" << std::endl;

}

std::vector<Product> &Shop::getProducts()
{
    return products;
}

std::vector<Customer> &Shop::getCustomers()
{
    return customers;
}

