#include <iostream>
#include <cstring>
#include "User.h"
using namespace std;


// ctor, parameter: nama pengguna
User::User(char* name) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->num_of_favourite_music = 0;
    this->music_list = new char*[100];
    n_user++;
}

// cctor
User::User(const User& u) {
    this->name = new char[strlen(u.getName())];
    strcpy(this->name, u.name);
    this->num_of_favourite_music = u.getNumOfFavouriteMusic();
    this->music_list = new char*[100];
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(u.music_list[i])];
        strcpy(this->music_list[i], u.music_list[i]);
    }
    n_user++;
}

// dtor
// selain implementasi, print juga "User <nama user> deleted<endl>"
// Contoh:
// User A deleted
//
User::~User() {
    cout << "User " << name << "deleted" << endl;
    delete[] this->name;
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        delete[] this->music_list[i];
    }
    delete[] this->music_list;
}

// Asumsi: musik unik, parameter: judul musik
void User::addFavouriteMusic(char* judul) {
    this->music_list[num_of_favourite_music] = new char[strlen(judul)];
    strcpy(this->music_list[num_of_favourite_music], judul);
    this->num_of_favourite_music++;
}

void User::deleteFavouriteMusic(char* judul) {
    if (this->num_of_favourite_music > 0) {
        if (this->num_of_favourite_music == 1) {
            if (strcmp(this->music_list[0], judul) == 0) {
                // delete[] this->music_list[0];
                this->num_of_favourite_music--;
            }   
        }
        else {
            for (int i = 0; i < this->num_of_favourite_music; i++) {
                if (strcmp(this->music_list[i], judul) == 0) {
                    // delete[] this->music_list[i];
                    this->num_of_favourite_music--;
                    int j = i;
                    while (j < this->num_of_favourite_music) {
                        strcpy(this->music_list[j], this->music_list[j + 1]);
                        j++;
                    }
                    break;
                }
            }
        }
    }
}

void User::setName(char* name) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

char* User::getName() const {
    return this->name;
};
int User::getNumOfFavouriteMusic() const {
    return this->num_of_favourite_music;

}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const {
    if (this->num_of_favourite_music == 0) {
        cout << "No music in your favourite list" << endl;
    }
    else {
        for (int i = 0; i < this->num_of_favourite_music; i++) {
            cout << i + 1 << ". " << this->music_list[i] << endl;
        }
    }
}

int User::getNumOfUser() {
    return User::n_user;
}
// protected:
// char* name;
// int num_of_favourite_music; // jumlah musik yang ada pada music_list
// char** music_list; // daftar judul musik
// static int n_user;