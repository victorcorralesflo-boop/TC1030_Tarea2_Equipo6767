CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude

all: sobrecarga polimorfismo pruebas

sobrecarga:
	$(CXX) $(CXXFLAGS) src/main_sobrecarga.cpp -o sobrecarga

polimorfismo:
	$(CXX) $(CXXFLAGS) src/main_polimorfismo.cpp -o polimorfismo

pruebas:
	$(CXX) $(CXXFLAGS) tests/pruebas_minimas.cpp -o pruebas

clean:
	rm -f sobrecarga polimorfismo pruebas *.exe
