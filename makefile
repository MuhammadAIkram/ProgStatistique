.SILENT:

main:	main.cpp Classes/DataSource1D.o
	echo "Creation du main"
	g++	main.cpp Classes/DataSource1D.o -o Aplli	-I Classes/ -Wall

Classes/DataSource1D.o:	Classes/DataSource1D.h Classes/DataSource1D.cpp
	echo "Creation du DataSource1D.o"
	g++ Classes/DataSource1D.cpp -c -o Classes/DataSource1D.o -Wall #-D DEBUG

clean:
	rm Classes/*.o