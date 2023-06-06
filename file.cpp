#include "file.h"

#include <fstream>
#include <sstream>

using namespace std;

File::File()
{

}

std::vector<Product> File::dataFromTxt(std::string source)
{
    std::vector<Product> tab;
    fstream file;
    string line;
    file.open(source, ios_base::in);
    if(file.is_open()){
        file >> line; //headers

        while(!file.eof()){
            file >> line;
            stringstream l(line);

            string a, b, c, d, e, f;

            getline(l, a, ';');
            getline(l, b, ';');
            getline(l, c, ';');
            getline(l, d, ';');
            getline(l, e, ';');
            getline(l, f);

            tab.push_back(Product(atoi(a.c_str()), b, c, atof(d.c_str()), atof(e.c_str()), atoi(f.c_str())));

        }
    }
    file.close();
    return tab;
}
