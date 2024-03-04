// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <string>
// #define quote(x)

#include <bits/stdc++.h>

using namespace std;

// Person class which is acting as a base class for User class
class Person
{
private:
    string name;
    int age;

public:
    // Constructors
    Person() {}
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    // Getter for name
    string getName()
    {
        return this->name;
    }

    // Getter for age
    int getAge()
    {
        return this->age;
    }
};

// User class which is inherited from Person class and acts as base class for classes NormalUser, Admin, HotelAgent
class User : public Person
{
private:
    string username;
    string password;

public:
    // Constructors
    User() {}
    User(string name, int age, string uname, string pwd, string userType) : Person(name, age)
    {
        this->username = uname;
        this->password = pwd;
    }

    // Getter for username
    string getUserName()
    {
        return this->username;
    }

    // Getter for password
    string getPassword()
    {
        return this->password;
    }

    // Method for creating users on the basis of their types
    static User *createUser(string userType);
};

// Hotel class
class Hotel
{
private:
    string hotelName;
    string hotelLocation;
    int numOfRooms;
    int hotelRating;
    bool isApproved;

public:
    Hotel() {}
    Hotel(string hname, string loc, int rooms, int rating)
    {
        this->hotelName = hname;
        this->hotelLocation = loc;
        this->numOfRooms = rooms;
        this->hotelRating = rating;
        this->isApproved = false;
    }

    // Getter for hotel name
    string getHotelName()
    {
        return this->hotelName;
    }

    // Getter for hotel location
    string getHotelLocation()
    {
        return this->hotelLocation;
    }

    // Setter for the rating
    void setHotelRating(int rating)
    {
        this->hotelRating = rating;
    }

    // Getter for hotel rating
    int getHotelRating()
    {
        return this->hotelRating;
    }

    // Setter for number of rooms
    void setNumberOfRoome(int rooms)
    {
        this->numOfRooms = rooms;
    }

    // Getter for number of rooms
    int getNumberOfRooms()
    {
        return this->numOfRooms;
    }

    // Setter for approval
    void setApproved(bool approved)
    {
        this->isApproved = approved;
    }

    // Getter for approval
    bool getApproved()
    {
        return this->isApproved;
    }
};

//
class HotelManagementSystem
{

private:
    vector<User *> users;
    vector<User *> hotelAgents;
    vector<Hotel *> hotels;

public:
    HotelManagementSystem() {}

    vector<User *> &getUsers()
    {
        return this->users;
    }

    vector<Hotel *> &getHotels()
    {
        return this->hotels;
    }

    vector<User *> &getHotelAgents()
    {
        return this->hotelAgents;
    }

    void registerUser(User *user)
    {
        users.push_back(user);

        string type = typeid(user).name();
        if (type.substr(1) == "agent")
        {
            hotelAgents.push_back(user);
        }
    }

    vector<Hotel *> hotelsList(string &criteria)
    {
        vector<Hotel *> hotelsBasedOnCriteria;
        for (Hotel *hotel : hotels)
        {
            if (hotel->getHotelLocation() == criteria)
            {
                hotelsBasedOnCriteria.push_back(hotel);
            }
        }
        return hotelsBasedOnCriteria;
    }

    // Approve hotel details
    void approvedHotel(Hotel *hotel)
    {
        hotel->setApproved(true);
    }

    void displayHotelDetails()
    {
        // all hotel details
    }
};

class Administrator : public User
{
public:
    // Administrator() {}
    // Administrator(string name, int age, string userName, string password)
    //     : User(name, age, userName, password, "admin") {}

    void approveHotelDetails(Hotel *hotel)
    {
        hotel->setApproved(true);
        cout << "Hotel details approved successfully!" << std::endl;
    }

    // Delete user and hotel details
    void deleteDetails(User *user, Hotel *hotel, HotelManagementSystem *HotelManagementSystem)
    {
        string userType = typeid(user).name();
        userType.substr(1);

        if (userType == "agent")
        {
            auto it = find(HotelManagementSystem->getHotelAgents().begin(), HotelManagementSystem->getHotelAgents().end(), user);
            if (it != HotelManagementSystem->getHotelAgents().end())
            {
                HotelManagementSystem->getHotelAgents().erase(it);
            }
        }

        else if (userType == "normal")
        {
            auto it = find(HotelManagementSystem->getUsers().begin(), HotelManagementSystem->getUsers().end(), user);
            if (it != HotelManagementSystem->getUsers().end())
            {
                HotelManagementSystem->getUsers().erase(it);
            }
        }

        if (hotel != NULL)
        {
            auto it = find(HotelManagementSystem->getHotels().begin(), HotelManagementSystem->getHotels().end(), hotel);
            if (it != HotelManagementSystem->getHotels().end())
            {
                HotelManagementSystem->getHotels().erase(it);
            }
        }
    }
};

class NormalUser : public User
{
public:
    // Constructor
    NormalUser() {}
    NormalUser(string name, int age, string username, string password)
        : User(name, age, username, password, "normal") {}

    void bookHotelRoom(Hotel *hotel, HotelManagementSystem *HotelManagementSystem)
    {
        if (hotel->getApproved() && hotel->getNumberOfRooms() > 0)
        {
            hotel->setNumberOfRoome(hotel->getNumberOfRooms() - 1);
            cout << "Room Booked successfully\n";
        }
        else
        {
            cout << "Booking failed either the hotel is not approved or no rooms available\n";
        }
    }
};

class HotelAgent : public User
{
public:
    // Constructor
    HotelAgent() {}
    HotelAgent(string name, int age, string username, string password)
        : User(name, age, username, password, "agent") {}

    // Add or update hotel details
    void addOrUpdateHotelDetails(Hotel *hotel, HotelManagementSystem *HotelManagementSystem)
    {
        auto it = find(HotelManagementSystem->getHotels().begin(), HotelManagementSystem->getHotels().end(), hotel);
        if (it == HotelManagementSystem->getHotels().end())
        {
            HotelManagementSystem->getHotels().push_back(hotel);
        }
    }
};

// Factory method for creating differnt types of users
User *User::createUser(string type)
{
    if (type == "admin")
    {
        return new Administrator();
    }
    else if (type == "agent")
    {
        return new HotelAgent();
    }
    else if (type == "normal")
    {
        return new NormalUser();
    }
    else
    {
        return NULL;
    }
};

// MARK:- Function to check whether the input is a number or not
// DESC:- Checking each character of the string if it is a number or not
bool isValidNumber(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] < '0' or str[i] > '9')
            return false; // if a character is not a digit then returning false
    }
    return true;
}

int main()
{
    return 0;
}