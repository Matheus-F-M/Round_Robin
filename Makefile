binary: scheduling_exercise.cpp
	g++ $< -o $@

.PHONY: run clean

run:
	./binary

clean:
	rm binary