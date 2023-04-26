CC=g++

.PHONY: clean

a: gphl.o
	$(CC) -Wall $<

gphl.o: gphl.cpp
	$(CC) -Wall -c $< -o $@

clean:
	rm -rf *.o *.exe *.out

cleanpy:
	rm -rf build *.egg-info*
