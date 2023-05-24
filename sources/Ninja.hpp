#pragma once

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
        protected:
            int velocity;

        public:
            // Constructor.
            Ninja(string name, Point location, int hitpoint, int velocity);

            // Essential methods for the battle.
            void move(Character *enemy);
            void slash(Character *enemy);
            void SlashOrShoot(Character *enemy);
            string print();

            // Getters & setters.
            int getVelocity();
    };
}