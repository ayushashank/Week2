#include <bits/stdc++.h>
using namespace std;

class Country
{
    int countryId;
    string countryName;
    unordered_map<int, vector<City *>> cities;

public:
    Country(int id, const string &name)
    {
        this->countryId = id;
        this->countryName = name;
    }
    int getCountryId()
    {
        return this->countryId;
    }
    string getCountryName()
    {
        return this->countryName;
    }
    vector<City *> getCities(int countryId)
    {
        return this->cities[countryId];
    }
};

class City
{
    int cityId;
    string cityName;
    int countryId;
    vector<int> walls;

public:
    City(int id, const string &name, int countryId)
    {
        this->cityId = id;
        this->cityName = name;
        this->countryId = countryId;
    }

    int getCityId()
    {
        return this->cityId;
    }
    string getCityName()
    {
        return this->cityName;
    }
    int getCountryId()
    {
        return this->countryId;
    }
    vector<int> getWalls()
    {
        return this->walls;
    }

    void addWall(int wallId) { walls.push_back(wallId); }
};

class Wall
{
    int wallId;
    vector<int> bricks;

public:
    Wall(int id) : wallId(id) {}

    int getWallId()
    {
        return wallId;
    }
    vector<int> getBricks()
    {
        return bricks;
    }
    void addBrick(int brickId)
    {
        bricks.push_back(brickId);
    }
};

class Brick
{
    int brickId;
    string message;
    int ownerId;
    vector<string> messages;

public:
    Brick(int id)
    {
        this->brickId = id;
    }
    int getBrickId()
    {
        return brickId;
    }
    string getContent()
    {
        return message;
    }
    int getOwnerId()
    {
        return ownerId;
    }
    vector<string> getComments()
    {
        return messages;
    }

    void setMessage(string newMessage)
    {
        this->message = newMessage;
    }
    void setOwnerId(int newOwnerId)
    {
        this->ownerId = newOwnerId;
    }

    void addMessage(string &message)
    {
        messages.push_back(message);
    }
};

class User
{
    int userId;
    string name;

public:
    User(int id, const string &userName) : userId(id), name(userName) {}
    int getUserId() const { return userId; }
    string getName() const { return name; }
};

class Owner : public User
{
    vector<int> bricksOwned;

public:
    Owner(int id, const string &userName) : User(id, userName) {}

    void addBrick(int brickId) { bricksOwned.push_back(brickId); }
};

class Admin : public User
{
public:
    Admin(int id, const string &userName) : User(id, userName) {}

    void editBrickContent(Brick &brick, const string newContent)
    {
        brick.setMessage(newContent);
    }
};

class Location
{
    int countryId;
    int cityId;
    int wallId;
    int brickId;

public:
    Location(int country, int city, int wall, int brick)
        : countryId(country), cityId(city), wallId(wall), brickId(brick) {}

    int getCountryId() const { return countryId; }
    int getCityId() const { return cityId; }
    int getWallId() const { return wallId; }
    int getBrickId() const { return brickId; }
};

class Bridge
{
    vector<Brick> bricks;

public:
    void addOrEditBrick(const Location &loc, Owner &owner, const string &content)
    {
        for (auto &brick : bricks)
        {
            if (brick.getBrickId() == loc.getBrickId())
            {
                brick.setMessage(content);
                return;
            }
        }
        Brick newBrick(bricks.size() + 1);
        newBrick.setMessage(content);
        newBrick.setOwnerId(owner.getUserId());
        bricks.push_back(newBrick);
        owner.addBrick(newBrick.getBrickId());
    }
    void
    handleWriteOperation(const Location &loc, Owner &owner, const string &content)
    {
        for (auto &brick : bricks)
        {
            if (brick.getBrickId() == loc.getBrickId())
            {
                if (!brick.getContent().empty())
                {
                    cout << "Brick has already content" << endl;
                    return;
                }
                brick.setMessage(content);
                return;
            }
        }
        Brick newBrick(bricks.size() + 1);
        newBrick.setMessage(content);
        newBrick.setOwnerId(owner.getUserId());
        bricks.push_back(newBrick);
        owner.addBrick(newBrick.getBrickId());
    }

    string readBrickContent(const Location &loc)
    {
        for (auto &brick : bricks)
        {
            if (brick.getBrickId() == loc.getBrickId())
            {
                return brick.getContent();
            }
        }
        return "";
    }

    void deleteBrick(const Location &loc)
    {

        auto Brick = bricks.begin();
        while (Brick != bricks.end())
        {

            if (Brick->getBrickId() == loc.getBrickId())
            {

                Brick = bricks.erase(Brick);
            }
            else
            {
                ++Brick;
            }
        }
    }
};

int main()
{
    return 0;
}