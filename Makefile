CFLAGS = -Wall -Wextra -g -pedantic -D_XOPEN_SOURCE=700

all: res metric

res: main.o mstrtod.o resistor.o
	$(CC) $(LDFLAGS) -o $@ $^

metric: metric.o mstrtod.o
	$(CC) $(LDFLAGS) -o $@ $^

resistor.o: resistor.h

.PHONY: clean
clean:
	rm -f *.o res metric
