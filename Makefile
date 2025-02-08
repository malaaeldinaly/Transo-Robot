CC = gcc
CFLAGS = -Iinclude

DEPS = include/utils.h include/sensors.h include/motors.h include/servo.h
SRC_OBJ = src/utils.o src/sensors.o src/motors.o src/servo.o
MOCK_OBJ = tests/mock_wiringPi.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

transo-robot: src/main.o $(SRC_OBJ)
	$(CC) -o $@ $^ -lwiringPi

clean:
	rm -f src/*.o transo-robot tests/*.o tests/test_main tests/test_motors tests/test_sensors tests/test_servo tests/test_utils

# Test targets
tests/test_%.o: tests/test_%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tests/test_main: tests/test_main.o $(SRC_OBJ) $(MOCK_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tests/test_motors: tests/test_motors.o src/motors.o src/utils.o $(MOCK_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tests/test_sensors: tests/test_sensors.o src/sensors.o src/utils.o $(MOCK_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tests/test_servo: tests/test_servo.o src/servo.o src/utils.o $(MOCK_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tests/test_utils: tests/test_utils.o src/utils.o $(MOCK_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

test: tests/test_main tests/test_motors tests/test_sensors tests/test_servo tests/test_utils
	./tests/test_main
	./tests/test_motors
	./tests/test_sensors
	./tests/test_servo
	./tests/test_utils