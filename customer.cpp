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

void Customer::makeOrder()
{
    //insert data
    Order *order = new Order(3434, 0, transfer);
    //confirm or add more?
    confirmOrder(order);
    delete order;//?
}

void Customer::confirmOrder(Order *ord)
{
    if(ord->getEditable()){
        //do you want to add something more?
        bool choice = false;
        while(choice) ord->addProduct(4, 5);

        ord->setEditable(false);
        this->orders.push_back(*ord);

    }
}
