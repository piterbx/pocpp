#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "product.h"
#include "customer.h"

namespace File {

    void dataFromCsv(std::string source, std::vector<Product> &tab);
    void dataFromCsv(std::string source, std::vector<Customer> &tab);
    void dataFromCsv(std::string source, std::vector<Order> &tab);

    void toFileCsv(std::string source, std::vector<Customer> tab);
    void toFileCsv(std::string source, std::vector<Order> tab);

}

#endif // FILE_H
