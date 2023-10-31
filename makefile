compile:
	g++ -c Clementine.cpp Loan.cpp Register.cpp Retirement.cpp
	g++ -o calculate.out -Wall Clementine.o Loan.o Register.o Retirement.o
run:
	./calculate.out
clean:
	rm *.o