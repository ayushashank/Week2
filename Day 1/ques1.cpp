#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
private:
    string driver;

public:
    Vehicle() {}
    Vehicle(string driver)
    {
        this->driver = driver;
    }
    string getDriver()
    {
        return this->driver;
    }
};

class Car : public Vehicle
{
public:
    Car() {}
    Car(string driver) : Vehicle(driver) {}
};

class Aircraft : public Vehicle
{
public:
    Aircraft() {}
    Aircraft(string driver) : Vehicle(driver) {}
};

class Person
{
private:
    string name;
    int age;

public:
    Person()
    {
        name = "";
        age = 0;
    }
    Person(string name)
    {
        this->name = name;
        age = 0;
    }
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
};

class MemberOfParliament : public Person
{
private:
    string constituency;
    int spendings;
    string designation;
    bool canBeArrested;
    Car carVal;

public:
    MemberOfParliament()
    {
        constituency = "";
        spendings = 0;
        designation = "";
        canBeArrested = false;
    }

    MemberOfParliament(string name, int age, string constituency, int spendings, string designation) : Person(name, age)
    {
        this->constituency = constituency;
        this->spendings = spendings;
        this->designation = designation;
    }

    void setCar(Car car)
    {
        this->carVal = car;
    }
    Car getCar()
    {
        return this->carVal;
    }
    void setCanBeArrested(bool val)
    {
        this->canBeArrested = val;
    }
    bool getCanBeArrested()
    {
        return canBeArrested;
    }

    string getConstituency()
    {
        return this->constituency;
    }
    int getSpendings()
    {
        return spendings;
    }
    string getDesignation()
    {
        return this->designation;
    }
    bool exceedsSpendingLimit()
    {
        return getSpendings() > 100000;
    }
};
struct MisterDatasource
{
    /* data */
};

class Minister : public MemberOfParliament
{
public:
    Minister(string name, int age, string constituency, int spendings, string designation) : MemberOfParliament(name, age, constituency, spendings, designation)
    {
    }
    bool exceedsSpendingLimit()
    {
        return this->getSpendings() > 1000000;
    }
};

class PrimeMinister : public MemberOfParliament
{
private:
    Aircraft aircraftVal;

public:
    PrimeMinister(string name, int age, string constituency, int spendings, string designation) : MemberOfParliament(name, age, constituency, spendings, designation) {}

    void setAircraft(Aircraft aircraft)
    {
        this->aircraftVal = aircraft;
    }

    Aircraft getAircraft()
    {
        return this->aircraftVal;
    }

    bool exceedsSpendingLimit()
    {
        return this->getSpendings() > 10000000;
    }
};

class Commissioner : public Person
{
public:
    Commissioner(string name, int age) : Person(name, age) {}
    void canArrest(MemberOfParliament obj)
    {
        if (obj.getDesignation() == "PM")
        {
            cout << "Prime Minister cannot be arrested" << endl;
        }
        if (obj.exceedsSpendingLimit())
        {
            cout << obj.getName() << " can be arrested" << endl;
        }
        else
        {
            cout << obj.getName() << " cannot be arrested" << endl;
        }
    }
};

int main()
{
    PrimeMinister minis("Sanskar", 20, "Naraina", 23456, "Minister");
    // Commissioner comm("Ayush", 21);

    // cout << "Name of the Commissioner is: " << comm.getName() << endl;

    Car car("ubjhv");
    MemberOfParliament objMp("eyfgv", 65, "uyfegv", 3563, "mp");

    objMp.setCar(car);

    cout << objMp.getCar().getDriver() << endl;

    return 0;
}