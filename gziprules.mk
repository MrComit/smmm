# Compress binary file to gzip
$(BUILD_DIR)/%.gz: $(BUILD_DIR)/%.bin
	$(call print,Compressing:,$<,$@)
ifeq ($(GZIPVER),std)
	$(V)$(GZIP) -c -9 -n $< > $@
else
	$(V)$(GZIP) -c -12 -n $< > $@
endif

# Strip gzip header
$(BUILD_DIR)/%.szp: $(BUILD_DIR)/%.gz
	$(call print,Converting:,$<,$@)
	$(V)dd bs=10 skip=1 if=$< of=$@
	$(V)$(FILESIZER) $(<:.gz=.bin) $@

# convert binary szp to object file
$(BUILD_DIR)/%.szp.o: $(BUILD_DIR)/%.szp
	$(call print,Converting GZIP to ELF:,$<,$@)
	$(V)printf ".section .data\n\n.incbin \"$<\"\n" | $(AS) $(ASFLAGS) -o $@