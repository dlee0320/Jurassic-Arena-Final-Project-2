#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;
int luck = 10;
int randomnumber(int max);

const int maxdinos = 3;

class Dino{
public:
	char call;
	string dinoname;
	int HP;
	int attack;
	int defense;

	void HPdamage(int damage){
		HP -= damage;
	}

	void defenseaddition(int addition){
		defense += addition;
	}

	void defensesubtraction(int subtraction){
		defense -= subtraction;
	}

	void veloPassive(int Lifesteal){
		HP += Lifesteal / 2;
	}

	void dinobonus(int bonus){
		attack += bonus;
	}

	void dinonormal(int bonus){
		attack -= bonus;
	}

};

class player{
public:
	string name;
	Dino dino[maxdinos];
	int HP;

	void HPdamage(int death){
		HP -= death;
	}

};


int main(){
	srand(time(NULL));
	int trichance = 30;
	int bonus[2][maxdinos];
	int rexinitialHP[2][maxdinos];
	int rexinitialattack[2][maxdinos];
	int stegodamage;
	int dodge;
	int chance;
	int ankylcount = 1;
	int damage;
	int dinoVictim;
	int input;
	int death = 0;
	int alive[2][maxdinos] = { 1, 1, 1, 1, 1, 1 };
	int compare[2][maxdinos];
	int tricMultiplier = 1;
	int rand[2][maxdinos];
	// Title Page
	cout << "                             Welcome to the...\n";
	cout << endl;
	cout << "	  ==========================================================\n";
	cout << "	  |        * *   * ****     **     ****  ****  *****  ***  |\n";
	cout << "	  |        * *   * *   *   *  *   *     *        *   *     |\n";
	cout << "	  |        * *   * *   *  *    *   **    **      *   *     |\n";
	cout << "	  |  *     * *   * ****  ********    *     *     *   *     |\n";
	cout << "	  |   *   *  *   * *  *  *      *     *     *    *   *     |\n";
	cout << "	  |    ***    ***  *   * *      * ****  ****   *****  ***  |\n";
	cout << "	  |                                                        |\n";
	cout << "	  |             **    ****  ***** *    *    **             |\n";
	cout << "	  |            *  *   *   * *     **   *   *  *            |\n";
	cout << "	  |           *    *  *   * *     * *  *  *    *           |\n";
	cout << "	  |          ******** ****  ***** *  * * ********          |\n";
	cout << "	  |          *      * *  *  *     *   ** *      *          |\n";

	cout << "	  |          *      * *   * ***** *    * *      *          |\n";
	cout << "	  ==========================================================\n";
	cout << endl;
	cout << "Press enter to continue.";
	char c1;
	cin.get(c1);
	cout << endl;

	// Introduction to the game
	cout << "In the Jurassic Arena, two challengers enter and only one leaves victorious.\n";
	cout << endl;

	cout << "                               Instructions\n\n";
	cout << "      The game begins by having Player 1 select all three of their dinosaurs. \n";
	cout << "                 Then Player 2 will select all of theirs. \n";
	cout << "   Select a dinosaur by entering its corresponding number and pressing enter.\n";
	cout << "            There are six possible dinosaurs to select from.\n";
	cout << "                Each dinosaur has its own special ability.\n\n";
	cout << "Dinosaurs:\n";
	cout << "Triceratops - Critical Strike: 30% chance of 3 x attack.\n";
	cout << "Tyrannosaurus Rex - Attack Boost: Attack up 1 for every 5 HP lost.\n";
	cout << "Ankylosaurus - Team Defend: Team defend boost every third turn.\n";
	cout << "Pterodactyl - Dodge: 45% chance of incoming attack doing no damage.\n";
	cout << "Velociraptor - Lifesteal: Regains 1/2 of damage dealt as health.\n";
	/*cout << "Stegosaurus - Thorns: Deals damage to attacker equal to 1/4 of damage taken.\n";*/
	//cout << "Brachiosaurus - Cripple: 25% chance to  reduce victim's health by 50%.\n";
	cout << "Megalodon - Pierce: 40% chance to ignore defense.\n\n";
	cout << "Press enter to continue.";
	cin.get(c1);
	cout << endl;
	cout << " After selection all the dinosaurs will all be displayed on the gameplay board.\n";
	cout << "            Player 1 attacks first with each of their dinosaurs.\n";
	cout << "    Input the number of the dinosaur that will be attacked and press enter.\n";
	cout << "           Player 2 will then attack with all of their dinosaurs.\n";
	cout << "     No dinosaurs will be killed off until both player's turns have ended.\n";
	cout << "          (This game simulates simultaneous attacks between teams.)\n";
	cout << "                Once a dinosuar dies it cannot be used again.\n";
	cout << "   The player that kills its opponents team is the champion of Jurassic Arena.\n\n";
	cout << "Press enter to continue.";
	cin.get(c1);
	cout << endl;


	cout << endl;

	player player[2];
	player[0].HP = maxdinos;
	player[1].HP = maxdinos;

	for (int j = 0; j < 2; j++){
		cout << "Player " << j + 1 << endl;
		player[j].HP = maxdinos;
		for (int i = 0; i < maxdinos; i++){
			if (i == 0){
				cout << "(1) Triceratops \n(2) Tyrannosaurus Rex \n(3) Ankylosaurus \n(4) Pterodactyl \n";
				cout << "(5) Velociraptor \n(6) Megalodon \n\n";
			}
			cout << "Choose a dinosaur: \n";
			cin >> input;
			while ((input < 1) || (input > 6)){
				cout << "Input is invalid, choose again: ";
				cin >> input;
			}
			if (i == 2){
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			}
			if (input == 1){
				player[j].dino[i].call = 'T';
				player[j].dino[i].dinoname = "Triceratops";
				player[j].dino[i].HP = 150 + randomnumber(21) - 10;
				player[j].dino[i].attack = 25;
				player[j].dino[i].defense = 10;
			}
			else if (input == 2){
				player[j].dino[i].call = 'R';
				player[j].dino[i].dinoname = "Tyrannosaurus Rex";
				player[j].dino[i].HP = 120 + randomnumber(21) - 10;
				player[j].dino[i].attack = 40;
				player[j].dino[i].defense = 9;
			}
			else if (input == 3){
				player[j].dino[i].call = 'A';
				player[j].dino[i].dinoname = "Ankylosaurus";
				player[j].dino[i].HP = 160 + randomnumber(21) - 10;
				player[j].dino[i].attack = 20;
				player[j].dino[i].defense = 12;
			}
			else if (input == 4){
				player[j].dino[i].call = 'P';
				player[j].dino[i].dinoname = "Pterodactyl";
				player[j].dino[i].HP = 110 + randomnumber(21) - 10;
				player[j].dino[i].attack = 25;
				player[j].dino[i].defense = 7;
			}
			else if (input == 5){
				player[j].dino[i].call = 'V';
				player[j].dino[i].dinoname = "Velociraptor";
				player[j].dino[i].HP = 110 + randomnumber(21) - 10;
				player[j].dino[i].attack = 30;
				player[j].dino[i].defense = 8;
			}
			else if (input == 6){
				player[j].dino[i].call = 'M';
				player[j].dino[i].dinoname = "Megalodon";
				player[j].dino[i].HP = 120 + randomnumber(21) - 10;
				player[j].dino[i].attack = 35;
				player[j].dino[i].defense = 11;
			}
			/*else if (input == 7){
			player[j].dino[i].call = 'B';
			player[j].dino[i].dinoname = "Brachiosaurus";
			player[j].dino[i].HP = 170 + randomnumber(21) - 10;
			player[j].dino[i].attack = 20;
			player[j].dino[i].defense = 5;
			}
			else if (input == 8){
			player[j].dino[i].call = 'S';
			player[j].dino[i].dinoname = "Stegosaurus";
			player[j].dino[i].HP = 130 + randomnumber(21) - 10;
			player[j].dino[i].attack = 25;
			player[j].dino[i].defense = 10;
			}*/
		}
		cout << endl;
	}
	for (int j = 0; j < 2; j++){
		for (int i = 0; i < maxdinos; i++){
			if (player[j].dino[i].call == 'R'){
				rexinitialHP[j][i] = player[j].dino[i].HP;
				rexinitialattack[j][i] = player[j].dino[i].attack;
			}
		}
	}

	cout << "Let the battle begin!" << endl << endl;

	cout << endl;

	//Total number of dinosaurs from the team are summed into the variable allHealth1. 
	int allHealth1 = maxdinos;
	//Total number of dinosaurs from the team are summed into the variable allHealth2. 
	int allHealth2 = maxdinos;

	int attackValue = 2;

	//Regulates rotation between players.
	do{



		for (int j = 0; j < 2; j++){
			for (int i = 0; i < maxdinos; i++){
				bonus[j][i] = randomnumber(11) - 5;
				player[j].dino[i].dinobonus(bonus[j][i]);

				compare[j][i] = alive[j][i];
				/*	if (player[j].dino[i].call == 'R'){
				rexHP[j][i] = player[j].dino[i].HP;
				}*/
			}
		}

		if (ankylcount % 2 == 0){
			for (int j = 0; j < 2; j++){
				for (int i = 1; i <= maxdinos; i++){
					if (player[j].dino[i - 1].call == 'A'){
						for (int k = 1; k <= maxdinos; k++){
							player[j].dino[k - 1].defenseaddition(10);
						}
					}
				}
			}
		}

		cout << "Player 1" << setw(40) << "Player 2" << endl;
		cout << "1. " << player[0].dino[0].dinoname << setw(40) << "1. " << player[1].dino[0].dinoname << endl;
		cout << setw(11) << "Health: " << player[0].dino[0].HP << setw(40) << "Health: " << player[1].dino[0].HP << endl;
		cout << setw(11) << "Attack: " << player[0].dino[0].attack << setw(40) << " Attack: " << player[1].dino[0].attack << endl;
		cout << setw(11) << "Defense: " << player[0].dino[0].defense << setw(40) << "Defense: " << player[1].dino[0].defense << endl;
		cout << "2. " << player[0].dino[1].dinoname << setw(40) << "2. " << player[1].dino[1].dinoname << endl;
		cout << setw(11) << "Health: " << player[0].dino[1].HP << setw(40) << "Health: " << player[1].dino[1].HP << endl;
		cout << setw(11) << "Attack: " << player[0].dino[1].attack << setw(40) << " Attack: " << player[1].dino[1].attack << endl;
		cout << setw(11) << "Defense: " << player[0].dino[1].defense << setw(40) << "Defense: " << player[1].dino[1].defense << endl;
		cout << "3. " << player[0].dino[2].dinoname << setw(40) << "3. " << player[1].dino[2].dinoname << endl;
		cout << setw(11) << "Health: " << player[0].dino[2].HP << setw(40) << "Health: " << player[1].dino[2].HP << endl;
		cout << setw(11) << "Attack: " << player[0].dino[2].attack << setw(40) << " Attack: " << player[1].dino[2].attack << endl;
		cout << setw(11) << "Defense: " << player[0].dino[2].defense << setw(40) << "Defense: " << player[1].dino[2].defense << endl;
		cout << endl;

		// Player 1 Attack Phase
		for (int i = 1; i <= maxdinos; i++){
			if (alive[0][i - 1]){
				cout << "Player 1, your attack!" << endl;
				cout << "Attacking with dinosaur " << i << endl;
				cout << "Number of the dinosaur you are going to attack: ";
				cin >> dinoVictim;
				while (dinoVictim > maxdinos || dinoVictim < 0){ //Checks that user's input is valid.
					cout << "Invalid input. Try again: ";
					cin >> dinoVictim;
				}
				if (player[1].dino[dinoVictim - 1].call == 'P'){
					chance = randomnumber(100);
					if (chance < 45){
						dodge = 1;
						cout << "The Pterodactyl dodged!!" << endl;
					}
				}
				if (dodge == 0){
					if (player[0].dino[i - 1].call == 'T'){
						rand[0][i - 1] = randomnumber(100);
						if (rand[0][i - 1] < trichance){
							tricMultiplier = 3;
							cout << "Critical Strike!! \n";
						}
						damage = tricMultiplier*player[0].dino[i - 1].attack - player[1].dino[dinoVictim - 1].defense;
						player[1].dino[dinoVictim - 1].HPdamage(damage);
						if (damage < 0)
							damage = 0;
					}
					// Megalodon Passive
					else if (player[0].dino[i - 1].call == 'M'){
						rand[0][i - 1] = randomnumber(100);
						if (rand[0][i - 1] < 40){
							damage = player[0].dino[i - 1].attack;
							player[1].dino[dinoVictim - 1].HPdamage(damage);
							cout << "Pierce!! \n";
						}
						else{
							damage = player[0].dino[i - 1].attack - player[1].dino[dinoVictim - 1].defense;
							player[1].dino[dinoVictim - 1].HPdamage(damage);
							if (damage < 0)
								damage = 0;
						}
					}
					else{
						damage = player[0].dino[i - 1].attack - player[1].dino[dinoVictim - 1].defense;
						player[1].dino[dinoVictim - 1].HPdamage(damage);
						if (damage < 0)
							damage = 0;
					}
					// Velociraptor Passive
					if (player[0].dino[i - 1].call == 'V'){
						player[0].dino[i - 1].veloPassive(damage);
					}
					// Stegosaurus Passive
					/*if (player[1].dino[dinoVictim - 1].call == 'S'){
					stegodamage = damage / 4;
					player[0].dino[i - 1].HPdamage(stegodamage);
					}*/


				}
			}
			cout << endl;
			tricMultiplier = 1;
			dodge = 0;
		}

		// Player 2 Attack Phase
		for (int i = 1; i <= maxdinos; i++){
			if (alive[1][i - 1]){
				cout << "Player 2, your attack!" << endl;
				cout << "Attacking with dinosaur " << i << endl;
				cout << "Number of the dinosaur you are going to attack: ";
				cin >> dinoVictim;
				while (dinoVictim > maxdinos || dinoVictim < 0){ //Checks that user's input is valid.
					cout << "Invalid input. Try again: ";
					cin >> dinoVictim;
				}
				if (player[0].dino[dinoVictim - 1].call == 'P'){
					chance = randomnumber(100);
					if (chance < 45){
						dodge = 1;
						cout << "The Pterodactyl dodged!!" << endl;
					}
				}
				//////Triceratops Attack
				if (dodge == 0){
					if (player[1].dino[i - 1].call == 'T'){
						rand[1][i - 1] = randomnumber(100);
						if (rand[1][i - 1] < trichance){
							tricMultiplier = 3;
							cout << "Critical Strike!!\n";
						}
						damage = tricMultiplier*player[1].dino[i - 1].attack - player[0].dino[dinoVictim - 1].defense;
						player[0].dino[dinoVictim - 1].HPdamage(damage);
						if (damage < 0)
							damage = 0;
					}
					// Megalodon Passive
					else if (player[1].dino[i - 1].call == 'M'){
						rand[1][i - 1] = randomnumber(100);
						if (rand[1][i - 1] < 40){
							damage = player[1].dino[i - 1].attack;
							player[0].dino[dinoVictim - 1].HPdamage(damage);
							cout << "Pierce!! \n";
						}
						else{
							damage = player[1].dino[i - 1].attack - player[0].dino[dinoVictim - 1].defense;
							player[0].dino[dinoVictim - 1].HPdamage(damage);
							if (damage < 0)
								damage = 0;
						}
					}
					else{
						damage = player[1].dino[i - 1].attack - player[0].dino[dinoVictim - 1].defense;
						player[0].dino[dinoVictim - 1].HPdamage(damage);
						if (damage < 0)
							damage = 0;
					}
					// Velociraptor Passive
					if (player[1].dino[i - 1].call == 'V'){
						player[1].dino[i - 1].veloPassive(damage);
					}
					// Stegosaurus Passive
					/*if (player[0].dino[dinoVictim - 1].call == 'S'){
					stegodamage = damage / 4;
					player[1].dino[i - 1].HPdamage(stegodamage);
					}*/
				}
			}
			cout << endl;
			tricMultiplier = 1;
			dodge = 0;
		}

		for (int j = 0; j < 2; j++){
			for (int i = 0; i < maxdinos; i++){
				if (player[j].dino[i].HP > 0)
					alive[j][i] = 1;
				else{
					alive[j][i] = 0;
					player[j].dino[i].HP = 0;
				}

				if (alive[j][i] != compare[j][i]){
					death = 1;
					player[j].HPdamage(death);
				}
			}
		}

		if (ankylcount % 2 == 0){				// Ankylosaurus Passive
			for (int j = 0; j < 2; j++){
				for (int i = 1; i <= maxdinos; i++){
					if (player[j].dino[i - 1].call == 'A'){
						for (int k = 1; k <= maxdinos; k++){
							player[j].dino[k - 1].defensesubtraction(10);
						}
					}
				}
			}
		}
		ankylcount++;

		for (int j = 0; j < 2; j++){
			for (int i = 0; i < maxdinos; i++){
				player[j].dino[i].dinonormal(bonus[j][i]);
			}
		}

		for (int j = 0; j < 2; j++){            // T-Rex Passive
			for (int i = 0; i < maxdinos; i++){
				if (player[j].dino[i].call == 'R'){
					player[j].dino[i].attack = rexinitialattack[j][i] + (rexinitialHP[j][i] - player[j].dino[i].HP) / 5;
				}
			}
		}

	} while ((player[0].HP > 0) && (player[1].HP > 0)); //Checks to see if either team has a an overall health value of zero.

	if (player[0].HP > 0){
		cout << "Player 1 is the champion of Jurassic Arena!" << endl;
	}
	else
		cout << "Player 2 is the champion of Jurassic Arena!" << endl;

	cout << "\n\n\n(No dinosaurs were harmed in the making of this game.)\n\n";
	return 0;
}

int randomnumber(int max){
	return rand() % max;
};