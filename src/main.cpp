#include "../include/elastic_collisions.hpp"

// Magic numbers for window size
constexpr int windowWidth = 800;
constexpr int windowHeight = 600;

int main() {
    // Create a window with the specified size
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "elastic-collisions", sf::Style::Titlebar | sf::Style::Close);

    auto particleA = std::make_unique<Particle>(320, 60);
    auto particleB = std::make_unique<Particle>(320, 300);

    // Main Loop to keep the window open until the user closes it
    while (window.isOpen()) {
        sf::Event event;

        // Event loop for handling user input
        while (window.pollEvent(event)) {
            // Close the window if the user clicks the close button
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::Resized) {
                // Force back to the original size
                window.setSize(sf::Vector2u(windowWidth, windowHeight));
            }
        }

        // Check if the particles are at the edges of the window and bounce them off the edges
        particleA->edges(windowWidth, windowHeight);
        particleB->edges(windowWidth, windowHeight);
        
        // Collision handling
        particleA->collide(*particleB);
        
        // Update the particles position
        particleA->update();
        particleB->update();

        // Clear the window with a black background for erase the previous frame
        window.clear(sf::Color::Black);

        // Particle drawing
        particleA->draw(window);
        particleB->draw(window);

        // Display the contents of the window
        window.display();
    }

    return 0;
}