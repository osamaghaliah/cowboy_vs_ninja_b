/**
 * This class represents a cowboy who gets spawned with 110 HP and 6 bullets.
 * Cowboy's speciality is to deal a damage of 10 per bullet. Also, he is able to refill his mag with another 6 bullets.
 *
 * @author Osama M. Ghaliah
 */

#pragma once

#include "Character.hpp"

using namespace std;

namespace ariel {
    class Cowboy : public Character {
        protected:
            int bullets;

        public:
            // Constructor.
            Cowboy(string name, Point location);

            // Essential methods for the battle.
            void shoot(Character *enemy);
            void SlashOrShoot(Character *enemy);
            bool hasboolets();
            void reload();
            string print();

            // Getters & setters.
            int getBullets();
            void setBullets(int bullets);
    };
}
