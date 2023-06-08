#include <cstring>

#include "customer.h"
#include "shop.h"



Customer::Customer(std::string name, std::string surname, std::string email, std::string phoneNumber, std::string deliveryAddress, gender sex)
    :name(name),surname(surname),email(email),phoneNumber(phoneNumber),deliveryAddress(deliveryAddress),sex(sex)
{
    this->id = Shop::getShop()->getCustomers().size();
}

Customer::~Customer()
{

}

int Customer::getId()
{
    return id;
}

std::vector<Order> &Customer::getOrders()
{
    return orders;
}

void Customer::showData()
{
    std::cout << std::endl << "Customer " << this->id << " info: " << std::endl
              << "name: " << this->name << std::endl
              << "surname: " << this->surname << std::endl
              << "email: " << this->email << std::endl
              << "phone: " << this->phoneNumber << std::endl
              << "default delivery address: " << this->deliveryAddress << std::endl
              << "gender: ";

    switch(this->sex){
    case 0: std::cout << "male"; break;
    case 1: std::cout << "female"; break;
    case 2: std::cout << "other"; break;
    }

    std::cout << std::endl;
}

void Customer::editCustomerData(std::string newName, std::string newSurname, std::string newEmail, std::string newPhoneNumber, std::string newDeliveryAddress, gender newSex)
{
    if(strcmp(newName.data(), "n")!=0) this->name = newName;
    if(strcmp(newSurname.data(), "n")!=0) this->surname = newSurname;
    if(strcmp(newEmail.data(), "n")!=0) this->email = newEmail;
    if(strcmp(newPhoneNumber.data(), "n")!=0) this->phoneNumber = newPhoneNumber;
    if(strcmp(newDeliveryAddress.data(), "n")!=0) this->deliveryAddress = newDeliveryAddress;
    if(newSex!=none) this->sex = newSex;
}

void Customer::showOrders()
{
    for(Order &o : orders) o.showOrder();
}

void Customer::makeOrder()
{
    Order *order = new Order(transfer, cart);
    order->showOrder();
    this->orders.push_back(*order);
    delete order;
}

void Customer::editOrder(int id)
{
    Order *tmp = nullptr;
    for(Order &o : orders) if(o.getId()==id) tmp = &o;
    if(tmp!=nullptr){
        tmp->showOrder();
        std::cout << "editing order: " << tmp->getId() << std::endl;

    } else std::cout << "wrong order id" << std::endl;
}

void Customer::addToCart(int prodId, int qty)
{
    std::vector<Product> prods = Shop::getShop()->getProducts();

    Product *tmp = nullptr;
    for(Product & prod : prods){
        if(prod.getCode()==prodId) tmp = &prod;
    }

    if(tmp!=nullptr){

        if(tmp->getQuantity()>qty){//jesli jest tyle w magazynie

            tmp->setQuantity(tmp->getQuantity()-1); // - z magazynu

            cart.insert(std::pair<int,int>(prodId,qty)); //do koszyka
            std::cout << "item added" << std::endl;

        }

    } else std::cout << "not found" << std::endl;

}
