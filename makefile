all: signal.c
	gcc signal.c -o signal.exe

run: all
	./signal.exe

clean:
	rm foo
	rm *.out
	rm *~
