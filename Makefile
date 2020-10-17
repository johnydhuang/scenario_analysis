CC = gcc
CFLAGS += 

INC = 
INC += -I/usr/local/include/
INC += -I.

LDFLAG = -lm

OBJ += laa_analysis.o

all: laa_analysis

laa_analysis: ${OBJ}
	${CC} ${OBJ} -o laa_analysis ${CFLAGS} ${INC} ${LDFLAG} 

laa_analysis.o: laa_analysis.c laa_analysis.h
	${CC} ${CFLAGS} laa_analysis.c ${INC} -c 

clean:
	rm *.o
