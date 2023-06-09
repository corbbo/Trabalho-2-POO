// Tecnico.hpp (Roland Teodorowitsch; 16 maio 2023)

#ifndef _TECNICO_HPP
#define _TECNICO_HPP

#include "Pessoa.hpp"

using namespace std;

class Tecnico : public Pessoa {
private:
  Pais *selecao;
public:
  Tecnico(Pais *s, string n, Data &d, Pais *p);
  ~Tecnico();
  Pais *obtemSelecao() const;
  void defineSelecao(Pais *s);
  string str() const;
};

#endif
