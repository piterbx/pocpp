#include <memory>

#include "shop.h"
#include "file.h"

Shop* Shop::shop = nullptr;

Shop::Shop()
{
    File::dataFromCsv("C:\\Users\\Piotrek\\Desktop\\Projekt zaliczeniowy\\files\\products.csv", products);
    File::dataFromCsv("C:\\Users\\Piotrek\\Desktop\\Projekt zaliczeniowy\\files\\customers.csv", customers);
    File::dataFromCsv("C:\\Users\\Piotrek\\Desktop\\Projekt zaliczeniowy\\files\\orders.csv", orders);
}

Shop::~Shop()
{
    File::toFileCsv("C:\\Users\\Piotrek\\Desktop\\Projekt zaliczeniowy\\files\\customers.csv", customers);
    File::toFileCsv("C:\\Users\\Piotrek\\Desktop\\Projekt zaliczeniowy\\files\\orders.csv", orders);

    File::toFileBinary("C:\\Users\\Piotrek\\Desktop\\Projekt zaliczeniowy\\files\\customers.xls", customers);
    File::toFileBinary("C:\\Users\\Piotrek\\Desktop\\Projekt zaliczeniowy\\files\\orders.xls", orders);
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

    this->customers.push_back(Customer(name, surname, email, phoneNumber, deliveryAddress, static_cast<gender>(selectGender)));

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
    showCustomers();
    int id;
    std::cout << "as who? type customer id: ";
    std::cin >> id;
    if(id<static_cast<int>(customers.size()) && id >=0){

        Customer &tmp = customers[id];
        int decisionAddMore = 1;

        while(decisionAddMore!=0){

            if(decisionAddMore==1) showProducts();
            else std::cout << "removing: " << std::endl;

            int prodId, qty;
            std::cout << "select product, type id: ";
            std::cin >> prodId;
            std::cout << "quantity: ";
            std::cin >> qty;

            if(decisionAddMore==1){
                tmp.addToCart(prodId, qty);

            } else if(decisionAddMore==2) tmp.removeFromCart(prodId, qty);

            std::cout << "[0] = confirm order, [1] = add more products [2] = remove product" << std::endl << "choice: ";
            std::cin >> decisionAddMore;
        }

        int selectPayMethod;
        std::cout << "select payment method (0=transfer 1=blik): ";
        std::cin >> selectPayMethod;

        tmp.makeOrder(static_cast<methodsOfPayment>(selectPayMethod));
        std::cout << "ordered" << std::endl << std::endl;

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
    if(orders.size()>0){
        for(Order &ord : orders){
            ord.showOrder();
        }
    } else std::cout << "no orders found" << std::endl;

}

std::vector<Product> &Shop::getProducts()
{
    return products;
}

std::vector<Customer> &Shop::getCustomers()
{
    return customers;
}

std::vector<Order> &Shop::getOrders()
{
    return orders;
}

