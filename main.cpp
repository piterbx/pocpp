#include <iostream>
#include <vector>

#include "shop.h"

int main()
{
    int choice=0;
    Shop *sh = Shop::getShop();
    std::cout << "shop is up" << std::endl
              << "Choose action:" << std::endl
              << "[1] add new customer" << std::endl
              << "[2] change data in existing customer " << std::endl
              << "[3] make new order" << std::endl
              << "[4] edit existing order" << std::endl
              << "[5] show all products" << std::endl
              << "[6] show all orders" << std::endl
              << "[7] exit" << std::endl;

    try {
        while(choice!=7){
            std::cin >> choice;
            if(std::cin.fail()) throw 45;

            switch(choice){
            case 1: sh->addNewCustomer(); break;
            case 7:
                return 0;
            default:
                std::cout << "wrong number" << std::endl;
            }
        }
    } catch(...) {
        std::cout << "error" << std::endl;
    }

    return 0;
}
