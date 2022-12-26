#include <iostream>

using namespace std;



int COUNTER = 0;

struct GuestData {
    int age;
    int fee;
    string firstName;
    string lastName;
    int type;
    string parking;
    string room;
    bool access;
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




//void insert_Front(struct GuestData** head, )

void insert_front(struct GuestData** head, int age, int fee, string firstName, string lastName, int type, string parking, string room, bool access)
{
    struct GuestData* listData = new GuestData;
    listData->age = age;
    listData->fee = fee;
    listData->firstName = firstName;
    listData->lastName = lastName;
    listData->type = type;
    listData->parking = parking;
    listData->room = room;
    listData->access = access;
    listData->next = (*head);
    listData->prev = NULL;

    if ((*head) != NULL)
    {
        (*head)->prev = listData;
        (*head) = listData;
    }

    cout << "Uzytko metody insert_front" << endl;
    cout << "Dodano element: " << firstName << ", " << lastName << endl;
}

void insert_after(struct GuestData* prev, int age, int fee, string firstName, string lastName, int type, string parking, string room, bool access)
{
    if (prev == NULL)
    {
        cout << "Brakuje ostatniego elementu :)" << endl;
        return;
    }

    struct GuestData* listData = new GuestData;
    listData->age = age;
    listData->fee = fee;
    listData->firstName = firstName;
    listData->lastName = lastName;
    listData->type = type;
    listData->parking = parking;
    listData->room = room;
    listData->access = access;
    
    listData->next = prev->next;
    prev->next = listData;
    listData->prev = prev;

    if (listData->next!=NULL)
    {
        listData->next->prev = listData;
    }

    cout << "Uzytko metody insert_after" << endl;
    cout << "Dodano element: " << firstName << ", " << lastName << endl;
}


void insert_back(struct GuestData** head, int age, int fee, string firstName, string lastName, int type, string parking, string room, bool access)
{
    struct GuestData* listData = new GuestData;
    struct GuestData* last = *head;

    listData->age = age;
    listData->fee = fee;
    listData->firstName = firstName;
    listData->lastName = lastName;
    listData->type = type;
    listData->parking = parking;
    listData->room = room;
    listData->access = access;
    listData->next = NULL;

    if ((*head) == NULL)
    {
        listData->prev = NULL;
        *head = listData;
        return;
    }

    

    cout << "Uzytko metody insert_back" << endl;
    cout << "Dodano element: " << firstName << ", " << lastName << endl;
}

void display(struct GuestData* listData)
{
    struct GuestData* last;

    while (listData != NULL)
    {
        cout << "Imie: " << listData->firstName << endl;
        cout << "Nazwisko: " << listData->lastName << endl;
        cout << "Wiek: " << listData->age << endl;
        cout << "Kwota do zaplaty: " << listData->fee << endl;
        cout << "Typ: " << listData->type << endl;
        cout << "Czy parking?: " << listData->parking << endl;
        cout << "Pokoj: " << listData->room << endl;
        cout << "Dostepny?: " << listData->access << endl;

        last = listData;
        listData = listData->next;
    }

    if (listData == NULL)
    {
        cout << "Brak elementow do wyswietlenia" << endl;
        return;
    }
}


void guestData() {

    GuestData data;
   
    int age;
    int fee;
    string firstName;
    string lastName;
    int type;
    string room;
    bool parking;
    bool access;
    string option;
        

    cout << "Podaj wiek: ";
    cin >> age;

    if (age < 18)
        cout << "Aby sie zarejestrowac musisz miec conajmnmiej 18 lat." << endl;
    else
        cout << "Podaj imie: ";
    cin >> firstName;
    cout << "Podaj nazwisko";
    cin >> lastName;

    cout << "Podaj opcje ktora Cie interesuje (1 - Pojedynczy pokoj (150zl), 2 - Pokoj dwuosobowy (250zl), 3 - Apartament (350zl), 4 - Pokoj rodzinny (350zl). : ";
    cin >> type;

    while (type > 4) {
        cout << "Podana opcja nie istnieje, sprobuj jeszcze raz";
        if (type == 1) {
            room = "Single";
            fee += 150;
        }

        if (type == 2) {
            room = "Double";
            fee += 250;
        }

        if (type == 3) {
            room = "Apartament";
            fee += 350;
        }
        if (type == 4) {
            room = "Family";
            fee += 350;
        }

    
    }

    cout << "Czy chcesz rowniez zarezerwowac miejsce parkingowe ? (T/N): ";

    do
    {
        cin >> option;
        

    } while (option != "T" && option != "N"); {
        cout << "Mozesz podac tylko T (tak) lub N (nie). Sprobuj jeszcze raz.";
        cin >> option;
        if (option == "N") {
            parking = "Nie";
        }
        else {
            parking = "Tak";
            fee += 20;

        }


        //Jezeli lista jest psuta to dodajesz pierwszy element listy jako ostatni
        if (ELEMENTS_LIST == NULL)
        {
            insert_back(int age, int fee, string firstName, string lastName, int type, string parking, string room, bool access);
        }
        else
        {
            //w innym przypadku dodajemy nowe elementy z przodu listy
            insert_front(int age, int fee, string firstName, string lastName, int type, string parking, string room, bool access);
        }

        
       
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





