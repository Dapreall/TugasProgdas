#include <string>
#include <iostream>
using namespace std;

class personType {
public:
    personType(string first ="", string last =""){
        firstName = first;
        lastName = last;
    }
    
    void print(){
        cout << firstName << " " << lastName << endl;
    }

    void setName(string first, string last){
        firstName = first;
        lastName = last;
    }

    string getFirstName(){
        return firstName;
    }

    string getLastName(){
        return lastName;
    }

protected:
    string firstName; 
    string lastName; 
};

class doctorType : public personType {
public:
    doctorType(string nama_depan, string nama_belakang, string spec)
    {
        spesialis = spec;
        firstName = nama_depan;
        lastName = nama_belakang;
    }


    void setSpesialis(string spec){
        spesialis = spec;
    }

    string getSpesialis(){
        return spesialis;
    }

private:
    string spesialis;
};

class dateType{
public:
    dateType(int tanggal ,string bulan, int tahun):
            Day(tanggal),Month(bulan),Year(tahun){
            }    

    int getDay(){
        return Day;
    }
    string getMonth(){
        return Month;
    }
    int getYear(){
        return Year;
    }
    string Fulldate(){
        return to_string(Day)+" "+Month+" "+to_string(Year);
    }

private:
    int Day;
    string Month;
    int Year;
};


class patientType : public personType{
protected:
    int ID;
    int Age;
    dateType tgl_lahir;
    dateType tgl_masuk;
    dateType tgl_keluar;
    doctorType dokter;

public:
    patientType(string nama_depan, string nama_belakang, int umur, int identitas, dateType kelahiran, dateType masuk, dateType keluar,doctorType Dokter) 
                :personType (nama_depan, nama_belakang), Age(umur), ID(identitas), tgl_lahir(kelahiran), tgl_masuk(masuk), tgl_keluar(keluar),dokter(Dokter){}
    
    void setData(int identitas, int umur){
        ID = identitas;
        Age = umur;
    }
    int getID(){
        return ID;
    }
    int getAge(){
        return Age;
    }

    dateType gettgl_lahir(){
        return tgl_lahir;
    }

    dateType gettgl_masuk(){
        return tgl_masuk;
    }

    dateType gettgl_keluar(){
        return tgl_keluar;
    }

    void setDocName(string namaDokter){
        dokter.setName(namaDokter, "");
    }
    string getDocName(){
        return dokter.getFirstName() + " " + dokter.getLastName();
    }
};

class billType{
protected:
    int ID;
    string Room, Med;
    patientType dataPasien;

public:
    billType(patientType data, string obat, string kamar):
    dataPasien(data), Med(obat), Room(kamar){
        billType::ID=dataPasien.getID();
    }

    int getID(){
        return this->ID;
    }

    string getRoom(){
        return Room;
    }

    string getMed(){
        return Med;
    }

};

int main() {
    cout << "Ini adalah data Nota yang kami berikan kepada yang bersangkutan" << endl;

    doctorType myDoctor("John", "Thor", "Tulang Belakang");
    dateType tgl_lahir(12, "Agustus" , 2005);
    dateType tgl_masuk(20, "November", 2023);
    dateType tgl_keluar(21, "November", 2023);
    patientType pasien1("Dhafarel", "Hariyanto", 18, 987654, tgl_lahir, tgl_masuk, tgl_keluar, myDoctor);
    billType billing(pasien1, "Mylanta", "Exclusive");

    cout << "======== Data Dokter ========" << endl;
    cout << "Nama Dokter    : " << myDoctor.getFirstName() << " " << myDoctor.getLastName() << endl;
    cout << "Spesialis      : " << myDoctor.getSpesialis() << endl;
    cout << "======== Data Pasien ========" << endl;
    cout << "Nama Pasien    : " << pasien1.getFirstName() << " " << pasien1.getLastName() << endl;
    cout << "Usia           : " << pasien1.getAge() << endl;
    cout << "TTL            : Jakarta, "<<tgl_lahir.Fulldate() << endl;
    cout << "Nomor ID       : "<< billing.getID() << endl;
    cout << "Tanggal Masuk  : "<< tgl_masuk.Fulldate() << endl;
    cout << "Tanggal Keluar : "<< tgl_keluar.Fulldate() << endl;
    cout << "Nama Perawat   : "<< myDoctor.getFirstName() << " " << myDoctor.getLastName()<<endl;
    cout << "Obat           : "<< billing.getMed() << endl;
    cout << "Ruangan        : "<< billing.getRoom() << endl;

    return 0;
}