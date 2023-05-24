#include "Team.hpp"

using namespace ariel;

/**
 * This is the essential constructor of a team.
 * @param captain - a pointer of a character that will be assigned as a captain for this team.
 */
Team::Team(Character *captain) : fighters{} {
    if (!captain->getInTeam() && !captain->getIsCaptain()) {
        // Shallow - to maintain addresses.
        this->captain = captain;
        this->captain->setIsCaptain(true);
        this->captain->setInTeam(true);
        this->add(captain);
    } else {
        throw runtime_error(captain->getName() + " is already in a team.");
    }
}

/**
 * A destructor to free all this team's characters from the memory to avoid memory leaks.
 */
Team::~Team() {
    // Destructing each character's object one by one.
    for (size_t i = 0; i < this->getFighters().size(); i++) {
        delete this->getFighters()[i];
    }
}

/**
 * This method adds a new fighter to this team.
 * @param fighter - a pointer of the new fighter that will be added to this team.
 */
void Team::add(Character *fighter) {
    // A team cannot have more than 10 fighters.
    if (this->fighters.size() >= 10) {
        throw runtime_error("Team is FULL.");
    } else {
        // Making sure that the given fighter doesn't exist in this team neither in another team.
        for (size_t i = 0; i < this->fighters.size(); i++) {
            if (this->fighters[i] == fighter || fighter->getInTeam()) {
                throw runtime_error(fighter->getName() + " is already in the team.");
            }
        }

        this->fighters.push_back(fighter);
        // Marking the added fighter that he is in a team now.
        fighter->setInTeam(true);
    }
}

/**
 * This method chooses a new captain for this team once the previous captain is dead.
 * The new captain is the partner that is the closest to the previous captain.
 */
void Team::assignNewCaptain() {
    if (this->stillAlive() == 0) {
        return;
    }

    double minimalDistance = std::numeric_limits <double> :: max();
    size_t NewCaptainIndex;

    // In each iteration, the minimalDistance is updated to find the closest "next captain" from this team's dead captain.
    for (size_t i = 0; i < this->getFighters().size(); i++) {
        if (this->fighters[i] != this->captain) {
            double distanceFromCaptain = this->captain->getLocation().distance(this->fighters[i]->getLocation());

            if ((distanceFromCaptain < minimalDistance) && this->fighters[i]->isAlive()) {
                minimalDistance = distanceFromCaptain;
                NewCaptainIndex = i;
            }
        }
    }

    // The new captain is the one at [NewCaptainIndex].
    this->setCaptain(this->fighters[NewCaptainIndex]);
}

/**
 * This method is responsible to find a victim which is the closest to this team's captain.
 * The chosen victim will be attacked by all this team's fighters.
 * @param captain - a pointer of this team's captain.
 * @return - a pointer of a character - Cowboy or Ninja.
 */
Character* Team::getNewVictim(Character *captain) {
    if (this->stillAlive() == 0) {
        return nullptr;
    }

    double minimalDistance = numeric_limits <double> :: max();
    size_t NewVictimIndex;

    // In each iteration, the minimalDistance is updated to find the closest victim to this team's captain.
    for (size_t i = 0; i < this->getFighters().size(); i++) {
        if (this->getFighters()[i]->isAlive()) {
            double distanceFromCaptain = this->getFighters()[i]->getLocation().distance(captain->getLocation());

            if (distanceFromCaptain < minimalDistance) {
                minimalDistance = distanceFromCaptain;
                NewVictimIndex = i;
            }
        }
    }

    return this->getFighters()[NewVictimIndex];
}

/**
 * This method makes this team to attack the enemies team.
 * The attack is performed as follows:
 *  1. Fighters of this team always attempt to attack the enemy that is the closest to this team's captain.
 *  2. In case a ninja fighter of this team couldn't slash his enemy - he moves towards him.
 * @param opponent - a pointer of the enemies team.
 */
void Team::attack(Team *opponent) {
    // Handling extreme cases.
    if (opponent == nullptr) {
        throw invalid_argument("Attacking is only performed on valid pointers - NOT null ones.");
    }
    if (opponent->stillAlive() == 0) {
        throw runtime_error("The enemy's team is dead");
    }
    if (!this->captain->isAlive()) {
        this->assignNewCaptain();

        if (this->captain == nullptr) {
            return;
        }
    }

    // Choosing a victim (to be attacked) from the opponent team that is the closest to this team's captain.
    Character* chosenVictim = opponent->getNewVictim(this->captain);

    // Looping over this team's alive fighters to attack the chosen victim that is the closest to this team's captain.
    for (size_t i = 0; i < this->fighters.size(); i++) {
        if (this->fighters[i]->isAlive()) {
            if (this->fighters[i]->print().at(0) == 'N') {
                // Ninjas can only slash when it is less than 1 meter away from the enemy.
                if (this->fighters[i]->distance(chosenVictim) < 1) {
                    this->fighters[i]->SlashOrShoot(chosenVictim);
                } else {
                    // Retrieving the ninja - so it can move towards the chosen enemy.
                    Ninja *ninja = dynamic_cast <Ninja*> (this->fighters[i]);
                    ninja->move(chosenVictim);
                }
            } else if (this->fighters[i]->print().at(0) == 'C') {
                this->fighters[i]->SlashOrShoot(chosenVictim);
            } else {
                throw runtime_error("Unknown character recognized.");
            }

            // Re-choosing a new victim once the previous victim dies.
            if (!chosenVictim->isAlive()) {
                chosenVictim = opponent->getNewVictim(this->captain);

                // In such case, the attack stops. Because, the opponent team will be all dead.
                if (chosenVictim == nullptr) {
                    return;
                }
            }
        }
    }
}

/**
 * This method tells us how many alive fighters are left in this team.
 * @return - this team's alive fighters.
 */
int Team::stillAlive() {
    int aliveFighters = 0;

    // Counting this team's alive characters only.
    for (size_t i = 0; i < this->fighters.size(); i++) {
        if (this->fighters[i]->isAlive()) {
            aliveFighters++;
        }
    }

    return aliveFighters;
}

/**
 * This method prints this team's characters' details - either dead or alive.
 */
void Team::print() {
    for (size_t i = 0; i < this->fighters.size(); i++) {
        cout << this->fighters[i]->print();
    }
}

/**
 * This is a getter for this team's captain - could be a cowboy or a ninja.
 * @return - a pointer of this team's captain.
 */
Character* Team::getCaptain() {
    return this->captain;
}

/**
 * This is a setter for this team's captain.
 * @param captain - a pointer to a character that will be the new captain for this team.
 */
void Team::setCaptain(Character *captain) {
    this->captain = captain;
}

/**
 * This is a getter for this team's fighters.
 * @return - a pointers vector of this team's fighters.
 */
vector <Character*> Team::getFighters() {
    return this->fighters;
}