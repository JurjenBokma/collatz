#!/usr/bin/make

SUBDIRS = c++

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: clean

define MKCLEAN

$(MAKE) -C $(DIR) clean

endef

clean:
	$(foreach DIR,$(SUBDIRS),$(MKCLEAN))
