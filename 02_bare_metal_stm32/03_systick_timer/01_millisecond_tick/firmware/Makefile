###############################################################################
# Project Configuration
###############################################################################

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

TARGET = main

MCU = cortex-m4

CFLAGS = -mcpu=$(MCU) -mthumb -std=gnu11 -O0 -g3 -Wall -c
LDFLAGS = -nostdlib -T stm32f446re.ld

###############################################################################
# Source Files
###############################################################################

SRCS = \
main.c \
systick.c \
startup_stm32f446re.c

OBJS = $(SRCS:.c=.o)

###############################################################################
# Build
###############################################################################

all: $(TARGET).elf $(TARGET).bin $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	$(SIZE) $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

###############################################################################
# Flash (OpenOCD)
###############################################################################

flash:
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program $(TARGET).elf verify reset exit"

###############################################################################
# Clean
###############################################################################

clean:
	del /Q *.o *.elf *.bin *.hex

###############################################################################
# Rebuild
###############################################################################

rebuild: clean all

.PHONY: all clean flash rebuild