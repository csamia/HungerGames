#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

//void playerStats(int health, string weapon) {
	//cout << "You have " << health << " health" << endl;
	//cout << "Your current weapon is the: " << weapon << endl;
	//cout << endl;
//}

//string death() {
	//cout << "You were terminated" << endl; 
//}
void playerStats(int health, string weapon, bool formatted = false) {
	if (formatted) {
		// formatted version
		cout << "\n===============================" << endl;
		cout << "       Player Stats            " << endl;
		cout << "===============================" << endl;
		cout << left << setw(20) << "Health:" << setw(10) << health << endl;
		cout << left << setw(20) << "Weapon:" << setw(10) << (weapon.empty() ? "None" : weapon) << endl;
		cout << "===============================" << endl;
	}
	else {
		// simpler version 
		 cout << "You have " << health << " health" << endl;
		cout << "Your current weapon is the: " << weapon << endl;
		cout << endl;
	}
}

string getUserInput() {
	string userInput;
	getline(cin, userInput);
	transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
	return userInput;
}

bool isAlive(int health) {
	if (health <= 0) {
		return false;
	} else {
		return true;
	}
}
void handleDeath(int playerHealth, string weapon) {
	playerStats(playerHealth, weapon,true); 
	cout << "Game Over." << endl; 
	cout << "Thank you for playing my game!" << endl; 
}

