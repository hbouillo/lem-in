# SHELL
ZSH = /bin/zsh
ifneq ("$(wildcard $(ZSH))","")
SHELL = /bin/zsh
endif

# DEBUG_MODE
ifneq ($(MODE),DEBUG)
override MODE = NORMAL
endif
export MODE
ifeq ($(MODE),DEBUG)
DEBUG_FLAGS = -fsanitize=address -g
else
DEBUG_FLAGS = -Wall -Werror -Wextra
endif

# LIBS VARS
LIBS_PATH=$(shell echo ~/.libs)

# STYLE VARS
STL_BOLD = \x1b[1m
RGB_YELLOW = \x1b[38;2;239;196;23m
RGB_LGREEN = \x1b[38;2;93;239;183m
RGB_CYAN = \x1b[38;2;112;225;232m
RGB_BLUE = \x1b[38;2;83;154;252m
RGB_LBLUE = \x1b[38;2;147;204;252m
RGB_LRED = \x1b[38;2;255;100;100m
RGB_RESET = \x1b[0m

# MESSAGE VARS
ifeq ($(MODE),DEBUG)
BGN_1 = "$(STL_BOLD)$(RGB_YELLOW)⚠  Compiling $(RGB_LRED)
BGN_2 = $(RGB_YELLOW) in $(RGB_LRED)$(MODE)$(RGB_YELLOW) mode. ⚠ $(RGB_RESET)"
else
BGN_1 = "$(STL_BOLD)$(RGB_BLUE)⧖  Compiling $(RGB_CYAN)
BGN_2 = $(RGB_BLUE) in $(RGB_CYAN)$(MODE)$(RGB_BLUE) mode. ⧖ $(RGB_RESET)"
endif

NDONE_1 = "$(STL_BOLD)$(RGB_LRED)✗  Nothing to be done for $(RGB_CYAN)
NDONE_2 = $(RGB_LRED). ✗$(RGB_RESET)"
SDONE_1 = "$(STL_BOLD)$(RGB_BLUE)✓  Compiled $(RGB_CYAN)
SDONE_2 = $(RGB_BLUE) successfully. ✓$(RGB_RESET)"

END_MSG = end_msg_ndone

# FUNCTIONS

define bgn_msg
	@echo $(BGN_1)$(1)$(BGN_2)
endef

define end_msg_sdone
	@echo $(SDONE_1)$(1)$(SDONE_2)
endef

define end_msg_ndone
	@echo $(NDONE_1)$(1)$(NDONE_2)
endef

define lib_configure_make_install
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Creating $(RGB_CYAN)$(1)\
	$(RGB_BLUE)... ⧖ $(RGB_RESET)"
	@echo "\tConfiguring..."
	@cd $(1) && ./configure --prefix=$(LIBS_PATH) 1>/dev/null
	@echo "\tCompiling..."
	@$(MAKE) -C $(1) 1>/dev/null
	@echo "\tInstalling to $(STL_BOLD)$(RGB_LBLUE)$(LIBS_PATH)$(RGB_RESET)..."
	@$(MAKE) -C $(1) install 1>/dev/null
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Installed $(RGB_CYAN)$(1)\
	$(RGB_BLUE) successfully. ✓$(RGB_RESET)"
endef

define lib_clean
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Cleaning $(RGB_CYAN)$(1)\
	$(RGB_BLUE)... ⧖$(RGB_RESET)"
	@$(MAKE) -C $(1) 1>/dev/null 2>/dev/null clean
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Cleaned $(RGB_CYAN)$(1)\
	$(RGB_BLUE) objs successfully. ✓$(RGB_RESET)"
endef

define compile
	@echo "\tCompiling $(STL_BOLD)$(RGB_LBLUE)$@$(RGB_RESET)..."
	@mkdir -p $(@D)
	@$(CC) $(1) -c $< -o $@
endef

define link
	@echo "\tLinking $(STL_BOLD)$(RGB_LRED)$@$(RGB_RESET)..."
	@$(CC) -o $@ $^ $(1)
	@$(eval END_MSG = end_msg_sdone)
endef

define link_lib
	@echo "\tArchiving $(STL_BOLD)$(RGB_LRED)$@$(RGB_RESET)..."
	@ar rc $@ $^
	@echo "\tIndexing  $(STL_BOLD)$(RGB_LRED)$@$(RGB_RESET)..."
	@ranlib $@
	@$(eval END_MSG = end_msg_sdone)
endef

define link_dylib
	@mkdir -p lib
	@echo "\tCompiling $(STL_BOLD)$(RGB_LRED)$@$(RGB_RESET)..."
	@$(CC) -dynamiclib -install_name "@executable_path/lib/$(notdir $@)" -o $@ $^ $(1)
	@$(eval END_MSG = end_msg_sdone)
endef

define dylib_install
	@install_name_tool -id "@executable_path/lib/$(notdir $(1))" $(1)
	@cp $(1) ./lib
endef

define dylib_include_install
	@cp -R $(1)/* ./lib/inc/
endef

define clean
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Cleaning $(RGB_CYAN)$(1)\
	$(RGB_BLUE) objs... ⧖$(RGB_RESET)"
	@/bin/rm -f $(2)
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Cleaned $(RGB_CYAN)$(1)\
	$(RGB_BLUE) objs successfully. ✓$(RGB_RESET)"
endef

define fclean
	$(call clean,$(1),$(2))
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Cleaning $(RGB_CYAN)$(1)\
	$(RGB_BLUE)... ⧖$(RGB_RESET)"
	@echo "\tCleaning $(STL_BOLD)$(RGB_LRED)$(1)$(RGB_RESET)..."
	@/bin/rm -f $(1)
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Cleaned $(RGB_CYAN)$(1)\
	$(RGB_BLUE) successfully. ✓$(RGB_RESET)"
endef

define lib_fclean
	$(call clean,$(1),$(2))
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Cleaning $(RGB_CYAN)$(1)\
	$(RGB_BLUE)... ⧖$(RGB_RESET)"
	@echo "\tCleaning $(STL_BOLD)$(RGB_LRED)$(1)$(RGB_RESET)..."
	@/bin/rm -rf lib
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Cleaned $(RGB_CYAN)$(1)\
	$(RGB_BLUE) successfully. ✓$(RGB_RESET)"
endef

.NOTPARALLEL:
