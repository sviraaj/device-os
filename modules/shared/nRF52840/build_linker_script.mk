WRITE_FILE_CREATE = $(shell echo "$(2)" > $(1))
WRITE_FILE_APPEND = $(shell echo "$(2)" >> $(1))

COMMA := ,

ifneq (,$(PREBUILD))
# Should declare enough RAM for inermediate linker script: 89K
USER_SRAM_LENGTH = 89K
else
DATA_SECTION_LEN  = $(shell arm-none-eabi-objdump -h --section=.data $(INTERMEDIATE_ELF) | grep .data)
DATA_SECTION_LEN := 0x$(word 3,$(DATA_SECTION_LEN))
BSS_SECTION_LEN   = $(shell arm-none-eabi-objdump -h --section=.bss $(INTERMEDIATE_ELF) | grep .bss)
BSS_SECTION_LEN  := 0x$(word 3,$(BSS_SECTION_LEN))

# Note: reserving 16 bytes for alignment just in case
USER_SRAM_LENGTH = ( $(DATA_SECTION_LEN) + $(BSS_SECTION_LEN) + 16 )

all: $(INTERMEDIATE_ELF)
endif

all:
	@echo Creating $(MODULE_USER_MEMORY_FILE_GEN) ...
	$(call WRITE_FILE_APPEND, "$(MODULE_USER_MEMORY_FILE_GEN)",_user_part_static_ram_size = $(USER_SRAM_LENGTH);)
