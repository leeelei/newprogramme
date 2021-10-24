CC=gcc
CFLAG=-w -g -O2
ALL=main
OBJECT=main.o add.o sub.o
$(ALL):$(OBJECT)
	$(CC) $(CFLAG) $^ -o $@
%*.o:%*.c
	$(CC) $(CFLAG) -c $^ -o $@

.PHONY:
	clean
clean:
	rm -rf $(ALL) $(OBJECT)
