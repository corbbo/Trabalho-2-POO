// Pais.cpp (Roland Teodorowitsch; 16 maio 2023)

#include <iostream>
#include <sstream>
#include "Pais.hpp"

Pais::Pais(string n,string s, string c) {
  nome = n;
  sigla = s;
  confederacao = c;
#ifdef DEBUG
    cout << "+ Pais(" << nome << "," << sigla << "," << confederacao << ") criado..." << endl;
#endif
}

Pais::~Pais() {
#ifdef DEBUG
    cout << "- Pais (" << nome << "," << sigla << "," << confederacao << ") destruído..." << endl;
#endif
}
  
string Pais::obtemNome() const {
    return nome;
}

string Pais::obtemSigla() const {
    return sigla;
}

string Pais::obtemConfederacao() const {
    return confederacao;
}

void Pais::defineNome(string n) {
    nome = n;
}

void Pais::defineSigla(string s) {
    sigla = s;
}

void Pais::defineConfederacao(string c) {
    confederacao = c;
}

string Pais::str() const {
    stringstream ss;
    ss << nome << " (" << sigla << ") - " << confederacao;
    return ss.str();
}

bool Pais::operator<(const Pais &p) const {
    return sigla < p.obtemSigla();
}

