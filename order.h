#ifndef ORDER_H
#define ORDER_H

#include <map>
#include <vector>
#include <ctime>

#include "product.h"

enum methodsOfPayment {transfer, blik};

class Order
{
    static int nrOfOrders;

    int id;
    std::time_t time;
    double totalValue;
    methodsOfPayment paymentMethod;
    std::map<int,int> orderedProducts; //prodId, quantity

    float countTotalValue();

public:
    Order(methodsOfPayment paymentMethod, std::map<int,int> cart);
    ~Order();

    void showOrder();

    int getId();
};

#endif // ORDER_H
