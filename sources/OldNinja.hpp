/**
 * This class represents a ninja of type OldNinja which gets spawned with 150 HP and 8 velocity.
 *
 * @author Osama M. Ghaliah
 */

#pragma once

#include "Ninja.hpp"

namespace ariel {
    class OldNinja : public Ninja {
        public:
            // Constructor.
            OldNinja(string name, Point location, int hitpoint = OLDNINJA_HP, int velocity = OLDNINJA_VELOCITY);
    };
}
