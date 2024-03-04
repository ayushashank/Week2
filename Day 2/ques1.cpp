#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class Person for creating a person
class Person
{
private:
    string personName;

public:
    // Constructors;
    Person()
    {
        this->personName = "";
    }
    Person(string name)
    {
        this->personName = name;
    }

    // Method to set the person name
    void setPersonName(string name)
    {
        this->personName = name;
    }

    // Method to return the person name
    string getPersonName()
    {
        return this->personName;
    }
};

// Class admin to maek an admin of a floor
class Admin : public Person
{
public:
    // Constructors
    Admin() : Person() {}
    Admin(string name) : Person(name) {}

    // Methods for the admins
    void addParkingFloor(){};
    void removeParkingFloor();
    void addParkingSpot();
    void removeParkingSpot();
    void addParkingAttendant();
    void removeParkingAttendant();
    void addModifyParkingRate();
};

// Customer class for having customers who need to park the vehicle
class Customer : public Person
{
public:
    // Constructors
    Customer() : Person() {}
    Customer(string name) : Person(name) {}

    // Methods for Customers
    void takeTicket();
    void scanTicket();
    void makeCreditCardPayment();
    void makeCashPayment();
};

// Class for creating parking attendant for each parking lot
class ParkingAttendant : public Person
{
public:
    // Constructors
    ParkingAttendant() : Person() {}
    ParkingAttendant(string name) : Person(name) {}

    // Methods for ParkingAttendant
    void takeTicket(Customer customer);
    void scanTicket(Customer customer);
    void takeCashPayment(Customer customer);
};

// Class for parking spots
class ParkingSpot
{
private:
    string parkingSpotType;
    bool isOccupied;

public:
    // Constructors
    ParkingSpot()
    {
        this->parkingSpotType = "";
        isOccupied = false;
    }
    ParkingSpot(string type)
    {
        this->parkingSpotType = type;
        isOccupied = false;
    }

    // Assigning the type and marking it unoccupied
    ParkingSpot(string type, bool isOccupied)
    {
        this->parkingSpotType = type;
        this->isOccupied = isOccupied;
    }

    // Methods for Parking Spot
    bool isSpotOccupied() { return isOccupied; }
    void occupySpot() { this->isOccupied = true; }
    void vacateSpot() { this->isOccupied = false; }
};

// Class for Parking floor
class ParkingFloor
{
private:
    vector<ParkingSpot> spots;
    // System displayBoard;

public:
    // Constructors
    ParkingFloor()
    {
        this->spots = {};
    }
    ParkingFloor(vector<ParkingSpot> spotVector)
    {
        this->spots = spotVector;
    }

    // Methods for Parking floor
    void addParkingSpot(string spotType){};
    void removeParkingSpot(string spotType);
    void displayFreeSpots();
};

// Class for parking lot
class ParkingLot
{
private:
    vector<Admin> admins;
    vector<Customer> customers;
    vector<ParkingAttendant> parkingAttendants;
    vector<ParkingFloor> parkingFloors;

public:
    // adding admin to the parking lot
    void addAdmin(Admin &admin)
    {
        admins.push_back(admin);
    }

    // adding customer to customer
    void addCustomer(Customer &customer)
    {
        customers.push_back(customer);
    }

    // adding parking attendant to the parking lot
    void addParkingAttendant(ParkingAttendant &parkingAttendant)
    {
        parkingAttendants.push_back(parkingAttendant);
    }

    // adding parking floors to the parking lot
    void addParkingFloor(ParkingFloor &parkingFloor)
    {
        parkingFloors.push_back(parkingFloor);
    }
};

// Creating a vehicle class
class Vehicle
{
private:
    string vehicleType;

public:
    // Constructors
    Vehicle() { this->vehicleType = ""; }
    Vehicle(string type) { this->vehicleType = type; }

    // Method to return the type pf the vehicle
    string getVehicleType() { return this->vehicleType; }
};

int main()
{
    // ParkingLot parkingLotObj;

    // Admin adminObj("Admin1");
    // parkingLotObj.addAdmin(adminObj);

    // Customer customerObj("Customer1");
    // parkingLotObj.addCustomer(customerObj);

    // ParkingAttendant parkingAttendantObj("Attendant1");
    // parkingLotObj.addParkingAttendant(parkingAttendantObj);

    // ParkingFloor parkingFloorObj();
    // parkingLotObj.addParkingFloor(parkingFloorObj);

    return 0;
}