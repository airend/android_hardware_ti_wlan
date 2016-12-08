TI_WLAN_FOLDER := $(call my-dir)/..

WL12XX_MODULES:
	make clean -C $(TI_WLAN_FOLDER)/mac80211/compat_wl12xx
	make -j8 -C $(TI_WLAN_FOLDER)/mac80211/compat_wl12xx KERNELDIR=$(KERNEL_OUT) KLIB=$(KERNEL_OUT) \
		KLIB_BUILD=$(KERNEL_OUT) ARCH=arm $(if $(ARM_CROSS_COMPILE),$(ARM_CROSS_COMPILE),$(KERNEL_CROSS_COMPILE))
	mv $(TI_WLAN_FOLDER)/mac80211/compat_wl12xx/{compat/compat,net/mac80211/mac80211,net/wireless/cfg80211,drivers/net/wireless/wl12xx/wl12xx,drivers/net/wireless/wl12xx/wl12xx_sdio}.ko $(KERNEL_MODULES_OUT)
	$(if $(ARM_EABI_TOOLCHAIN),$(ARM_EABI_TOOLCHAIN)/arm-eabi-strip,$(KERNEL_TOOLCHAIN_PATH)strip) \
		--strip-unneeded $(KERNEL_MODULES_OUT)/{compat,cfg80211,mac80211,wl12xx,wl12xx_sdio}.ko

TARGET_KERNEL_MODULES += WL12XX_MODULES
