// Aplicacao.cpp (Roland Teodorowitsch; 17 maio 2023)
// Trabalho 2 de POO - Thiago Zilberknop (última atualização 09/06/2023)

#include <iostream>
#include <fstream>
#include "Aplicacao.hpp"

vector<string> Aplicacao::splitCSV(string linhaCSV, char separador) {
  vector<string> res;
  char c;
  string campo = "";
  for (int i=0; i<linhaCSV.size(); ++i) {
      c = linhaCSV.at(i);
      if (c == separador) {
         res.push_back(campo);
         campo = "";
      }
      else
         campo.append(1,c);
  }
  res.push_back(campo);
  return res;
}

//--------------------------------------------------------

Aplicacao::Aplicacao() {
   // Garantindo que os vetores/ponteiros estão vazios e sem lixo
   partida = nullptr;
   paises.clear();
   jogadores.clear();
   arbitros.clear();
   tecnicos.clear();
}

Aplicacao::~Aplicacao() {
   // Apaga os objetos criados dinamicamente
   for (int i=0; i<paises.size(); ++i) delete paises[i];
   for (int i=0; i<jogadores.size(); ++i) delete jogadores[i];
   for (int i=0; i<arbitros.size(); ++i) delete arbitros[i];
   if (partida != nullptr) delete partida;
}

bool Aplicacao::carregaTecnicos(string nomeArquivo) {
   for (int i=0; i<tecnicos.size(); ++i) delete tecnicos[i];
   tecnicos.clear();
   ifstream f(nomeArquivo);
   if (!f.is_open()) return false; // não conseguiu abrir o arquivo
   string linhaCSV;
   while (getline(f, linhaCSV)) {
         vector<string> campos = splitCSV(linhaCSV,';');
         if (campos.size() != 4) { // não tem os 4 campos esperados
             f.close();
             return false;
         }
         Pais *s = obtemPais(campos[0]); // define s como a seleção com a sigla indicada
         Pais *p = obtemPais(campos[3]); // define p como o pais com a sigla indicada
         if (p == nullptr) { // não conseguiu achar o país
             f.close();
             return false;
         }
         Data d = Data(campos[2]);
         tecnicos.push_back(new Tecnico(s, campos[1], d, p));
   }
   f.close();
   return true;
}

void Aplicacao::mostraTecnicos() {
   for (int i = 0; i < tecnicos.size(); i++) cout << tecnicos[i]->str() << endl;
}

void Aplicacao::ordenaTecnicos() {
   for (int i = 0; i < tecnicos.size() - 1; i++) {
      int men = i;
      for (int j = i + 1; j < tecnicos.size(); j++) {
          if ( tecnicos[j]->obtemNome() < tecnicos[men]->obtemNome()) men = j;
      }
      if (men != i) {
         Tecnico *aux = tecnicos[men];
         tecnicos[men] = tecnicos[i];
         tecnicos[i] = aux;
      }	
  }
}

bool Aplicacao::carregaJogadores(string nomeArquivo) {
   for (int i=0; i<jogadores.size(); ++i) delete jogadores[i];
   jogadores.clear();
   ifstream f(nomeArquivo);
   if (!f.is_open()) return false; // não conseguiu abrir o arquivo
   string linhaCSV;
   while (getline(f, linhaCSV)) {
         vector<string> campos = splitCSV(linhaCSV,';');
         if (campos.size() != 5) { // não tem os 5 campos esperados
             f.close();
             return false;
         }
         Pais *p = obtemPais(campos[0]); // define p como o pais com a sigla indicada
         if (p == nullptr) { // não conseguiu achar o país
             f.close();
             return false;
         }
         Data d = Data(campos[4]);
         jogadores.push_back(new Jogador(p, stoi(campos[1]), string2posicao_t(campos[2]), campos[3], d));
   }
   f.close();
   return true;
}

void Aplicacao::mostraJogadores() {
   for (int i = 0; i < jogadores.size(); i++) cout << jogadores[i]->str() << endl;
}

void Aplicacao::ordenaJogadores() {
  for (int i = 0; i < jogadores.size() - 1; i++) {
      int men = i;
      for (int j = i + 1; j < paises.size(); j++) {
          if ( jogadores[j]->obtemNome() < jogadores[men]->obtemNome()) men = j;
      }
      if (men != i) {
         Jogador *aux = jogadores[men];
         jogadores[men] = jogadores[i];
         jogadores[i] = aux;
      }	
  }
}

