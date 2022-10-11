/****************************
 *
 * HEADER
 *
 * *** **********************/


#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>  
#include <iterator>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ranges>
const std::string rule_msg_1 = R"(The selected password must be at least eight characters long.)";
const std::string rule_msg_2 = R"(The selected password must have at least one uppercase letter.)";
const std::string rule_msg_3 = R"(The selected password must have at least one lowercase letter.)";
const std::string rule_msg_4 = R"(The selected password must have at least one digit.)";
const std::string rule_msg_5 = R"(The selected password must have at least one of special characters: [@,!,#,^,&,*,$])";
const std::string rule_msg_6 = R"(The selected password has been leaked.)";
const std::string rule_msg_7 = R"(The selected password cannot contain a dictionary word.)";

//The goal of this programming assignment is to develop a password checker program that checks how
//strong is the entered password.The password checker have seven rules to evaluate the vulnerability of
//the given password :
//1. The selected password must be at least eight characters long.
//2. The selected password must have at least one uppercase letter.
//3. The selected password must have at least one lowercase letter.
//4. The selected password must have at least one digit.
//5. The selected password must have at least one of these special characters : @, !, #, ^, &, *, or $.
//6. The program has also access to a list of previously leaked passwords and should reject if the
//entered password is already leaked with respect to the list.
//7. The selected password cannot consist of an English word.For example, mybookLet1990!violates
//this rule.A dictionary of words(with at least size of 5) is given.Using shorter English words or
//using any other words that are not in the file is valid.
//Searching large files is an expensive operation, therefore your code must first check the first five criteria
//and then if the entered password satisfies those, the program checks the entered password against rule
//sixand then rule seven.
//The dictionary files(both English and leaked) contain only lowercase words, so when evaluating rule six
//and seven, you should ignore the case of letters.
//The leaked password file is big, so you need to search the file efficiently.Here you must use binary
//search.The leaked password file has been ordered, however, the order is only based on alphabeticaland
//numerical characters(the order ignores the symbols and special characters).Therefore, you need to write
//a compare function that compares the words accordingly(consider only alphabetical or numerical
//	characters in the comparison).You will use this compare function inside your binary search.
//	For example, if maur7007 is in the leaked password file, $Maur7007# will be considered unacceptable.



//This function checks if the given password satisfies the first five rules.
//If the password satisfies the first five rules, the function returns true, otherwise it returns false.

