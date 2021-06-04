#include "game.h"

using namespace std;

int main()
{
    system("color 0A");

    Game game;

    game.welcome();
    cout<<"\n\t\t\tpress Enter to continue"<<endl;

    getchar();
    game.showPlayers();
    /*cout<<"\n\t\t\tpress Enter to continue"<<endl;
    getchar();*/
    game.selectPlayer();


    game.showTeamPlayer();

    game.toss();
    cout<<"\n\t\t\tpress Enter to start First Innings"<<endl;
    getchar();
    game.startFirstInnings();
    game.swapping();
    game.secondInningStart();
    game.scoreBoard();
    game.swapping();
    game.scoreBoard();

}
