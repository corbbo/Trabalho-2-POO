APP = app
CFLAGS = -c -std=c++11

all:									${APP}

${APP}:									app.o Aplicacao.o Partida.o Evento.o Arbitro.o Jogador.o Tecnico.o Pais.o Pessoa.o Data.o
										g++ app.o Aplicacao.o Partida.o Evento.o Arbitro.o Jogador.o Tecnico.o Pais.o Pessoa.o Data.o -o ${APP}

app.o:									app.cpp Aplicacao.cpp Aplicacao.hpp
										g++ ${CFLAGS} app.cpp

Aplicacao.o:							Aplicacao.cpp Aplicacao.hpp Partida.cpp Partida.hpp Evento.cpp Evento.hpp Pais.cpp Pais.hpp Jogador.cpp Jogador.hpp Tecnico.cpp Tecnico.hpp Arbitro.cpp Arbitro.hpp Pessoa.cpp Pessoa.hpp Data.cpp Data.hpp
										g++ ${CFLAGS} Aplicacao.cpp

Partida.o:								Partida.cpp Partida.hpp Evento.cpp Evento.hpp Pais.cpp Pais.hpp Jogador.cpp Jogador.hpp
										g++ ${CFLAGS} Partida.cpp

Evento.o:								Evento.cpp Evento.hpp Pais.cpp Pais.hpp Jogador.cpp Jogador.hpp
										g++ ${CFLAGS} Evento.cpp

Arbitro.o:								Arbitro.cpp Arbitro.hpp Pessoa.cpp Pessoa.hpp Data.cpp Data.hpp
										g++ ${CFLAGS} Arbitro.cpp

Jogador.o:								Jogador.cpp Jogador.hpp Pessoa.cpp Pessoa.hpp Data.cpp Data.hpp
										g++ ${CFLAGS} Jogador.cpp

Tecnico.o:								Tecnico.cpp Tecnico.hpp Pessoa.cpp Pessoa.hpp Data.cpp Data.hpp
										g++ ${CFLAGS} Tecnico.cpp

Pais.o:									Pais.cpp Pais.hpp
										g++ ${CFLAGS} Pais.cpp

Pessoa.o:								Pessoa.cpp Pessoa.hpp Data.cpp Data.hpp
										g++ ${CFLAGS} Pessoa.cpp

Data.o:									Data.cpp Data.hpp
										g++ ${CFLAGS} Data.cpp

run:									${APP}
										./${APP}

clean:									
										rm -f app.o Aplicacao.o Partida.o Evento.o Arbitro.o Jogador.o Tecnico.o Pessoa.o Data.o ${APP}