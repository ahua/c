#
# if you want the ram-disk device, define this to be the
# size in blocks.
#
RAMDISK =  #-DRAMDISK=512

AS86	=as86 -0 -a
LD86	=ld86 -0

AS	=as
LD	=ld
LDFLAGS	=-m elf_i386 -Ttext 0 -e startup_32
CC	=gcc -mcpu=i386 $(RAMDISK)
CFLAGS	=-Wall -O -fomit-frame-pointer  

CPP	=cpp -nostdinc -Iinclude

#
# ROOT_DEV specifies the default root-device when making the image.
# This can be either FLOPPY, /dev/xxxx or empty, in which case the
# default of /dev/hd6 is used by 'build'.
#
ROOT_DEV= # 
SYSTEM_BIN=init/main.o kernel/sched.o kernel/printk.o mm/memory.o kernel/chr_drv/tty_io.o

.c.s:
	$(CC) $(CFLAGS) -nostdinc -Iinclude -S -o $*.s $<
.s.o:
	$(AS)  -o $*.o $<
.c.o:
	$(CC) $(CFLAGS) -nostdinc -Iinclude -c -o $*.o $<

all:	Image

Image: boot/bootsect boot/setup tools/system tools/build
	objcopy -O binary -R .note -R .comment tools/system tools/kernel
	tools/build boot/bootsect boot/setup tools/kernel $(ROOT_DEV) > Image
	rm tools/kernel -f
	sync

disk: Image
	dd bs=8192 if=Image of=a.img conv=notrunc

clean:
	rm -f boot/setup boot/bootsect Image tools/system
	rm -f $(SYSTEM_BIN)

tools/build: tools/build.c
	$(CC) $(CFLAGS) -o tools/build tools/build.c

boot/head.o: boot/head.s
	gcc -I./include -traditional -c boot/head.s
	mv head.o boot/

tools/system:	boot/head.o $(SYSTEM_BIN)
	$(LD) $(LDFLAGS) boot/head.o $(SYSTEM_BIN) -o tools/system 
	nm tools/system | grep -v '\(compiled\)\|\(\.o$$\)\|\( [aU] \)\|\(\.\.ng$$\)\|\(LASH[RL]DI\)'| sort > System.map 

boot/setup: boot/setup.s
	$(AS86) -o boot/setup.o boot/setup.s
	$(LD86) -s -o boot/setup boot/setup.o

boot/setup.s:	boot/setup.S include/linux/config.h
	$(CPP) -traditional boot/setup.S -o boot/setup.s

boot/bootsect.s: boot/bootsect.S include/linux/config.h
	$(CPP) -traditional boot/bootsect.S -o boot/bootsect.s

boot/bootsect:	boot/bootsect.s
	$(AS86) -o boot/bootsect.o boot/bootsect.s
	$(LD86) -s -o boot/bootsect boot/bootsect.o


