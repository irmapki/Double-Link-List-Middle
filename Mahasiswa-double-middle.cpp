#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataUser {
  string nama, jurusan, NIM;
  DataUser *sebelumnya;
  DataUser *selanjutnya;
};

DataUser *kepala, *ekor, *saat_ini, *nodeBaru, *hapus, *setelahNode;

// Buat Double Linked List
void buatDoubleLinkedList(string data[3]) {
  kepala = new DataUser();
  kepala->nama = data[0];
  kepala->jurusan = data[1];
  kepala->NIM = data[2];
  kepala->sebelumnya = NULL;
  kepala->selanjutnya = NULL;
  ekor = kepala;
}

// hitung Double Linked List
int hitungDoubleLinkedList() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    saat_ini = kepala;
    int jumlah = 0;
    while (saat_ini != NULL) {
      jumlah++;
      // pindah
      saat_ini = saat_ini->selanjutnya;
    }
    return jumlah;
  }
  return 0;
}

// Tambah Awal
void tambahAwal(string data[3]) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    nodeBaru = new DataUser();
    nodeBaru->nama = data[0];
    nodeBaru->jurusan = data[1];
    nodeBaru->NIM = data[2];
    nodeBaru->sebelumnya = NULL;
    nodeBaru->selanjutnya = kepala;
    kepala->sebelumnya = nodeBaru;
    kepala = nodeBaru;
  }
}

// Tambah Akhir
void tambahAkhir(string data[3]) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    nodeBaru = new DataUser();
    nodeBaru->nama = data[0];
    nodeBaru->jurusan = data[1];
    nodeBaru->NIM = data[2];
    nodeBaru->sebelumnya = ekor;
    nodeBaru->selanjutnya = NULL;
    ekor->selanjutnya = nodeBaru;
    ekor = nodeBaru;
  }
}

// Tambah Tengah
void tambahTengah(string data[3], int posisi) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    if (posisi == 1) {
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    } else if (posisi < 1 || posisi > hitungDoubleLinkedList()) {
      cout << "Posisi diluar jangkauan!!!" << endl;
    } else {
      nodeBaru = new DataUser();
      nodeBaru->nama = data[0];
      nodeBaru->jurusan = data[1];
      nodeBaru->NIM = data[2];

      // traversing
      saat_ini = kepala;
      int nomor = 1;
      while (nomor < posisi - 1) {
        saat_ini = saat_ini->selanjutnya;
        nomor++;
      }

      setelahNode = saat_ini->selanjutnya;
      nodeBaru->sebelumnya = saat_ini;
      nodeBaru->selanjutnya = setelahNode;
      saat_ini->selanjutnya = nodeBaru;
      setelahNode->sebelumnya = nodeBaru;
    }
  }
}

// hapus Awal
void hapusAwal() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    hapus = kepala;
    kepala = kepala->selanjutnya;
    kepala->sebelumnya = NULL;
    delete hapus;
  }
}

// hapus Akhir
void hapusAkhir() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    hapus = ekor;
    ekor = ekor->sebelumnya;
    ekor->selanjutnya = NULL;
    delete hapus;
  }
}

// hapus Tengah
void hapusTengah(int posisi) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    if (posisi == 1 || posisi == hitungDoubleLinkedList()) {
      cout << "Posisi bukan posisi tengah!!" << endl;
    } else if (posisi < 1 || posisi > hitungDoubleLinkedList()) {
      cout << "Posisi diluar jangkauan!!" << endl;
    } else {
      int nomor = 1;
      saat_ini = kepala;
      while (nomor < posisi - 1) {
        saat_ini = saat_ini->selanjutnya;
        nomor++;
      }
      hapus = saat_ini->selanjutnya;
      setelahNode = hapus->selanjutnya;
      saat_ini->selanjutnya = setelahNode;
      setelahNode->sebelumnya = saat_ini;
      delete hapus;
    }
  }
}

// Ubah Data di Posisi Pertama
void changeFirst(string data[3]) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    kepala->nama = data[0];
    kepala->jurusan = data[1];
    kepala->NIM = data[2];
  }
}

// Ubah Data di Posisi Tengah
void changeMiddle(string data[3], int posisi) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else if (posisi <= 1 || posisi >= hitungDoubleLinkedList()) {
    cout << "Posisi bukan posisi tengah!!" << endl;
  } else {
    int nomor = 1;
    saat_ini = kepala;
    while (nomor < posisi) {
      saat_ini = saat_ini->selanjutnya;
      nomor++;
    }
    saat_ini->nama = data[0];
    saat_ini->jurusan = data[1];
    saat_ini->NIM = data[2];
  }
}

// Ubah Data di Posisi Terakhir
void changeLast(string data[3]) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    ekor->nama = data[0];
    ekor->jurusan = data[1];
    ekor->NIM = data[2];
  }
}

// Cetak Double Linked List
void cetakDoubleLinkedList() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    saat_ini = kepala;
    while (saat_ini != NULL) {
      // cetak
      cout << "Nama User : " << saat_ini->nama << endl;
      cout << "Jurusan User : " << saat_ini->jurusan << endl;
      cout << "NIM User : " << saat_ini->NIM << "\n" << endl;
      // pindah
      saat_ini = saat_ini->selanjutnya;
    }
  }
}

int main() {
  string newData[3] = {"Irma Fatimatuz Zahro", "informatika", "1111"};
  buatDoubleLinkedList(newData);

  cetakDoubleLinkedList();

  string data2[3] = {"Muhammad Diluc", "elektro", "2222"};
  tambahAwal(data2);
  cetakDoubleLinkedList();

  string data3[3] = {"Pace Mace", "manajemen", "3333"};
  tambahAkhir(data3);
  cetakDoubleLinkedList();

  string data4[3] = {"Nur sagiri", "kesmas", "4444"};
  tambahTengah(data4, 3);
  cetakDoubleLinkedList();

  string changeData[3] = {"pacar cina", "DKV", "9999"};
  changeFirst(changeData);
  cetakDoubleLinkedList();

  string changeDataMiddle[3] = {"Sulhan Ganteng", "Teknik mesin", "8888"};
  changeMiddle(changeDataMiddle, 2);
  cetakDoubleLinkedList();

  string changeDataLast[3] = {"Kurnia Agatha", "Sastra Jawa", "7777"};
  changeLast(changeDataLast);
  cetakDoubleLinkedList();

  hapusTengah(2);
  cetakDoubleLinkedList();
  
}
