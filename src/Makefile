#OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11
#all: program.exe
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#all: program.exe

program.exe: program.o CjAlfabetos.o Alfabeto.o CjMensajes.o Mensaje.o
	g++ -o program.exe *.o

CjAlfabetos.o: CjAlfabetos.cc CjAlfabetos.hh
		g++ -c CjAlfabetos.cc $(OPCIONS)

CjMensajes.o: CjMensajes.cc CjMensajes.hh
		g++ -c CjMensajes.cc $(OPCIONS)

Alfabeto.o: Alfabeto.cc Alfabeto.hh
		g++ -c Alfabeto.cc $(OPCIONS)

Mensaje.o: Mensaje.cc Mensaje.hh
		g++ -c Mensaje.cc $(OPCIONS)

program.o: program.cc
		g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.tar
tar:
	tar -cvf practica.tar *cc *hh
