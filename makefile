CXX = gcc

INCS = -I.  -I"." 
OBJS = $(SRC:.c=.o)
LDFLAGS = --coverage
OPTIONS = -Wall -fexceptions -fprofile-arcs -ftest-coverage
SRC = ratp.c  main.c cmocka.o


all: $(OBJS)
	$(CXX) $(LDFLAGS) $(INCS) -o testAll  $(OBJS)

	
exec : all
	testAll.exe
%.o: %.c
	$(CXX) $(OPTIONS) -c  $< -o $@ $(INCS)
	
clean:
	rm $(OBJS) 


mrproper: clean
	rm testAll
	rm result.xml