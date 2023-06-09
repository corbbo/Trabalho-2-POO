// Data.hpp (Roland Teodorowitsch; 16 maio 2023)

#ifndef _DATA_HPP
#define _DATA_HPP

#include <string>
#include <vector>

using namespace std;

class Data {
private:
    int dia, mes, ano;
    vector<string> splitCSV(string linhaCSV, char separador);
public:
    Data(int d, int m, int a);
    Data(string s);
    ~Data();
    int obtemDia() const;
    int obtemMes() const;
    int obtemAno() const;
    void defineDia(int d);
    void defineMes(int m);
    void defineAno(int a);
    void defineData(int d, int m, int a);
    string str() const;
    bool operator<(const Data &d) const;
    bool operator>(const Data &d) const;
    bool operator==(const Data &d) const;
    bool operator<=(const Data &d) const;
    bool operator>=(const Data &d) const;
    bool operator!=(const Data &d) const;
    friend ostream &operator<<(ostream &out,const Data &d);
};

#endif
