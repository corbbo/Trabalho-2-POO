// Arbitro.hpp (Roland Teodorowitsch; 16 maio 2023)
// Trabalho 2 de POO - Thiago Zilberknop (última atualização 09/06/2023)

#ifndef _ARBITRO_HPP
#define _ARBITRO_HPP

#include "Pessoa.hpp"

using namespace std;

class Arbitro : public Pessoa {
private:
    int codigo;
public:
    Arbitro(int c, string n, Data &d, Pais *p);
    ~Arbitro();
    int obtemCodigo() const;
    void defineCodigo(int c);
    string str() const;
};

#endif
