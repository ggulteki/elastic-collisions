#include "../include/elastic_collisions.hpp"

// Magic numbers for window size
constexpr int windowWidth = 800;
constexpr int windowHeight = 600;

int main() {
    // Create a window with the specified size
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "elastic-collisions", sf::Style::Titlebar | sf::Style::Close);

    // Load a font for displaying text
    sf::Font font;
    if (!font.loadFromFile("../resources/Roboto_Condensed-Black.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return EXIT_FAILURE;
    }

    // Create text objects for displaying kinetic energy and momentum
    sf::Text kineticText, momentumText;
    kineticText.setFont(font);
    kineticText.setCharacterSize(20);
    kineticText.setFillColor(sf::Color::Green);
    kineticText.setPosition(10, 10);

    momentumText.setFont(font);
    momentumText.setCharacterSize(20);
    momentumText.setFillColor(sf::Color::Green);
    momentumText.setPosition(10, 40);

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

        // Collision handling
        particleA->collide(*particleB);

        // Update the particles position
        particleA->update();
        particleB->update();

        // Check if the particles are at the edges of the window and bounce them off the edges
        particleA->edges(windowWidth, windowHeight);
        particleB->edges(windowWidth, windowHeight);

        // Clear the window with a black background for erase the previous frame
        window.clear(sf::Color::Black);

        // Particle drawing
        particleA->draw(window);
        particleB->draw(window);

        // Calculate the total kinetic energy and momentum of the system
        double kineticEnergyA = particleA->kineticEnergy();
        double kineticEnergyB = particleB->kineticEnergy();
        double totalKineticEnergy = kineticEnergyA + kineticEnergyB;

        double momentumA = particleA->momentum();
        double momentumB = particleB->momentum();
        double totalMomentum = momentumA + momentumB;

        // Update the text strings with the calculated values
        kineticText.setString("Total Kinetic Energy: " + std::to_string(totalKineticEnergy));
        momentumText.setString("Total Momentum: " + std::to_string(totalMomentum));

        // Draw the text on the window
        window.draw(kineticText);
        window.draw(momentumText);

        // Display the contents of the window
        window.display();
    }

    return 0;
}