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
	arm-none-eabi-size $@

clean:
	rm -rf *.o *.elf
# Flash the main.elf to the STM32 board
flash:
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program main.elf verify reset exit"

# Clean and then Build
rebuild: clean all