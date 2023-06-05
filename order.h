#ifndef ORDER_H
#define ORDER_H

#include <map>
#include <vector>

#include "product.h"

enum methodsOfPayment {transfer, blik};

class Order
{
    static int nrOfOrders;

    bool editable;
    int id;
    int time;
    double totalValue;
    methodsOfPayment paymentMethod;
    std::map<int,int> orderedProducts; //prodId, quantity

    void addProduct(int prodId, int qty);

public:
    Order(int time, double totalValue, methodsOfPayment paymentMethod);
    ~Order();
};

#endif // ORDER_H
