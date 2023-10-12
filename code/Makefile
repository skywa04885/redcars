CC = g++
CPPFLAGS=-Wall -pedantic -std=c++17 -Wextra

TARGET = redcars

MODEL = model/GeoPosition.o model/Vehicle.o model/Card.o model/Customer.o model/Reservation.o model/Station.o model/User.o model/Usage.o model/Distance.o model/TimeFrame.o model/Money.o model/Charge.o model/Subscription.o

all: $(TARGET)

$(TARGET): redcars.o  $(MODEL)

clean:
	rm -f model/*.o *.o $(TARGET)
