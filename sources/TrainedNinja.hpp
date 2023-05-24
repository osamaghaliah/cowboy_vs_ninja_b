/**
 * This class represents a ninja of type TrainedNinja which gets spawned with 120 HP and 12 velocity.
 *
 * @author Osama M. Ghaliah
 */

#pragma once

#include "Ninja.hpp"

using namespace std;

namespace ariel {
    class TrainedNinja : public Ninja {
        public:
            // Constructor.
            TrainedNinja(string name, Point location, int hitpoint = TRAINNINJA_HP, int velocity = TRAINEDNINJA_VELOCITY);
    };
}