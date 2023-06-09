// Evento.cpp (Roland Teodorowitsch; 22 maio 2023)
// Trabalho 2 de POO - Thiago Zilberknop (última atualização 09/06/2023)

#include <iostream>
#include <sstream>
#include <iomanip>
#include "Evento.hpp"
#include "Pais.hpp"

//-----------------------------------------------------

Evento::Evento(int m, Jogador *j, evento_t e) {
    minuto = m;
    jogador = j;
    evento = e;
}

Evento::~Evento() {} // não há nada a fazer pois não foi feito new

int Evento::obtemMinuto() const         {return minuto;}
Jogador *Evento::obtemJogador() const   {return jogador;}
evento_t Evento::obtemEvento() const    {return evento;}

void Evento::defineMinuto(int m)        {minuto = m;}
void Evento::defineJogador(Jogador *j)  {jogador = j;}
void Evento::defineEvento(evento_t e)   {evento = e;}

bool Evento::operator<(const Evento &e) const {
     if (minuto < e.minuto) return true;
     else return false;
}

ostream &operator<<(ostream &os, const Evento &e) { //nao necessita ser friend pois usa os metodos publicos da classe; nao precisa do operador de escopo Evento:: pois esta sendo definido fora da classe?
    os << e.str();
    return os;
}

//-----------------------------------------------------

string Evento::str() const {
  stringstream ss;
  Pais *p = jogador->obtemPais();
  ss << setw(2) << setfill('0') << minuto << ": [" << p->obtemSigla() << "] " << jogador->obtemNumero() << " " << jogador->obtemNome();
  switch (evento) {
         case ENTRADA:
              if (minuto == 0)
                 ss << " foi escalado.";
              else
                 ss << " entrou em campo.";
              break;
         case SAIDA:
              ss << " foi substituído.";
              break;
         case GOL:
              ss << " fez gol.";
              break;
         case AMARELO:
              ss << " recebeu cartão amarelo.";
              break;
         case VERMELHO:
              ss << " recebeu cartão vermelho.";
              break;
         default:
              ss << "EVENTO INVÁLIDO...";
  }
  return ss.str();
}

evento_t string2evento_t(string s) {
    if (s == "E") return ENTRADA;
    else if (s == "S") return SAIDA;
    else if (s == "G") return GOL;
    else if (s == "A") return AMARELO;
    else if (s == "V") return VERMELHO;
    else {
        cerr << "string \"" << s << "\" para evento_t INVÁLIDA!" << endl;
        exit(1);
    }
}

string evento_t2string(evento_t e) {
    switch(e) {
          case ENTRADA: return "E";
          case SAIDA: return "S";
          case GOL: return "G";
          case AMARELO: return "A";
          case VERMELHO: return "V";
    }
    return "?";
}


