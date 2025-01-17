CC = gcc
# Can change optimization level if needed
# -Wall flag enables all of the compiler's warning messages
#  -Werror treats all compiler warnings as errors
#  -O0 is the lowest optimization level
#  -g enables generating debug info for use with gdb
DEBUG_FLAGS = -Wall -Werror -O0 -g

linkedlisttest: linkedlistmain.c linkedlist.c linkedlist.h
	$(CC) $(DEBUG_FLAGS) -o linkedlisttest linkedlistmain.c linkedlist.h linkedlist.c

runlinkedlist: linkedlisttest
	./linkedlisttest

debuglinkedlisttest: linkedlisttest
	gdb linkedlisttest

leakchecklinkedlisttest: linkedlisttest
	valgrind --leak-check=full ./linkedlisttest

dynamicarraytest: dynamicarraymain.c dynamicarray.c dynamicarray.h
	$(CC) $(DEBUG_FLAGS) -o dynamicarraytest dynamicarraymain.c dynamicarray.c dynamicarray.h

rundynamicarraytest: dynamicarraytest
	./dynamicarraytest

debugdynamicarraytest: dynamicarraytest
	gdb dynamicarraytest

leakcheckdynamicarraytest: dynamicarraytest
	valgrind --leak-check=full ./dynamicarraytest

.PHONY: clean

clean:
	rm -f *.o
