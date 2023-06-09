// Pessoa.cpp (Roland Teodorowitsch; 16 maio 2023)

#include <iostream>
#include <sstream>
#include "Pessoa.hpp"

Pessoa::Pessoa(string n, Data &d, Pais *p) {
    nome = n;
    nascimento = new Data(d.obtemDia(),d.obtemMes(),d.obtemAno());
    pais = p;
#ifdef DEBUG
    cout << "+ Pessoa(" << nome << "," << *nascimento << "," << pais->obtemSigla() << ") criada..." << endl;
#endif
}

Pessoa::~Pessoa() {
#ifdef DEBUG
    cout << "- Pessoa(" << nome << "," << *nascimento << "," << pais->obtemSigla() << ") destruída..." << endl;
#endif
    delete nascimento;
}

string Pessoa::obtemNome() const {
    return nome;
}

Data *Pessoa::obtemNascimento() const {
    return nascimento;
}

Pais *Pessoa::obtemPais() const {
    return pais;
}

void Pessoa::defineNome(string n) {
    nome = n;
}

void Pessoa::defineNascimento(Data &d) {
    nascimento->defineDia( d.obtemDia() );
    nascimento->defineMes( d.obtemMes() );
    nascimento->defineAno( d.obtemAno() );
}

void Pessoa::definePais(Pais *p) {
    pais = p;
}

string Pessoa::str() const {
    stringstream ss;
    ss << nome << " (" << pais->obtemSigla() << "), " << *nascimento;
    return ss.str();
}

bool Pessoa::operator<(const Pessoa &p) const {
    return nome < p.obtemNome();
}
