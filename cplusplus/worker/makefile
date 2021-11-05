CC=g++
CFLAG=-w -g -O2
ALL=workerManager
OBJECT=workerManager.o employee.o manager.o boss.o
$(ALL):$(OBJECT)
	$(CC) $(CFLAG) $^ -o $@
%*.o:%*.cpp
	$(CC) $(CFLAG) -cpp $^ -o $@

.PHONY:
	 clean
clean:
	rm -rf  $(ALL) $(OBJECT)
