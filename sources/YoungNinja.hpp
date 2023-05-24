/**
 * This class represents a ninja of type OldNinja which gets spawned with 100 HP and 14 velocity.
 *
 * @author Osama M. Ghaliah
 */

#pragma once

#include "Ninja.hpp"

using namespace std;

namespace ariel {
    class YoungNinja : public Ninja {
        public:
            // Constructor.
            YoungNinja(string name, Point location, int hitpoint = YOUNGNINJA_HP, int velocity = YOUNGNINJA_VELOCITY);
    };
}
