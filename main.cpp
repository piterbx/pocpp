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
              << "[3] make order" << std::endl
              << "[4] show all products" << std::endl
              << "[5] show all orders" << std::endl
              << "[6] exit" << std::endl;

    try {
        while(choice!=7){
            std::cout << "choice: ";
            std::cin >> choice;
            if(std::cin.fail()) throw std::runtime_error("not an int");

            switch(choice){
            case 1: sh->addNewCustomer(); break;
            case 2: sh->editCustomer(); break;
            case 3: sh->makeOrder(); break;
            case 4: sh->showProducts(); break;
            case 5: sh->showOrders(); break;
            case 6:
                return 0;
            default:
                std::cout << "wrong number" << std::endl;
            }
        }
    } catch(std::exception const & ex) {
        std::cout << "error: " << ex.what() << std::endl;
    }

    return 0;
}
