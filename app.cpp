// app.cpp (Roland Teodorowitsch; 23 maio 2023)
#include <iostream>
#include "Aplicacao.hpp"

int main(int argc, char *argv[]) {
  Aplicacao app;

  if (argc != 2) {
     cerr << argv[0] << ": [ERRO] número inválido de parâmetros na linha de comando..." << endl << endl;
     cerr << "Syntaxe: " << argv[0] << " <arquivo_de_partida.csv>" << endl << endl;	
     return 1;
  }
  if (!app.carregaPaises("paises.csv")) return 0;
  cout << "----------" << endl;
  app.mostraPaises();
  app.ordenaPaises();
  cout << "----------" << endl;
  app.mostraPaises();
  cout << "----------" << endl;
  if (!app.carregaArbitros("arbitros.csv")) return 0;
  app.mostraArbitros();
  app.ordenaArbitros();
  cout << "----------" << endl;
  app.mostraArbitros();
  cout << "----------" << endl;
  if (!app.carregaTecnicos("tecnicos.csv")) return 0;
  app.mostraTecnicos();
  app.ordenaTecnicos();
  cout << "----------" << endl;
  app.mostraTecnicos();
  cout << "----------" << endl;
  if (!app.carregaJogadores("jogadores.csv")) return 0;
  app.mostraJogadores();
  app.ordenaJogadores();
  cout << "----------" << endl;
  app.mostraJogadores();
  cout << "----------" << endl;
  if (!app.carregaPartida(argv[1])) return 0;
  app.mostraPartida();
  cout << "----------" << endl;
  app.mostraRelatorio();
  cout << "----------" << endl;
  return 0;
}