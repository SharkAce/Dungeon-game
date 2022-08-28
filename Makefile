CC := g++

EXEC := debug
BUILD_DIR := build

LIBRARIES := -lsfml-graphics -lsfml-window -lsfml-system

WARNINGS := -Wall 
OPTIONS := --verbose

HEADERS := $(shell find src -name '*.hpp')
SOURCE := $(shell find src -name '*.cpp')
OBJECTS := $(SOURCE:.cpp=.o)

all: $(BUILD_DIR)/$(EXEC)

vbuild: $(OBJECTS) $(BUILD_DIR)/$(EXEC)
	$(CC) $(WARNINGS) $(OPTIONS) -o $(BUILD_DIR)/$(EXEC) $(OBJECTS) $(LIBRARIES)

$(BUILD_DIR)/$(EXEC): $(OBJECTS)
	$(CC) $(WARNINGS) -o $@ $^ $(LIBRARIES)

$(OBJECTS): | $(BUILD_DIR)

$(BUILD_DIR):
	mkdir build

$(OBJECTS): %.o : %.cpp
	$(CC) -o $@ -c $<	

clean:
	rm -f $(BUILD_DIR)/$(EXEC)
	rm -f $(OBJECTS)

# Run in Fullscreen
run:
	$(BUILD_DIR)/$(EXEC) f

# Run windowed
runw:
	$(BUILD_DIR)/$(EXEC)
