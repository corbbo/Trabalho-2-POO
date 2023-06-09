// Arbitro.cpp (Roland Teodorowitsch; 16 maio 2023)
// Trabalho 2 de POO - Thiago Zilberknop (última atualização 09/06/2023)

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Arbitro.hpp"

using namespace std;

Arbitro::Arbitro(int c, string n, Data &d, Pais *p) : Pessoa(n,d,p) {
    codigo = c;
#ifdef DEBUG
    cout << "+ Arbitro(" << codigo << "," << nome << "," << *nascimento << "," << pais->obtemSigla() << ") criado..." << endl;
#endif
}

Arbitro::~Arbitro() {
#ifdef DEBUG
    cout << "- Arbitro(" << codigo << "," << nome << "," << *nascimento << "," << pais->obtemSigla() << ") destruído..." << endl;
#endif
}

int Arbitro::obtemCodigo() const {
    return codigo;
}

void Arbitro::defineCodigo(int c) {
    codigo = c;
}

string Arbitro::str() const {
   stringstream ss;
   ss << "[" << setw(2) << setfill(' ') << codigo << "] " << Pessoa::str();
   return ss.str();
}
