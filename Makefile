OUTPUT_DIR=output/

all: $(OUTPUT_DIR)RunningMedian

$(OUTPUT_DIR)RunningMedian: RunningMedian.cpp
	mkdir -p $(OUTPUT_DIR)
	g++ -Wall -Wextra $< -o $@
