// Trabalho 2 de POO - Thiago Zilberknop (última atualização 09/06/2023)

#include "data.hpp"
#include <sstream>
#include <iomanip>


vector<string> Data::splitCSV(string linhaCSV, char separador) {
  vector<string> res;
  char c;
  string campo = "";
  for (int i=0; i<linhaCSV.size(); ++i) {
      c = linhaCSV.at(i);
      if (c == separador) {
         res.push_back(campo);
         campo = "";
      }
      else
         campo.append(1,c);
  }
  res.push_back(campo);
  return res;
}

Data::Data(int d, int m, int a) {
    dia = d;
    mes = m;
    ano = a;
}

Data::Data(string data) {
    vector<string> campos = splitCSV(data, '/');
    if (campos.size() != 3) {
        dia = 0;
        mes = 0;
        ano = 0;
    } else {
        dia = stoi(campos[0]);
        mes = stoi(campos[1]);
        ano = stoi(campos[2]);
    }
}

Data::~Data() {}

int Data::obtemDia() const {return dia;}
int Data::obtemMes() const {return mes;}
int Data::obtemAno() const {return ano;}

void Data::defineDia(int d) {dia = d;}
void Data::defineMes(int m) {mes = m;}
void Data::defineAno(int a) {ano = a;}

bool Data::operator<(const Data &d) const {
    if (ano < d.ano)
        return true;
    if (ano > d.ano)
        return false;
    if (mes < d.mes)
        return true;
    if (mes > d.mes)
        return false;
    return dia < d.dia;
}

bool Data::operator>(const Data &d) const {
    if (ano > d.ano)
        return true;
    if (ano < d.ano)
        return false;
    if (mes > d.mes)
        return true;
    if (mes < d.mes)
        return false;
    return dia > d.dia;
}

bool Data::operator==(const Data &d) const {
    return ano == d.ano && mes == d.mes && dia == d.dia;
}

bool Data::operator!=(const Data &d) const {
    return ano != d.ano || mes != d.mes || dia != d.dia;
}

bool Data::operator<=(const Data &d) const {
    return *this < d || *this == d;
}

bool Data::operator>=(const Data &d) const {
    return *this > d || *this == d;
}

ostream &operator<<(ostream &os, const Data &d) {
    os << setw(2) << setfill('0') << d.obtemDia() << "/" << setw(2) << setfill('0') << d.obtemMes() << "/" << d.obtemAno();
    return os;
}

istream &operator>>(istream &is, Data &d) {
    // &is stream de entrada
    // &d é o objeto que vai receber os dados lidos
    int dia, mes, ano;
    char barra1, barra2;
    is >> dia >> barra1 >> mes >> barra2 >> ano;
    if (barra1 != '/' || barra2 != '/')
        is.setstate(ios_base::failbit); // seta o bit de erro pois não leu as barras corretamente (formato inválido)
    else
        d = Data(dia, mes, ano); // define a data com os valores lidos
    return is;
}

string Data::str() const {
    stringstream ss;
    ss << *this;
    return ss.str();
}