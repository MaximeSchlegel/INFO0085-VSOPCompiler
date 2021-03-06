CC := g++
CPP_FLAG := -W -Wall -g
LLVM_FLAGS := $(shell llvm-config --cppflags --ldflags --libs core --system-libs)
LLVM_FLAGS := $(subst -I,-isystem,$(LLVM_FLAGS))

EXEC := vsopc

BUILD_DIR := ../build

EXCEPT_DIR := exception
EXCEPT_SRC := $(wildcard $(EXCEPT_DIR)/src/*.cpp)
EXCEPT_OBJ := $(patsubst $(EXCEPT_DIR)/src/%.cpp, $(BUILD_DIR)/exception/%.o, $(EXCEPT_SRC))

DEBUG_DIR := debugger
DEBUG_SRC := $(wildcard $(DEBUG_DIR)/src/*.cpp)
DEBUG_OBJ := $(patsubst $(DEBUG_DIR)/src/%.cpp, $(BUILD_DIR)/debugger/%.o, $(DEBUG_SRC))

ASTNODE_DIR := ast_node
ASTNODE_SRC := $(wildcard $(ASTNODE_DIR)/src/*.cpp)
ASTNODE_OBJ := $(patsubst $(ASTNODE_DIR)/src/%.cpp, $(BUILD_DIR)/ast_node/%.o, $(ASTNODE_SRC))

SYMBTAB_DIR := symbol_table
SYMBTAB_SRC := $(wildcard $(SYMBTAB_DIR)/src/*.cpp)
SYMBTAB_OBJ := $(patsubst $(SYMBTAB_DIR)/src/%.cpp, $(BUILD_DIR)/symbol_table/%.o, $(SYMBTAB_SRC))


all: install-tools vsopc


install-tools:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/ast_node
	mkdir -p $(BUILD_DIR)/symbol_table
	mkdir -p $(BUILD_DIR)/exception
	mkdir -p $(BUILD_DIR)/debugger

	[ -e /lib/x86_64-linux-gnu/libz.so ] \
		|| sudo ln -s /lib/x86_64-linux-gnu/libz.so.1 \
						/lib/x86_64-linux-gnu/libz.so
	[ -e /usr/lib/x86_64-linux-gnu/libstdc++.so ] \
		|| sudo ln -s /usr/lib/x86_64-linux-gnu/libstdc++.so.6 \
						/usr/lib/x86_64-linux-gnu/libstdc++.so

$(BUILD_DIR)/exception/%.o: $(EXCEPT_DIR)/src/%.cpp
	$(CC) $(CPP_FLAG) -c -o $@ $< $(LLVM_FLAGS)

$(BUILD_DIR)/debugger/%.o: $(DEBUG_DIR)/src/%.cpp
	$(CC) $(CPP_FLAG) -c -o $@ $< $(LLVM_FLAGS)

$(BUILD_DIR)/ast_node/%.o: $(ASTNODE_DIR)/src/%.cpp
	$(CC) $(CPP_FLAG) -c -o $@ $< $(LLVM_FLAGS)

$(BUILD_DIR)/symbol_table/%.o: $(SYMBTAB_DIR)/src/%.cpp
	$(CC) $(CPP_FLAG) -c -o $@ $< $(LLVM_FLAGS)

$(BUILD_DIR)/parser.o compiler/src/Parser.h: compiler/vsop_parser.y ast_node/ASTNode.h
	bison -d --locations -o compiler/src/Parser.c compiler/vsop_parser.y
	$(CC) $(CPP_FLAG) -c -o $(BUILD_DIR)/parser.o compiler/src/Parser.c $(LLVM_FLAGS)

$(BUILD_DIR)/lexer.o compiler/src/Lexer.h: compiler/src/Parser.h compiler/vsop_lexer.l
	flex --header-file=compiler/src/Lexer.h -o compiler/src/Lexer.c compiler/vsop_lexer.l
	$(CC) $(CPP_FLAG) -c -o $(BUILD_DIR)/lexer.o compiler/src/Lexer.c $(LLVM_FLAGS)

$(BUILD_DIR)/ASTProcessor.o: compiler/src/ASTProcessor.cpp
	$(CC) $(CPP_FLAG) -c -o $(BUILD_DIR)/ASTProcessor.o compiler/src/ASTProcessor.cpp $(LLVM_FLAGS)

$(EXEC): compiler/src/main.cpp $(BUILD_DIR)/lexer.o $(BUILD_DIR)/parser.o $(BUILD_DIR)/ASTProcessor.o $(EXCEPT_OBJ) $(DEBUG_OBJ) $(ASTNODE_OBJ) $(SYMBTAB_OBJ)
	$(CC) $(CPP_FLAG) $^ -o $@ $(LLVM_FLAGS)


clean:
	rm -rf $(BUILD_DIR)

clean-all: clean
	rm ./$(EXEC)
