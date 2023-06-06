#include "order.h"
#include "shop.h"

int Order::nrOfOrders = 0;

Order::~Order()
{
    nrOfOrders--;
}

void Order::setEditable(bool edit)
{
    editable = edit;
}

bool Order::getEditable()
{
    return editable;
}

void Order::addProduct(int prodId, int qty)
{
    std::vector<Product> prods = Shop::getShop()->getProducts();

    Product *tmp = nullptr;
    for(Product & prod : prods){
        if(prod.getCode()==prodId) tmp = &prod;
    }

    if(tmp!=nullptr){

        if(tmp->getQuantity()>qty){//jesli jest tyle w magazynie

            tmp->setQuantity(tmp->getQuantity()-1); // - z magazynu

            orderedProducts.insert(std::pair<int,int>(prodId,qty));
            countTotalValue();

        }

    } else std::cout << "not found" << std::endl;
}

void Order::countTotalValue()
{
    float sum = 0;
    for(const auto & [key,value] : this->orderedProducts){
        float tmp;
        for(Product &prod : Shop::getShop()->getProducts()){
            if(prod.getCode()==key) tmp = prod.getPrice();
        }
        sum += tmp * value;
    }
}

Order::Order(int time, double totalValue, methodsOfPayment paymentMethod)
    :time(time),totalValue(totalValue),paymentMethod(paymentMethod)
{
    this->editable = true;
    this->id = nrOfOrders++;
}
