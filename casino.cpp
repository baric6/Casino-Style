/*
*Baric
*Cis 1111
*April-30-2018
*/

#include <iostream>
#include <ctime>
#include <cmath> 
#include <fstream>

using namespace std;

//protoypes
void game(int lottery_arr[], int lottery_size, int count, int srand);
void game(int srand, int count, int choise_spinner);
void horse_race(int srand, int count, int choice_horse);
void horse_time(int choice_horse, int winning_num);

int main() {

	unsigned count;
	int srand(time(0));

	int choice_switch;

	//lottery varables
	const int lottery_size = 5;
	int lottery_arr[lottery_size] = { 0 };
	////////////////////////////////////

	//slots varables
	int choise_spinner = 1;
	///////////////////////////////////

	//horse varables
	int choice_horse = 0;
	///////////////////////////////////


	cout << "\t\t==========================" << endl;
	cout << "\t\tWelcome to Grand ol Casino" << endl;
	cout << "\t\t==========================" << endl << endl;

	cout << "When you return to HOME menu your Tokens will be restored.." << endl << endl;
	cout << "The Game takes 1 Tokens each round of the instance.. " << endl << endl;
	cout << "How many Tokens you want to play with? ";
	cin >> count;

	system("cls");

	//while (count > 0) {

		char choice_user = 'y';
		while (choice_user == 'y' || choice_user == 'Y') {


			cout << "\t\t==========================" << endl;
			cout << "\t\tWelcome to Grand ol Casino" << endl;
			cout << "\t\t==========================" << endl << endl;

			cout << "Player Tokens: " << count << endl << endl;

			cout << "Press 1 to play The South-Park Lottry" << endl;
			cout << "Press 2 to play The Golden-Grail Slots" << endl;
			cout << "Press 3 to play The Red-Rider Horse-Track" << endl << endl;
			cout << "Press 4 to exit" << endl;

			cout << endl;

			cout << "Enter Your Choice Here: ";
			cin >> choice_switch;

			system("cls");

			if (choice_switch > 0 || choice_switch < 4) {

				switch (choice_switch) {
				case 1:
					//south-park lottery
					game(lottery_arr, lottery_size, count, srand);
					break;

				case 2:
					//cout << "slots remember to connect....lol 
					game(srand, count, choise_spinner);
					break;

				case 3:
					//cout << "game three " << endl;
					horse_race(srand, count, choice_horse);
					break;

				}
			}

			cout << "\t\t===============" << endl;
			cout << "\t\tGrand ol Casino" << endl;
			cout << "\t\t===============" << endl << endl;
			//if <= 0
			cout << "Please press 'y' to go back to the main menu.....Or 'q' to quit ";
			cin >> choice_user;

			system("cls");
		}

		
	}

