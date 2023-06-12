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

    int ownerId;
    int id;
    std::time_t time;
    double totalValue;
    methodsOfPayment paymentMethod;
    std::map<int,int> orderedProducts; //prodId, quantity

    float countTotalValue();

public:
    Order(methodsOfPayment paymentMethod, std::map<int,int> cart);
    Order(int id, int ownerId, std::time_t time, double totalValue, methodsOfPayment paymentMethod, std::map<int,int> cart);

    void showOrder();

    void setOwnerId(int owner);

    int getOwnerId();
    int getId();
    std::time_t getTime();
    double getTotalValue();
    methodsOfPayment getPaymentMethod();
    std::map<int, int> &getOrderedProducts();
};

#endif // ORDER_H
