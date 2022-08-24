CC := c++
EXEC_FILE := dungeon-game
OBJECTS := $(shell find src/ -name '*.cpp' | sed 's/.cpp/.o/g;s/src\//build\//g')

all: $(EXEC_FILE)

$(EXEC_FILE): $(OBJECTS)
	$(CC) $^ -o $@

build/%.o: src/%.cpp
	$(CC) -o $@ -c $<

install: $(EXEC_FILE)
	cp $(EXEC_FILE) /usr/bin/

uninstall:
	unlink /usr/bin/$(EXEC_FILE)

clean:
	rm -f build/*
	rm -f $(EXEC_FILE)
