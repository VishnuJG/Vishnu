a.out:client.o server.o
	gcc client.o server.o
client.o:client.c interface.h
	gcc -c client.o
server.o:server.c interface.h
	gcc -c server.c