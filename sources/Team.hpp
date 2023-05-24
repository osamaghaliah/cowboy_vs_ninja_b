/**
 * This class represents a team of fighters - either cowboys or ninjas.
 * A team has the ability to assign a captain for themselves and to attack the opponent team.
 * NOTE :- A team can have a maximum of 10 fighters.
 *
 * @author Osama M. Ghaliah
 */

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace std;

namespace ariel {
    class Team {
        protected:
            Character *captain;
            vector <Character*> fighters;

        public:
            // Constructor.
            Team(Character *captain);
            // Destructor.
            ~Team();

            // Essential methods for the battle.
            void add(Character *fighter);
            virtual void attack(Team *opponent);
            int stillAlive();
            void print();
            void assignNewCaptain();
            Character* getNewVictim(Character *opponent);

            // Getters & setters.
            Character* getCaptain();
            void setCaptain(Character *captain);
            vector <Character*> getFighters();
    };
}