Jogador* Aplicacao::obtemJogador(string nome, int numero) {
   for (int i = 0; i < jogadores.size(); i++) {
      if (jogadores[i]->obtemPais()->obtemSigla() == nome && jogadores[i]->obtemNumero() == numero) return jogadores[i];
   }
   return nullptr;
}

void Aplicacao::mostraPartida() {
   if (partida == nullptr) cout << "Nenhuma partida carregada" << endl;
   else cout << partida->str() << endl;
}

void Aplicacao::mostraRelatorio() {
   if (partida == nullptr) cout << "Nenhuma partida carregada" << endl;
   else {
      int size = partida->obtemNumEventos();
      for (int i = 0; i < size; i++) {
         Jogador* player = partida->obtemEvento(i)->obtemJogador();
         cout << player->str() << " ===> " << partida->obtemEvento(i)->obtemMinuto() << " minuto(s)" << endl;
      }
   }
}

//--------------------------------------------------------

bool Aplicacao::carregaPaises(string nomeArquivo) {
  for (int i=0; i<paises.size(); ++i)
      delete paises[i];
  paises.clear();
  ifstream f(nomeArquivo);
  if (!f.is_open())
     return false;
  string linhaCSV;
  while (getline(f, linhaCSV)) {
        vector<string> campos = splitCSV(linhaCSV,';');
        if (campos.size() != 3) {
           f.close();
           return false;
        }
        paises.push_back( new Pais(campos[0],campos[1],campos[2]) );
  }
  f.close();
  return true;
}

void Aplicacao::mostraPaises() {
  for (int i=0; i<paises.size(); ++i)
      cout << paises[i]->str() << endl;
}

void Aplicacao::ordenaPaises() {
  for (int i=0; i<paises.size()-1; ++i) {
      int men = i;
      for (int j=i+1; j<paises.size(); ++j) {
          if ( *paises[j] < *paises[men] )
             men = j;
      }
      if (men != i) {
         Pais *aux = paises[men];
         paises[men] = paises[i];
         paises[i] = aux;
      }	
  }
}

Pais *Aplicacao::obtemPais(string sigla) {
  for (int i=0; i<paises.size(); ++i) {
      if (paises[i]->obtemSigla() == sigla)
         return paises[i];
  }
  return nullptr;
}

bool Aplicacao::carregaArbitros(string nomeArquivo) {
  for (int i=0; i<arbitros.size(); ++i)
      delete arbitros[i];
  arbitros.clear();
  ifstream f(nomeArquivo);
  if (!f.is_open())
     return false;
  string linhaCSV;
  while (getline(f, linhaCSV)) {
        vector<string> campos = splitCSV(linhaCSV,';');
        if (campos.size() != 4) {
           f.close();
           return false;
        }
        Pais *p = obtemPais(campos[3]);
        Data d(campos[2]);
        arbitros.push_back( new Arbitro(stoi(campos[0]),campos[1],d,p) );
  }
  f.close();
  return true;
}

void Aplicacao::mostraArbitros() {
  for (int i=0; i<arbitros.size(); ++i)
      cout << arbitros[i]->str() << endl;
}

void Aplicacao::ordenaArbitros() {
  for (int i=0; i<arbitros.size()-1; ++i) {
      int men = i;
      for (int j=i+1; j<arbitros.size(); ++j) {
          if ( *arbitros[j] < *arbitros[men] )
             men = j;
      }
      if (men != i) {
         Arbitro *aux = arbitros[men];
         arbitros[men] = arbitros[i];
         arbitros[i] = aux;
      }	
  }
}

bool Aplicacao::carregaPartida(string nomeArquivo) {
  ifstream f(nomeArquivo);
  if (!f.is_open())
     return false;
  string linhaCSV;
  if (getline(f, linhaCSV)) {
     vector<string> campos = splitCSV(linhaCSV,';');
     if (campos.size() != 5) {
        f.close();
        return false;
     }
     Data d(campos[0]);
     partida = new Partida( d, campos[1], obtemPais(campos[2]), obtemPais(campos[3]), stoi(campos[4]) );
     while (getline(f, linhaCSV)) {
           vector<string> camposEvento = splitCSV(linhaCSV,';');
           if (camposEvento.size() != 4) {
              f.close();
              return false;
           }
           Jogador *j = obtemJogador(camposEvento[1],stoi(camposEvento[2]));
           partida->adicionaEvento( stoi(camposEvento[0]),j,string2evento_t(camposEvento[3]) );
     }
  }
  f.close();
  return true;
}
