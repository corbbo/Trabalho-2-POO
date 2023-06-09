// Partida.cpp (Roland Teodorowitsch; 17 maio 2023)
// Trabalho 2 de POO - Thiago Zilberknop (última atualização 09/06/2023)

#include <iostream>
#include <sstream>
#include "Partida.hpp"

//------------------------------------------------------

Partida::Partida(Data &d, string e, Pais *s1, Pais *s2, int m) {
    eventos.clear();
    dia = new Data(d);
    estadio = e;
    selecao1 = s1;
    selecao2 = s2;
    minutos = m;
}

Partida::~Partida() {
    delete dia;
    for (int i=0; i<eventos.size(); ++i) delete eventos[i];
}

void Partida::adicionaEvento(int m, Jogador *j, evento_t e) {
    eventos.push_back(new Evento(m,j,e));
}

Data *Partida::obtemDia() const             {return dia;}
string Partida::obtemEstadio() const        {return estadio;}
Pais *Partida::obtemSelecao1() const        {return selecao1;}
Pais *Partida::obtemSelecao2() const        {return selecao2;}
int Partida::obtemMinutos() const           {return minutos;}
Evento *Partida::obtemEvento(int i) const   {return eventos[i];}
int Partida::obtemNumEventos() const        {return eventos.size();}

void Partida::defineDia(Data &d)            {*dia = d;}
void Partida::defineEstadio(string e)       {estadio = e;}
void Partida::defineSelecao1(Pais *s1)      {selecao1 = s1;}
void Partida::defineSelecao2(Pais *s2)      {selecao2 = s2;}
void Partida::defineMinutos(int m)          {minutos = m;}

//------------------------------------------------------

string Partida::str() const {
  stringstream ss;
  ss << *dia << ", " << estadio << ": ";
  ss << selecao1->obtemNome() << " [" << selecao1->obtemSigla() << "] X ";
  ss << "[" << selecao2->obtemSigla() << "] " << selecao2->obtemNome();
  ss << " (" << minutos << " minutos de jogo)" << endl;
  for (int i=0; i<eventos.size(); ++i) {
      ss << *eventos[i] << endl;
  }
  return ss.str();
}
