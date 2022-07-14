#to quickly compile and run the code
CC= g++
all: object app
app: main.o bank.o secure.o
	$(CC) -o $@ $^
object: main..o bank.o secure.o
%.o: %.cpp
	$(CC) -c $^
clean:
	rm app Bank.data bank.o secure.o main.o
#just type make in terminal to build and 'make clean' to remove all files generated