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

    float countTotalValue();

public:
    Order(methodsOfPayment paymentMethod, std::map<int,int> cart);
    ~Order();

    void showOrder();

    void setEditable(bool edit);
    bool getEditable();
};

#endif // ORDER_H
