CC := g++

EXEC := debug
BUILD_DIR := build

LIBRARIES := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OPTIONS := -Wall -O3

SOURCES := $(shell find src -name '*.cpp')
OBJECTS := $(SOURCES:.cpp=.o)
DEPENDS := $(SOURCES:.cpp=.d)

.PHONY: all clean

all: $(BUILD_DIR)/$(EXEC)

$(BUILD_DIR)/$(EXEC): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OPTIONS) $^ -o $@ $(LIBRARIES)

-include $(DEPENDS)

%.o : %.cpp Makefile
	$(CC) -MMD -MP -c $< -o $@	

clean:
	rm -f $(BUILD_DIR)/$(EXEC)
	rm -f $(OBJECTS)
	rm -f $(DEPENDS)

# Run in Fullscreen
run:
	$(BUILD_DIR)/$(EXEC)

# Run windowed
runw:
	$(BUILD_DIR)/$(EXEC) w
