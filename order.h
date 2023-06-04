#ifndef ORDER_H
#define ORDER_H

#include <map>

#include "product.h"

enum paymentMethod {transfer, blik};

class Order
{
    int id;
    int time;
    double totalValue;
    paymentMethod methodOfPayment;
    std::map<Product,int> orderedProducts;

    Order();
};

#endif // ORDER_H
