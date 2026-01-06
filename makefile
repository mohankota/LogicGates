# ==============================
# Toolchain
# ==============================
CC = gcc

# ==============================
# Directories
# ==============================
SRC_DIR    = SRC
INC_DIR    = INC
TEST_DIR   = TEST
UNITY_DIR  = TEST/unity
OBJ_DIR    = OBJ
TARGET_DIR = TARGET

# ==============================
# Compiler flags
# ==============================
CFLAGS = -Wall -Wextra -Werror -std=c99 -I$(INC_DIR) -I$(TEST_DIR) -I$(UNITY_DIR)

# ==============================
# Application
# ==============================
APP = logic_gate
APP_SRC = $(SRC_DIR)/LogicGateMain.c
LIB_SRCS = $(filter-out $(APP_SRC), $(wildcard $(SRC_DIR)/*.c))
LIB_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(LIB_SRCS))
APP_OBJ  = $(OBJ_DIR)/LogicGateMain.o
APP_OUT  = $(TARGET_DIR)/$(APP)

# ==============================
# Unity
# ==============================
UNITY_SRC   = $(UNITY_DIR)/unity.c
UNITY_SETUP = $(UNITY_DIR)/unity_setup.c

# ==============================
# Unit tests (auto-detected)
# ==============================
TEST_SRCS := $(wildcard $(TEST_DIR)/*_test.c)
TEST_BINS := $(patsubst $(TEST_DIR)/%_test.c,$(TARGET_DIR)/%_test,$(TEST_SRCS))

# ==============================
# Test selection logic
# ==============================
# Extra args: make test HalfAdder_test.c
EXTRA_TESTS := $(filter %.c,$(MAKECMDGOALS))

# Convert file names → test binaries
SELECTED_TEST_BINS := $(patsubst %.c,$(TARGET_DIR)/%,$(notdir $(EXTRA_TESTS)))

# Decide which tests to run
ifeq ($(EXTRA_TESTS),)
RUN_TESTS := $(TEST_BINS)
else
RUN_TESTS := $(SELECTED_TEST_BINS)
endif

# Tell make these are NOT real build targets
.PHONY: $(EXTRA_TESTS)

# ==============================
# Default build
# ==============================
all: $(APP_OUT)

# ==============================
# Build application
# ==============================
$(APP_OUT): $(APP_OBJ) $(LIB_OBJS) | $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# ==============================
# Compile objects
# ==============================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ==============================
# Build test binaries
# ==============================
$(TARGET_DIR)/%_test: $(TEST_DIR)/%_test.c $(LIB_OBJS) $(UNITY_SRC) $(UNITY_SETUP) | $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# ==============================
# Run tests + generate report
# ==============================
test: $(RUN_TESTS)
	@REPORT=test_report.txt; \
	echo "====================" > $$REPORT; \
	echo "   Unit Test Report " >> $$REPORT; \
	echo "====================" >> $$REPORT; \
	TOTAL=0; FAILS=0; \
	for t in $(RUN_TESTS); do \
		NAME=$$(basename $$t); \
		echo -n "Running $$NAME ... "; \
		./$$t > /dev/null 2>&1; \
		if [ $$? -eq 0 ]; then \
			echo "PASS"; \
			echo "$$NAME: PASS" >> $$REPORT; \
		else \
			echo "FAIL"; \
			echo "$$NAME: FAIL" >> $$REPORT; \
			FAILS=$$((FAILS+1)); \
		fi; \
		TOTAL=$$((TOTAL+1)); \
	done; \
	echo "--------------------"; \
	echo "Total tests: $$TOTAL"; \
	echo "Passed: $$((TOTAL-FAILS))"; \
	echo "Failed: $$FAILS"; \
	if [ $$FAILS -eq 0 ]; then \
		echo "ALL TESTS PASSED"; \
	else \
		echo "SOME TESTS FAILED"; \
	fi

# ==============================
# Run application
# ==============================
run: all
	./$(APP_OUT)

# ==============================
# Directories
# ==============================
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# ==============================
# Clean
# ==============================
clean:
	rm -rf $(OBJ_DIR) $(TARGET_DIR) test_report.txt

.PHONY: all test run clean
