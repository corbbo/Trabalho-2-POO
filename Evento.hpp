// Evento.hpp (Roland Teodorowitsch; 22 maio 2023)

#ifndef _EVENTO_HPP
#define _EVENTO_HPP

#include <string>
#include "Jogador.hpp"

using namespace std;

typedef enum {
  ENTRADA, SAIDA, GOL, AMARELO, VERMELHO
} evento_t;

class Evento {
private:
  int minuto;
  Jogador *jogador;
  evento_t evento;
public:
  Evento(int m, Jogador *j, evento_t e);
  ~Evento();
  int obtemMinuto() const;
  Jogador *obtemJogador() const;
  evento_t obtemEvento() const;
  void defineMinuto(int m);
  void defineJogador(Jogador *j);
  void defineEvento(evento_t e);
  bool operator<(const Evento &e) const;
  friend ostream &operator<<(ostream &out,const Evento &e);
  string str() const;
};

evento_t string2evento_t(string s);
string evento_t2string(evento_t e);

#endif
