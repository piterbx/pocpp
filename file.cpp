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

void File::toFileCsv(std::string source, std::vector<Order> tab)
{
    std::fstream file;
    file.open(source, std::ios_base::out);
    if(file.is_open()){
        file << "orderId;ownerId;time;totalValue;paymentMethod;orderedProducts";
        for(Order & ord : tab){

            file << '\n' << ord.getId() << ';' << ord.getOwnerId() << ';' << ord.getTime() << ';' << ord.getTotalValue()
                 << ';' << ord.getPaymentMethod() << ';';

            for(const auto & [key, value] : ord.getOrderedProducts()){
                file << key << '=';
                file << value << '|'; //separator
            }

            //przydałaby się baza lub json
        }
    }
    file.close();
}

void File::dataFromCsv(std::string source, std::vector<Order> &tab)
{
    std::fstream file;
    std::string line;
    file.open(source, std::ios_base::in);
    if(file.is_open()){
        file >> line; //headers

        while(!file.eof()){
            file >> line;
            std::stringstream l(line);

            //orderId;ownerId;time;totalValue;paymentMethod;orderedProducts
            std::string a, b, c, d, e, f;
            std::map<int,int> tmp;

            getline(l, a, ';');
            getline(l, b, ';');
            getline(l, c, ';');
            getline(l, d, ';');
            getline(l, e, ';');
            getline(l, f);


            std::stringstream ordProds(f);
            std::string prod;
            while(getline(ordProds, prod, '|')){
                std::stringstream prd(prod);
                std::string pId, qty;
                getline(prd, pId, '=');
                getline(prd, qty, '|');
                tmp.insert(std::pair<int,int>(stoi(pId), stoi(qty)));
            }

            tab.push_back(Order(stoi(a), stoi(b), static_cast<std::time_t>(stoi(c)), stof(d), static_cast<methodsOfPayment>(stoi(e)), tmp));
        }
    }
    file.close();
}

void File::toFileBinary(std::string source, std::vector<Customer> tab)
{
    std::ofstream file;
    file.open(source, std::ios_base::out |std::ios_base::binary);
    if(file.is_open()){
        std::string line;
        for(Customer c : tab){
            line = std::to_string(c.getId()) + c.getName() + c.getSurname() + c.getEmail() + c.getPhoneNumber() + c.getDeliveryAddress();
            if(c.getGender()==male) line += male;
            else if(c.getGender()==female) line += female;
            else line += other;
            file.write(reinterpret_cast<char*>(&line), sizeof(line));
        }
    }
    file.close();
}

void File::toFileBinary(std::string source, std::vector<Order> tab)
{
    std::ofstream file;
    file.open(source, std::ios_base::out |std::ios_base::binary);
    if(file.is_open()){
        std::string line;
        for(Order ord : tab){
            line = std::to_string(ord.getId()) +" "+ std::to_string(ord.getOwnerId()) +" "+ std::to_string(ord.getTime()) +" "+
                    std::to_string(ord.getTotalValue());

            if(ord.getPaymentMethod()==transfer) line+=" transfer";
            else line+=" blik";

            for(const auto & [key, value] : ord.getOrderedProducts()){
                line+= " prodId: " + key;
                line += " quantity: " + value;
            }

            file.write(reinterpret_cast<char*>(&line), sizeof(line));
        }
    }
    file.close();
}
