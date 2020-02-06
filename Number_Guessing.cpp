#include<iostream>
#include<ctime>
#include <string.h>
using namespace std;

int main() {
	int language;
	while (1) {
		cout << "Select language 選擇語言 (國語請按1；Press 2 for English)：";
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin >> language;
		if (language < 3 && language>0) {
			break;
		}
		else {
			cout << "Input Error!! 輸入錯誤!!" << endl << endl;
			continue;
		}
	}

	int playAgain;
	do {
		system("cls");
		cout << "============= 1A2B =============" << endl;
		//generate answer
		srand(time(NULL));
		int answer[4];
		int counter = 0;
		bool answer_legal;

		do {
			answer_legal = true;
			answer[counter] = (rand() % 10);

			//check if answer[counter] is different with other digits
			for (int i = 0; i < counter; i++) {
				if (answer[counter] == answer[i]) {
					answer_legal = false;
				}
			}

			//It's also illegal if answer[counter] is 0
			if (answer_legal == false || answer[counter] == 0) {
				continue;
			}
			counter++;
		} while (counter < 4);
		
		//print the answer directily
		//cout << answer[0] << answer[1] << answer[2] << answer[3] << endl << endl;

		//let users guess the answer
		char in[5];
		//in[3] = '\0';
		bool win = false;
		while (!win) {
			memset(in, '\0', sizeof(in));
			in[4] = '\0';
			bool check_integer = true;
			bool check_unduplicated = true;
			bool notMoreThanFourChar = true;
			bool notLessThanFourChar = true;
			int A = 0, B = 0;

			switch (language) {
			case 1:
				cout << "請輸入4個數字：" ;
				break;
			case 2:
				cout << "Please input 4 digit number: ";
				break;
			}
			
			cin >> in;
			cout << in << "： ";
			//Change the value from ascii code to the real number
			int input[4] = { in[0] - 48, in[1] - 48,in[2] - 48,in[3] - 48};

			//check if the user input more than 4 characters
			if (in[4] != '\0') {
				notMoreThanFourChar = false;
			}
			//check if the user input less than 4 characters
			if (in[3] == '\0') {
				notLessThanFourChar = false;
			}
			//check if input[i] is an integer
			for (int i = 0; i < 4; i++) {
				if (input[i] < 1 || input[i] > 9) {
					check_integer = false;
				}
			}
			//check if there are same numbers in input[]
			for (int i = 0; i < 4; i++) {
				for (int j = (i + 1); j < 4; j++) {
					if (input[i] == input[j]) {
						check_unduplicated = false;
					}
				}
			}

			if (!notMoreThanFourChar||!notLessThanFourChar) {
				switch (language) {
				case 1:
					cout << "輸入錯誤！需數入4個整數。" << endl << endl;
					break;
				case 2:
					cout << "Input error! 4 integers please!" << endl << endl;
					break;
				}
				continue;
			}
			if (!check_integer) {
				switch (language) {
				case 1:
					cout << "輸入錯誤！只能輸入1～9。" << endl << endl;
					break;
				case 2:
					cout << "Input error! 1～9 only!" << endl << endl;
					break;
				}
				continue;
			}
			if (!check_unduplicated) {
				switch (language) {
				case 1:
					cout << "輸入錯誤！需輸入不同的數字。" << endl << endl;
					break;
				case 2:
					cout << "Input error! Different please!" << endl << endl;
					break;
				}
				continue;
			}

			//count the number of A and B
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (input[i] == answer[j]) {
						if (input[i] == answer[i]) {
							A++;
						}
						else {
							B++;
						}
					}
				}
			}
			cout << A << "A" << B << "B" << endl;
			if (A == 4) {
				win = true;
				switch (language) {
				case 1:
					cout << "恭喜你贏了！";
					break;
				case 2:
					cout << "You win!!!";
					break;
				}
			}
			cout << endl;
		}

		//ask whether the user want to play again or not?
		while (1) {
			switch (language) {
			case 1:
				cout << endl << "再玩一次？(1:Yes 2:No)：";
				break;
			case 2:
				cout << endl << "Do you want to play again? (1:Yes 2:No)：";
				break;
			}
			playAgain = 0;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cin >> playAgain;
			if (playAgain < 3 && playAgain>0) {
				cout << endl << endl;
				break;
			}
			else {
				switch (language) {
				case 1:
					cout << "輸入錯誤！" << endl << endl;
					break;
				case 2:
					cout << "Input Error!!" << endl << endl;
					break;
				}
				continue;
			}
		}
	} while (playAgain == 1);

	system("pause");
	return 0;
}