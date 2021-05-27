include ../make.cfg

samples: main

main: main.c
	$(CC) --cpu 65sc02 -t none -O main.c
	$(AS) --cpu 65sc02 main.s
	$(AS) --cpu 65sc02 crt0.s
	$(AS) --cpu 65sc02 interrupt.s
	$(AS) --cpu 65sc02 vectors.s
	$(LD) -C hbos.cfg -m main.map crt0.o interrupt.o vectors.o main.o supervision.lib

clean:
	@$(DEL) main 2>$(NULLDEV)
