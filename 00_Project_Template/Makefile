CC = arm-none-eabi-gcc
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0
LDFLAGS = -nostdlib -T linker_script.ld

all: main.elf

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $^

startup_stm32f446re.o: startup_stm32f446re.c
	$(CC) $(CFLAGS) -o $@ $^

main.elf: main.o startup_stm32f446re.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf