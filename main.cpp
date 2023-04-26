#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
    sf::RectangleShape rectangle2(sf::Vector2f(120.0, 60.0));
    rectangle2.setPosition(100.0, 300.0);
    rectangle2.setFillColor(sf::Color::Green);

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color::Green);

    sf::RectangleShape rectangle3(sf::Vector2f(120.0, 60.0));
    rectangle3.setPosition(650.0, 100.0);
    rectangle3.setFillColor(sf::Color::Green);

    sf::RectangleShape rectangle4(sf::Vector2f(120.0, 60.0));
    rectangle4.setPosition(250.0, 350.0);
    rectangle4.setFillColor(sf::Color::Green);

    bool selected = false;
    sf::RectangleShape* selectedRect = nullptr;



    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                            // get the position of the mouse click
                            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                            // check if a rectangle was clicked
                            if (rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                selected = true;
                                selectedRect = &rectangle;
                                rectangle.setFillColor(sf::Color::Red);
                            }
                            else if (rectangle2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                selected = true;
                                selectedRect = &rectangle2;
                                rectangle2.setFillColor(sf::Color::Red);
                            }
                            else if (rectangle3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                selected = true;
                                selectedRect = &rectangle3;
                                rectangle3.setFillColor(sf::Color::Red);
                            }
                            else if (rectangle4.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                selected = true;
                                selectedRect = &rectangle4;
                                rectangle4.setFillColor(sf::Color::Red);

                             }
                         }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                            // release the selected shape
                            selectedRect = nullptr;

                            // reset the color of all shapes
                            rectangle.setFillColor(sf::Color::Green);
                            rectangle2.setFillColor(sf::Color::Green);
                            rectangle3.setFillColor(sf::Color::Green);
                            rectangle4.setFillColor(sf::Color::Green);
                        }
                        else if (event.type == sf::Event::MouseMoved && selectedRect != nullptr) {
                            // move the selected shape to the mouse position
                            selectedRect->setPosition(event.mouseMove.x, event.mouseMove.y);
                        }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...

        window.draw(rectangle);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);

        // end the current frame
        window.display();
    }

    return 0;
}
