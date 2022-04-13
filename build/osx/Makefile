
CC := gcc
CXX := g++

MAIN_EXEC ?= Math
TEST_EXEC ?= MathTest

TOP_DIR ?= ../..
BIN_DIR ?= ../../bin
OBJ_DIR ?= ../../obj
SRC_DIR ?= ../../src

MAIN_OBJ ?= $(TOP_DIR)/obj/Driver.o
TEST_OBJ ?= $(TOP_DIR)/obj/TestFramework.o $(TOP_DIR)/obj/Test.o
MAIN_DIR ?= ../../main
TEST_DIR ?= ../../test

SRCS := $(shell find $(SRC_DIR) -name *.cpp -or -name *.c)
OBJS := $(foreach O, $(notdir $(SRCS:%=$(OBJ_DIR)/%.o)), $(OBJ_DIR)/$O)

LIB_DIRS := \

LIBS := \

INC_DIRS := \
	../../include \

INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS ?= $(INC_FLAGS) -g -DDEBUG

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=c++11 -g -DDEBUG

default: $(BIN_DIR)/$(MAIN_EXEC) $(BIN_DIR)/$(TEST_EXEC)

$(BIN_DIR)/$(MAIN_EXEC): $(OBJS) $(MAIN_OBJ)
	$(MKDIR_P) $(dir $@)
	$(CXX) $(OBJS) $(MAIN_OBJ) -o $@ $(LDFLAGS) $(LIB_DIRS) $(LIBS)

$(BIN_DIR)/$(TEST_EXEC): $(OBJS) $(TEST_OBJ)
	$(MKDIR_P) $(dir $@)
	$(CXX) $(OBJS) $(TEST_OBJ) -o $@ $(LDFLAGS) $(LIB_DIRS) $(LIBS)

$(MAIN_OBJ): $(MAIN_DIR)/Driver.cpp
	$(MKDIR_P) $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/TestFramework.o: $(TEST_DIR)/TestFramework.cpp
	$(MKDIR_P) $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Test.o: $(TEST_DIR)/Test.cpp
	$(MKDIR_P) $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# c source
$(OBJ_DIR)/%.c.o: $(SRC_DIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# c++ source
$(OBJ_DIR)/%.cpp.o: $(SRC_DIR)/%.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

EMACS := $(shell find $(TOP_DIR) -name *~)

clean:
	$(RM) -r $(EMACS)
	$(RM) -r $(OBJ_DIR)
	$(RM) -r $(BIN_DIR)

MKDIR_P ?= mkdir -p
