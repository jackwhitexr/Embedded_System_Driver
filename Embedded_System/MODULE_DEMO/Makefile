obj-m := hello.o 
KERNELDIR := /lib/modules/4.4.0-22-generic/build 
PWD := $(shell pwd) 

modules: 
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules 

modules_install: 
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install 
