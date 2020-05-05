main: Menu.o Arc.o Graphe.o GrapheNonOriente.o GrapheOriente.o PbTriTopologique.o PbTSP.o Sommet.o                       
	g++ Menu.o Arc.o Graphe.o GrapheNonOriente.o GrapheOriente.o PbTriTopologique.o PbTSP.o Sommet.o -o main       

Sommet.o: Sommet.cpp Sommet.hpp
	g++ -c Sommet.cpp

Arc.o: Arc.cpp Arc.hpp Sommet.hpp
	g++ -c Arc.cpp

Graphe.o: Graphe.cpp Arc.hpp Sommet.hpp Graphe.hpp
	g++ -c Graphe.cpp

GrapheOriente.o: GrapheOriente.cpp Arc.hpp Sommet.hpp Graphe.hpp GrapheOriente.hpp
	g++ -c  GrapheOriente.cpp

GrapheNonOriente.o: GrapheNonOriente.cpp Arc.hpp Sommet.hpp Graphe.hpp GrapheNonOriente.hpp
	g++ -c  GrapheNonOriente.cpp

PbTriTopologique.o : PbTriTopologique.cpp Arc.hpp Sommet.hpp Graphe.hpp GrapheOriente.hpp PbTriTopologique.hpp
	g++ -c PbTriTopologique.cpp

PbTSP.o: PbTSP.cpp Arc.hpp Sommet.hpp Graphe.hpp GrapheNonOriente.hpp PbTSP.hpp
	g++ -c PbTSP.cpp

Menu.o: Menu.cpp Arc.hpp Sommet.hpp Graphe.hpp GrapheOriente.hpp PbTriTopologique.hpp GrapheNonOriente.hpp PbTSP.hpp
	g++ -c Menu.cpp

clean:
	rm *.o