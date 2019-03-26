
BUILD_DIR = build

TARGET = start

PREFIX = arm-none-eabi-

C_INCLUDES = -I. -Iinc

CFLAGS = $(C_INCLUDES) -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

C_SOURCES = src/main.c src/irq.c src/led.c

ASM_SOURCES = src/start.S

OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.S=.o)))
vpath %.S $(sort $(dir $(ASM_SOURCES)))

$(warning  $(OBJECTS))

all: clean $(BUILD_DIR) $(BUILD_DIR)/$(TARGET).bin $(BUILD_DIR)/$(TARGET).imx

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(PREFIX)gcc  $(CFLAGS) -c  $< -o $@

$(BUILD_DIR)/%.o: %.S  Makefile | $(BUILD_DIR)
	$(PREFIX)gcc  $(CFLAGS) -c  $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(PREFIX)gcc -nostdlib -nostartfiles $(OBJECTS) -T ldscript -o $(BUILD_DIR)/$(TARGET).elf -Wl,-Map=$(BUILD_DIR)/$(TARGET).map
	$(PREFIX)size $@


$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(PREFIX)objcopy -O binary $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).bin

$(BUILD_DIR)/$(TARGET).imx: $(BUILD_DIR)/$(TARGET).bin
	mkimage -n boot.cfgout -T imximage -e 0x00908000 -d $< $@ > $(BUILD_DIR)/mkimage.log

clean:
	rm -rf build

$(BUILD_DIR):
	mkdir $@
