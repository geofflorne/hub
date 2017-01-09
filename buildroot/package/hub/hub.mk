################################################################################
#
# Hub
#
################################################################################

HUB_SITE = https://github.com/UVicFormulaMotorsport/hub/archive
HUB_SOURCE = master.zip
HUB_INSTALL_TARGET = YES

define HUB_BUILD_CMDS
    $(MAKE) -C $(@D)
endef

define HUB_INSTALL_TARGET_CMDS
    $(MAKE) -C $(@D) install INSTALL_ROOT=$(TARGET_DIR)
endef

$(eval $(generic-package))
