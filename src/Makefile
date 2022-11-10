OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11
all: program.exe

#program.exe: program.o CjAlfabetos.o CjMensajes.o Alfabeto.o Mensaje.o
#	g++ -o program.exe *.o

program.exe: program.o CjMensajes.o Mensaje.o
	g++ -o program.exe *.o

#CjAlfabetos.o: CjAlfabetos.cc CjAlfabetos.hh
#		g++ - CjAlfabetos.cc $(OPCIONS)

CjMensajes.o: CjMensajes.cc CjMensajes.hh
		g++ -c CjMensajes.cc $(OPCIONS)

#Alfabeto.o: Alfabeto.cc Alfabeto.hh
#		g++ - Alfabeto.cc $(OPCIONS)

Mensaje.o: Mensaje.cc Mensaje.hh
		g++ -c Mensaje.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
