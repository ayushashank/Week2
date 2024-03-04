#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Message class for creating messages
class Message
{
public:
    string messageContent;
    string sender;
    string receiver;

    Message(string content, string sender, string receiver)
    {
        this->messageContent = content;
        this->sender = sender;
        this->receiver = receiver;
    }

    string getSender()
    {
        return this->sender;
    }
    string getReceiver()
    {
        return this->receiver;
    }
    string getMessageContent()
    {
        return this->messageContent;
    }
};

// class MessageFactory
// {
// public:
//     Message *build(string messageType)
//     {
//         if (messageType == "text")
//             return new Message();
//         else if (messageType == "video")
//             return new Message();
//         else if (messageType == "audio")
//             return new Message();
//         else
//             return NULL;
//     }
// };

// Status class for creating statuses
class Status
{
public:
    User user;
    string statusContent;

    Status()
    {
        this->statusContent = "";
    }
    Status(string content, User user)
    {
        this->statusContent = content;
        this->user = user;
    }
    string getStatusContent()
    {
        return this->statusContent;
    }
    User getUser()
    {
        return this->user;
    }
};

// class StatusFactory
// {
// public:
//     Status *build(string statusType)
//     {
//         if (statusType == "text")
//             return new Status();
//         else if (statusType == "video")
//             return new Status();
//         else if (statusType == "audio")
//             return new Status();
//         else
//             return NULL;
//     }
// };

// Person class for creating a person
class Person
{
    string personeName;
    int age;

public:
    Person()
    {
        this->personeName = "";
        this->age = 0;
    }
    Person(string name, int age)
    {
        this->personeName = name;
        this->age = age;
    }

    string getPersonName()
    {
        return this->personeName;
    }
    int getPersonAge()
    {
        return this->age;
    }
};

// User class which is inheriting person class
class User : public Person
{
    int userId;
    vector<Contact> contacts;
    vector<Status> statuses;
    vector<Message> messages;

public:
    User() : Person()
    {
        this->userId = -1;
        this->contacts = {};
        this->statuses = {};
        this->messages = {};
    }
    User(int userId, string userName, int age) : Person(userName, age)
    {
        this->userId = userId;
        this->contacts = {};
        this->statuses = {};
        this->messages = {};
    }

    int getUserId()
    {
        return this->userId;
    }
    string getUsername()
    {
        return this->getPersonName();
    }

    void addContact(Contact contact)
    {
        this->contacts.push_back(contact);
    }
    void postStatus(Status status)
    {
        this->statuses.push_back(status);
    }
    void sendMessage(Contact contact, string messageContent)
    {
        Message message();
        // this->messages.push_back(message);
        // contact.receivedMessages.push_back(message);
    }
};

// Contact class for making new contacts
class Contact : public Person
{
    int contactNumber;
    vector<Message> messages;
    User user;

public:
    Contact(string contactName, int age, int contactNumber, User user) : Person(contactName, age)
    {
        this->contactNumber = contactNumber;
        this->messages = {};
        this->user = user;
    }
    int getContactNumber()
    {
        return this->contactNumber;
    }
    User getUser()
    {
        return this->user;
    }
    void receiveMessage(Message message)
    {
        this->messages.push_back(message);
    }
    vector<Message> getMessages()
    {
        return this->messages;
    }
    void displayContactInfo()
    {
        // displaying all the information of the current contact
    }
};

int main()
{
    return 0;
}