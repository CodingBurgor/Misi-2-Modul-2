#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main(){
    bool tutup = false; //membuat suatu variabel yang mencatat apakah toko tutup (true) atau pelanggan bisa masuk (false)
    //Pada program ini saya akan menggunakan indeks dari array untuk ID dari menu pada array tersebut.
    string daftarMenu[] = {"Nasi Goreng","Ayam Goreng","Telor dadar","Telor mata sapi","Lemon tea","Air mineral","Es teh","Jus jeruk","Ayam geprek","Mi goreng"};
    // array daftarMenu berisi nama dari setiap menu
    string kategori[] = {"makanan","makanan","makanan","makanan","minuman","minuman","minuman","minuman","makanan","makanan"};
    // array kategori akan berisi kategori dari tiap menu sesuai dengan ID masing masing (indeks array)
    float daftarHarga[] = {20000,15000,10000,10000,6000,5000,3000,10000,15000,13000};
    // array daftarHarga akan berisi harga dari tiap menu sesuai dengan ID masing masing (indeks array)
    int jumlahTransaksi = 0; //membuat suatu variabel yang mencatat apakah toko sudah melakukan transaksi
    string Nama; // membuat suatu variabel yang mencatat nama dari pelanggan
    int bonPembelian[10]; //Saya membuat array Bonpembelian yang akan mencatat ID dari masing masing pembelian dengan maksimal 10 barang karena hannya ada 10 menu (jika membeli semua menu)
    int jumlahPembelian[10]; //sama seperti bonPembelian namun untuk jumlah

    while (tutup == false){ //membuat loop yang akan terus berjalan selama pemilik memilih pelanggan bisa masuk 
        //untuk pencatatan transaksi saya akan menggunakan array juga dan setiap indeks berfungsi sebagai urutan dari transaksi


        cout << "Ketik angka yang sesuai dengan pilihan (0/1) lalu pencet ENTER \n";
        cout << "Apakah toko tutup (0) atau pelanggan masuk (1): ";
        int ans1; // membuat suatu variabel yang akan menyimpan pilihan dari pemilik toko
        cin >> ans1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       
        if(ans1 == 0){
            break; // apabila memilih untuk tutup maka akan keluar dari loop
        
        } else if(ans1 != 1){ // angka selain 1 dan 0 berarti kesalahan input
            cout << "Terjadi kesalahan, silakan ulang\n";
            continue;

        } else {
            cout << "Nama pelanggan adalah: ";
            getline(cin,Nama); //Memasukkan Nama pelanggan kedalam variabel Nama
            
            bool lihatMenu = true;
            while (lihatMenu == true){ //membuat loop yang akan menampilkan pilihan untuk melihat menu atau keluar
                int ans2; // membuat suatu variabel yang akan menyimpan pilihan dari pelanggan
                cout << "Melihat menu(0) atau membeli makanan/minuman(1) atau keluar warung(2): ";
                cin >> ans2;
                if(ans2 == 1){
                    int ID,Jumlah;
                    cout << "Silahkan memasukkan ID dari makanan/minuman (angka pada[] dalam menu): ";
                    cin >> ID;
                    bonPembelian[jumlahTransaksi] = ID;
                    cout << "Silahkan memasukkan jumlah dari makanan/minuman: ";
                    cin >> Jumlah;
                    jumlahPembelian[jumlahTransaksi] = Jumlah;
                    ++jumlahTransaksi;

                } else if (ans2 != 0 && ans2 != 1 && ans2 != 2){ // angka selain 1 atau 0 atau 2 berarti kesalahan input
                    cout << "Terjadi kesalahan. silahkan ulang\n";
                    continue;
                } else if(ans2 == 0) {
                    cout << "|||||||||||\n"; // Hiasan hehe
                    cout << "DAFTAR MENU\n";
                    cout << "|||||||||||\n";
                    for (int i = 0; i < 10; ++i){ // menampilkan daftar menu
                        cout << "[" << i << "] " << kategori[i] << " " << daftarMenu[i] << " Rp" << daftarHarga[i] << " Per item \n";
                    }
                } else if(ans2 ==2 ){
                    break;
                }
            }
        }
    }
    if(jumlahTransaksi == 0) {
        cout << "Tidak Ada penjualan\n";
    }  else{
        cout << "Nama pelanggan: " << Nama <<"\n";
        for(int i = 0; i < jumlahTransaksi; i++){
            cout << daftarMenu[bonPembelian[i]] << " " << jumlahPembelian[i] <<"x dengan harga total: Rp"<<  jumlahPembelian[i] * daftarHarga[bonPembelian[i]] << "\n";
        }
    }

    return 0;
}
