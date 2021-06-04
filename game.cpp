#include "game.h"
using namespace std;

Game ::Game()
{
    playerPerTeam = 10;
    maxBalls = 24;
    totalPlayers = 22;

    players[0]="MSDhoni";
    players[1]="BKumar";
    players[2]="RohitS";
    players[3]="Jadeja";
    players[4]="SDhawan";
    players[5]="Bumrah";
    players[6]="VKohli";
    players[7]="MShami";
    players[8]="SRaina";
    players[9]="HPandya";
    players[10]="ARahane";
    players[11]="Chahal";
    players[12]="DKartik";
    players[13]="DChahar";
    players[14]="SIyer";
    players[15]="SThakur";
    players[16]="RPant";
    players[17]="Khaleel";
    players[18]="ManishP";
    players[19]="UYadav";
    players[20]="KLRahul";
    players[21]="RAswhin";
    /*players[22]="ISharma";



*/
    isFirstInning = false;
    teamA.name="Team-A";
    teamB.name="Team-B";
}
void Game::welcome()                           //CRICK-KER
{
    cout << "\t\t\t------------------------------------------------\n";
    cout << "\t\t\t================== CRICK-KER ===================\n";
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t|\t\t\t\t\t\t|\n";
    cout << "\t\t\t|\tWelcome to Our Visual Cricket Game \t|\n";
    cout << "\t\t\t|\t\t\t\t\t\t|\n";
    cout << "\t\t\t|\t\t\t\t\t\t|\n";
    cout << "\t\t\t-------------------------------------------------\n";


    cout <<endl<<endl;

    cout << "\t\t\t ----------------------------------------------------------" <<endl;
    cout << "\t\t\t *********************  INSTRUCTIONS  *********************" <<endl;
    cout << "\t\t\t --------------------------------------------------------- " <<endl;
    cout << "\t\t\t |                                                        |" <<endl;
    cout << "\t\t\t |  1. Create 2 teams (Team-A and Team-B with 10          |" <<endl;
    cout << "\t\t\t |     Player each                                        |" <<endl;
    cout << "\t\t\t |  2. Lead the toss and decide the choose of play        |" <<endl;
    cout << "\t\t\t |  3. Each Inning will be of 24 ball                     |" <<endl;
    cout << "\t\t\t |  4. First player always batting first                  |" <<endl;
    cout << "\t\t\t |  5. Last player always bowling first                   |" <<endl;
    cout << "\t\t\t  -------------------------------------------------------- " <<endl;

}
void Game ::showPlayers()
{
    system("cls");
    cout << "\t\t\t------------------------------------------------" <<endl;
    cout << "\t\t\t=============== Pool of Players ================" <<endl;
    cout << "\t\t\t------------------------------------------------" <<endl;
    for(int i=0;i<totalPlayers;i+=2)
    {
        //usleep(100000);
        cout<<"\t\t\t\t"<<"["<<i+1<<"] : \t"<<players[i]<<"\t\t"<<"["<<i+2<<"] : \t"<<players[i+1]<<endl;
    }


}
int Game ::takeIntegerInput()
{
    int n;
    while(!(cin>>n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<< "Invalid Input ! please try again with valid input.";
    }
    return n;
}
bool Game::validateSelectedPlayer(int index)
{
    int n;
    vector<Player> players;
    players = teamA.players;
    n = players.size();
    for(int i=0;i<n;i++)
    {
        if(players[i].id == index)
        {
            return false;
        }
    }
    players = teamB.players;
    n = players.size();
    for(int i=0;i<n;i++)
    {
        if(players[i].id == index)
        {
            return false;
        }
    }
    return true;
}
void Game ::selectPlayer()
{

    cout << endl;
    cout << "\t\t\t------------------------------------------------" <<endl;
    cout << "\t\t\t=========== Create Team-A and Team-B ===========" <<endl;
    cout << "\t\t\t------------------------------------------------" <<endl;
    cout << endl;
    cout<<"\t\t\tEnter Code of Players Name"<<endl;
    for(int i=0;i<playerPerTeam; i++)
    {

        // ADD PLAYER TO TEAM A
        TeamASelection:

        cout << endl << "Select player "<<i+1<<" for Team A -";
        int playerIndexTeamA = takeIntegerInput()-1;

        if(playerIndexTeamA<0 || playerIndexTeamA>22)
        {
            cout<<endl<<" Please select from the given players"<<endl;
            goto TeamASelection;
        }
        else if(!validateSelectedPlayer(playerIndexTeamA))
        {
            cout<<endl<<"Player has been already selected, Please select other player"<<endl;
            goto TeamASelection;
        }
        else
        {
            Player teamAPlayer;
            teamAPlayer.id = playerIndexTeamA;
            teamAPlayer.name = players[playerIndexTeamA];
            teamA.players.push_back(teamAPlayer);
            players[playerIndexTeamA]=" ";
        }


        // ADD PLAYER TO TEAM B
        TeamBSelection:
        cout << endl << "Select player "<<i+1<<" for Team B -";
        int playerIndexTeamB = takeIntegerInput()-1;

        if(playerIndexTeamB<0 || playerIndexTeamB>22)
        {
            cout<<endl<<"!!! Please select from the given players"<<endl;
            goto TeamBSelection;
        }
        else if(!validateSelectedPlayer(playerIndexTeamB))
        {
            cout<<endl<<"!!!!  Player has been already selected, Please select other player"<<endl;
            goto TeamBSelection;
        }
        else
        {
            Player teamBPlayer;
            teamBPlayer.id = playerIndexTeamB;
            teamBPlayer.name = players[playerIndexTeamB];
            teamB.players.push_back(teamBPlayer);
            players[playerIndexTeamB]=" ";
        }
        system("cls");
        showPlayers();



    }
}
void Game ::showTeamPlayer()   //|       [0] RohitS       |
{
    vector <Player> teamAPlayers = teamA.players;
    vector <Player> teamBPlayers = teamB.players;
    cout << endl << endl;
    //cout << "\t\t\t|------------------------|\t\t|------------------------|" <<endl;
    cout << "\t\t\t|-------| Team-A |-------|\t\t|-------| Team-B |-------|" <<endl;
    cout << "\t\t\t|________________________|\t\t|________________________|" <<endl;

    for(int i=0; i<playerPerTeam;i++)
    {
         cout << "\t\t\t|\t" << "[" << i+1 << "] " << teamAPlayers[i].name << "\t |"
         << "\t\t"
			<< "|\t" << "[" << i+1 << "] " << teamBPlayers[i].name << "\t |" << endl;
    }
    cout << "\t\t\t|________________________|\t\t|________________________|" << endl << endl;

}
void Game ::toss()
{
    cout << "\t\t\t\t|------------------------------------------------|" <<endl;
    cout << "\t\t\t\t|================== Let's Toss ==================|" <<endl;
    cout << "\t\t\t\t|------------------------------------------------|" <<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"\n\t\t\tPress Enter to Toss"<<endl;
    getchar();
    cout << "\t\t\ttosing the Coin..."<< endl;
    usleep(2000000);
    srand(time(NULL));
    int randomValue = rand()%2;  //   0 or 1
    switch(randomValue)
    {
        case 0:
            cout << "\n\t\t\tTeam-A won the toss\n"<<endl;
            tossChoice(teamA);
            break;
        case 1:
            cout << "\n\t\t\tTeam-B won the toss\n"<<endl;
            tossChoice(teamB);
            break;


    }
}
void Game ::tossChoice(Team tossWinnerTeam)
{
    cout << "\t\t\tEnter 1 to bat or 2 to bowl first. "<<endl
        << "\t\t\t1. Bat"<<endl
        << "\t\t\t2. Bowl"<<endl;
    int Choice = takeIntegerInput();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    switch(Choice)
    {
        case 1:
            cout << endl<<"\t\t\t" << tossWinnerTeam.name << " Won the toss and elected to bat first"<<endl<<endl;
            if(tossWinnerTeam.name.compare("Team-A")==0)
            {
                battingTeam = &teamA;
                bowlingTeam = &teamB;
            }
            else
            {
                battingTeam = &teamB;
                bowlingTeam = &teamA;
            }
            break;
        case 2:
             cout << endl <<"\t\t\t"<< tossWinnerTeam.name << " Won the toss and elected to bowl first"<<endl<<endl;
             if(tossWinnerTeam.name.compare("Team-A")==0)
            {
                bowlingTeam = &teamA;
                battingTeam = &teamB;
            }
            else
            {
                bowlingTeam = &teamB;
                battingTeam = &teamA;
            }
             break;
        default:
            cout << endl << "Invalid Input. Please try again:"<<endl<<endl;
            tossChoice(tossWinnerTeam);
            break;

    }

}
void Game ::startFirstInnings()
{
    system("cls");          //////////
    cout<<endl<<"\t\t\t\t"<<"-|   FIRST INNINGS STARTS  |-"<<endl<<endl;
    nextPlayerover=playerPerTeam-1;
    isFirstInning = true;
    initializePlayer();
    playInning();
}
void Game ::initializePlayer()
{
    // Choose batsman and bowler
    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam->players[playerPerTeam-1];

    cout<<"\t\t"<<battingTeam->name<<" - " <<batsman->name<<" is batting"<<endl;
    cout<<"\t\t"<<bowlingTeam->name<<" - " <<bowler->name <<" is bowling"<<endl<<endl;

}
void Game ::playInning()
{
    for(i=0; i < maxBalls; i++)
    {


        cout<<"\t\t\tPress Enter to bowl";
        getchar();
        system("cls");
        showTeamPlayer();
        cout<<endl;          //////////
        cout<<"\n\t\t\tBowling";
        for(int k=0;k<4;k++)
        {
            cout<<".";
            usleep(250000);
        }
        cout<<endl;
        bat();
        if(!validateInningScore())
        {
            break;
        }

    }
}
void Game ::bat()
{
    srand(time(NULL));
    int runScored = rand()%7;
    // update batting Team and bowling Team Score

    batsman->runScored = batsman->runScored + runScored;
    battingTeam->totalRunsScored = battingTeam->totalRunsScored + runScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;

    bowler->ballsBowled = bowler->ballsBowled + 1;
    bowlingTeam ->totalBallsBowled = bowlingTeam->totalBallsBowled +1;
    bowler->runsGiven = bowler->runsGiven + runScored;



    if(runScored !=0)
    {
        cout <<endl<<"\t\t\t"<<bowler->name <<" to "<<batsman->name <<" "<<runScored << " runs!"<<endl<<endl;

        over();
    }
    else
    {
        cout <<endl<<"\t\t\t"<<bowler->name <<" to "<<batsman->name <<" "<<" OUT !!!! "<<endl<<endl;

        battingTeam->wicketlost = battingTeam->wicketlost + 1;
        bowler->wicketTaken=bowler->wicketTaken+1;
        over();
        showGameScoreCard();

        int nextPlayerIndex = battingTeam->wicketlost;
        batsman = &battingTeam->players[nextPlayerIndex];
        cout<<"\t\t"<<battingTeam->name<<" - " <<batsman->name<<" Next to bat"<<endl;
        cout<<"\t\t"<<bowlingTeam->name<<" - " <<bowler->name <<" bowling"<<endl<<endl;
        //over();
    }
}
bool Game ::validateInningScore()
{
    if(isFirstInning)
    {
        if(battingTeam->wicketlost == playerPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
        {

            cout << "\t\t\t |||  FIRST INNINGS ENDS  |||" <<endl<<endl;
            usleep(4000000);
            system("pause");
            cout<< "\t\t\t"<< battingTeam->name<< " "<< battingTeam->totalRunsScored << " - "
                <<battingTeam->wicketlost<<" ("<<bowlingTeam->totalBallsBowled
                <<")"<<endl;
            cout<< "\t\t\t"<< bowlingTeam->name << " need " << battingTeam->totalRunsScored + 1
                <<" runs to win the match"<<endl<<endl;
                usleep(1000000);


            return false;
        }
    }
    return true;
}
void Game ::over()
{
    if(bowler->ballsBowled == 6 && i!=maxBalls-1)
    {
        showGameScoreCard();
        cout << "\t\t\t-----------------------<  OVER  >-----------------------" << endl;



        nextPlayerover-=1;

        bowler = &bowlingTeam->players[nextPlayerover];
        cout<<"\t\t"<<"Next Bowler :"<<bowler->name<<endl;

    }
}
void Game ::showGameScoreCard()
{
    cout << "\t\t\t----------------------------------------------------------" << endl;
    cout << "\t\t\t" << battingTeam->name <<" "<<battingTeam->totalRunsScored <<"-"
         << battingTeam->wicketlost <<" ("<<bowlingTeam->totalBallsBowled<<") |"<<batsman->name
         << " " << batsman->runScored <<"(" <<batsman->ballsPlayed<<")\t"<<bowler->name<<" "
         << bowler->ballsBowled <<" -" << bowler->runsGiven <<" - " << bowler->wicketTaken <<"\t" <<endl;
    cout << "\t\t\t----------------------------------------------------------" << endl;
}
void Game :: swapping()
{
    Team temp;
    temp = *battingTeam;
    *battingTeam = *bowlingTeam;
    *bowlingTeam = temp;
}
void Game :: secondInningStart()
{
    nextPlayerover=playerPerTeam-1;
    cout<<endl<<"\t\t\t"<<"----------------------------|   SECOND INNINGS STARTS   |----------------------------"<<endl<<endl;
    isFirstInning = false;
    initializePlayer();
    playInning();
    cout << " \n\t\t\t\t---<><><>  Match End <><><>--- "<<endl;
    usleep(3000000);
    system("cls");
    matchResult();
}
void Game :: matchResult()
{
    if(bowlingTeam->totalRunsScored>battingTeam->totalRunsScored)
    {
        cout <<"\n\t\t\t"<<"---------<><><><><> "<<bowlingTeam->name<<" Won the Match"<<" <><><><><>---------"<<endl;
        cout <<"\n\t\t\t"<<bowlingTeam->name<<" Won by "<<bowlingTeam->totalRunsScored-battingTeam->totalRunsScored<<" Run(s)"<<endl<<endl;
    }
    else if(bowlingTeam->totalRunsScored<battingTeam->totalRunsScored)
    {
        cout <<"\n\t\t\t"<<"---------<><><><><> "<<battingTeam->name<<" Won the Match"<<" <><><><><>----------"<<endl;
        cout <<"\n\t\t\t"<<battingTeam->name<<" Won by "<<battingTeam->totalRunsScored-bowlingTeam->totalRunsScored<<" Run(s)"<<endl<<endl;
    }
    else
    {
        cout <<"\n\t\t\t!!!!!!!!     MATCH TIE     !!!!!!!!"<<endl<<endl;
    }
    usleep(2000000);
}
void Game ::scoreBoard()
{
    int n=0;

    cout<< "\t\t\t"<< battingTeam->name<< " "<< battingTeam->totalRunsScored << " - "
                <<battingTeam->wicketlost<<" ("<<bowlingTeam->totalBallsBowled<<")"<<endl;
    cout << "\t\t\t================================================= "<<endl;
    cout << "\t\t\t|      PLAYER        BATTING        BOWLING      |"<<endl;

    for(int i=0;i<playerPerTeam;i++)
    {
        cout << "\t\t\t|------------------------------------------------|"<<endl;
        batsman = &battingTeam->players[n];
        cout << "\t\t\t"<<"|\t"<<batsman->name<<"\t\t"<<batsman->runScored<<"("<<batsman->ballsPlayed<<")\t\t"<<batsman->ballsBowled<<"-"
        <<batsman->runsGiven<<"-"<<batsman->wicketTaken<<"\t |"<<endl;
        n++;
    }
    cout << "\t\t\t================================================= "<<endl<<endl;
    system("pause");
}
