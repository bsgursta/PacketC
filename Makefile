CC=arm-none-eabi-gcc
CXX=arm-none-eabi-g++

CFLAGS=-mcpu=cortex-m7 -mthumb -nostdlib -nostartfiles --specs=nosys.specs -g -O0
CPPFLAGS=-DSTM32F767xx -Ivendor/CMSIS/Device/ST/STM32F7/Include -Ivendor/CMSIS/CMSIS/Core/Include

SRC_DIR = src
START_DIR = startup
OUT_DIR = build
SYSTEM_DIR = vendor/CMSIS/Device/ST/STM32F7/Source/Templates
LINKER_FILE = STM32F767XX_FLASH.ld
LDFLAGS=-T $(LINKER_FILE)

PROGRAMMER=openocd
PROGRAMMER_FLAGS=-f interface/stlink.cfg -f target/stm32f7x.cfg


all: packetcommand.elf

packetcommand.elf: $(OUT_DIR)/startup.o $(OUT_DIR)/sys_stubs.o $(OUT_DIR)/main.o $(OUT_DIR)/system_stm32f7xx.o
	$(CXX) $^ -o $@ $(LDFLAGS) $(CFLAGS)

$(OUT_DIR)/startup.o: $(START_DIR)/startup.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

$(OUT_DIR)/sys_stubs.o: $(START_DIR)/sys_stubs.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

$(OUT_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) -c $< -o $@ $(CFLAGS) $(CPPFLAGS) -fno-exceptions -fno-rtti

$(OUT_DIR)/system_stm32f7xx.o: $(SYSTEM_DIR)/system_stm32f7xx.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)


flash: packetcommand.elf
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program packetcommand.elf verify reset exit"

clean:
	rm -f $(OUT_DIR)/*.o *.elf
