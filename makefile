.SILENT:

main:	main.cpp Classes/DataSource1D.o Classes/EtudeStatistiques1D.o Classes/Echantillon.o
	echo "Creation du main"
	g++	main.cpp Classes/DataSource1D.o Classes/EtudeStatistiques1D.o Classes/Echantillon.o -o Aplli	-I Classes/ -Wall

Classes/DataSource1D.o:	Classes/DataSource1D.h Classes/DataSource1D.cpp
	echo "Creation du DataSource1D.o"
	g++ Classes/DataSource1D.cpp -c -o Classes/DataSource1D.o -Wall #-D DEBUG

Classes/EtudeStatistiques1D.o:	Classes/EtudeStatistiques1D.h Classes/EtudeStatistiques1D.cpp Classes/DataSource1D.o
	echo "Creation du EtudeStatistiques1D.o"
	g++ Classes/EtudeStatistiques1D.cpp -c -o Classes/EtudeStatistiques1D.o -Wall #-D DEBUG

Classes/Echantillon.o:	Classes/Echantillon.h Classes/Echantillon.cpp Classes/DataSource1D.o Classes/EtudeStatistiques1D.o
	echo "Creation du Echantillon.o"
	g++ Classes/Echantillon.cpp -c -o Classes/Echantillon.o -Wall #-D DEBUG

clean:
	rm Classes/*.o