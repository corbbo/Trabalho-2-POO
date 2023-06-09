// Pessoa.hpp (Roland Teodorowitsch; 16 maio 2023)

#ifndef _PESSOA_HPP
#define _PESSOA_HPP

#include <string>
#include "Data.hpp"
#include "Pais.hpp"

using namespace std;

class Pessoa {
protected:
  string nome;
  Data *nascimento;
  Pais *pais;
public:
  Pessoa(string n, Data &d, Pais *p);
  ~Pessoa();
  string obtemNome() const;
  Data *obtemNascimento() const;
  Pais *obtemPais() const;
  void defineNome(string n);
  void defineNascimento(Data &d);
  void definePais(Pais *p);
  virtual string str() const;
  bool operator<(const Pessoa &p) const;
};

#endif
