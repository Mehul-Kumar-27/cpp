# Default target
all:
	@echo "Please specify a cpp file: make run <filepath>"
	@echo "Example: make run src/main.cpp"

# Create output directory if it doesn't exist
$(shell mkdir -p output)

# Extract the filename from the command line arguments
ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

# Extract the base filename without extension
BASENAME := $(notdir $(basename $(ARGS)))

# Declare phony targets
.PHONY: all run clean help test

# Compile and run target
run:
	@if [ -z "$(ARGS)" ]; then \
		echo "Error: Please specify a file path"; \
		echo "Example: make run src/main.cpp"; \
		exit 1; \
	fi
	@if [ ! -f "$(ARGS)" ]; then \
		echo "Error: File '$(ARGS)' does not exist"; \
		exit 1; \
	fi
	@echo "Resolving dependencies for $(ARGS)..."
	@SRC_FILES=$$(find . -name '*.cpp'); \
	echo "Found source files: $$SRC_FILES"; \
	echo "Compiling $(ARGS) and dependencies..."; \
	g++ -std=c++20 -o output/$(BASENAME) $$SRC_FILES && \
	echo "Executable created at output/$(BASENAME)" && \
	echo "Running the program:" && \
	./output/$(BASENAME)

# Clean the output directory
clean:
	rm -rf output/*

# Help target
help:
	@echo "Available commands:"
	@echo "  make run <filepath>  - Compile and run a specific cpp file"
	@echo "  make clean          - Remove all files from output directory"
	@echo "  make help           - Show this help message"
	@echo "  make test <filepath> - Compile and run specific test"
	@echo ""
	@echo "Example usage:"
	@echo "  make run hello.cpp"
	@echo "  make run src/hello.cpp"
	@echo "  make test tests/test_custom_sorting.cpp"

# Test target to compile and run Google Test tests
test:
	@if [ -z "$(ARGS)" ]; then \
		echo "Error: Please specify a test file path"; \
		exit 1; \
	fi
	@if [ ! -f "$(ARGS)" ]; then \
		echo "Error: Test file '$(ARGS)' does not exist"; \
		exit 1; \
	fi
	@echo "Compiling $(ARGS) and dependencies..."
	g++ -std=c++17 -I/opt/homebrew/Cellar/googletest/1.15.2/include \
	-L/opt/homebrew/Cellar/googletest/1.15.2/lib -lgtest -lgtest_main -pthread \
	$(ARGS) custom/*.cpp arrays/*.cpp -o output/test_runner && \
	./output/test_runner --gtest_catch_exceptions=0 --gtest_break_on_failure --gtest_print_time=0

# Catch-all target to handle the arguments
%:
	@echo "Invalid target: $@"
	@echo "Use 'make help' to see available commands."
