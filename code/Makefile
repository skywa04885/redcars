CC = g++
CPPFLAGS=-Wall -pedantic -std=c++17 -Wextra

TARGET = redcars

MODEL = model/GeoPosition.o model/Vehicle.o model/Card.o model/Customer.o model/Reservation.o model/Station.o model/User.o model/Usage.o model/Distance.o model/TimeFrame.o model/Money.o model/Charge.o model/Subscription.o model/BankAccount.o
CONTROLLERS = controllers/Controller.o controllers/CliController.o controllers/RegisterController.o controllers/ReservationController.o controllers/VehicleSearchController.o controllers/CheckInController.o controllers/CheckOutController.o controllers/SubscribeController.o
PAYMENT = payment/PaymentSystem.o
MOCK = mock/CliMock.o
REPO = repo/Repository.o repo/CustomerRepository.o repo/BankAccountRepository.o repo/CardRepository.o repo/VehicleRepository.o repo/ReservationRepository.o repo/StationRepository.o
DELIVERY = delivery/DeliverySystem.o
MAIL = mail/EmailSystem.o
VIEW = view/View.o
VEHICLE = vehicle/VehicleComs.o

OBJECTS = $(MODEL) $(CONTROLLERS) $(PAYMENT) $(REPO) $(MOCK) $(MAIL) $(DELIVERY) $(VIEW) $(VEHICLE)

all: $(TARGET)

$(TARGET): redcars.o $(OBJECTS)

clean:
	rm -f $(OBJECTS) redcars.o $(TARGET)
