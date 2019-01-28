all : linked_list

linked_list : linked_list.o main.o
	gcc linked_list.o main.o -o linked_list

linked_list.o : linked_list.c
	gcc linked_list.c -g -c -o linked_list.o

main.o : main.c
	gcc main.c -g -c -o main.o

clean :
	rm -f *.o linked_list

mrproper : clean
	rm -f linked_list