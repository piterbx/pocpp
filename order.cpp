#include <chrono>

#include "order.h"
#include "shop.h"

int Order::nrOfOrders = 0;

Order::~Order()
{
    nrOfOrders--;
}

void Order::showOrder()
{
    std::cout << "Order id: " << this->id << std::endl
              << "Time: " << this->time << std::endl
              << "Products: " << std::endl;

    for(auto & [key, value] : this->orderedProducts){
        for(Product & prod : Shop::getShop()->getProducts()) if(prod.getCode()==key) prod.showProduct();
    }
    std::cout << "Total value: " << this->totalValue << std::endl
              << "Selected payment method: " << this->paymentMethod << std::endl;

}

int Order::getId()
{
    return id;
}

float Order::countTotalValue()
{
    float sum = 0;
    for(const auto & [key,value] : this->orderedProducts){
        float tmp;
        for(Product &prod : Shop::getShop()->getProducts()){
            if(prod.getCode()==key) tmp = prod.getPrice()+prod.getPrice()*prod.getVat();
        }
        sum += tmp * value;
    }
    return sum;
}

Order::Order(methodsOfPayment paymentMethod, std::map<int,int> cart)
    :paymentMethod(paymentMethod), orderedProducts(cart)
{
    //time = std::chrono::system_clock::now();

    this->id = nrOfOrders++;

    totalValue = countTotalValue();
}
