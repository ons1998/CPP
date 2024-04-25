
//Composite Pattern for a Playlist Application Ons Bouzidi


#include <iostream>
#include <vector> 
#include <string>
#include <algorithm> // for std::remove


// Component Interface
class Component {
public : 
virtual ~Component() = default; 
virtual void play() = 0;
virtual void setPlaybackSpeed( float speed ) =0;
virtual std::string getName() =0;


};



// Song class ( represents individual objects)

class Song : public Component {

private:
std::string songName;
std::string artist;
float speed;

public: 

Song(const std::string& name, const std::string& artist)
        : songName(name), artist(artist), speed(1.0) {}

        
void play() override {

/* in real-world application, the play method is complicated. Playing audio 
typically involves interacting with audio libraries or API to handle playback
the purpose of this code is to get used to working with the composite pattern so I won't 
be implementing this method just yet, but sometime in the future for sure! */


}

void setPlaybackSpeed(float speed) override
{
        this->speed = speed;

}

std::string getName() override
{
return songName;
} 

std::string getArtist() {

return artist;
}

};

// Playlist class (represents compositions)
class Playlist : public Component {

private:
std::string playlistName;
std::vector<Component*> playlist;
public: 

Playlist(const std::string& name) : playlistName(name) {}

 
void play() override {
for (auto p: playlist){

    p->play(); 
}

}

void setPlaybackSpeed(float speed) override
{

        for (auto p : playlist) {
            p->setPlaybackSpeed(speed);
        }

}

std::string getName() override
{
return playlistName;
} 

void add(Component* component){

playlist.push_back(component);


}

void remove(Component* component) {

playlist.erase(std::remove(playlist.begin(), playlist.end() , component),playlist.end());
  
}

};

int main () {

Song song1("Do I Wanna Know?", "Arctic Monkeys");
Song song2("Lambs wool", "Foster The People");


Playlist IndieRock("Indie Rock");

IndieRock.add(&song1);
IndieRock.add(&song2);

IndieRock.setPlaybackSpeed(1.2);


return 0;



}