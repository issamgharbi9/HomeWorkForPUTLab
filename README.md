# HomeWorkForPUTLab
🛠🔥 Assignment 🔥🛠
Create two variables in the program that represent the speed of one of the objects - the horizontal (x) and vertical (y) components, e.g. rectangle_velocity_x and rectangle_velocity_y. They will denote the speed of the object in pixels per second. Give them values of 50 and 150 respectively.

Use the time calculated in the previous task and in each loop run move rectangular object with the sf::Transformable::move method by the distance that should be covered in the measured time at the set speed. HINT:

distance

Then add the variable rectangle_angular_velocity describing the speed of rotation of the figure around its axis (in degrees per second) and give it a value of 10. Use the rotate method to cause the object to rotate.

Note: Unlike trigonometric functions in a standard library, functions in SFML operate at angles expressed in degrees.

Simple collisions
Collision detection between objects on stage is the foundation of the mechanics of many games or applications that perform simple physics simulations. Since accurate collision calculations for many irregular objects would be very resource-intensive, some simplifications are used, such as approximating the shape of objects with a rectangle/circle (in a plane) or a cuboid (in 3D space).

The objects we have drawn have the getGlobalBounds() method, which returns the sf::FloatRect rectangle which is the outline of the figure, in the coordinates of the window. Usage example:

sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;
🛠🔥 Assignment 🔥🛠
Using the contour of a rotating rectangle, write a set of conditions to verify that it touches one of the edges of the screen. If so, "bounce" it by changing the return speed in the correct direction depending on the wall the object is hitting. You can assume that window has fixed dimensions (or advanced check for current window size using sf::RenderWindow::getSize method).

Colours
Colours in SFML are described in RGB (red, green, blue). Each color component is an 8-bit number without a character (0-255 range). This is a very common way of representing colour in computer graphics. It's sometimes called RGB888 or RGB 24-bit.

The basic figures in SFML have a contour and fill colour.

For example:

rectangle.setFillColor(sf::Color(255, 255, 0));
will change the colour of the filling of the rectangle to yellow.

🛠🔥 Assignment 🔥🛠
Add a change of colour of the rectangle to a random colour after each bounce, so that the effect is similar to the one shown below:

https://jug.dpieczynski.pl/lab-ie-2/_images/sfml_bounce.gif
