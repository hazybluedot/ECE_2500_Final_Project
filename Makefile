CFLAGS = -Wall -Wextra -g -pedantic -D_XOPEN_SOURCE=700

all: res metric

res: main.o
	$(CC) $(LDFLAGS) -o $@ $^

metric: metric.o mstrtod.o
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f *.o res metric
