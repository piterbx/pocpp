#include "customer.h"
#include "shop.h"

int Customer::nrOfCustomers = 0;


Customer::Customer(std::string name, std::string surname, std::string email, double phoneNumber, std::string deliveryAddress, gender sex)
    :name(name),surname(surname),email(email),phoneNumber(phoneNumber),deliveryAddress(deliveryAddress),sex(sex)
{
    this->id = nrOfCustomers++;
}

Customer::~Customer()
{
    nrOfCustomers--;
}

void Customer::editCustomerData()
{

}

void Customer::makeOrder()
{
    //insert data
    Order *order = new Order(3434, countTotalValue(), transfer);
    order->addProduct(2, 4);
    //confirm or add more?


    delete order;
}
