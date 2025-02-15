#ifndef ELASTIC_COLLISIONS_H
#define ELASTIC_COLLISIONS_H

// Standard library includes
#include <iostream>
#include <array>
#include <random>
#include <cmath>
#include <memory>

// SFML include
#include <SFML/Graphics.hpp>

/*
    Define a class to represent a particle
*/
class Particle {
    public:
        std::array<double, 2> position; // x, y
        std::array<double, 2> velocity; // x, y
        double mass; // mass of the particle
        double radius; // radius of the particle

        Particle(double x, double y); // Constructor Declaration

        /*
            Functions Declarations
        */
        static double random(double min, double max);
        static std::array<double, 2> random2D();
        void update();
        void collide(Particle& other);
        void edges(double width, double height);
        void draw(sf::RenderWindow& window);
};

#endif // ELASTIC_COLLISIONS_H
