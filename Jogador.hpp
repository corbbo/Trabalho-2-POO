// Jogador.hpp (Roland Teodorowitsch; 17 maio 2023)

#ifndef _JOGADOR_HPP
#define _JOGADOR_HPP

#include "Pessoa.hpp"

using namespace std;

typedef enum {
  GK, DF, MF, FW
} posicao_t;

class Jogador : public Pessoa {
private:
    int numero;
    posicao_t posicao;
public:
    Jogador(Pais *p, int num, posicao_t pos, string n, Data &d);
    ~Jogador();
    int obtemNumero() const;
    posicao_t obtemPosicao() const;
    void defineNumero(int n);
    void definePosicao(posicao_t pos);
    string str() const;
};

posicao_t string2posicao_t(string s);
string posicao_t2string(posicao_t p);

#endif
