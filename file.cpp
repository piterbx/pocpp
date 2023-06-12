#include <algorithm>
#include <string>

#include "file.h"

void File::dataFromCsv(std::string source, std::vector<Product> &tab)
{
        tab.resize(0);
        std::fstream file;
        std::string line;
        file.open(source, std::ios_base::in);
        if(file.is_open()){
            file >> line; //headers
            getline(file, line);

            while(!file.eof()){
                file >> line;
                std::stringstream l(line);

                std::string a, b, c, d, e, f;

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
}

void File::dataFromCsv(std::string source, std::vector<Customer> &tab)
{
        std::fstream file;
        std::string line;
        file.open(source, std::ios_base::in);
        if(file.is_open()){
            file >> line; //headers

            while(!file.eof()){
                file >> line;
                std::stringstream l(line);

                std::string a, b, c, d, e, f;
                gender g;

                getline(l, a, ';');
                getline(l, b, ';');
                getline(l, c, ';');
                getline(l, d, ';');
                getline(l, e, ';');
                getline(l, f);

                std::replace( e.begin(), e.end(), '_', ' ');

                if(f.compare("female")==0) g=female;
                else if(f.compare("male")==0) g=male;
                else g=other;

                tab.push_back(Customer(a, b, c, d, e, g));

            }
        }
        file.close();
}

void File::toFileCsv(std::string source, std::vector<Customer> tab)
{
    std::fstream file;
    file.open(source, std::ios_base::out);
    if(file.is_open()){
        file << "name;surname;email;phoneNumber;deliveryAddress;gender";
        for(Customer & c : tab){

            std::string adr = c.getDeliveryAddress();
            std::replace( adr.begin(), adr.end(), ' ', '_');

            std::string tmp;
            if(c.getGender()==male) tmp = "male";
            else if(c.getGender()==female) tmp = "female";
            else tmp = "other";

            file << '\n' << c.getName() << ';' << c.getSurname() << ';' << c.getEmail() << ';' << c.getPhoneNumber() << ';' << adr << ';' << tmp;
        }
    }
    file.close();
}
