#include "Ninja.hpp"

using namespace ariel;

/**
 * An essential constructor to construct an instance of a ninja.
 * Initializes name, location and hitpoint by using the parent class - Character
 * @param name
 * @param location
 * @param hitpoint
 * @param velocity
 */
Ninja::Ninja(string name, Point location, int hitpoint, int velocity) : Character(name, location, hitpoint) {
    this->velocity = velocity;
}

/**
 * This method moves this ninja towards its enemy.
 * NOTE: A ninja moves a distance that is equal to its velocity's value.
 * @param enemy - a pointer of the enemy that this ninja is willing to move to.
 */
void Ninja::move(Character *enemy) {
    if (!this->isAlive()) {
        return;
    } else if (!enemy->isAlive()) {
        return;
    }

    Point nextTarget = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->getVelocity());

    this->setLocation(nextTarget);
}

/**
 * This method makes this ninja to slash his enemy if and only if his enemy is less than 1 meter close to it.
 * A slash by  this ninja deals 40 damage to the enemy.
 * @param enemy - a pointer of the enemy that will be slashed by this ninja.
 */
void Ninja::slash(Character *enemy) {
    if (enemy == this) {
        throw runtime_error("A ninja cannot hurt himself.");
    }
    if (!enemy->isAlive()) {
        throw runtime_error("A ninja cannot attack a dead enemy.");
    } else if (!this->isAlive()) {
        throw runtime_error("A dead ninja cannot attack anyone.");
    }

    if (this->isAlive() && this->location.distance(enemy->getLocation()) < 1) {
        enemy->hit(NINJA_DAMAGE);
    }
}

/**
 * As described inside Character.hpp
 * @param enemy - a pointer of an enemy that will be slashed.
 */
void Ninja::SlashOrShoot(Character *enemy) {
    this->slash(enemy);
}

string Ninja::print() {
    if (!this->isAlive()) {
        return "Name: (" + this->name + ") | Location: " + this->location.toString() + "\n";
    } else {
        return "N - Name: " + this->name + " | HP: " + to_string(this->hitpoint) + " | Location: " +
               this->location.toString() + "\n";
    }
}

/**
 * This is a getter for this ninja's velocity.
 * @return
 */
int Ninja::getVelocity() {
    return this->velocity;
}