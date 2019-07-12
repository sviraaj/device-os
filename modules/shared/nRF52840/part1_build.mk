
ifeq (,$(SYSTEM_PART1_MODULE_VERSION))
$(error SYSTEM_PART1_MODULE_VERSION not defined)
endif

GLOBAL_DEFINES += MODULE_VERSION=$(SYSTEM_PART1_MODULE_VERSION)
ifeq ("$(HYBRID_BUILD)", "y")
GLOBAL_DEFINES += HYBRID_BUILD=1
GLOBAL_DEFINES += MODULE_FUNCTION=$(MODULE_FUNCTION_MONO_FIRMWARE)
GLOBAL_DEFINES += MODULE_INDEX=0
else
GLOBAL_DEFINES += MODULE_FUNCTION=$(MODULE_FUNCTION_SYSTEM_PART)
GLOBAL_DEFINES += MODULE_INDEX=1
endif
ifeq ("$(MODULE_DEPENDENCY2)", "")
MODULE_DEPENDENCY2=0,0,0
endif
GLOBAL_DEFINES += MODULE_DEPENDENCY=${MODULE_FUNCTION_BOOTLOADER},0,${BOOTLOADER_DEPENDENCY}
GLOBAL_DEFINES += MODULE_DEPENDENCY2=$(MODULE_DEPENDENCY2)

ifeq ("$(INCLUDE_APP)", "y")
GLOBAL_DEFINES += INCLUDE_APP
endif

LINKER_FILE=$(SYSTEM_PART1_MODULE_PATH)/linker.ld
LINKER_DEPS += $(LINKER_FILE)

LINKER_DEPS += $(SYSTEM_PART1_MODULE_PATH)/module_system_part1_export.ld
LINKER_DEPS += $(SHARED_MODULAR)/module_user_export.ld

LINKER_DEPS += $(NEWLIB_TWEAK_SPECS)
LDFLAGS += --specs=nano.specs --specs=$(NEWLIB_TWEAK_SPECS)
LDFLAGS += -L$(SYSTEM_PART1_MODULE_PATH)
LDFLAGS += -L$(SHARED_MODULAR)
LDFLAGS += -L$(USER_PART_MODULE_PATH)
LDFLAGS += -T$(LINKER_FILE)
LDFLAGS += -Wl,--defsym,PLATFORM_DFU=$(PLATFORM_DFU)
LDFLAGS += -Wl,-Map,$(TARGET_BASE).map

# Minimum main stack size with S140 softdevice is 1536 bytes
# __STACKSIZE__ is referenced by build/arm/linker/nrf52840/platform_ram.ld
MAIN_STACK_SIZE = 2048
LDFLAGS += -Wl,--defsym,__STACKSIZE__=$(MAIN_STACK_SIZE)
LDFLAGS += -Wl,--defsym,__STACK_SIZE=$(MAIN_STACK_SIZE)

# assembler startup script
ASRC += $(COMMON_BUILD)/arm/startup/startup_$(STM32_DEVICE_LC).S
ASFLAGS += -I$(COMMON_BUILD)/arm/startup
ASFLAGS +=  -Wa,--defsym -Wa,SPARK_INIT_STARTUP=0
ASFLAGS += -D__STACKSIZE__=$(MAIN_STACK_SIZE) -D__STACK_SIZE=$(MAIN_STACK_SIZE)

ifneq ("$(HAL_MINIMAL)","y")
USE_PRINTF_FLOAT ?= y
endif

ifeq ("$(USE_PRINTF_FLOAT)","y")
LDFLAGS += -u _printf_float
endif

LDFLAGS += -u uxTopUsedPriority

INCLUDE_DIRS += $(SHARED_MODULAR)/inc/system-part1
SYSTEM_PART1_MODULE_SRC_PATH = $(SYSTEM_PART1_MODULE_PATH)/src

CPPSRC += $(call target_files,$(SYSTEM_PART1_MODULE_SRC_PATH),*.cpp)
CSRC += $(call target_files,$(SYSTEM_PART1_MODULE_SRC_PATH),*.c)
