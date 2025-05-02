gtwap: main.o attitude.o network.o packet.o networkdevice.o
	g++ -Wall -o gtwap main.o attitude.o network.o packet.o networkdevice.o

main.o:
	g++ -Wall -c main.cpp

attitude.o: attitude.h
	g++ -Wall -c attitude.cpp

network.o: network.h networkdevice.h
	g++ -Wall -c network.cpp

packet.o: packet.h networkdevice.h
	g++ -Wall -c packet.cpp

networkdevice.o: attitude.h networkdevice.h
	g++ -Wall -c networkdevice.cpp

clean:
	rm *.o gtwap
