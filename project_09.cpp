//MOnster Combat
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int playerChoice;
    int monsterMaxHealth, playerHealth, playerInitiative, playerAttack, playerDefense, playerAgility;
    int monsterAttack, monsterDefense, monsterMagic;

    // Initialize player and monster attributes
    playerAttack = 10;
    playerDefense = 15;
    playerAgility = 5;
    monsterAttack = 10;
    monsterDefense = 15;
    monsterMagic = 5;

    // Seed the random number generator
    srand((unsigned)time(0));

    // Randomly determine who starts the battle
    playerInitiative = rand() % 2 + 1;

    // Randomly assign health points to the player and the monster
    monsterMaxHealth = rand() % 50 + 60;
    playerHealth = rand() % 20 + 80;

    // Player starts the battle
    if (playerInitiative == 1) {
        cout << "You start.\n==========\n";

        // Battle loop
        while (playerHealth > 0 || monsterMaxHealth > 0) {
            // Player's turn
            cout << "What do you want to do?\n1 - Fierce Attack\n2 - Lithe Attack\n3 - Defensive moves\n";
            do { cin >> playerChoice; } while (playerChoice > 3 || playerChoice < 1);

            // Randomly determine player's attack attributes based on choice
            switch (playerChoice) {
            case 1:
                playerAttack = rand() % 20 + 10;
                playerDefense = rand() % 10 + 10;
                playerAgility = rand() % 5;
                break;
            case 2:
                playerAttack = rand() % 5 + 10;
                playerDefense = rand() % 10 + 10;
                playerAgility = rand() % 15;
                break;
            case 3:
                playerAttack = rand() % 10 + 10;
                playerDefense = rand() % 20 + 10;
                playerAgility = rand() % 5;
                break;
            }

            // Randomly determine monster's attack attributes
            playerChoice = rand() % 3;
            switch (playerChoice) {
            case 1:
                monsterAttack = rand() % 20 + 10;
                monsterDefense = rand() % 10 + 10;
                monsterMagic = rand() % 5;
                break;
            case 2:
                monsterAttack = rand() % 5 + 10;
                monsterDefense = rand() % 10 + 10;
                monsterMagic = rand() % 15;
                break;
            case 3:
                monsterAttack = rand() % 10 + 10;
                monsterDefense = rand() % 20 + 10;
                monsterMagic = rand() % 5;
                break;
            }

            // Player attacks monster
            int monsterHurt = (playerAttack - monsterMagic) - (monsterDefense / playerAttack);
            if (monsterHurt < 0) {
                monsterHurt = 0;
            }
            monsterMaxHealth = monsterMaxHealth - monsterHurt;
            cout << "You did " << monsterHurt << " damage to the monster!\n";

            // Check if monster is defeated
            if (monsterMaxHealth < 1) {
                cout << "You killed the beast!! You won with " << playerHealth << " hp left.\n";
                cin.get();
                return 0;
            }

            cout << "The monster now has " << monsterMaxHealth << " hp left.\n";

            // Monster attacks player
            int playerHurt = (monsterAttack - playerAgility) - (playerDefense / monsterAttack);
            if (playerHurt < 0) {
                playerHurt = 0;
            }
            playerHealth = playerHealth - playerHurt;
            cout << "The monster hit you for " << playerHurt << " damage.\n";

            // Check if player is defeated
            if (playerHealth < 1) {
                cout << "You died. The beast still has " << monsterMaxHealth << " hp left.\n";
                cin.get();
                return 0;
            }

            cout << "You now have " << playerHealth << " hp left.\n\n";
        }
    }
    // Monster starts the battle
    else {
        cout << "Monster starts.\n==============\n";

        // Battle loop
        while (playerHealth > 0 || monsterMaxHealth > 0) {
            // Randomly determine monster's attack attributes
            playerChoice = rand() % 3;
            switch (playerChoice) {
            case 1:
                monsterAttack = rand() % 20 + 10;
                monsterDefense = rand() % 10 + 10;
                monsterMagic = rand() % 5;
                break;
            case 2:
                monsterAttack = rand() % 5 + 10;
                monsterDefense = rand() % 10 + 10;
                monsterMagic = rand() % 15;
                break;
            case 3:
                monsterAttack = rand() % 10 + 10;
                monsterDefense = rand() % 20 + 10;
                monsterMagic = rand() % 5;
                break;
            }

            // Monster attacks player
            int playerHurt = (monsterAttack - playerAgility) - (playerDefense / monsterAttack);
            if (playerHurt < 0) {
                playerHurt = 0;
            }
            playerHealth = playerHealth - playerHurt;
            cout << "The monster hit you for " << playerHurt << " damage.\n";

            // Check if player is defeated
            if (playerHealth < 1) {
                cout << "You died. The beast still has " << monsterMaxHealth << " hp left.\n";
                cin.get();
                return 0;
            }

            cout << "You now have " << playerHealth << " hp left.\n\n";

            // Player's turn
            cout << "What do you want to do?\n1 - Fierce Attack\n2 - Lithe Attack\n3 - Defensive moves\n";
            do { cin >> playerChoice; } while (playerChoice > 3 || playerChoice < 1);

            // Randomly determine player's attack attributes based on choice
            switch (playerChoice) {
            case 1:
                playerAttack = rand() % 20 + 10;
                playerDefense = rand() % 10 + 10;
                playerAgility = rand() % 5;
                break;
            case 2:
                playerAttack = rand() % 5 + 10;
                playerDefense = rand() % 10 + 10;
                playerAgility = rand() % 15;
                break;
            case 3:
                playerAttack = rand() % 10 + 10;
                playerDefense = rand() % 20 + 10;
                playerAgility = rand() % 5;
                break;
            }

            // Player attacks monster
            int monsterHurt = (playerAttack - monsterMagic) - (monsterDefense / playerAttack);
            if (monsterHurt < 0) {
                monsterHurt = 0;
            }
            monsterMaxHealth = monsterMaxHealth - monsterHurt;
            cout << "You did " << monsterHurt << " damage to the monster!\n";

            // Check if monster is defeated
            if (monsterMaxHealth < 1) {
                cout << "You killed the beast!! You won with " << playerHealth << " hp left.\n";
                cin.get();
                return 0;
            }

            cout << "The monster now has " << monsterMaxHealth << " hp left.\n";
        }
    }
}
