run:
	gcc */*.c *.c -o tsync.out -pthread
clean:
	rm -rf *.out
