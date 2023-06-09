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

}

#endif // FILE_H
