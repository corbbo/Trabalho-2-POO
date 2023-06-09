// Partida.hpp (Roland Teodorowitsch; 17 maio 2023)

#ifndef _PARTIDA_HPP
#define _PARTIDA_HPP

#include <string>
#include <vector>
#include "Data.hpp"
#include "Pais.hpp"
#include "Evento.hpp"

using namespace std;

class Partida {
protected:
  Data *dia;
  string estadio;
  Pais *selecao1;
  Pais *selecao2;
  int minutos;
  vector<Evento *> eventos;
public:
  Partida(Data &d, string e, Pais *s1, Pais *s2, int m);
  ~Partida();
  Data *obtemDia() const;
  string obtemEstadio() const;
  Pais *obtemSelecao1() const;
  Pais *obtemSelecao2() const;
  int obtemMinutos() const;
  void defineDia(Data &d);
  void defineEstadio(string e);
  void defineSelecao1(Pais *s1);
  void defineSelecao2(Pais *s2);
  void defineMinutos(int m);
  void adicionaEvento(int m, Jogador *j, evento_t e);
  Evento *obtemEvento(int i) const;
  int obtemNumEventos() const;
  string str() const;
};

#endif
