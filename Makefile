CC = gcc
ListR: ListR.o
	$(CC) $(LDFLAGS) ListR.o -o ListR

ListR.o: ListR.c
	$(CC) $(CFLAGS) -c ListR.c

clean:
	rm -rf *.o *~ *.exe ListR