#include "Character.hpp"

using namespace ariel;

Character::Character(string name, Point location, int hitpoint) {
    this->name = name;
    this->location.setX(location.getX());
    this->location.setY(location.getY());
    this->hitpoint = hitpoint;
    this->inTeam = false;
    this->isCaptain = false;
}

Point Character::getLocation() {
    return this->location;
}

void Character::setLocation(Point other) {
    this->location.setX(other.getX());
    this->location.setY(other.getY());
}

string Character::getName() {
    return this->name;
}

void Character::setName(string name) {
    this->name = name;
}

int Character::getHitpoint() {
    return this->hitpoint;
}

void Character::setHitpoint(int hitpoint) {
    this->hitpoint = hitpoint;
}

bool Character::getInTeam() {
    return this->inTeam;
}

void Character::setInTeam(bool inTeam) {
    this->inTeam = inTeam;
}

bool Character::getIsCaptain() {
    return this->isCaptain;
}

void Character::setIsCaptain(bool isCaptain) {
    this->isCaptain = isCaptain;
}

bool Character::isAlive() {
    if (this->hitpoint <= 0)
        return false;

    return true;
}

double Character::distance(Character *character) {
    return this->getLocation().distance(character->getLocation());
}

/**
 * This method decreases this character's hitpoint with the given amount.
 * @param damage - the amount of hitpoints that will be decreased from this character's hitpoint.
 */
void Character::hit(int damage) {
    // Handling an extreme case.
    if (!this->isAlive()) {
        return;
    }

    if (damage >= 0 && this->getHitpoint() - damage >= 0) {
        this->hitpoint -= damage;
    } else if (this->getHitpoint() - damage < 0) {
        this->setHitpoint(0);
    } else {
        throw invalid_argument("A character cannot be hit with non-positive/zero damage.");
    }
}

/**
 * This method will be overridden inside Cowboy & Ninja classes.
 * It is built to detect either slash or shoot during the attack(Team *opponent) method of Team class.
 * @param enemy - a pointer of the enemy that will be slash/shot by this character.
 */
void Character::SlashOrShoot(Character *enemy) {
    // Implementation of this method exists inside Cowboy & Ninja classes.
    // There is no need to have any implementations in here - would be useless.
}

string Character::print() {
    if (!this->isAlive()) {
        return "Name: (" + this->name + ") | Location: " + this->location.toString() + "\n";
    } else {
        return "Name: " + this->name + " | HP: " + to_string(this->hitpoint) + " | Location: " +
               this->location.toString() + "\n";
    }
}