OPTIONS=-Wall -std=c++11

CC=g++

all: randomLib.o makeAlphaPassword makeAlphaNumericPassword makeNumericPassword makeSpecialPassword

randomLib.o: randomLib.cpp
	$(CC) $(OPTIONS) -c randomLib.cpp

makeAlphaPassword: password.cpp randomLib.o
	$(CC) $(OPTIONS) -o makeAlphaPassword -D TYPE=1 password.cpp randomLib.o

makeNumericPassword: password.cpp randomLib.o
	$(CC) $(OPTIONS) -o makeNumericPassword -D TYPE=2 password.cpp randomLib.o

makeAlphaNumericPassword: password.cpp randomLib.o
	$(CC) $(OPTIONS) -o makeAlphaNumericPassword -D TYPE=3 password.cpp randomLib.o

makeSpecialPassword: password.cpp randomLib.o
	$(CC) $(OPTIONS) -o makeSpecialPassword -D TYPE=4 password.cpp randomLib.o

randomLib.o: randomLib.cpp
	$(CC) $(OPTIONS) -c randomLib.cpp

clean:
	rm -f *~ core *.log *.gch   *.o makeAlphaPassword makeNumericPassword makeAlphaNumericPassword makeSpecialPassword

setPermissions:
	/home/fac/msarr/public_files/set_file_permissions2.sh
