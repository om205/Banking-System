#to quickly compile and run the code
all: main.cpp bank.cpp secure.cpp
	g++ -o bank_management_app main.cpp bank.cpp secure.cpp
clean:
	rm bank_management_app