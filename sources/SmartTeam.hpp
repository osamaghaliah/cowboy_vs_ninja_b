/**
 * This class represents a team of fighters who is prepared to perform an attack strategically.
 * The team's strategy is based on the following tactics:
 *
 *  1. The fighter with the highest HP is the team's tanker - sacrificing for his teammates.
 *     This team's tanker is always spawned at a location that is always in front of his teammates.
 *     Once the tanker is dead, a new tanker is assigned according to its HP... and so on.
 *     Such tactic is supposed to make this team to last longer at the battlefield.
 *
 *  2. Since the cowboys are able to shoot anyone from any range, they must shoot the enemy who is characterized
 *     with the highest HP. Such tactic is supposed to make the enemy's team to die faster.
 *     Besides, whenever there are any ninja-enemies who are getting close to a cowboy - the cowboy moves farther.
 *     Such sub-tactic is supposed to make this team to last longer at the battlefield.
 *
 *  3. Ninjas are simply fast. Therefore, they must be always "velocity" meters away from the tanker so they can slash the enemies
 *     who are close to this team's tanker and to directly move with their tanker. Such tactic is supposed to make this team to last
 *     longer at the battlefield AND contribute to make the enemy's team to die faster - slashing is harmful.
 *     However, the type of ninjas who must be close to the tanker is prioritized according to the highest velocity:
 *      ==> If the team contains Young ninjas - they are the best option to be the tanker's guardians.
 *      ==> If the team contains Trained ninjas - they are the second best option to be the tanker's guardians.
 *      ==> If the team contains Old Ninjas - one of them is assigned as the team's tanker, then, they are considered
 *          to be the third best option to be the tanker's guardians.
 *
 * @author Osama M. Ghaliah
 */

#pragma once

#include "Team.hpp"

using namespace std;

namespace ariel {
    class SmartTeam : public Team {
        /**
         * IMPLEMENTATION FOR THIS CLASS IS LEFT FOR THE PRESENTATION.
         * THE ESSENTIAL STRATEGY IS DESCRIBED ABOVE.
         */
    };
}
