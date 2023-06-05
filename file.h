#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <vector>

#include "product.h"

class File
{
    File();
public:
    static std::vector<Product> dataFromTxt(std::string source);
    static void dataFromCsv(std::string source);
};

#endif // FILE_H
