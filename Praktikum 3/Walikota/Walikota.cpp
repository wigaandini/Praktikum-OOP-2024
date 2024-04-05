// Erdianti Wiga Putri A
// 13522053 - K1

#include <iostream>
#include "Walikota.hpp"
using namespace std;
    
    
/*
    Membuat objek Walikota dengan jumlah default kayu, gulden, dan pekerja
*/
Walikota::Walikota() {
    this->kayu = DEFAULT_KAYU;
    this->gulden = DEFAULT_GULDEN;
    this->pekerja = DEFAULT_PEKERJA;
}
/*
    Membuat objek Walikota dengan jumlah kayu, gulden, pekerja, dan bangunan sesuai argumen.
*/
Walikota::Walikota(int kayu, int gulden, int pekerja) {
    this->kayu = kayu;
    this->gulden = gulden;
    this->pekerja = pekerja;
}
/*
    Menghancurkan objek walikota
*/
Walikota::~Walikota() {
    this->bangunan.clear();
}

/*
    Membangun bangunan baru sesuai nama yang diberikan. Metode ini menggunakan metode pakaiKayu, pakaiGulden, perkejakanPekerja secara urut. Untuk membuat satu bangunan, akan menghabiskan kayu dan gulden sesuai input dan akan dialokasikan 1 pekerja.

    Bangunan gagal dibangun apabila:
    1. Kayu habis. Keluarkan pesan dari exception ditambah dengan ", beli kayu dulu."
    2. Gulden habis. Keluarkan pesan dari exception ditambah dengan ", tagih pajak dulu."
    3. Tidak ada pekerja. Keluarkan pesan dari exception ditambah dengan ", rekrut pekerja dulu."

    Jika gagal dibangun, jumlah kayu, gulden, dan pekerja tidak berkurang. Gunakan metode batalPakaiKayu, batalPakaiGulden, dan batalkanPekerja.

    Jika berhasil, masukkan bangunan ke daftar bangunan dengan metode push_back(Bangunan b) dari vector. Selain itu, tampilkan pesan "Bangunan [<nomor_bangunan>] <nama_bangunan> berhasil dibangun". Untuk mengetahui panjang list saat ini gunakan metode size()

    (semua output ditambah newline)
*/
void Walikota::bangunBangunan(string namaBangunan, int kayu, int gulden) {
    try {
        Bangunan b(namaBangunan);
        pakaiKayu(kayu);
        pakaiGulden(gulden);
        pekerjakanPekerja();

        bangunan.push_back(b);

        cout << "Bangunan [" << bangunan.size() << "] " << b.getNamaBangunan() << " berhasil dibangun" << endl;
    }
    catch (KayuTidakCukupException& e) {
        cout << e.what() << ", beli kayu dulu." << endl;
    }
    catch (GuldenTidakCukupException& e) {
        batalPakaiKayu(kayu);
        cout << e.what() << ", tagih pajak dulu." << endl;
    }
    catch (PekerjaTidakCukupException& e) {
        batalPakaiKayu(kayu);
        batalPakaiGulden(gulden);
        cout << e.what() << ", rekrut pekerja dulu." << endl;
    }
}
/*
    Menambahkan kayu sesuai num
*/
void Walikota::tambahKayu(int num) {
    this->kayu += num;
}
/*
    Menambahkan gulden sesuai num
*/
void Walikota::tambahGulden(int num) {
    this->gulden += num;
}
/*
    Menambahkan pekerja sesuai num
*/
void Walikota::tambahPekerja(int num) {
    this->pekerja += num;
}
/*
    Menggunakan kayu sesuai num

    Lemparkan exception KayuTidakCukupException jika kayu tidak cukup. Kayu tidak digunakan.
*/
void Walikota::pakaiKayu(int num) {
    if (this->kayu < num) {
        throw KayuTidakCukupException();
    }
    this->kayu -= num;
}
/*
    Menggunakan gulden sesuai num

    Lemparkan exception GuldenTidakCukupException jika gulden tidak cukup. Gulden tidak digunakan.
*/
void Walikota::pakaiGulden(int num) {
    if (this->gulden < num) {
        throw GuldenTidakCukupException();
    }
    this->gulden -= num;
}
/*
    Mempekerjakan 1 pekerja

    Lemparkan exception PekerjaTidakCukupException jika pekerja tidak cukup. Pekerja batal bekerja.
*/
void Walikota::pekerjakanPekerja() {
    if (this->pekerja <= 0) {
        throw PekerjaTidakCukupException();
    }
    this->pekerja --;
}
/*
    Membatalkan penggunaan kayu sesuai num
*/
void Walikota::batalPakaiKayu(int num) {
    this->kayu += num;
}
/*
    Membatalkan penggunaan gulden sesuai num
*/
void Walikota::batalPakaiGulden(int num) {
    this->gulden += num;
}
/*
    Membatalkan 1 pekerja
*/
void Walikota::batalkanPekerja() {
    this->pekerja ++;
}
/*
    Menyebut bangunan pada index idx. Gunakan metode at(int idx) untuk mengakses bangunan. Tampilkan "<nama_bangunan>"

    Tampilkan exception yang dilemparkan c++ ketika idx tidak valid. Akhiri dengan newline.
*/
void Walikota::sebutBangunan(int idx) {
    try {
        cout << bangunan.at(idx).getNamaBangunan() << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}
/*
    Menampilkan status kota dengan format:
    
    Status kota:
        Kayu: <jumlah_kayu>
        Gulden: <jumlah_gulden>
        Pekerja: <jumlah_pekerja>
        Bangunan:
        Bangunan[i]: <nama_bangunan>
*/
void Walikota::statusKota() {
    cout << "Status kota:" << endl;
    cout << "    Kayu: " << this->kayu << endl;
    cout << "    Gulden: " << this->gulden << endl;
    cout << "    pekerja: " << this->pekerja << endl;
    cout << "    Bangunan:" << endl;
    for (int i = 0; i < this->bangunan.size(); i ++) {
        cout << "Bangunan[" << i+1 << "]: " << bangunan[i].getNamaBangunan() << endl;
    }
}