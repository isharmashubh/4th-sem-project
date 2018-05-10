#include <iostream>
using namespace std;
#include<string.h>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<cstring>


class passkey{
private:
	int password,key;
public:
	passkey();
	void getKey();
	friend void encrypt(passkey );
	friend void decrypt(passkey );

}file1;

passkey::passkey(){
	password = 6598;
}
void passkey::getKey(){
	cout << "Enter the key"<< endl;
	cin >> key;
}


string filename;

int main(){

	int pw,a;
	string c;
	cout << "Enter the correct password to get the options" << endl;
	cin >> pw;
	if(pw!=6598){
		cout << "The password you entered is not correct" << endl;
		return 0;
	}


	cout << "Press 1 for Encryption" << endl << "Press 2 for Decryption" << endl << "Press 3 to quit the program" << endl;
    cin >> a;
	
	if(a==1){
		file1.getKey();

		cout << "Enter the name of your file" << endl;
		cin >> filename;

		ofstream ourfile(filename);
		cout << "Enter data to your file" << endl;
		while(cin >> c){
			ourfile << c << " ";
		}
		ourfile.close();
		encrypt(file1);
		return 0;

	} //encryption


	else if(a==2){

		file1.getKey();
		cout << "Enter the name of the file to be decrypted" << endl;
		cin >> filename;
		decrypt(file1);
		return 0;
	}
	else if(a==3){
		cout << "Program is terminated" << endl;
		return 0;
	}
	else{
		cout << "The option you entered is invalid" << endl;
		return 0;
	}

}


void encrypt(passkey file){

	string encfilename = "Encrypted_";
	int n;
	srand(file.key);
	
	ifstream ourfile(filename);
	
	char ch[50] = "";
	
	ofstream encryptedFile(encfilename);

	ourfile.getline(ch,49);
	do{
		n = 1+rand()%9;
		for(int i=0; i<strlen(ch); i++){
			ch[i] = ch[i] + n;
		}
		encryptedFile << ch;
	}
	while(ourfile.getline(ch,49));
	

	encryptedFile.close();
	
	ourfile.close(); 
	//strcat(encfilename,ourfile);
	cout << "File successfully encrypted" << endl;
	cout << "Encrypted file stored in file with name" << encfilename << endl;


}


void decrypt(passkey file){

	string decfilename = "Decrypted_";
	int m;
	srand(file.key);

	ifstream encryptFile(filename);

	char ch[50] = "";

	ofstream decryptedFile(decfilename);

	encryptFile.getline(ch,49);

	do{
		m = 1+rand()%9;
		for(int i=0;i<strlen(ch);i++){
			ch[i] = ch[i]-m;
		}
		decryptedFile << ch;
	}
	while(encryptFile.getline(ch,49));

	decryptedFile.close();
	encryptFile.close();

	//strcat(decfilename, filename);

	cout << "File successfully decrypted" << endl;

	cout << "Decrypted file stored with name" << decfilename << endl;


}




