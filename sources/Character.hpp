/**
 * This class represents a character which reflects one of the following fighters:
 *  1. Cowboy.
 *  2. Ninja.
 * Each character specializes to damage his opponent and a special HP that they get spawned with.
 * A ninja deals 40 damage per slash | A cowboy deals 10 damage per bullet.
 * Besides, a character specializes to hold a location (X,Y) of the battlefield and a name.
 *
 * @author Osama M. Ghaliah
 */

#pragma once

// CONSTANTS
#define COWBOY_HP 110
#define OLDNINJA_HP 150
#define OLDNINJA_VELOCITY 8
#define TRAINNINJA_HP 120
#define TRAINEDNINJA_VELOCITY 12
#define YOUNGNINJA_HP 100
#define YOUNGNINJA_VELOCITY 14
#define COWBOY_DAMAGE 10
#define NINJA_DAMAGE 40

#include <stdexcept>
#include <string>
#include "Point.hpp"

using namespace std;

namespace ariel {
    class Character {
        protected:
            string name;
            Point location;
            int hitpoint;
            bool inTeam, isCaptain;

        public:
            // Constructor.
            Character(string name, Point location, int hitpoint);

            // Essential methods for the battle.
            bool isAlive();
            double distance(Character *character);
            void hit(int damage);
            virtual void SlashOrShoot(Character *enemy);
            virtual string print();

            // Getters & setters.
            string getName();
            void setName(string name);
            Point getLocation();
            void setLocation(Point other);
            int getHitpoint();
            void setHitpoint(int hitpoint);
            bool getInTeam();
            void setInTeam(bool inTeam);
            bool getIsCaptain();
            void setIsCaptain(bool isCaptain);
    };
}
