#pragma once

#include "Team.hpp"

using namespace std;

namespace ariel {
    class Team2 : public Team {
        public:
            Team2(Character *captain);
            void attack(Team *opponent);
    };
}
