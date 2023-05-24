#include "Cowboy.hpp"

using namespace ariel;

/**
 * An essential constructor to construct an instance of a Cowboy.
 * Initializes the name, location and hitpoint attributes using the parent class - Character.
 * @param name - name of the cowboy.
 * @param location - location of the cowboy - X & Y coordinates.
 */
Cowboy::Cowboy(string name, Point location) : Character(name, location, COWBOY_HP) {
    this->bullets = 6;
}

/**
 * This is a getter for this cowboy's weapon bullets (mag).
 * NOTE: Cowboy can hold up to 6 bullets - a fully loaded mag.
 * @return - number of remained bullets of the cowboy's mag.
 */
int Cowboy::getBullets() {
    if (this->bullets < 0) {
        throw logic_error("Cowboy's mag CANNOT hold a non-positive amount of bullets.");
    }

    return this->bullets;
}

/**
 * This is a setter for this cowboy's bullets.
 * @param bullets
 */
void Cowboy::setBullets(int bullets) {
    this->bullets = bullets;
}

/**
 * This method shoots an enemy. It deals 10 damage on the given enemy.
 * @param enemy - a pointer of an enemy that will be shot by this cowboy.
 */
void Cowboy::shoot(Character *enemy) {
    // Handling extreme cases.
    if (this == enemy) {
        throw runtime_error("A cowboy cannot hurt himself.");
    }
    if (!enemy->isAlive()) {
        throw runtime_error("A cowboy cannot attack a dead enemy.");
    } else if (!this->isAlive()) {
        throw runtime_error("A dead cowboy cannot shoot anyone.");
    }

    // A cowboy can only shoot if he has bullets left and that he is alive.
    if (this->hasboolets()) {
        enemy->hit(COWBOY_DAMAGE);
        this->bullets--;
    }
}

/**
 * As described inside Character.hpp
 * @param enemy - a pointer of an enemy that will be shot.
 */
void Cowboy::SlashOrShoot(Character *enemy) {
    // If the cowboy has NO bullets left in his mag, he reloads with another new 6 bullets.
    if (!this->hasboolets()) {
        this->reload();
    }

    this->shoot(enemy);
}

/**
 * This method tells us if this cowboy has any bullets in his mag or not.
 * @return - TRUE -> if the cowboy HAS bullets left. Otherwise, FALSE.
 */
bool Cowboy::hasboolets() {
    if (this->bullets == 0) {
        return false;
    } else if (this->bullets < 0) {
        throw logic_error("Cowboy's mag CANNOT hold a non-positive amount of bullets.");
    }

    // Cowboy's bullets are greater than 0.
    return true;
}

/**
 * This method makes the cowboy to reload his weapon - filling his mag to the maximum (6 bullets).
 */
void Cowboy::reload() {
    if (!this->isAlive()) {
        throw runtime_error("A dead cowboy cannot reload.");
    } else {
        this->setBullets(6);
    }
}

/**
 * This method tells us the details of this cowboy.
 * @return - a string which represents the details of this cowboy.
 */
string Cowboy::print() {
    if (!this->isAlive()) {
        return "Name: (" + this->name + ") | Location: " + this->location.toString() + "\n";
    } else {
        return "C - Name: " + this->name + " | HP: " + to_string(this->hitpoint) + " | Location: " +
               this->location.toString() + "\n";
    }
}