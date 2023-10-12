CC = g++
CPPFLAGS=-Wall -pedantic -std=c++17 -Wextra

TARGET = redcars

$(TARGET): redcars.o GeoPosition.o Vehicle.o Card.o Customer.o Reservation.o Station.o User.o Usage.o Distance.o TimeFrame.o Money.o Charge.o

clean:
	rm -f *.o $(TARGET)
