#Variables
COMPIL = g++
OPTIONS = -ansi -pedantic -Wall -std=c++11
OBJECTS = main.o Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o
EXEC = trajets

#Compilation du programme principal

$(EXEC): $(OBJECTS)
	$(COMPIL) $(OPTIONS) -o $(EXEC) $(OBJECTS)


# Ajout de l'option MAP si définie
ifdef MAP
OPTIONS += -DMAP
endif

#Compilation des fichiers source

main.o: main.cpp Catalogue.h
	$(COMPIL) $(OPTIONS) -c main.cpp

Catalogue.o: Catalogue.cpp Catalogue.h TrajetCompose.h
	$(COMPIL) $(OPTIONS) -c Catalogue.cpp

Trajet.o: Trajet.cpp Trajet.h
	$(COMPIL) $(OPTIONS) -c Trajet.cpp

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h Trajet.h
	$(COMPIL) $(OPTIONS) -c TrajetSimple.cpp

TrajetCompose.o: TrajetCompose.cpp TrajetSimple.h
	$(COMPIL) $(OPTIONS) -c TrajetCompose.cpp

#Nettoyage
clean:
	rm -f *.o $(EXEC)

valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)

