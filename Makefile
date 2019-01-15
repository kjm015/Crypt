#
# PROGRAM:    assign3
# PROGRAMMER: Kevin Miyata
# LOGON ID:   Z1771936
# DATE DUE:   5 October 2015
#

CC = g++
CCFLAGS = -g -Wall

assign3: assign3.o crypt.o
        $(CC) $(CCFLAGS) -o assign3 crypt.o

assign3.o: assign3.cc crypt.h
        $(CC) $(CCFLAGS) -c assign3.cc

crypt.o: crypt.cc crypt.h
        $(CC) $(CCFLAGS) -c crypt.cc

clean:
        -rm *.o assign3