int main() {

	int playerHealth = 10;
	string weapon = "";
	string playerName;
	string ready;
	string choiceOne;
	string choiceTwo;
	string choiceThree;
	string choiceFour;
	// Intro
	cout << "Welcome to the annual Hunger Games!" << endl;
	cout << "Enter your name, tribute: " << endl;
	getline(cin, playerName);

	cout << "\nHello " << playerName << ", the rules are simple: Survive at all costs" << endl;
	cout << "\n";
	cout << "You have 10 health. If you lose all your health, you will lose the Games." << endl;
	cout << "You wake up in a cage, bringing you up to a platform in the forest. " << endl;
	cout << "23 other tributes surround you with a large cornucopia of weapons in the middle." << endl;
	cout << "You have 10 seconds before the games begin" << endl;

	//Ask if user is ready to start game
	// Convert input to lowercase
	do {
		cout << "\nAre you ready? Enter Yes or No" << endl;
		getline(cin, ready);
		transform(ready.begin(), ready.end(), ready.begin(), ::tolower);
	} while (ready != "yes" && ready != "y" && ready != "n" && ready != "no");

	if (ready == "yes" || ready == "y") {
		cout << "The Hunger Games have begun!" << endl;
	}
	else {
		cout << "\nNo time to think, the games have begun!" << endl;
	}
	//Level one
	cout << "Make your first choice. Enter a, b or c: " << endl;
	cout << "Do you want to: " << endl;
	cout << "\n";
	cout << "a) Run to the cornucopia" << endl;
	cout << "b) Run into the forest" << endl;
	cout << "c) Hide behind the cornucopia and wait" << endl;
	do {
		cout << "\nEnter your choice (a, b, or c): ";
		choiceOne = getUserInput();  // your function already lowercases input
		if (choiceOne != "a" && choiceOne != "b" && choiceOne != "c") {
			cout << "Invalid input. Please enter a, b, or c." << endl;
		}
	} while (choiceOne != "a" && choiceOne != "b" && choiceOne != "c");


	if (choiceOne == "a") {
		cout << "You sprint to the cornucopia, and grab an axe. But just as you grab it, an arrow flies through the air, and pierces your leg! You run to the forest, blood staining your clothes." << endl;
		cout << "You lose 2 health, but you have a weapon in hand." << endl;
		playerHealth -= 2;
		weapon = "Axe";
	}
	else if (choiceOne == "b") {
		cout << "You flee into the forest. It's eerily quiet, but you're safe." << endl;
		weapon = "None";
	}
	else if (choiceOne == "c") {
		cout << "You hear everyone fighting as you crouch behind the cornucopia, hiding. Luckily, no one found you" << endl;
		weapon = "None";
	}

	playerStats(playerHealth, weapon);

	if (!isAlive(playerHealth)) {
		handleDeath(playerHealth, weapon);
		return 0;
	}
	cout << "Press Enter to move onto the next level...";
	// cin.ignore(numeric_limits<streamsize>::max()); // Clears input buffer
	cin.get(); // Waits for user to press Enter

	//Level two
	cout << "\nCongratulations, you have made it to level two!" << endl;

	cout << "3 cannons have been fired, a sign that three fellow tributes have fallen. " << endl;
	cout << "The sun dips below the horizon, long shadows darkening the arena. It's time to find shelter." << endl;

	cout << "What will you do? Make your choice." << endl;
	cout << "\n";
	cout << "a) Climb up and hide in a tree" << endl;
	cout << "b) Follow a group of people passing by" << endl;
	cout << "c) Start scavenging" << endl;
	do {
		cout << "\nEnter your choice (a, b, or c): ";
		choiceTwo = getUserInput();  // your function already lowercases input
		if (choiceTwo != "a" && choiceTwo != "b" && choiceTwo != "c") {
			cout << "Invalid input. Please enter a, b, or c." << endl;
		}
	} while (choiceTwo != "a" && choiceTwo != "b" && choiceTwo != "c");

	if (choiceOne == "a" && choiceTwo == "a") {
		cout << "Oh No! A girl with a braid is already in the tree and pushes you off! You lose 3 health." << endl;
		cout << "Luckily, you stumble into a cave and use your axe to make a fire and warm!" << endl;
		playerHealth -= 3;
		weapon = "Axe";

	}
	else if (choiceOne == "a" && choiceTwo == "b") {
		cout << "Oh no, you follow the group of people, but they seem hostile...they start to chase you down!" << endl; 
		cout << "You frantically run, but a bladed weapon flies straight for your heart. There's nothing you can do. You have been killed." << endl;
		cout << "You have lost the Hunger Games. TERMINATION - END OF GAME" << endl;
		playerHealth = 0;
		handleDeath(playerHealth, weapon);
		return 0;
	}
	else if (choiceOne == "a" && choiceTwo == "c") {
		cout << "You were lucky enough to find a large cave! You use your axe to make a fire and keep warm! " << endl;
		weapon = "Axe";
	}

	else if ((choiceOne == "b" || choiceOne == "c") && choiceTwo == "a") {
		cout << "Oh no! A girl with a braid is already in the tree and pushes you off! You lose 3 health." << endl;
		cout << "You are lucky enough to find a cave. But it's damp and cold and you start to freeze. You lose 2 more health." << endl;
		playerHealth -= 5;
		weapon = "None";
	}
	else if ((choiceOne == "b" || choiceOne == "c") && choiceTwo == "b") {
		cout << "Oh no, you follow the group of people, but they seem hostile...they start to chase you down!" << endl;
		cout << "You frantically run, but a bladed weapon flies straight for your heart. There's nothing you can do. You have been killed." << endl;
		cout << "You have lost the Hunger Games. TERMINATION - END OF GAME" << endl;
		playerHealth = 0;
		handleDeath(playerHealth, weapon);
		
		return 0;
	}
	else if ((choiceOne == "b" || choiceOne == "c") && choiceTwo == "c") {
		cout << "You are lucky enough to find a cave. But it's damp and cold and you start to freeze. You lose 2 more health." << endl;
		playerHealth -= 2;
		weapon = "None";
	}

	playerStats(playerHealth, weapon);

	if (!isAlive(playerHealth)) {
		handleDeath(playerHealth, weapon);
		return 0;
	}

	cout << "Press Enter to move onto the next level...";
	// cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears input buffer
	cin.get(); // Waits for user to press Enter

	//Level Three 
	cout << "\nWelcome to level three." << endl;
	cout << "While you're in the cave, you hear screaming and see bloodhounds chasing people! What will you do?" << endl;
	cout << "\n";
	cout << "a) Go investigate what's happening" << endl;
	cout << "b) Stay in your cave and lay low" << endl;
	cout << "c) Run with a group of people" << endl;
	do {
		cout << "\nEnter your choice (a, b, or c): ";
		choiceThree = getUserInput();  // your function already lowercases input
		if (choiceThree != "a" && choiceThree != "b" && choiceThree != "c") {
			cout << "Invalid input. Please enter a, b, or c." << endl;
		}
	} while (choiceThree != "a" && choiceThree != "b" && choiceThree != "c");

	if ((choiceOne == "a" && choiceTwo == "c" && choiceThree == "a") || (choiceOne == "a" && choiceTwo == "a" && choiceThree == "a")) {
		cout << "Oh no, the hounds start chasing you! Luckily you outrun them!!" << endl;
		cout << "You are safe." << endl;
	}
	else if ((choiceOne == "a" && choiceTwo == "c" && choiceThree == "b") || (choiceOne == "a" && choiceTwo == "a" && choiceThree == "b")) {
		cout << "A hound sneaks up from behind you and rips it's jaws at you! You have been killed." << endl;
		cout << "You have lost the Hunger Games. TERMINATION - END OF GAME" << endl;
		playerHealth = 0;
		handleDeath(playerHealth, weapon);
		return 0;
	}
	else if (choiceOne == "a" && choiceTwo == "a" && choiceThree == "c") {
		cout << "Oh no! A hound bites you! You have lost all your health." << endl;
		cout << "You have lost the Hunger Games. TERMINATION - END OF GAME" << endl;
		playerHealth = 0;
		handleDeath(playerHealth, weapon);
		return 0;
	}
	else if (choiceOne == "a" && choiceTwo == "c" && choiceThree == "c") {
		cout << "Oh no! A hound bites you! You lose 5 health" << endl;
		playerHealth -= 5;
	}
	else if ((choiceOne == "b" || choiceOne == "c") && ((choiceTwo == "a" || choiceTwo == "c") && choiceThree == "a")) {
		cout << "Oh no, the hounds start chasing you! Luckily you outrun them!!" << endl;
		cout << "You are safe." << endl;
	}
	else if ((choiceOne == "b" || choiceOne == "c") && ((choiceTwo == "a" || choiceTwo == "c") && choiceThree == "b")) {
		cout << "A hound sneaks up from behind you and rips it's jaws at you! You have been killed." << endl;
		cout << "You have lost the Hunger Games. TERMINATION - END OF GAME" << endl;
		playerHealth = 0;
		handleDeath(playerHealth, weapon);
		return 0;
	}
	else if ((choiceOne == "b" || choiceOne == "c") && ((choiceTwo == "a" || choiceTwo == "c") && choiceThree == "c")) {
		cout << "Oh no! A hound bites you! You lose the rest of your health." << endl;
		cout << "You have lost the Hunger Games. TERMINATION - END OF GAME" << endl;
		playerHealth = 0;
		handleDeath(playerHealth, weapon);
		return 0;
	}

	playerStats(playerHealth, weapon);

	if (!isAlive(playerHealth)) {
		handleDeath(playerHealth, weapon);
		return 0;
	}

	cout << "Press Enter to move onto the final level...";
	// cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears input buffer
	cin.get(); // Waits for user to press Enter

	//Level Four (Final Level)
	cout << "\nCongratulations. You have made it to the final level." << endl;
	cout << "To win the games you must kill the last hound." << endl; 
	cout << "Make your choice:" << endl; 
	cout << "\n";
	cout << "a) Run away from the hound and go to the cornucopia" << endl;
	cout << "b) Attack the hound" << endl; 
	cout << "c) Trap the hound using a snare" << endl; 
	do {
		cout << "\nEnter your choice (a, b, or c): ";
		choiceFour = getUserInput();  // your function already lowercases input
		if (choiceFour != "a" && choiceFour != "b" && choiceFour != "c") {
			cout << "Invalid input. Please enter a, b, or c." << endl;
		}
	} while (choiceFour != "a" && choiceFour != "b" && choiceFour != "c");

	if (((choiceOne == "a" && choiceTwo == "c" && choiceThree == "a") || (choiceOne == "a" && choiceTwo == "a" && choiceThree == "a")) && choiceFour == "a") {
		cout << "Oh No! You start running but the hounds are faster!" << endl;
		cout << "You have lost the Hunger Games. TERMINATION - END OF GAME" << endl;
		playerHealth = 0;
		handleDeath(playerHealth, weapon);
		return 0;
	}
	else if ((choiceOne == "a" && choiceTwo == "c" && choiceThree == "a") || (choiceOne == "a" && choiceTwo == "a" && choiceThree == "a") && choiceFour == "b") {
		cout << "You attack the hound with your axe!" << endl; 
		cout << "It attempts to bite back, but with a final slash, you kill it!" << endl; 
		cout << "Lights flash around you, and you hear the echoes of cheering!" << endl; 
		cout << "\n";
		cout << "Congrats! YOU HAVE WON THE GAMES" << endl;
		cout << "\n";
		return 0;
	}
	else if ((choiceOne == "a" && choiceTwo == "c" && choiceThree == "a") || (choiceOne == "a" && choiceTwo == "a" && choiceThree == "a") && choiceFour == "c") {
		cout << "You quickly grab a snare pulling it over the hound!" << endl; 
		cout << "It's jaws viciously snap at you, scratching your arms" << endl; 
		cout << "But you have it trapped and with a swift kick, you kill the hound" << endl; 
		cout << "Lights flash around you, and you hear the echoes of cheering!" << endl;
		cout << "\n";
		cout << "Congrats! YOU HAVE WON THE GAMES" << endl;
		cout << "\n";
		return 0;
	}
	else if ((choiceOne == "a" && choiceTwo == "c" && choiceThree == "c") && choiceFour == "a") {
		cout << "Oh No! You start running but the hounds are faster!" << endl;
		cout << "You have lost the Hunger Games. TERMINATION - END OF GAME" << endl;
		playerHealth = 0;
		handleDeath(playerHealth, weapon);
		return 0;
	}
	else if ((choiceOne == "a" && choiceTwo == "c" && choiceThree == "c") && choiceFour == "b") {
		cout << "You attack the hound with your axe!" << endl;
		cout << "It attempts to bite back, but with a final slash, you kill it!" << endl;
		cout << "Lights flash around you, and you hear the echoes of cheering!" << endl;
		cout << "\n";
		cout << "Congrats! YOU HAVE WON THE GAMES" << endl;
		return 0;
	}
	else if ((choiceOne == "a" && choiceTwo == "c" && choiceThree == "c") && choiceFour == "c") {
		cout << "You quickly grab a snare pulling it over the hound!" << endl;
		cout << "It's jaws viciously snap at you, scratching your arms" << endl;
		cout << "But you have it trapped and with a swift kick, you kill the hound" << endl;
		cout << "Lights flash around you, and you hear the echoes of cheering!" << endl;
		cout << "\n";
		cout << "Congrats! YOU HAVE WON THE GAMES" << endl;
		return 0;
	}
	else if (((choiceOne == "b" || choiceOne == "c") && ((choiceTwo == "a" || choiceTwo == "c") && choiceThree == "a")) && choiceFour == "a") {
		cout << "Oh No! You start running but the hounds are faster!" << endl;
		cout << "You have lost the Hunger Games. TERMINATION - END OF GAME" << endl;
		playerHealth = 0;
		handleDeath(playerHealth, weapon);
		return 0;
	}
	else if (((choiceOne == "b" || choiceOne == "c") && ((choiceTwo == "a" || choiceTwo == "c") && choiceThree == "a")) && choiceFour == "b") {
		cout << "You attack the hound with your fists! But it bites back, viciously ripping your hands apart!" << endl; 
		cout << "Oh No! The hound kills you" << endl; 
		cout << "You have lost the Hunger Games. TERMINATION - END OF GAME" << endl;
		playerHealth = 0;
		handleDeath(playerHealth, weapon);
		return 0;
	}
	else if (((choiceOne == "b" || choiceOne == "c") && ((choiceTwo == "a" || choiceTwo == "c") && choiceThree == "a")) && choiceFour == "c") {
		cout << "You quickly grab a snare pulling it over the hound!" << endl;
		cout << "It's jaws viciously snap at you, scratching your arms" << endl;
		cout << "But you have it trapped and with a swift kick, you kill the hound" << endl;
		cout << "Lights flash around you, and you hear the echoes of cheering!" << endl;
		cout << "\n";
		cout << "Congrats! YOU HAVE WON THE GAMES" << endl;
		return 0;
	}
	playerStats(playerHealth, weapon, true); 
	cout << "Thank you for playing my game!" << endl; 
	return 0;

}
