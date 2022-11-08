# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# based on [projectgenerator] version: [3.17.1] date: [Wed Oct 05 08:28:26 CEST 2022] 
#
# ChangeLog :
#	2022-10-5: Update to support building different examples
# ------------------------------------------------

include user_settings.mak

######################################
# target board
######################################
BOARD =  nucleo_f103rb

######################################
# target application folder
######################################
TARGET = 


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# Build path
BUILD_DIR = $(TARGET)$(PATH_DELIM)build

######################################
# source
######################################
# C sources
include c_sources.mak
include $(TARGET)/app_src.mak

$(info c-sources = $(C_SOURCES))

# ASM sources
ASM_SOURCES =  \
$(BOARD)/startup_stm32f103xb.s



#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)$(PATH_DELIM)$(PREFIX)gcc$(EXE)
AS = $(GCC_PATH)$(PATH_DELIM)$(PREFIX)gcc$(EXE) -x assembler-with-cpp
CP = $(GCC_PATH)$(PATH_DELIM)$(PREFIX)objcopy$(EXE)
SZ = $(GCC_PATH)$(PATH_DELIM)$(PREFIX)size$(EXE)
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m3

# fpu
# NONE for Cortex-M0/M0+/M3

# float-abi

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32F103xB


# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
-I$(BOARD)/Core/Inc \
-I$(BOARD)/Drivers/STM32F1xx_HAL_Driver/Inc \
-I$(BOARD)/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy \
-I$(BOARD)/Drivers/CMSIS/Device/ST/STM32F1xx/Include \
-I$(BOARD)/Drivers/CMSIS/Include \
-Isensirion


# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS += $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = $(BOARD)/STM32F103RBTx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections



#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))


# search path for c files
vpath %.c $(sort $(dir $(C_SOURCES)))


# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))

# search path for assembly files
vpath %.s $(sort $(dir $(ASM_SOURCES)))


$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# compile the sources and build the image
#######################################
build: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# load image to device
#######################################
flash: build
	-$(PROGRAMMER) --connect port=swd -w $(BUILD_DIR)/$(TARGET).elf


#######################################
# default action: build all; flashing is not done as it requires a nucleo board beeing connected
#######################################
all: 
	build

#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
