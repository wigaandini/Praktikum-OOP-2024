#include <iostream>
#include "User.h"
#include "PremiumUser.h"
using namespace std;

//ctor, active = true, parameter: nama pengguna
PremiumUser::PremiumUser(char*) : User(name) {
    this->active = true;
    this->num_of_music_downloaded = 0;
}

// cctor
PremiumUser::PremiumUser(const PremiumUser& pu) : User(pu.name) {
    this->active = pu.active;
    this->num_of_music_downloaded = pu.num_of_music_downloaded;
    this->num_of_favourite_music = pu.getNumOfFavouriteMusic();
    this->music_list = new char *[1000];
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(pu.music_list[i])];
        strcpy(this->music_list[i], pu.music_list[i]);
    }
    this->num_of_music_downloaded = pu.num_of_music_downloaded;
    this->active = pu.active;
    cout << "Premium User Copied" << endl;
} // implementasikan jika diperlukan, 
// jika tidak diperlukan, hapus cctor
// jika perlu diimplementasikan, print "Premium User Copied<endl>"

// dtor; implementasikan jika diperlukan
PremiumUser::~PremiumUser() {}
// jika tidak diperlukan, hapus dtor
// jika diperlukan
// selain implementasi, print juga "Premium user <nama user> deleted<endl>"
// Contoh:
// Premium user A deleted

// print kata-kata sbg. berikut: "Music Downloaded: <judul><endl>"
// Contoh: 
// Music Downloaded: Loyal - Chris Brown, Lil Wayne, Tyga
//
// Jika akun premium tidak aktif, print: "Activate premium account to download music<endl>"
void PremiumUser::downloadMusic(char* judul) {
    if (!this->active) {
        cout << "Activate premium account to download music" << endl;
    } 
    else {
        cout << "Music Downloaded: " << judul << endl;
        this->num_of_music_downloaded++;
    }
}

void PremiumUser::inactivatePremium() {
    this->active = false;
}

void PremiumUser::activatePremium() {
    this->active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const {
    return this->num_of_music_downloaded;
}

// mengembalikan nilai active
bool PremiumUser::getPremiumStatus() const {
    return this->active;
}