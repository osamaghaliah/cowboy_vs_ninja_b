#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character *captain) : Team(captain) {}

void Team2::attack(Team *opponent) {
    Team::attack(opponent);
}