int run(std::string leaked_password_file, std::string english_word_file) {
	int scuffed_count{};
	std::string password_input;
	std::cout << R"(Enter password: )";
	std::cin >> password_input;
	//check if password is at least 8 characters long
	if (password_input.length() < 8) {
		std::cout << rule_msg_1 << std::endl;
		scuffed_count++;
		//return 0;
	}
	//1. The selected password must be at least eight characters long.
	//2. The selected password must have at least one uppercase letter.
	//check if input password contains at least one uppercase letter
	bool has_uppercase = false;
	for (int i = NULL; i < password_input.length(); i++) {
		if (isupper(password_input[i])) {
			has_uppercase = true;
			break;
		}
	}
	if (!has_uppercase) {
		std::cout << rule_msg_2 << std::endl;
		scuffed_count++;
		//return 0;
	}
	//3. The selected password must have at least one lowercase letter.
	//check if input password contains at least one lowercase letter
	bool has_lowercase = false;
	for (int i = NULL; i < password_input.length(); i++) {
		if (islower(password_input[i])) {
			has_lowercase = true;
			break;
		}
	}
	if (!has_lowercase) {
		std::cout << rule_msg_3 << std::endl;
		scuffed_count++;
		//return 0;
	}
	//4. The selected password must have at least one digit.
	// check if input password contains at least one digit
	bool has_digit = false;
	for (int i = NULL; i < password_input.length(); i++) {
		if (isdigit(password_input[i])) {
			has_digit = true;
			break;
		}
	}
	if (!has_digit) {
		std::cout << rule_msg_4 << std::endl;
		scuffed_count++;
		//return 0;
	}
	//5. The selected password must have at least one of these special characters : @, !, #, ^, &, *, or $.
	// check if input password contains at least one special character
	bool has_special_char = false;
	for (int i = NULL; i < password_input.length(); i++) {
		if (password_input[i] == '@' || password_input[i] == '!' || password_input[i] == '#' || password_input[i] == '^' || password_input[i] == '&' || password_input[i] == '*' || password_input[i] == '$') {
			has_special_char = true;
			break;
		}
	}
	if (!has_special_char) {
		std::cout << rule_msg_5 << std::endl;
		scuffed_count++;
		//return 0;
	}
	//remove the special characters from the password_input
	
	//6. The program has also access to a list of previously leaked passwords and should reject if the
	//entered password is already leaked with respect to the list.
	// if the user input password matches any in the leaked password file, then the password is not valid
	// if the user input password does not match any in the leaked password file, then the password is valid

	//copy all the txt from a .txt file
	//read all txt from a txt file
	//check if the user input password matches any in the leaked password file

	//open the leaked password fil

	std::ifstream leaked_password_file_stream(leaked_password_file);
	//check if the file is open
	if (!leaked_password_file_stream.is_open()) {
		std::cout << R"(Error opening file)" << std::endl;
		return NULL;

	}
	
	//read the leaked password file
	std::string leaked_password;
	std::vector<std::string> leaked_passwords;
	while (std::getline(leaked_password_file_stream, leaked_password)) {
		leaked_passwords.push_back(leaked_password);
	}

	//check if the user input password matches any in the leaked password file

	//sort the leaked password file
	//std::sort(leaked_passwords.begin(), leaked_passwords.end(), compare);
	//check if the user input password matches any in the leaked password file

	//binary search the leaked password file
	//check if the password is any of the leaked passwords
	//remove all special characters from the password_input and declare a new string for that
	std::string password_input_no_special_chars;
	for (int i = NULL; i < password_input.length(); i++) {
		if (password_input[i] != '@' && password_input[i] != '!' && password_input[i] != '#' && password_input[i] != '^' && password_input[i] != '&' && password_input[i] != '*' && password_input[i] != '$') {
			password_input_no_special_chars += password_input[i];
		}
	}
	//std::cout << password_input_no_special_chars << std::endl;
	//remove special characters from the strings in the vector of leaked passwords and create a new vector without the numbers
	std::vector<std::string> leaked_passwords_no_special_chars;
	for (int i = NULL; i < leaked_passwords.size(); i++) {
		std::string leaked_password_no_special_chars;
		for (int j = NULL; j < leaked_passwords[i].length(); j++) {
			if (leaked_passwords[i][j] != '@' && leaked_passwords[i][j] != '!' && leaked_passwords[i][j] != '#' && leaked_passwords[i][j] != '^' && leaked_passwords[i][j] != '&' && leaked_passwords[i][j] != '*' && leaked_passwords[i][j] != '$') {
				leaked_password_no_special_chars += leaked_passwords[i][j];
			}
		}
		leaked_passwords_no_special_chars.push_back(leaked_password_no_special_chars);
	}
	//things for debugging
	//std::cout << password_input_no_special_chars << std::endl;
	//std::cout << leaked_passwords_no_special_chars[0] << std::endl;
	// print the vector of leaked passwords without special characters
	//for (int i = NULL; i < leaked_passwords_no_special_chars.size(); i++) {
	//	std::cout << leaked_passwords_no_special_chars[i] << std::endl;
	//}
	// 
	//password_input_no_special_chars to lowercase
	std::transform(password_input_no_special_chars.begin(), password_input_no_special_chars.end(), password_input_no_special_chars.begin(), ::tolower);
	//do the binary search
	if (std::binary_search(leaked_passwords_no_special_chars.begin(), leaked_passwords_no_special_chars.end(), password_input_no_special_chars)) {
		std::cout << rule_msg_6 << std::endl;
		scuffed_count++;
		//return NULL;
	}
	//close the leaked password file
	leaked_password_file_stream.close();
	//7. The selected password cannot consist of an English word.For example, mybookLet1990!violates

	std::ifstream english_words_file_stream(english_word_file);
	//check if the file is open
	if (!english_words_file_stream.is_open()) {
		std::cout << R"(Error opening file)" << std::endl;
		return 0;
	}
	//read the leaked password file
	std::string english_word;
	std::vector<std::string> english_words;
	while (std::getline(english_words_file_stream, english_word)) {
		english_words.push_back(english_word);
	}
	//close the leaked password file
	//check if the user input password matches any in the leaked password file
	//use binary search to figure out if any of the words in the english word dictionary are in the password
	//if the password is in the english word dictionary, then the password is not valid
	//if any word inside the vector of english words file is in the password, then the Password is rejected! using binary search
	//if the password is not in the english word dictionary, then the password is valid
	//if any word in the english word list is in the user input password, then the password is not valid
	//if the password is not in the english word dictionary, then the password is valid
	//remove numbers from the password_input and declare a new string for that
	std::string password_input_no_numbers;
	for (int i = NULL; i < password_input_no_special_chars.length(); i++) {
		if (!isdigit(password_input_no_special_chars[i])) {
			password_input_no_numbers += password_input_no_special_chars[i];
		}
	}
	if (std::binary_search(english_words.begin(), english_words.end(), password_input_no_numbers)) {
		std::cout << rule_msg_7 << std::endl;
		scuffed_count++;
		//return NULL;
	}
	english_words_file_stream.close();
	//output the password is valid or invalid if it doesnt pass a test above
	if (scuffed_count == NULL) {
		std::cout << R"(Password accepted!)" << std::endl;
	}
	else {
		std::cout << R"(Password rejected!)" << std::endl;
	}
	return NULL;
}

int main() {
	/** Change the address of the files appropriatly based on your local machine.
	 * This main function will be replaced during testing. Do not add any line of code to the main function
	 **/
	const std::string leaked_password_file = R"(alleged-gmail-passwords.txt)"; //change this based on the location of the file on your machine
	const std::string english_word_file = R"(words_5.txt)"; //change this based on the location of the file on your machine
	run(leaked_password_file, english_word_file);
	return NULL;
}