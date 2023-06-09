// Pais.hpp (Roland Teodorowitsch; 16 maio 2023)

#ifndef _PAIS_HPP
#define _PAIS_HPP

#include <string>

using namespace std;

class Pais {
private:
  string nome;
  string sigla;
  string confederacao;
public:
  Pais(string n="",string s="", string c="");
  ~Pais();	
  string obtemNome() const;
  string obtemSigla() const;
  string obtemConfederacao() const;
  void defineNome(string n);
  void defineSigla(string s);
  void defineConfederacao(string c);
  string str() const;
  bool operator<(const Pais &p) const;	
};

#endif
