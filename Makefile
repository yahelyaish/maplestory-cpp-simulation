# =========================
# Compiler
# =========================
CXX := g++

# =========================
# Directories
# =========================
SRCDIR := Src
INCDIR := Inc

# =========================
# Target
# =========================
TARGET := game

# =========================
# Flags
# =========================
CXXFLAGS := -Wall -Wextra -std=c++17 -ggdb -pthread \
            -I$(INCDIR) \
            -I$(INCDIR)/Character \
            -I$(INCDIR)/Task

# =========================
# Sources
# =========================
SOURCES := $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/*.cpp)

# =========================
# Phony targets
# =========================
.PHONY: all run clean

# =========================
# Default
# =========================
all: $(TARGET)

# =========================
# Build
# =========================
$(TARGET):
	@echo "🛠️  Building $(TARGET)"
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# =========================
# Run
# =========================
run: $(TARGET)
	@echo "▶ Running $(TARGET)"
	./$(TARGET)

# =========================
# Clean
# =========================
clean:
	@echo "🧹 Cleaning"
	rm -f $(TARGET)
