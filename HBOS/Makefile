
NULLDEV = /dev/null
DEL = rm -f
RMDIR = rmdir /s /q

AR = $(CC65_HOME)/bin/ar65
AS = $(CC65_HOME)/bin/ca65
CC = $(CC65_HOME)/bin/cc65
CL = $(CC65_HOME)/bin/cl65
LD = $(CC65_HOME)/bin/ld65


RUNTIME_SRC=$(wildcard runtime/*.s)
RUNTIME_OBJS=$(RUNTIME_SRC:.s=.o)

main: main.o $(RUNTIME_OBJS)
	$(LD) -C hbos.cfg -m main.map  $? -o $@

main.s : main.c
	$(CC) --cpu 65sc02 -t none -O $<

%.o : %.s
	$(AS) --cpu 65sc02 $< -o $@


clean:
	@$(DEL) main 2>$(NULLDEV)
	@$(DEL) main.o 2>$(NULLDEV)
	@$(DEL) main.s 2>$(NULLDEV)
	@$(DEL) main.map 2>$(NULLDEV)
	@$(DEL) runtime\\*.o 2>$(NULLDEV)
