compile1: task1.c
	gcc -o task1 task1.c
	./task1
compile2: task2.c
	gcc -o task2 task2.c
	./task2
compile3: task3.c
	gcc -o task3 task3.c
	./task3
compile4: task4.c
	gcc -o task4 task4.c
	./task4
compile5: task5.c
	gcc -o task5 task5.c
	./task5

clean: task1 task2 task3 task4 task5
	rm task1 task2 task3 task4 task5
