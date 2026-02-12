# =========================
# Compiler
# =========================
CXX := g++

# =========================
# Directories
# =========================
SRCDIR := Src
INCDIR := Inc
BUILDDIR := build

# =========================
# Target
# =========================
TARGET := $(BUILDDIR)/game

# =========================
# Flags
# =========================
CXXFLAGS := -Wall -Wextra -std=c++20 -ggdb -pthread -I$(INCDIR)

# =========================
# Sources & Objects
# =========================
SOURCES := $(shell find $(SRCDIR) -name "*.cpp")
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# =========================
# Phony targets
# =========================
.PHONY: all run clean

# =========================
# Default
# =========================
all: $(TARGET)

# =========================
# Link step
# =========================
$(TARGET): $(OBJECTS)
	@echo "🔗 Linking game"
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# =========================
# Compile step
# =========================
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================
# Run
# =========================
run: $(TARGET)
	@echo "▶ Running game"
	./$(TARGET)

# =========================
# Clean
# =========================
clean:
	@echo "🧹 Cleaning"
	rm -rf $(BUILDDIR)
