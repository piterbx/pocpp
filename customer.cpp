#include "customer.h"

int Customer::nrOfCustomers = 0;

Customer::Customer(std::string name, std::string surname, std::string email, double phoneNumber, std::string deliveryAddress, gender sex)
    :name(name),surname(surname),email(email),phoneNumber(phoneNumber),deliveryAddress(deliveryAddress),sex(sex)
{
    nrOfCustomers++;
}

Customer::~Customer()
{
    nrOfCustomers--;
}
