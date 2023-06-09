// Aplicacao.hpp (Roland Teodorowitsch; 17 maio 2023)
// Trabalho 2 de POO - Thiago Zilberknop (última atualização 09/06/2023)

#ifndef _APLICACAO_HPP
#define _APLICACAO_HPP

#include <string>
#include <vector>
#include "Pais.hpp"
#include "Arbitro.hpp"
#include "Tecnico.hpp"
#include "Jogador.hpp"
#include "Partida.hpp"

using namespace std;

class Aplicacao {
private:
  vector<Pais *> paises;
  vector<Arbitro *> arbitros;
  vector<Tecnico *> tecnicos;
  vector<Jogador *> jogadores;
  Partida *partida;
  static vector<string> splitCSV(string linhaCSV, char separador=';');
public:
  Aplicacao();
  ~Aplicacao();
  bool carregaPaises(string nomeArquivo);
  void mostraPaises();
  void ordenaPaises();
  Pais *obtemPais(string sigla);
  bool carregaArbitros(string nomeArquivo);
  void mostraArbitros();
  void ordenaArbitros();
  bool carregaTecnicos(string nomeArquivo);
  void mostraTecnicos();
  void ordenaTecnicos();
  bool carregaJogadores(string nomeArquivo);
  void mostraJogadores();
  void ordenaJogadores();
  Jogador *obtemJogador(string sigla, int numero);
  bool carregaPartida(string nomeArquivo);
  void mostraPartida();
  void mostraRelatorio();
};

#endif
