#include "User.h"
#include "ArtistUser.h"
using namespace std;
#include <iostream>


//ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char* name) : User(name) {
    this->num_of_music_uploaded = 0;
    this->uploaded_music_list = new char*[1000];
    num_of_artist++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser& au) : User(name) {
    this->num_of_music_uploaded = au.num_of_music_uploaded;
    this->uploaded_music_list = new char*[1000];
    for (int i = 0; i < this->num_of_music_uploaded; i++) {
        this->uploaded_music_list[i] = new char[strlen(au.uploaded_music_list[i])];
        strcpy(this->uploaded_music_list[i], au.uploaded_music_list[i]);
    }
    this->num_of_favourite_music = au.getNumOfFavouriteMusic();
    this->music_list = new char *[1000];
    for (int i = 0; i < this->num_of_favourite_music; i++){
        this->music_list[i] = new char[strlen(au.music_list[i])];
        strcpy(this->music_list[i], au.music_list[i]);
    }
    num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser() {
    cout << "Artist user " << name << " deleted" << endl;
    for (int i = 0; i < this->num_of_music_uploaded; i++) {
        delete[] this->uploaded_music_list[i];
    }
    delete[] this->uploaded_music_list;
}

// Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char* judul) {
    this->num_of_music_uploaded++;
    this->uploaded_music_list[this->num_of_music_uploaded] = new char[strlen(judul)];
    strcpy(this->uploaded_music_list[this->num_of_music_uploaded], judul);
}

void ArtistUser::deleteUploadedMusic(char* judul) {
    if (this->num_of_music_uploaded > 0) {
        if (this->num_of_music_uploaded == 1) {
            this->num_of_music_uploaded--;
        }
        else {
            for (int i = 0; i < this->num_of_music_uploaded; i++) {
                if (strcmp(this->uploaded_music_list[i], judul) == 0) {
                    delete[] this->uploaded_music_list[i];
                    this->num_of_music_uploaded--;
                    int j = i;
                    while (j < this->num_of_music_uploaded) {
                        strcpy(this->uploaded_music_list[j], this->uploaded_music_list[j + 1]);
                        j++;
                    }
                }
            }
        }
    }
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const {
    if (this->num_of_music_uploaded == 0) {
        cout << "No music uploaded" << endl;
    }
    else {
        for (int i = 0; i < this->num_of_music_uploaded; i++) {
            cout << i + 1 << ". " << this->uploaded_music_list[i] << endl;
        }
    }
}

int ArtistUser::getNumOfMusicUploaded() const {
    return this->num_of_music_uploaded;
}


int ArtistUser::getNumOfArtist() {
    return ArtistUser::num_of_artist;
}