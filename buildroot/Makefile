TOPDIR := $(shell pwd)/buildroot

GLOBAL_DL_PATH = $(HOME)/dl
LOCAL_DL_PATH  = $(TOPDIR)/dl
DL_PATH       ?= $(if $(wildcard $(GLOBAL_DL_PATH)),$(GLOBAL_DL_PATH),$(LOCAL_DL_PATH))

MAKE = make -C buildroot BR2_EXTERNAL=$(TOPDIR) BR2_DL_DIR=$(DL_PATH)
FWUP = sudo buildroot/output/host/usr/bin/fwup

# TARGETS ======================================================================

all:
	$(MAKE)
	@echo
	@echo "Hub built successfully. Images are in buildroot/output/images."

sd:
	$(FWUP)

sd-upgrade:

clean:
	rm -rf buildroot

help:
	@echo "Targets:"
	@echo "  all                     - Build the current configuration"
	@echo "  sd                      - Burn the SD card image"
	@echo "  sd-upgrade              - Upgrade the SD card image"
	@echo "  clean                   - Clean everything"
	@echo
	@echo "Configuration:"
	@echo "  menuconfig              - Run Buildroot's menuconfig"
	@echo "  linux-menuconfig        - Run Linux's menuconfig"
	@echo "  uboot-menuconfig        - Run U-Boot's menuconfig"
	@echo
	@echo "Board Configurations:"
	@$(foreach b, $(sort $(notdir $(wildcard configs/*_defconfig))), \
	  printf "  %-23s - Configure for %s board\\n" $(b) $(b:_defconfig=);)

# BUILDROOT TARGETS ============================================================

menuconfig:
	$(MAKE) menuconfig

linux-menuconfig:
	$(MAKE) linux-menuconfig

uboot-menuconfig:
	$(MAKE) uboot-menuconfig

%_defconfig: $(TOPDIR)/configs/%_defconfig
	$(MAKE) $@
