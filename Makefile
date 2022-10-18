CC := g++

EXEC := debug
BUILD_DIR := build

LIBRARIES := -lsfml-graphics -lsfml-window -lsfml-system

OPTIONS := -Wall -O3

SOURCE := $(shell find src -name '*.cpp')
OBJECTS := $(SOURCE:.cpp=.o)

all: $(BUILD_DIR)/$(EXEC)

vbuild: $(OBJECTS) $(BUILD_DIR)/$(EXEC)
	$(CC) $(OPTIONS) --verbose -o $(BUILD_DIR)/$(EXEC) $(OBJECTS) $(LIBRARIES)

$(BUILD_DIR)/$(EXEC): $(OBJECTS)
	$(CC) $(OPTIONS) -o $@ $^ $(LIBRARIES)

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
	$(BUILD_DIR)/$(EXEC)

# Run windowed
runw:
	$(BUILD_DIR)/$(EXEC) w
