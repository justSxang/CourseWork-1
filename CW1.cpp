// This is a mystery game with a brute-forced bot
    //that helps the players guess the right person, room, and weapon involved in the crime.


#include <iostream>
#include <string>
#include <cstdlib>  
#include <ctime>    
#include <chrono>
#include <thread>

using namespace std;

void display() {
    cout << "  " << endl;
    cout << "Weapons: Knife, Gun, Toothbrush, Pillow, Grass Cutter  " << endl;
    cout << "Rooms: Living Room, Kitchen, Dining Room, Bedroom, Guest Room " << endl;
    cout << "Persons: Nana, Ms. Yu, Mr. Eius"  << endl;
    cout << " " << endl;
}

int main() {

    cout << "Welcome to the Murder Mystery Game!" << endl;
    cout << "Things to keep in mind:" << endl;
    cout << "   - There are 5 rooms in the house where the murder could have happened. " << endl;
    cout << "   - There are 5 suspected weapons that have been used by the suspect. " << endl;
    cout << "   - There are 3 possible suspects. " << endl;
    display();

    string room[5];
    string weapon[5];
    string person[3];
    int player[3];

    room[0] = "Living Room";
    room[1] = "Kitchen";
    room[2] = "Dining Room";
    room[3] = "Bedroom";
    room[4] = "Guest Room";

    weapon[0] = "Knife";
    weapon[1] = "Gun";
    weapon[2] = "Toothbrush";
    weapon[3] = "Pillow";
    weapon[4] = "Grass Cutter";

    person[0] = "Nana";
    person[1] = "Ms. Yu";
    person[2] = "Mr. Eius";

    srand(static_cast<unsigned int>(time(nullptr))); 

    int randNum4Room = (rand() % 5);  
    int randNum4Weapon = (rand() % 5);  
    int randNum4Person = (rand() % 3);  

    string weaponUsed = weapon[randNum4Weapon]; 
    string cursedRoom = room[randNum4Room]; 
    string suspect = person[randNum4Person]; 


    cout << "Press Enter to Start" << endl;
    cin.get();



    //*****NEW ARRAY*****//
    string safeWeapon[5]; 
    string safeRoom[5];
    string safePerson[3];

    for (int i = 0; i < 5; i++) {
        safeWeapon[i] = weapon[i];
    }    
    for (int i = 0; i < 5; i++) {
        safeRoom[i] = room[i];
    }
    for (int i = 0; i < 3; i++) {
        safePerson[i] = person[i];
    }
    //-----NEW ARRAY-----//

    //*****REMOVE*****//
    //*****removeWeapon****//
    int index_to_remove = randNum4Weapon; 
    int n = 5;
    if (index_to_remove >= 0 && index_to_remove < n) {
        
        for (int i = index_to_remove; i < n - 1; i++) {
            safeWeapon[i] = safeWeapon[i + 1]; }
    }

    //*****removeRoom*****//
    index_to_remove = randNum4Room; 
    n = 5;
    if (index_to_remove >= 0 && index_to_remove < n) {
        
        for (int i = index_to_remove; i < n - 1; i++) {
            safeRoom[i] = safeRoom[i + 1]; }
    }

    //*****removePerson*****//
    index_to_remove = randNum4Person; 
    n = 3;
    if (index_to_remove >= 0 && index_to_remove < n) {
        
        for (int i = index_to_remove; i < n - 1; i++) {
            safePerson[i] = safePerson[i + 1]; }
        n--; 
    }
    //-----REMOVE-----//

    //*****CLUES*****//
    string clueWeapon[5];
    string clueRoom[5]; 
    string cluePerson[3];

    n = 4;
    for(int i = 0; i < 2; i++) {
        randNum4Room = (rand() % n);  
        randNum4Weapon = (rand() % n);  

        clueRoom[i] = safeRoom[randNum4Room];
        clueWeapon[i] = safeWeapon[randNum4Weapon];

        int index_to_remove = randNum4Weapon; 
        if (index_to_remove >= 0 && index_to_remove < n) {
            
            for (int i = index_to_remove; i < n - 1; i++) {
                safeWeapon[i] = safeWeapon[i + 1]; }
        }
        index_to_remove = randNum4Room; 
        if (index_to_remove >= 0 && index_to_remove < n) {
            
            for (int i = index_to_remove; i < n - 1; i++) {
                safeRoom[i] = safeRoom[i + 1]; }
        }
        n--; 
    }

    randNum4Person = (rand() % 2);
    cluePerson[0] = safePerson[randNum4Person];
    n = 2;
    if (randNum4Person == 0) {
        safePerson[0] = safePerson[1];
        safePerson[1] = " ";
    } else {
        safePerson[1] = " ";
    }

    int clueWeaponNum = 2;
    int clueRoomNum = 2;
    int cluePersonNum = 1;
    //-----CLUES-----//


    bool isMurderSolved = false;

    while (!isMurderSolved) {
        cout << "Choose your action:" << endl;
        cout << "1. Show list of Clues" << endl;
        cout << "2. Ask bot for clues" << endl;
        cout << "3. Make an accusation" << endl;
        cout << "4. Accept Defeat and Reveal the Truth \t -> " << ends;

        int choice;
        cin >> choice;
        int cont;
        int chosenWeapon;
        int chosenRoom;
        int chosenPerson;

        switch (choice) {
            case 1:
                system("cls");
                display();
                cout << " " << endl;
                cout << "CLUE: " << endl;
                cout << "These weapons are not used: " << ends;
                if (clueRoomNum <= 4) {
                    for (int i = 0; i < clueWeaponNum; i++) {
                        cout << clueWeapon[i] << ", ";
                    } cout << " " << endl;
                    if (clueWeapon[4] == weaponUsed)
                        cout << "\t " << weaponUsed << " is the weapon used." << endl;
                }

                cout << "The crime scene did not happen here: " << ends;
                if (clueRoomNum <= 4) {
                    for (int i = 0; i < clueRoomNum; i++) {
                        cout << clueRoom[i] << ", ";
                    } cout << " " << endl;
                    if (clueRoom[4] == cursedRoom)
                    cout << "\t " << cursedRoom << " is the right room." << endl;
                }
                cout << "The person mentioned is innocent: " << ends;
                for (int i = 0; i < cluePersonNum; i++) {
                    cout << cluePerson[i] << ", ";
                } cout << " " << endl;
                if (cluePerson[2] == suspect)
                    cout << "\t " << suspect << " is the killer." << endl;
                cout << " " << endl;
                break;
            case 2:
                cout << " " << endl;
                if (clueWeaponNum >= 4 && clueRoomNum >= 4 && cluePersonNum >= 2) {
                    cout << "You already have all the clues, please proceed to making an accusation. " << endl;
                    cout << " " << endl;
                    break;
                }
                else if (clueWeapon[4] == weaponUsed && clueRoom[4] == cursedRoom && cluePerson[4] == suspect)
                {
                    cout << "You have the clues you need, please proceed to making an accusation. " << endl;
                    cout << " " << endl;
                    break;
                }
                else {
                    cout << "Which weapon do you think the suspect used in killing? " << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << "[" << i+1 << "]" << weapon[i] << "\t" ;
                    } cout << "\t\t -> " << ends;
                    cin >> chosenWeapon;
                    cout << "Where do you think the crime scene took place? " << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << "[" << i+1 << "]" << room[i] << "\t" ;
                    } cout << "\t -> " << ends;
                    cin >> chosenRoom;
                    cout << "Who do you think is the killer? " << endl;
                    for (int i = 0; i < 3; i++) {
                        cout << "[" << i+1 << "]" << person[i] << "\t\t" ;
                    } cout << "\t\t\t -> " << ends;
                    cin >> chosenPerson;
                cout << " " << endl;
                cout << " " << endl;
                }
                if(chosenWeapon > 5 || chosenRoom > 5 || chosenPerson > 3)
                {
                    cout << "Invalid Choice.\n" << endl;
                    break;
                }
                if(weapon[chosenWeapon - 1] == weaponUsed && room[chosenRoom - 1] == cursedRoom && person[chosenPerson - 1] == suspect)
                {
                    cout << "Wow! You guessed it all right! " << endl;
                    clueWeapon[4] = weaponUsed;
                    clueRoom[4] = cursedRoom;
                    cluePerson[2] = suspect;
                }
                else if (weapon[chosenWeapon - 1] == weaponUsed || room[chosenRoom - 1] == cursedRoom || person[chosenPerson - 1] == suspect)
                {
                    int correct = 0;
                    if (weapon[chosenWeapon - 1] == weaponUsed)
                        correct++;
                    if (room[chosenRoom - 1] == cursedRoom)
                        correct++;
                    if (person[chosenPerson - 1] == suspect)
                        correct++;
                    cout << "You have " << correct << " correct guesses." << endl;
                }
                else
                    cout << "You guessed nothing correctly." << endl;
                cout << " " << endl;

                break;
            case 3:
                cout << " " << endl;
                cout << "What weapon did the killer used? " << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << "[" << i+1 << "]" << weapon[i] << "\t" ;
                    } cout << "\t\t -> " << ends;
                    cin >> chosenWeapon;
                cout << "Where did the crime scene happened? " << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << "[" << i+1 << "]" << room[i] << "\t" ;
                    } cout << "\t -> " << ends;
                    cin >> chosenRoom;
                cout << "Who is the killer? " << endl;
                    for (int i = 0; i < 3; i++) {
                        cout << "[" << i+1 << "]" << person[i] << "\t\t" ;
                    } cout << "\t\t\t -> " << ends;
                    cin >> chosenPerson;
                    cout << " " << endl;
                    if (weapon[chosenWeapon - 1] == weaponUsed && room[chosenRoom - 1] == cursedRoom && person[chosenPerson - 1] == suspect)
                    {
                        cout << "Congratulations! You've solved the murder mystery." << endl;
                        isMurderSolved = true;
                    }
                    else
                    {
                        cout << "You got it wrong. Continue to play?  \t [1] yes [press any key to quit]" << ends;
                        cin >> cont;
                        if (cont == 1)
                        {
                            system("cls");
                            break;
                        }
                        else {
                            system("cls");
                        }
                    }

            case 4:
                cout << " " << endl;
                cout << "Weapon Used: "<< weaponUsed << endl;
                cout << "Room: "<< cursedRoom << endl;
                cout << "Suspect: "<< suspect << endl;
                cout << "Thanks for playing! Come back anytime." << endl;
                return 0;
            default:
                cout << "\nInvalid choice. Please choose a valid option. \n " << endl;
        }
    }
    return 0;
}