void game(int lottery_arr[], int lottery_size, int count, int srand) {

	int i;

	char lottery_choice = 'y';
	while (lottery_choice == 'y' || lottery_choice == 'Y') {
		//
		cout << "\t\t=============================" << endl;
		cout << "\t\tWelcome to South-Park Lottery" << endl;
		cout << "\t\t=============================" << endl << endl;

		cout << "Player Tokens: " << count << endl << endl;

		cout << "**Instructions**" << endl;
		cout << "Enter five numbers 0-100....." << endl;
		cout << "Trying to match them with our Random number Drawing System....." << endl << endl;
		cout << "Hitting enter after every number....." << endl;

		for (i = 0; i < lottery_size; i++) {
			//cant figure out how to keep numbers within 0-100, if statement dose nothing 

			cout << "Enter number: ";
			cin >> lottery_arr[i];

			while (lottery_arr[i] < 0 || lottery_arr[i] >= 100) {
				cout << "please enter a valid number between 0 - 100 " << endl;
				cin >> lottery_arr[i];
			}
		}

		int number1 = rand() % 101;
		int number2 = rand() % 101;
		int number3 = rand() % 101;
		int number4 = rand() % 101;
		int number5 = rand() % 101;

		if (lottery_arr[0] == number1) {

			if (lottery_arr[1] == number2) {

				if (lottery_arr[2] == number3) {

					if (lottery_arr[3] == number4) {

						if (lottery_arr[4] == number5) {
							cout << endl;
							cout << "You got all five numbers right congrats, you win nothing, but good effort " << endl;
							cout << endl;
						}
						else {
							cout << endl;
							cout << "Sorry you didnt match the fifth number......." << endl;
							cout << endl;
						}
					}
					else {
						cout << endl;
						cout << "Sorry you didnt match the forth number......." << endl;
						cout << endl;
					}
				}
				else {
					cout << endl;
					cout << "Sorry you didnt match the third number......." << endl;
					cout << endl;
				}
			}
			else {
				cout << endl;
				cout << "Sorry you didnt match the second number......." << endl;
				cout << endl;
			}
		}
		else {
			cout << endl;
			cout << "Sorry you didnt match the first number......." << endl;
			cout << endl;
		}


		cout << "Winning Numbers: " << number1 << " " << number2 << " " << number3 << " " << number4 << " " << number5;

		cout << endl << endl;
		//if
		cout << "Please press 'y' to keep gambling on the lottery...Or put 'q' to go back....: " << endl;
		cin >> lottery_choice;

		cout << endl;
		//move up
		count--;

		system("cls");
	}
}
void game(int srand, int count, int choise_spinner) {


	while (choise_spinner == 1) {

		cout << "\t\t==================" << endl;
		cout << "\t\tGolden Grail Slots" << endl;
		cout << "\t\t==================" << endl << endl;

		cout << "**Instructions**" << endl;
		cout << "Press 1 to put a token into game..." << endl;
		cout << "There is a Anti-Cheat system so remember to play fair, You will be recorded......" << endl;

		//ofstream
		ofstream write;
		write.open("slots-anti-cheat.txt");

		int slot_spinner1 = rand() % 3;
		int slot_spinner2 = rand() % 3;
		int slot_spinner3 = rand() % 3;

		write << slot_spinner1 << " " << slot_spinner2 << " " << slot_spinner3 << endl;


		//ifstream
		ifstream read;

		read.open("slots-anti-cheat.txt");

		int sp1, sp2, sp3;

		while (read >> sp1) {

			read >> sp2;
			read >> sp3;
		}
		read.close();

		cout << endl;

		cout << "Player Tokens: " << count << endl;
		cout << "\t\t_________" << endl;
		cout << "\t\t|" << sp1 << "||" << sp2 << "||" << sp3 << "|o" << endl;
		cout << "\t\t|TTTTTTT||" << endl;

		if (slot_spinner1 == slot_spinner2 && slot_spinner1 == slot_spinner3 && slot_spinner2 == slot_spinner3) {
			cout << "\t\t You Win " << endl << endl;

			count++;
		}
		else {
			cout << "\t\t You Lose " << endl << endl;

			count--;
		}

		cout << "Please press '1' to keep sloting it up....Or '0' to quit ";
		cin >> choise_spinner;

		system("cls");
	}
}
void horse_race(int srand, int count, int choice_horse) {
	//int choice_horse;

	char user_playing = 'y';
	while (user_playing == 'y' || user_playing == 'Y') {

		cout << "\t\t=================================" << endl;
		cout << "\t\tWelcome to Red-Rider Horse Track " << endl;
		cout << "\t\t=================================" << endl << endl;

		cout << "**Instructions**" << endl;
		cout << "Pick one of the five horses and see if your horse won " << endl;

		cout << endl;

		cout << "Player Tokens " << count << endl << endl;
		cout << "Pick a horse you would like to bet on...... " << endl << endl;
		cout << "Press 0 for Butter-cup " << endl;
		cout << "Press 1 for MR.ED " << endl;
		cout << "Press 2 for Skipper  " << endl;
		cout << "Press 3 for White-lighting " << endl;
		cout << "press 4 for Gun-Ho " << endl;
		cin >> choice_horse;


		int winning_num = rand() % 5;

		if (choice_horse == winning_num) {
			cout << endl;
			cout << "You picked the winning horse......Congrats " << endl << endl;

			count++;
		}
		else {
			cout << endl;
			cout << "Your horse didnt win the race.....Play again to try your luck " << endl << endl;
			
			count--;
		}
		cout << "The winning horse was number: " << winning_num << endl << endl;

		//fuction in a fuction
		horse_time(choice_horse, winning_num);

		cout << "Press 'y' to keep gambling or Press 'q' to quit ";
		cin >> user_playing;
		system("cls");
	}
}
void horse_time(int choice_horse, int winning_num) {
	double final_time = pow(choice_horse, 6) + 9;
	//1000ms = 1s
	cout << "Horse "<< winning_num <<" passed the finish line in "<<final_time<< " milliseconds before the others" << endl << endl;
}
