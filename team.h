#include<vector>
#include "player.h"

class Team
{
    public:
        Team();
        std::string name;
        int totalRunsScored;
        int wicketlost;
        int totalBallsBowled;
        std::vector<Player>players;
};
