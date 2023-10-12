CC = g++
CPPFLAGS=-Wall -pedantic -std=c++17 -Wextra

TARGET = redcars

MODEL = model/GeoPosition.o model/Vehicle.o model/Card.o model/Customer.o model/Reservation.o model/Station.o model/User.o model/Usage.o model/Distance.o model/TimeFrame.o model/Money.o model/Charge.o model/Subscription.o model/BankAccount.o
CONTROLLERS = controllers/Controller.o controllers/CliController.o controllers/RegisterController.o
PAYMENT = payment/PaymentSystem.o
MOCK = mock/CliMock.o
REPO = repo/Repository.o repo/CustomerRepository.o repo/BankAccountRepository.o repo/CardRepository.o
MAIL = mail/EmailSystem.o
DELIVERY = delivery/DeliverySystem.o

OBJECTS = $(MODEL) $(CONTROLLERS) $(PAYMENT) $(REPO) $(MOCK) $(MAIL) $(DELIVERY)

all: $(TARGET)

$(TARGET): redcars.o $(OBJECTS)

clean:
	rm -f $(OBJECTS) redcars.o $(TARGET)
