objects = main.o Controller.o View.o Pierres.o Entity.o Queue.o Order.o Driver.o Franchise.o Location.o DriverArray.o FranchiseArray.o

app: $(objects)
	g++ -o app $(objects) 

main.o: main.cc Controller.h 
	g++ -c main.cc 

Controller.o: Controller.h Controller.cc
	g++ -c Controller.cc
	
View.o: View.cc View.h
	g++ -c View.cc
	
Pierres.o: Pierres.cc Pierres.h DriverArray.h FranchiseArray.h
	g++ -c Pierres.cc

Entity.o: Entity.cc Entity.h
	g++ -c Entity.cc

Queue.o: Queue.h Queue.cc
	g++ -c Queue.cc

Order.o: Order.h Order.cc
	g++ -c Order.cc

	
Driver.o: Driver.cc Driver.h Entity.h
	g++ -c Driver.cc 

Franchise.o: Franchise.cc Franchise.h 
	g++ -c Franchise.cc

Location.o: Location.cc Location.h
	g++ -c Location.cc
	
DriverArray.o: DriverArray.cc DriverArray.h
	g++ -c DriverArray.cc

FranchiseArray.o: FranchiseArray.cc FranchiseArray.h
	g++ -c FranchiseArray.cc

clean:
	rm -f app *.o