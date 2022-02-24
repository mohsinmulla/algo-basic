TEMPFILE_DATA := $(shell mktemp)

all: qf qu quwpc genuf perc

qf: ufcli.c qf.c
	$(CC) -Wall -o $@ $^

qu: ufcli.c qu.c
	$(CC) -Wall -o $@ $^

quwpc: ufcli.c quwpc.c
	$(CC) -Wall -o $@ $^

genuf: genuf.c
	$(CC) -Wall -o $@ $^

perc: perc.c quwpc.c
	$(CC) -Wall -o $@ $^

test: all
	@./genuf 10000 > $(TEMPFILE_DATA)

	@cat $(TEMPFILE_DATA) | ./qf | md5sum
	@cat $(TEMPFILE_DATA) | ./qu | md5sum
	@cat $(TEMPFILE_DATA) | ./quwpc | md5sum

	@rm -f $(TEMPFILE_DATA) 

clean:
	rm -f qf qu quwpc genuf
