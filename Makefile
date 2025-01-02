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
.PHONY: all run clean help

# Compile and run target
run:
	@if [ "$(ARGS)" = "" ]; then \
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
	@echo ""
	@echo "Example usage:"
	@echo "  make run hello.cpp"
	@echo "  make run src/hello.cpp"

# Catch-all target to handle the arguments
%:
	@:
