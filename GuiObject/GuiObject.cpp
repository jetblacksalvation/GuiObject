// GuiObject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

sf::RenderWindow* window;
struct DrawingInterface {
    virtual void Draw() const = 0;
};

template <typename t > 
struct MeshInterface {
    MeshInterface() {
    }
    
    virtual void SetMesh(void * ptr) = 0;
};
struct BoundingBox {
    int x, y;
};
struct KeyEvents {
    KeyEvents(std::initializer_list<char> event_codes) {
        for (char index : event_codes) {
            values.emplace(index, 0);

        }
    }
    void PollEvents() {
        
        while (window->pollEvent(event)) {
            for (auto& elem : values) {
                //call virtual function 
                elem.second = (event.type == elem.first);//if true set pair to true 

                PollEventsVirtual(elem.first);
            }
        }
        
    };
    virtual void PollEventsVirtual(char code) const = 0;

    sf::Event event;
    std::map<char, bool> values;
};

int main()
{
    std::cout << "Hello World!\n";
}
