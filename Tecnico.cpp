// Tecnico.cpp (Roland Teodorowitsch; 16 maio 2023)

#include <iostream>
#include <sstream>
#include "Tecnico.hpp"

using namespace std;

Tecnico::Tecnico(Pais *s, string n, Data &d, Pais *p) : Pessoa(n,d,p) {
    selecao = s;
#ifdef DEBUG
    cout << "+ Tecnico(" << selecao->obtemSigla() << "," << nome << "," << *nascimento << "," << pais->obtemSigla() << ") criado..." << endl;
#endif
}

Tecnico::~Tecnico() {
#ifdef DEBUG
    cout << "- Tecnico(" << selecao->obtemSigla() << "," << nome << "," << *nascimento << "," << pais->obtemSigla() << ") destruído..." << endl;
#endif
}

Pais *Tecnico::obtemSelecao() const {
    return selecao;
}

void Tecnico::defineSelecao(Pais *s) {
    selecao = s;
}

string Tecnico::str() const {
   stringstream ss;
   ss << "[" << selecao->obtemSigla() << "] " << Pessoa::str();
   return ss.str();
}
