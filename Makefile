BUILD_DIR := build

configure:
	cmake -S . -B $(BUILD_DIR)

build: configure
	cmake --build $(BUILD_DIR)

server: build
	./$(BUILD_DIR)/race_timer_server

clean:
	rm -rf $(BUILD_DIR)

.PHONY: configure build server client clean