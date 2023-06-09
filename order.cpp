#include <chrono>
#include <ctime>

#include "order.h"
#include "shop.h"

int Order::nrOfOrders = 0;

Order::~Order()
{
    nrOfOrders--;
}

void Order::showOrder()
{
    std::cout << std::endl << "Order id: " << this->id << std::endl << "Time: ";

    std::tm* now = std::localtime(&time);
    std::cout << (now->tm_year + 1900) << '-'
              << (now->tm_mon + 1) << '-'
              << now->tm_mday << " "
              << now->tm_hour << ':'
              << now->tm_min << ':'
              << now->tm_sec << std::endl;

    std::cout << "Products: " << std::endl;

    for(auto & [key, value] : this->orderedProducts){
        Shop::getShop()->getProducts()[key].showProduct();
        std::cout << "quantity: " << value << std::endl;
    }
    std::cout << "Total value: " << this->countTotalValue() << std::endl
              << "Selected payment method: ";
    if(this->paymentMethod==0) std::cout << "transfer" << std::endl;
    else std::cout << "blik" << std::endl;
    std::cout << std::endl;

}

int Order::getId()
{
    return id;
}

float Order::countTotalValue()
{
    float sum = 0;
    for(const auto & [key,value] : this->orderedProducts){
        float tmp = 0;
        Product prod = Shop::getShop()->getProducts()[key];
        tmp = prod.getPrice()+prod.getPrice()*prod.getVat();
        sum += tmp * value;
    }
    totalValue = sum;
    return sum;
}

Order::Order(methodsOfPayment paymentMethod, std::map<int,int> cart)
    :paymentMethod(paymentMethod), orderedProducts(cart)
{
    this->time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    this->id = nrOfOrders++;

    countTotalValue();
}
