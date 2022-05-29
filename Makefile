main: filosofo1 filosofo2 filosofo3 filosofo4 filosofo5
	gcc main.c -o main	

filosofo1:
	gcc filosofo1.c	-o filosofo1
filosofo2:
	gcc filosofo2.c -o filosofo2
filosofo3:
	gcc filosofo3.c	-o filosofo3
filosofo4:
	gcc filosofo4.c	-o filosofo4
filosofo5:
	gcc filosofo5.c	-o filosofo5

clean:
	rm main filosofo1 filosofo2 filosofo3 filosofo4 filosofo5 a.out