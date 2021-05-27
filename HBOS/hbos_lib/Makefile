include ../make.cfg

samples: hbos.lib

hbos.lib:crt0.o
	copy $(CC65_HOME)\\lib\\supervision.lib hbos.lib
	$(AR) a hbos.lib crt0.o
	copy /Y hbos.lib $(CC65_HOME)\\lib\\hbos.lib


crt0.o: crt0.s
	$(AS) crt0.s
	
clean:
	@$(DEL) hbos.lib crt0.o 2>$(NULLDEV)
