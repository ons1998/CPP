//Observer Pattern for youtube Channel 
//ONS bouzidi

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Observer;

class Subject{

public : 
virtual ~Subject() {} ;

void registerObserver(Observer* observer) {

observers.push_back(observer);

}

void removeObserver(Observer* observer)
{

 observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());

}
void notifyObservers()
{

for (Observer* observer : observers) 
{

observer->update(getStatus()); 

}

}

virtual std::string getStatus() const =0;
virtual void setStatus(const std::string& status) =0;

private : 

    std::vector<Observer*> observers;

};


class Observer {
public:
    virtual void update(const std::string& status) = 0;
};

class Channel : public Subject 
{
public:

std::string getStatus() const override {

    return status;
}

void setStatus (const std::string& status )
{

this-> status = status;
notifyObservers();
}

private : 
std::string status;


};


class Follower : public Observer 
{

public:
 Follower(const std::string& name) : followerName(name) {}
void update(const std::string& status) override
{

std::cout << followerName << ":"<<status << std::endl;

}


private : 
std::string followerName;
};

int main() {

   Channel channel;
    Follower follower1("Follower1"), follower2("Follower2");
   channel.registerObserver(&follower1);
   channel.registerObserver(&follower2);

   channel.setStatus("Channel is Live");
   channel.removeObserver(&follower2);

   channel.setStatus("Live now ended");


    return 0;
}


