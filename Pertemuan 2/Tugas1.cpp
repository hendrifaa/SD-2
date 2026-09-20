#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void tampilkan() {
    Node* bantu = head;

    cout << "Isi Linked List: ";

    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }

    while (bantu != NULL) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }

    cout << "NULL" << endl;
}

void tambahAwal(int nilai) {
    Node* baru = new Node;

    baru->data = nilai;
    baru->next = head;
    head = baru;
}

void tambahAkhir(int nilai) {
    Node* baru = new Node;

    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        return;
    }

    Node* bantu = head;

    while (bantu->next != NULL) {
        bantu = bantu->next;
    }

    bantu->next = baru;
}

void tambahSetelah(int nilaiBaru, int nilaiCari) {
    Node* bantu = head;

    while (bantu != NULL && bantu->data != nilaiCari) {
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Nilai " << nilaiCari << " tidak ditemukan!" << endl;
        return;
    }

    Node* baru = new Node;

    baru->data = nilaiBaru;
    baru->next = bantu->next;
    bantu->next = baru;
}

void hapusNilai(int nilai) {
    if (head == NULL) {
        cout << "Linked List kosong!" << endl;
        return;
    }

    if (head->data == nilai) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* bantu = head;

    while (bantu->next != NULL &&
           bantu->next->data != nilai) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        cout << "Nilai " << nilai << " tidak ditemukan!" << endl;
        return;
    }

    Node* hapus = bantu->next;
    bantu->next = hapus->next;

    delete hapus;
}

int main() {
    int pilihan;
    int nilai;
    int nilaiBaru;
    int nilaiCari;

    do {
        cout << endl;
        cout << "===== MENU SINGLE LINKED LIST =====" << endl;
        cout << "1. Tambah di awal" << endl;
        cout << "2. Tambah di akhir" << endl;
        cout << "3. Tambah setelah nilai tertentu" << endl;
        cout << "4. Hapus berdasarkan nilai" << endl;
        cout << "5. Tampilkan Linked List" << endl;
        cout << "0. Keluar" << endl;

        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;

                tambahAwal(nilai);
                tampilkan();
                break;

            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;

                tambahAkhir(nilai);
                tampilkan();
                break;

            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilaiBaru;

                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiCari;

                tambahSetelah(nilaiBaru, nilaiCari);
                tampilkan();
                break;

            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;

                hapusNilai(nilai);
                tampilkan();
                break;

            case 5:
                tampilkan();
                break;

            case 0:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}