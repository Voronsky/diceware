CC = gcc
TARGET = diceware


diceware: diceware.o
	$(CC) -o diceware diceware.o

diceware.o: diceware.c
	$(CC) -c diceware.c

clean:
	rm -r *.o

cleanall:
	rm -r $(TARGET) *.o
