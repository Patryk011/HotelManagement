// ProjektBazaHotelu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <conio.h>
#include <cstring>


using namespace std;



int COUNTER = 0;

struct GuestData { 

    int age;
    int fee;
    char firstName[25];
    char lastName[25];
    int type;
    bool parking;
    struct GuestData* next;
    struct GuestData* prev;


};

struct GuestData* ELEMENTS_LIST = NULL;

struct Guest {
    GuestData data;
    Guest* next;
};

struct Access {
    Access* next;
};

typedef Guest* pointer;
typedef Access* pointerA;




void insert_Front(struct GuestData** head, )




GuestData guestData() {

    GuestData data;
    Facilities access;
    char o;
    int w;


    cout << "Podaj wiek: ";
    cin >> data.age;

    if (data.age < 18)
        cout << "Aby sie zarejestrowac musisz miec conajmnmiej 18 lat." << endl;
    else
        cout << "Podaj imie: ";
    cin >> data.firstName;
    cout << "Podaj nazwisko";
    cin >> data.lastName;

    cout << "Podaj opcje ktora Cie interesuje (1 - Pojedynczy pokoj (150zl), 2 - Pokoj dwuosobowy (250zl), 3 - Apartament (350zl), 4 - Pokoj rodzinny (350zl). : ";
    cin >> w;

    while (w > 4) {
        cout << "Podana opcja nie istnieje, sprobuj jeszcze raz";

        if (w == 1 && access.singleRoom != 0) {
            data.fee += 150;
            data.room = "single";
            access.singleRoom -= 1;
        }
        if (w == 2 && access.doubleRoom != 0) {
            data.fee += 250;
            data.room = "double";
            access.doubleRoom -= 1;
        }
        if (w == 3 && access.apartament != 0) {
            data.fee += 350;
            data.room = "apartament";
            access.apartament -= 1;
        }
        if (w == 4 && access.family != 0) {
            data.fee += 350;
            data.room = "family";
            access.family -= 1;
        }
    }

    cout << "Czy chcesz rowniez zarezerwowac miejsce parkingowe ? (T/N): ";

    do

    {
        cin >> o; 
        o = toupper(_getch());

    } while (o != 'T' && o != 'N'); {
        cout << "Mozesz podac tylko T (tak) lub N (nie). Sprobuj jeszcze raz.";
        cin >> o;
        if (o == 'N') {
            data.parking = "Nie";
        }
        else {
            data.parking = "Tak";
            data.fee += 20;

        }

        return data;
       
    }
}



void addGuest(pointer* guests, GuestData data) {
    if ((*guests) == NULL) {
       pointer newGuest;
       newGuest = (Guest*)malloc(sizeof(Guest));
        newGuest->data = data;
        newGuest->next = NULL;
        (*guests) = newGuest;
       }
        else
          addGuest(&(*guests)->next, data);
  }
        

void showGuests(pointer guests) {
    if (guests == NULL) {
        cout << "W bazie nie ma zadnych gosci";
    }
    while (guests != NULL) {
        cout << guests->data.firstName << " " << guests->data.lastName;
        cout << "Pokoj: " << guests -> data.room;
        cout << "Oplata: " << guests -> data.fee;
        cout << "Parking: " << guests->data.parking;
    }
}





void saveGuestToFile(pointer guests) {

    FILE* file;
    int size = sizeof(GuestData);
    file = fopen("guests.dat", "wb");
    if (file == NULL)
        return;
    while (guests != NULL) {
        fwrite(&(guests->data), size, 1, file);
        guests = guests->next;
    }
    fclose(file);
}

void readGuestsFromFile(pointer* guests) {
    FILE* file;
    int size = sizeof(GuestData);
    GuestData data;
    file = fopen("guests.dat", "rb");
    if (file == NULL)
        return;
    while (fread(&data, size, 1, file) == 1)
        addGuest(&(*guests), data);
    fclose(file);
}







int main()
{



    pointer guests = NULL;
    pointerA access = NULL;


    int option = 0;



    readGuestsFromFile(&guests);




    while (option != 3) {
        cout << "Dziekujemy, ze chcesz zarezerwowac pobyt w naszym hotelu." << endl;
        cout << "\n 1. Rezerwacja";
        cout << "\n 2. Wyswietl goœci";
        cout << "\n 3. Zakoncz program" << endl;


        cout << "Wybierz opcje: ";
        cin >> option;
        cout << endl;



        switch (option) {

        case 1:
        {
            GuestData gData = guestData();
            addGuest(&guests, gData);
            break;
        }
        case 2:
        {
            showGuests(guests);
            break;
        }
        case 3:
        {
            cout << "Dziekujemy, za korzystanie z naszych us³ug";
            break;
        }
        default: {
            cout << "Nie ma takiej opcji";
            break;
        }
               system("cls");
        }

        saveGuestToFile(guests);


        return 0;

    }

}





