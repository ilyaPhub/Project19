#include <iostream>
using namespace std;

const int MAX_CONTACTS = 100;  
const int NAME_SIZE = 100;      
const int PHONE_SIZE = 20;      
const int INFO_SIZE = 200;      

class Contact {
public:
    char name[NAME_SIZE];
    char homePhone[PHONE_SIZE];
    char workPhone[PHONE_SIZE];
    char mobilePhone[PHONE_SIZE];
    char additionalInfo[INFO_SIZE];

    Contact() {
        name[0] = homePhone[0] = workPhone[0] = mobilePhone[0] = additionalInfo[0] = '\0';
    }

    void input() {
        cout << "Введіть ФІО: ";
        cin.getline(name, NAME_SIZE);
        cout << "Введіть домашній телефон: ";
        cin.getline(homePhone, PHONE_SIZE);
        cout << "Введіть робочий телефон: ";
        cin.getline(workPhone, PHONE_SIZE);
        cout << "Введіть мобільний телефон: ";
        cin.getline(mobilePhone, PHONE_SIZE);
        cout << "Введіть додаткову інформацію: ";
        cin.getline(additionalInfo, INFO_SIZE);
    }

    void display() const {
        cout << "ФІО: " << name << endl;
        cout << "Домашній телефон: " << homePhone << endl;
        cout << "Робочий телефон: " << workPhone << endl;
        cout << "Мобільний телефон: " << mobilePhone << endl;
        cout << "Додаткова інформація: " << additionalInfo << endl;
    }
};

class PhoneBook {
private:
    Contact contacts[MAX_CONTACTS];
    int contactCount = 0;

public:
    void addContact() {
        if (contactCount < MAX_CONTACTS) {
            contacts[contactCount].input();
            contactCount++;
        }
        else {
            cout << "Телефонна книга заповнена!" << endl;
        }
    }

    void deleteContact(const char* name) {
        for (int i = 0; i < contactCount; ++i) {
            if (strcmp(contacts[i].name, name) == 0) {
                for (int j = i; j < contactCount - 1; ++j) {
                    contacts[j] = contacts[j + 1];
                }
                contactCount--;
                cout << "Контакт видалено." << endl;
                return;
            }
        }
        cout << "Контакт не знайдено." << endl;
    }

    void searchContact(const char* name) const {
        for (int i = 0; i < contactCount; ++i) {
            if (strcmp(contacts[i].name, name) == 0) {
                contacts[i].display();
                return;
            }
        }
        cout << "Контакт не знайдено." << endl;
    }

    void displayAll() const {
        for (int i = 0; i < contactCount; ++i) {
            contacts[i].display();
            cout << "---------------------" << endl;
        }
    }

    void saveToFile() const {
        for (int i = 0; i < contactCount; ++i) {
            cout << contacts[i].name << '\n'
                << contacts[i].homePhone << '\n'
                << contacts[i].workPhone << '\n'
                << contacts[i].mobilePhone << '\n'
                << contacts[i].additionalInfo << '\n';
        }
        cout << "Дані збережено." << endl;
    }

    void loadFromFile() {
        contactCount = 0;
        while (cin.getline(contacts[contactCount].name, NAME_SIZE) &&
            cin.getline(contacts[contactCount].homePhone, PHONE_SIZE) &&
            cin.getline(contacts[contactCount].workPhone, PHONE_SIZE) &&
            cin.getline(contacts[contactCount].mobilePhone, PHONE_SIZE) &&
            cin.getline(contacts[contactCount].additionalInfo, INFO_SIZE)) {
            contactCount++;
            if (contactCount >= MAX_CONTACTS) {
                cout << "Досягнуто максимального розміру телефонної книги." << endl;
                break;
            }
        }
        cout << "Дані завантажено." << endl;
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;
    do {
        cout << "\n1. Додати абонента\n2. Видалити абонента\n3. Пошук абонента\n4. Показати всіх абонентів\n";
        cout << "5. Зберегти у файл\n6. Завантажити з файлу\n0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            phoneBook.addContact();
        }
        else if (choice == 2) {
            char name[NAME_SIZE];
            cout << "Введіть ФІО для видалення: ";
            cin.getline(name, NAME_SIZE);
            phoneBook.deleteContact(name);
        }
        else if (choice == 3) {
            char name[NAME_SIZE];
            cout << "Введіть ФІО для пошуку: ";
            cin.getline(name, NAME_SIZE);
            phoneBook.searchContact(name);
        }
        else if (choice == 4) {
            phoneBook.displayAll();
        }
        else if (choice == 5) {
            phoneBook.saveToFile();
        }
        else if (choice == 6) { 
            phoneBook.loadFromFile();
        }
    } while (choice != 0);

    return 0;
}
