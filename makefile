main: build/List_point.o build/princ.o
	g++ build/List_point.o build/princ.o -o build/main

build/princ.o: tools/princ.cpp include/list.hpp
	g++ -c tools/princ.cpp -o build/princ.o -std=c++14 -Wall -Iinclude

build/List_vect.o: src/List_vect.cpp include/list.hpp
	g++ -c src/List_vect.cpp -o build/List_vect.o -std=c++14 -Wall -Iinclude

build/List_point.o: src/List_point.cpp include/list.hpp
	g++ -c src/List_point.cpp -o build/List_point.o -std=c++14 -Wall -Iinclude

clean:
	rm -f build/*.o build/main
