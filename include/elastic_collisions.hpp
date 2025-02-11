#ifndef ELASTIC_COLLISIONS_H
#define ELASTIC_COLLISIONS_H

// Standard library includes
#include <iostream>
#include <array>
#include <random>
#include <cmath>

// OpenGL includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
    Define a class to represent a particle
*/
class Particle {
    public:
        std::array<double, 2> position; // x, y 

        std::array<double, 2> velocity; // x, y
        
        std::array<double, 2> acceleration{0.0, 0.0}; // x, y
        
        double mass; // mass of the particle        
        
        double radius; // radius of the particle
        
        Particle(double x, double y) : position{x, y} {}; // Constructor Declaration
        
        /*
            Functions Declarations
        */
        static double random(double min, double max);
        
        static std::array<double, 2> random2D(); 
        
        void applyForce(const std::array<double, 2>& force);

        void update();

        void collide(const Particle& p);
};

#endif // ELASTIC_COLLISIONS_H