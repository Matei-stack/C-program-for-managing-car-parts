/*
   1. Proiect privind gestionarea pieselor unei - masini -

   2. Am ales aceasta tema deoarece recent am achizitionat o masina si mi s-a parut util sa pot stoca date despre componentele acesteia.

*/

#include <iostream>
#include <fstream>

#include <vector>
#include <utility>
#include <string>



using namespace std;

class Motor {
private:
    char* denumire;                         // atribute
    int capacitate;
    int nrMotoare;
    int nrKm;
    bool electric;
    const string felulAprinderii;
    int serieMotor;
    static int kmTestare;

public:
    Motor() = default;
    Motor(const char* denumire, int capacitate, bool electric, const string felulAprinderii, int serieMotor, int nrKm) :felulAprinderii("ardere") {       // Constructor cu parametri

        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);

        this->capacitate = capacitate;
        this->electric = electric;
        this->serieMotor = serieMotor;
        this->nrKm = nrKm;



    }


    Motor(const char* denumire, int capacitate, bool electric, const string felulAprinderii, int nrKm) :felulAprinderii("ardere") {                // Constructor cu parametri
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
        this->capacitate = capacitate;
        this->electric = electric;
        this->nrKm = nrKm;


    }

    Motor(const Motor& m1) {                                        // Constructor de copiere
        if (m1.denumire != NULL) {
            this->denumire = new char[strlen(m1.denumire) + 1];
            strcpy_s(this->denumire, strlen(m1.denumire) + 1, m1.denumire);
        }
        else
            denumire = NULL;
        this->capacitate = m1.capacitate;
        this->electric = m1.electric;
        this->nrKm = m1.nrKm;

    }


    char* getDenumire() const {                                       // afisare denumire
        return this->denumire;
    }
    void setDenumire(const char* denumire) {                // prelucrare denumire
        if (denumire && strlen(denumire) > 2) {
            if (this->denumire) {
                delete[]this->denumire;

            }
            this->denumire = new char[strlen(denumire) + 1];
            strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
        }
    }

    int getCapacitate()const {                                       // afisare capacitate
        return this->capacitate;
    }

    void setCapacitate(int modificareCapacitate) {              // prelucrare capacitate
        if (capacitate > 0)
            capacitate = modificareCapacitate;
    }

    bool getElectric()const {                                        // afisare electric
        return electric;
    }
    void setElectric(int modificareElectric) {                  // modificare electric 
        if (electric != modificareElectric)
            electric = modificareElectric;
    }

    string getFelulAprinderii()const {                         // afisare felul aprinderii
        return felulAprinderii;
    }

    int getSerieMotor()const {                                // afisare serie motor
        return serieMotor;
    }
    void setSerieMotor(int modificareSerie) {            //modificare serie 
        if (serieMotor > 0)
            serieMotor = modificareSerie;
    }
    int getnrKm() const {                                     // afisare nrKm
        return nrKm;
    }
    void setNrKm(int modificareKm) {                 // modificare nrKm 
        if (nrKm < modificareKm)
            modificareKm = nrKm;
    }

    friend istream& operator>>(istream& iStream, Motor& motor) {                         // operator >> 
        cout << "Denumire: ";
        char aux[20];
        iStream >> aux;
        if (motor.denumire != NULL) {
            delete[]motor.denumire;
        }
        motor.denumire = new char[strlen(aux) + 1];
        strcpy_s(motor.denumire, strlen(aux) + 1, aux);
        cout << "Capacitate: ";
        iStream >> motor.capacitate;
        cout << "Electric: ";
        iStream >> motor.electric;
        cout << "nrKm : ";
        iStream >> motor.nrKm;

        return iStream;

    }

    const Motor& operator=(const Motor& motor1) {               // Operator =         
        if (this != &motor1) {
            if (this->denumire)
                delete[] this->denumire;
            this->denumire = new char[strlen(motor1.denumire) + 1];
            strcpy_s(this->denumire, strlen(motor1.denumire) + 1, motor1.denumire);
            this->capacitate = motor1.capacitate;
            this->electric = motor1.electric;
            this->nrKm = motor1.nrKm;

        }
        return *this;
    }

    //int& operator[](int index) {                                   // operator []
    //    if (index >= 0 && index < nrMotoare) {
    //        return an_motoare[index];
    //    }

    //}
    const Motor& operator++() {
        this->nrKm++;
        return *this;
    }
    const Motor& operator++(int) {                                          // operator ++ - forma II **
        Motor aux = *this;
        this->nrKm++;
        return aux;
    }

    operator float() {                                                 // operator cast implicit
        return(kmTestare + this->nrKm);
    }
    Motor operator!() {                                                // operator !
        Motor aux = *this;
        aux.capacitate = !aux.capacitate;
        return aux;
    }
    bool operator==(const Motor& motor) {                                  // operator ==
        if (this->capacitate != motor.capacitate) {
            return false;
        }
        if (this->nrKm != motor.nrKm) {
            return false;
        }
        if (this->electric != motor.electric) {
            return false;
        }
        if (this->nrKm != motor.nrKm) {
            return false;
        }
        if (this->felulAprinderii.compare(motor.felulAprinderii) != 0) {
            return false;
        }
        return true;
    }

    bool operator>=(const Motor& m) {                                   // operator >=
        return this->capacitate >= m.capacitate;
    }

    ~Motor() {                                                           // Destructor
        if (this->denumire != NULL)
        {
            delete[] this->denumire;
        }
    }

    friend ofstream& operator <<(ofstream& fisier, const Motor& m) {                 //  scriere din fisier txt
        if (m.denumire)
            fisier << m.denumire << " ";
        fisier << m.capacitate << " ";
        fisier << m.electric << " ";
        fisier << m.felulAprinderii << " ";
        fisier << m.nrKm << "| ";
        // fisier << endl;
        return fisier;
    }

    friend ifstream& operator >>(ifstream& fisier, Motor& m) {                               // citire fisier txt
        if (m.denumire) {
            delete[] m.denumire;
        }
        char aux[50];
        fisier >> aux;
        m.denumire = new char[strlen(aux) + 1];
        strcpy(m.denumire, aux);
        fisier >> m.capacitate;
        fisier >> m.electric;
        char aux2[50];
        fisier >> aux2;
        fisier >> m.nrKm;

        return fisier;
    }

    void scriereFisierBinar(fstream& f) {                                            // scriere in binar
        int lungime = strlen(this->denumire);
        f.write((char*)&lungime, sizeof(lungime));
        f.write(this->denumire, lungime);
        char aux = '\0';
        f.write((char*)&aux, sizeof(char));
        f.write((char*)&this->capacitate, sizeof(this->capacitate));
        f.write((char*)&this->electric, sizeof(this->electric));
        f.write((char*)&this->nrKm, sizeof(this->nrKm));

    }

    void citireFisierBinar(fstream& f) {                                               // citire din binar
        int lungime = 0;
        f.read((char*)&lungime, sizeof(lungime));
        if (this->denumire)
            delete[]this->denumire;
        this->denumire = new char[lungime + 1];
        f.read(this->denumire, lungime + 1);
        f.read((char*)&this->capacitate, sizeof(this->capacitate));
        f.read((char*)&this->electric, sizeof(this->electric));
        f.read((char*)&this->nrKm, sizeof(this->nrKm));
    }

};
int Motor::kmTestare = 20;
ostream& operator<<(ostream& oStream, const Motor& motor) {                                                                                            // operator <<
    if (motor.getDenumire() != NULL) {
        oStream << "\nMotor -> | Denumire: " << motor.getDenumire();
    }
    if (motor.getCapacitate() != NULL) {
        oStream << "| Capacitate: " << motor.getCapacitate();
    }
    if (motor.getElectric() == true || motor.getElectric() == false) {
        oStream << "| Electricitate: " << motor.getElectric();
    }
    if (size(motor.getFelulAprinderii()) != 0) {
        oStream << "| Felul aprinderii: " << motor.getFelulAprinderii();
    }
    if (motor.getSerieMotor() != NULL) {
        oStream << "| Serie motor: " << motor.getSerieMotor();
    }
    if (motor.getnrKm() != NULL) {
        oStream << "| Nr. km: " << motor.getnrKm() << " ";
    }

    return oStream;
}


Motor operator+(const Motor& m1, const Motor& m2) {            // operator +
    Motor m = m1;
    m.setCapacitate(m1.getCapacitate() + m2.getCapacitate());
    return m;
}

class Sasiu {
private:
    char* denumire;
    int nrAxe;
    const string tipSasiu;
    static int serieProba;
    int serieSasiu;
    bool defect;
public:

    Sasiu(const char* denumire = "Sasiu", bool defect = false, int nrAxe = 1, const string tipSasiu = "automobile") :tipSasiu("automobile")                        // constructor 1
    {
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
        this->nrAxe = nrAxe;
        this->defect = defect;
    }
    Sasiu(const char* denumire, int nrAxe, const string tipSasiu) :tipSasiu("motocicleta") {                              // constructor 2
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
        this->nrAxe = nrAxe;
    }
    Sasiu(const Sasiu& s) {                                                                                                  // Constructor de copiere
        if (s.denumire != NULL) {
            this->denumire = new char[strlen(s.denumire) + 1];
            strcpy_s(this->denumire, strlen(s.denumire) + 1, s.denumire);
        }
        else
            denumire = NULL;
        this->nrAxe = s.nrAxe;
        this->defect = s.defect;
    }


    char* getDenumire() const {                                       // afisare denumire
        return this->denumire;
    }
    void setDenumire(const char* denumire) {                // prelucrare denumire
        if (denumire && strlen(denumire) > 2) {
            if (this->denumire) {
                delete[]this->denumire;
            }
            this->denumire = new char[strlen(denumire) + 1];
            strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
        }
    }

    int getNrAxe()const {                                     // get nrAxe
        return this->nrAxe;
    }

    void setNrAxe(int modificareNrAxe) {                     // set nrAxe
        if (nrAxe != modificareNrAxe)
            nrAxe = modificareNrAxe;
    }
    const string getTipSasiu()const {                         // get tipSasiu
        return this->tipSasiu;
    }

    bool getDefect() const {                                      // get defect
        return defect;
    }
    void setDefect(int modificareDefect) {                  // set defect
        if (defect != modificareDefect)
            defect = modificareDefect;
    }
    int getSerieSasiu() const {
        return this->serieSasiu;
    }
    void setSerieSasiu(int modificareSerieSasiu) {
        if (this->serieSasiu != modificareSerieSasiu)
            this->serieSasiu = modificareSerieSasiu;
    }


    friend istream& operator >>(istream& iStream, Sasiu& s) {                                                                      // operator >>
        char aux[20];
        cout << "Denumire: ";
        iStream >> aux;
        if (s.denumire != NULL) {
            delete[]s.denumire;
        }
        s.denumire = new char[strlen(aux) + 1];
        strcpy_s(s.denumire, strlen(aux) + 1, aux);
        cout << "NrAxe: ";
        iStream >> s.nrAxe;
        cout << "Defect: ";
        iStream >> s.defect;

        return iStream;
    }
    const Sasiu& operator=(const Sasiu& s) {               // Operator =         
        if (this != &s) {
            if (this->denumire)
                delete[] this->denumire;
            this->denumire = new char[strlen(s.denumire) + 1];
            strcpy_s(this->denumire, strlen(s.denumire) + 1, s.denumire);
            this->nrAxe = s.nrAxe;
            this->defect = s.defect;
        }
        return *this;
    }

    const Sasiu& operator++() {                                            // operator ++ - forma I
        this->nrAxe++;
        return *this;
    }
    const Sasiu& operator++(int) {                                          // operator ++ - forma II **
        Sasiu aux = *this;
        this->nrAxe++;
        return aux;
    }

    operator float() {                                                 // operator cast implicit
        return(serieProba + this->serieSasiu);
    }
    Sasiu operator!() {                                                // operator !
        Sasiu aux = *this;
        aux.nrAxe = !aux.nrAxe;
        return aux;
    }
    bool operator==(const Sasiu& s) {                                  // operator ==
        if (this->nrAxe != s.nrAxe) {
            return false;
        }
        if (this->serieSasiu != s.serieSasiu) {
            return false;
        }
        if (this->defect != s.defect) {
            return false;
        }
        if (this->tipSasiu.compare(s.tipSasiu) != 0) {
            return false;
        }
        return true;
    }
    bool operator>=(const Sasiu& s) {                                   // operator >=
        return this->nrAxe >= s.nrAxe;
    }

    ~Sasiu() {                                                           // Destructor
        if (this->denumire != NULL)
        {
            delete[] this->denumire;
        }
    }
    friend ofstream& operator <<(ofstream& fisier, const Sasiu& s) {                 //  scriere fisier txt
        if (s.denumire)
            fisier << s.denumire << " ";
        fisier << s.nrAxe << " ";
        fisier << s.serieSasiu << " ";
        fisier << s.tipSasiu << " ";
        fisier << s.defect << "| ";
        //fisier << endl;
        return fisier;
    }

    friend ifstream& operator >>(ifstream& fisier, Sasiu& s) {                               // citire fisier txt
        if (s.denumire) {
            delete[] s.denumire;
        }
        char aux[50];
        fisier >> aux;
        s.denumire = new char[strlen(aux) + 1];
        strcpy(s.denumire, aux);
        fisier >> s.nrAxe;
        fisier >> s.serieSasiu;
        char aux2[50];
        fisier >> aux2;
        fisier >> s.defect;

        return fisier;
    }

    void scriereFisierBinar(fstream& f) {                                            // scriere in binar
        int lungime = strlen(this->denumire);
        f.write((char*)&lungime, sizeof(lungime));
        f.write(this->denumire, lungime);
        char aux = '\0';
        f.write((char*)&aux, sizeof(char));
        f.write((char*)this->nrAxe, sizeof(this->nrAxe));
        f.write((char*)this->serieSasiu, sizeof(this->serieSasiu));
        f.write((char*)this->defect, sizeof(this->defect));

    }

    void citesteFisierBinar(fstream& f) {                                               // citire din binar
        int lungime = 0;
        f.read((char*)&lungime, sizeof(lungime));
        if (this->denumire)
            delete[]this->denumire;
        this->denumire = new char[lungime + 1];
        f.read(this->denumire, lungime + 1);
        f.read((char*)&this->nrAxe, sizeof(this->nrAxe));
        f.read((char*)&this->serieSasiu, sizeof(this->serieSasiu));
        f.read((char*)&this->defect, sizeof(this->defect));
    }

};
static int serieProba = 620;

ostream& operator <<(ostream& oStream, const Sasiu& s) {                                                                         // operator <<
    oStream << "\nSasiu -> ";
    if (s.getDenumire() != NULL) {
        oStream << "| Denumire:" << s.getDenumire();
    }
    if (s.getDefect() == true || s.getDefect() == false) {
        oStream << "| Defect: " << s.getDefect();
    }
    if (s.getNrAxe() != NULL) {
        oStream << "| Numar axe: " << s.getNrAxe();
    }
    if (size(s.getTipSasiu()) != NULL) {
        oStream << "| Tip sasiu:  " << s.getTipSasiu() << " ";
    }

    return oStream;
}

Sasiu operator+(const Sasiu& s1, const Sasiu& s2) {            // operator +
    Sasiu s = s1;
    s.setNrAxe(s1.getNrAxe() + s2.getNrAxe());
    return s;
}

class Distributie {
private:
    char* producator;
    int garantie;
    float pret;
    bool patruTimpi;
    static int TVA;
    const string tipDistributie;

public:
    Distributie(const char* producator = "Prod", bool patruTimpi = false, int garantie = 1, const string tipDistributie = "Curea", float pret = 10) :tipDistributie("Curea") {           // Constructor 1
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->garantie = garantie;
        this->pret = pret;
        this->patruTimpi = patruTimpi;
    }
    Distributie(const char* producator, int garantie, const string tipDistributie, float pret) :tipDistributie("Curea") {                        // Constructor 2
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->garantie = garantie;
        this->pret = pret;
    }
    Distributie(const Distributie& d) {                                                                                                  // Constructor de copiere
        if (d.producator != NULL) {
            this->producator = new char[strlen(d.producator) + 1];
            strcpy_s(this->producator, strlen(d.producator) + 1, d.producator);
        }
        else
            producator = NULL;
        this->garantie = d.garantie;
        this->patruTimpi = d.patruTimpi;
        this->pret = d.pret;
    }
    char* getProducator() const {                                       // get producator
        return this->producator;
    }
    void setDenumire(const char* producator) {                // set producator
        if (producator && strlen(producator) > 2) {
            if (this->producator) {
                delete[]this->producator;
            }
            this->producator = new char[strlen(producator) + 1];
            strcpy_s(this->producator, strlen(producator) + 1, producator);
        }
    }
    int getGarantie()const {                         // get garantie
        return this->garantie;
    }

    void setGarantie(int modificareGarantie) {           // set garantie 
        if (garantie != modificareGarantie)
            garantie = modificareGarantie;
    }

    bool getPatruTimpi() const {                                      // get patruTimpi
        return this->patruTimpi;
    }
    void setPatruTimpi(int modificarePatruTimpi) {                  // set patruTimpi
        if (patruTimpi != modificarePatruTimpi)
            this->patruTimpi = modificarePatruTimpi;
    }

    float getPret()const {                                    // get pret
        return this->pret;
    }
    void setPret(int modificarePret) {             // set pret
        if (this->pret != modificarePret)
            this->pret = modificarePret;
    }
    const string getTipDistributie()const {                         // get tipSasiu
        return this->tipDistributie;
    }

    friend istream& operator >>(istream& iStream, Distributie& d) {                                                                      // operator >>
        char aux[20];
        cout << "Producator: ";
        iStream >> aux;
        if (d.producator != NULL) {
            delete[]d.producator;
        }
        d.producator = new char[strlen(aux) + 1];
        strcpy_s(d.producator, strlen(aux) + 1, aux);
        cout << "Garantie ";
        iStream >> d.garantie;
        cout << "Patru Timpi? : ";
        iStream >> d.patruTimpi;
        cout << "Pret: ";
        iStream >> d.pret;

        return iStream;
    }
    const Distributie& operator=(const Distributie& d) {               // Operator =         
        if (this != &d) {
            if (this->producator)
                delete[] this->producator;
            this->producator = new char[strlen(d.producator) + 1];
            strcpy_s(this->producator, strlen(d.producator) + 1, d.producator);
            this->pret = d.pret;
            this->patruTimpi = d.patruTimpi;
            this->garantie = d.garantie;
        }
        return *this;
    }

    const Distributie& operator++() {                                            // operator ++ - forma I
        this->garantie++;
        return *this;
    }
    const Distributie& operator++(int) {                                          // operator ++ - forma II **
        Distributie aux = *this;
        this->garantie++;
        return aux;
    }
    operator float() {                                                 // operator cast implicit ( pret + tva )
        return(TVA + this->pret);
    }
    Distributie operator!() {                                                // operator !
        Distributie aux = *this;
        aux.garantie = !aux.garantie;
        return aux;
    }
    bool operator==(const Distributie& d) {                                  // operator ==
        if (this->garantie != d.garantie) {
            return false;
        }
        if (this->pret != d.pret) {
            return false;
        }
        if (this->patruTimpi != d.patruTimpi) {
            return false;
        }
        if (this->tipDistributie.compare(d.tipDistributie) != 0) {
            return false;
        }
        return true;
    }
    bool operator>=(const Distributie& d) {                                   // operator >=
        return this->garantie >= d.garantie;
    }
    ~Distributie() {                                                           // Destructor
        if (this->producator != NULL)
        {
            delete[] this->producator;
        }
    }
    friend ofstream& operator <<(ofstream& fisier, const Distributie& d) {                 //  scriere fisier txt
        if (d.producator)
            fisier << d.producator << " ";
        fisier << d.garantie << " ";
        fisier << d.pret << " ";
        fisier << d.tipDistributie << " ";
        fisier << d.patruTimpi << " ";
        fisier << endl;
        return fisier;
    }

    friend ifstream& operator >>(ifstream& fisier, Distributie& d) {                               // citire fisier txt
        if (d.producator) {
            delete[] d.producator;
        }
        char aux[50];
        fisier >> aux;
        d.producator = new char[strlen(aux) + 1];
        strcpy(d.producator, aux);
        fisier >> d.garantie;
        fisier >> d.pret;
        char aux2[50];
        fisier >> aux2;
        fisier >> d.patruTimpi;

        return fisier;
    }

    void scriereFisierBinar(fstream& f) {                                            // scriere in binar
        int lungime = strlen(this->producator);
        f.write((char*)&lungime, sizeof(lungime));
        f.write(this->producator, lungime);
        char aux = '\0';
        f.write((char*)&aux, sizeof(char));
        f.write((char*)&this->garantie, sizeof(this->garantie));
        f.write((char*)&this->pret, sizeof(this->pret));
        f.write((char*)&this->patruTimpi, sizeof(this->patruTimpi));

    }

    void citesteFisierBinar(fstream& f) {                                               // citire din binar
        int lungime = 0;
        f.read((char*)&lungime, sizeof(lungime));
        if (this->producator)
            delete[]this->producator;
        this->producator = new char[lungime + 1];
        f.read(this->producator, lungime + 1);
        f.read((char*)&this->garantie, sizeof(this->garantie));
        f.read((char*)&this->pret, sizeof(this->pret));
        f.read((char*)&this->patruTimpi, sizeof(this->patruTimpi));
    }

};
static int TVA = 5;
ostream& operator <<(ostream& oStream, const Distributie& d) {                                                                         // operator <<
    oStream << "\nDistributie -> ";
    if (d.getProducator() != NULL) {
        oStream << "| Producator: " << d.getProducator();
    }
    if (d.getGarantie() != NULL) {
        oStream << "| Garantie: " << d.getGarantie();
    }
    if (d.getPret() != NULL) {
        oStream << "| Pret: " << d.getPret();
    }
    if (d.getPatruTimpi() == false || d.getPatruTimpi() == true) {
        oStream << "| Patru timpi: " << d.getPatruTimpi();
    }
    if (size(d.getTipDistributie()) != NULL) {
        oStream << "| Tip distributie: " << d.getTipDistributie() << " ";
    }
    return oStream;
}

Distributie operator+(Distributie& d1, Distributie& d2) {            // operator + /verifica
    Distributie d = d1;
    d.setPret(d1.getPret() + d2.getPret());
    return d;
}


class Ambreiaj {
private:
    char* producator;
    int anFabricatie;
    float pret;
    static int serieProba1;
    int serieAmbreiaj;
    const string tipAmbreiaj;
    bool activ = false;

public:
    Ambreiaj() {
        this->anFabricatie = 2000;
        this->pret = 0;
    };
    Ambreiaj(const char* producator, int anFabricatie, float pret, int serieAmbreiaj, const string tipAmbreiaj) :tipAmbreiaj(" umed ") {            // constructor 1
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->serieAmbreiaj = serieAmbreiaj;
        this->anFabricatie = anFabricatie;
        this->pret = pret;

    }
    Ambreiaj(const char* producator, float pret, int serieAmbreiaj, const string tipAmbreiaj) :tipAmbreiaj(" uscat ") {                    // constructor 2
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->serieAmbreiaj = serieAmbreiaj;
        this->pret = pret;
    }

    Ambreiaj(const Ambreiaj& a1) {                                         // Constructor de copiere
        if (a1.producator != NULL) {
            this->producator = new char[strlen(a1.producator) + 1];
            strcpy_s(this->producator, strlen(a1.producator) + 1, a1.producator);
        }
        else
            producator = NULL;
        this->serieAmbreiaj = a1.serieAmbreiaj;
        this->pret = a1.pret;
        this->anFabricatie = a1.anFabricatie;
    }


    char* getProducator() const {                                       // get producator
        return this->producator;
    }

    void setProducator() {                                          // set producator
        if (producator && strlen(producator) > 2) {
            if (this->producator) {
                delete[]this->producator;
            }
            this->producator = new char[strlen(producator) + 1];
            strcpy_s(this->producator, strlen(producator) + 1, producator);
        }
    }
    int getSerieAmbreiaj()const {                                    // get serieAmbreiaj
        return this->serieAmbreiaj;
    }

    void setSerieAmbreiaj(int modificareSerie) {                // set serieAmbreiaj
        if (serieAmbreiaj != modificareSerie)
            serieAmbreiaj = modificareSerie;
    }

    float getPret()const {                                           // get pret
        return this->pret;
    }

    void setPret(float modificarePret) {                        // set pret
        if (pret != modificarePret)
            pret = modificarePret;
    }

    int getAnFabricatie()const {                                    // get anFabricatie
        return this->anFabricatie;
    }

    void setAnFabricatie(int modificareAnFabricatie) {         // set anFabricatie
        if (anFabricatie != modificareAnFabricatie)
            anFabricatie = modificareAnFabricatie;
    }
    const string getTipAmbreiaj()const {                         // get tipAmbreiaj
        return this->tipAmbreiaj;
    }
    bool getActiv()const {                                         // get stare ambreiaj
        return this->activ;
    }
    void setActiv(bool modificareActiv) {                               // set stare ambreiaj
        if (modificareActiv != true && modificareActiv != false) {
            return;
        }

        activ = modificareActiv;
    }

    virtual void activareAmbreiaj() {                                    // functie virtuala activare ambreiaj
        setActiv(true);
    };

    friend istream& operator >>(istream& iStream, Ambreiaj& a) {                     // operator >>
        cout << "Producator: ";

        char aux[20];
        iStream >> aux;
        if (a.producator != NULL) {
            delete[]a.producator;
        }
        a.producator = new char[strlen(aux) + 1];
        strcpy_s(a.producator, strlen(aux) + 1, aux);

        cout << "Pret: ";
        iStream >> a.pret;

        cout << "Anul fabricarii: ";
        iStream >> a.anFabricatie;

        cout << "Serie ambreiaj: ";
        iStream >> a.serieAmbreiaj;

        return iStream;
    }
    const Ambreiaj& operator=(const Ambreiaj& a) {                // operator =
        if (this != &a) {
            if (this->producator)
                delete[] this->producator;
            this->producator = new char[strlen(a.producator) + 1];
            strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
            this->serieAmbreiaj = a.serieAmbreiaj;
            this->anFabricatie = a.anFabricatie;
            this->pret = a.pret;
        }
        return *this;
    }

    const Ambreiaj& operator ++() {                                           // operator ++ - forma I
        this->pret++;
        return *this;
    }
    const Ambreiaj& operator++(int) {                                        // operator ++ - forma II **
        Ambreiaj aux = *this;
        this->pret++;
        return aux;
    }

    operator float() {                                                      // operator cast implicit
        return(serieProba1 + this->serieAmbreiaj);
    }

    Ambreiaj operator !() {
        Ambreiaj aux = *this;
        aux.anFabricatie = !aux.anFabricatie;
        return aux;
    }

    bool operator == (const Ambreiaj& a) {                                // operator ==
        if (this->anFabricatie != a.anFabricatie)
            return false;
        if (this->pret != a.pret)
            return false;
        if (this->serieAmbreiaj != a.serieAmbreiaj)
            return false;
        if (this->tipAmbreiaj.compare(a.tipAmbreiaj) != 0)
            return false;
        return true;
    }
    bool operator >=(const Ambreiaj& a) {                                // operator >=
        return this->pret >= a.pret;
    }

    ~Ambreiaj() {                                                         // destructor
        if (this->producator != NULL)
            delete[] this->producator;
    }
    friend ofstream& operator <<(ofstream& fisier, const Ambreiaj& a) {                 //  scriere fisier txt
        if (a.producator)
            fisier << a.producator << " ";
        fisier << a.anFabricatie << " ";
        fisier << a.pret << " ";
        fisier << a.tipAmbreiaj << " ";
        fisier << a.serieAmbreiaj << "| ";
        // fisier << endl;
        return fisier;
    }

    friend ifstream& operator >>(ifstream& fisier, Ambreiaj& a) {                               // citire fisier txt
        if (a.producator) {
            delete[] a.producator;
        }
        char aux[50];
        fisier >> aux;
        a.producator = new char[strlen(aux) + 1];
        strcpy(a.producator, aux);
        fisier >> a.anFabricatie;
        fisier >> a.pret;
        char aux2[50];
        fisier >> aux2;
        fisier >> a.serieAmbreiaj;

        return fisier;
    }

    void scriereFisierBinar(fstream& f) {                                            // scriere in binar
        int lungime = strlen(this->producator);
        f.write((char*)&lungime, sizeof(lungime));
        f.write(this->producator, lungime);
        char aux = '\0';
        f.write((char*)&aux, sizeof(char));
        f.write((char*)&this->anFabricatie, sizeof(this->anFabricatie));
        f.write((char*)&this->pret, sizeof(this->pret));
        f.write((char*)&this->serieAmbreiaj, sizeof(this->serieAmbreiaj));

    }

    void citesteFisierBinar(fstream& f) {                                               // citire din binar
        int lungime = 0;
        f.read((char*)&lungime, sizeof(lungime));
        if (this->producator)
            delete[]this->producator;
        this->producator = new char[lungime + 1];
        f.read(this->producator, lungime + 1);
        f.read((char*)&this->anFabricatie, sizeof(this->anFabricatie));
        f.read((char*)&this->pret, sizeof(this->pret));
        f.read((char*)&this->serieAmbreiaj, sizeof(this->serieAmbreiaj));
    }

};
static int serieProba1 = 213;
ostream& operator <<(ostream& oStream, const Ambreiaj& a) {                                                                                            // operator <<                       

    oStream << "\nAmbreiaj -> ";
    if (a.getProducator() != NULL) {
        oStream << "| Producator: " << a.getProducator();
    }
    if (a.getAnFabricatie() != NULL) {
        oStream << "| An fabricatie: " << a.getAnFabricatie();
    }
    if (a.getPret() != NULL) {
        oStream << "| Pret: " << a.getPret();
    }
    if (size(a.getTipAmbreiaj()) != NULL) {
        oStream << "| Tip ambreiaj: " << a.getTipAmbreiaj();
    }
    if (a.getSerieAmbreiaj() != NULL) {
        oStream << "| Serie ambreiaj: " << a.getSerieAmbreiaj() << " ";
    }
    return oStream;
}


Ambreiaj operator+(Ambreiaj& a1, Ambreiaj& a2) {            // operator + 
    Ambreiaj a = a1;
    a.setPret(a1.getPret() + a2.getPret());
    return a;
}

// Masina* masini = [Masina(1), Masina(2)];
// &masini[1].ambreiaj.getActiv();

class CutieDeViteze {
private:
    char* producator;
    float pret;
    int caiPutere;
    bool secondHand;
    static int nrTrepte;
    const string tipCutie;
    static int stage1;
    int vitezaCurenta; // get set
public:

    CutieDeViteze(const char* producator = "2", float pret = 1.2, int caiPutere = 500, bool secondHand = false, const string tipCutie = "Manuala") : tipCutie("Manuala ") {                 // constructor 1
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->pret = pret;
        this->caiPutere = caiPutere;
        this->secondHand = secondHand;
    }

    CutieDeViteze(const char* producator, float pret, int caiPutere, const string tipCutie) : tipCutie("Automata ") {                 // constructor 2
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->pret = pret;
        this->caiPutere = caiPutere;
    }

    CutieDeViteze(const CutieDeViteze& cv) {                                                                                     // constructor de copiere
        if (cv.producator != NULL) {
            this->producator = new char[strlen(cv.producator) + 1];
            strcpy_s(this->producator, strlen(cv.producator) + 1, cv.producator);
        }
        else
            producator = NULL;
        this->pret = cv.pret;
        this->caiPutere = cv.caiPutere;
        this->secondHand = cv.secondHand;
    }
    int getVitezaCurenta() {
        return this->vitezaCurenta;
    }

    void setVitezaCurenta(int viteza) {
        if (viteza < 0) {
            return;
        }
        this->vitezaCurenta = viteza;
    }

    char* getProducator()const {                                       // get producator
        return this->producator;
    }

    void setProducator() {                                          // set producator
        if (producator && strlen(producator) > 2) {
            if (this->producator) {
                delete[]this->producator;
            }
            this->producator = new char[strlen(producator) + 1];
            strcpy_s(this->producator, strlen(producator) + 1, producator);
        }
    }


    float getPret()const {                                           // get pret
        return this->pret;
    }

    void setPret(float modificarePret) {                        // set pret
        if (pret != modificarePret)
            pret = modificarePret;
    }

    int getCaiPutere()const {                                         // get caiPutere
        return caiPutere;
    }

    void setCaiPutere(int modificareCaiPutere) {                 // set caiPutere
        if (modificareCaiPutere != caiPutere)
            caiPutere = modificareCaiPutere;
    }

    bool getSecondHand() const {                                        // get SecondHand
        return secondHand;
    }
    void setSecondHand(int modificareSecondHand) {             // set SecondHand
        if (secondHand != modificareSecondHand)
            secondHand = modificareSecondHand;
    }

    const string getTipCutie() const {                         // get Tip Cutie
        return tipCutie;
    }

    virtual void schimbareViteza(bool urcare) {                // metoda virtuala 
        if (urcare) {
            setVitezaCurenta(getVitezaCurenta() + 1);
            return;
        }
        setVitezaCurenta(getVitezaCurenta() - 1);
    };

    friend istream& operator>> (istream& iStream, CutieDeViteze& cv) {                                                                   // operator >> 
        char aux[20];
        cout << "Producator: ";
        iStream >> aux;
        if (cv.producator != NULL)
            delete[]cv.producator;
        cv.producator = new char[strlen(aux) + 1];
        strcpy_s(cv.producator, strlen(aux) + 1, aux);
        cout << "Pret: ";
        iStream >> cv.pret;
        cout << "Cai putere: ";
        iStream >> cv.caiPutere;
        cout << "Second hand: ";
        iStream >> cv.secondHand;
        return iStream;

    }

    const CutieDeViteze& operator=(const CutieDeViteze& cv) {                                                // operator =
        if (this != &cv) {
            if (this->producator)
                delete[] this->producator;
            this->producator = new char[strlen(cv.producator) + 1];
            strcpy_s(this->producator, strlen(cv.producator) + 1, cv.producator);
            this->pret = cv.pret;
            this->caiPutere = cv.caiPutere;
            this->secondHand = cv.secondHand;
        }
        return *this;
    }

    const CutieDeViteze& operator ++ () {                                          // operator ++ - forma I
        this->caiPutere++;
        return *this;
    }

    const CutieDeViteze& operator++(int) {                                         // operator ++ - forma II **
        CutieDeViteze aux = *this;
        this->caiPutere++;
        return aux;
    }
    operator float() {                                                              // operator cast implicit
        return(stage1 + this->caiPutere);
    }

    CutieDeViteze operator !() {                                                  // operator !
        CutieDeViteze aux = *this;
        aux.pret = !aux.pret;
        return aux;
    }
    bool operator == (const CutieDeViteze& cv) {                                         // operator ==
        if (this->pret != cv.pret)
            return false;
        if (this->caiPutere != cv.caiPutere)
            return false;
        if (this->secondHand != cv.secondHand)
            return false;
        if (this->tipCutie.compare(cv.tipCutie) != 0)
            return false;
        return true;
    }

    bool operator >=(const CutieDeViteze& cv) {                             // operator >=
        return this->pret >= cv.pret;
    }
    ~CutieDeViteze() {                                               // destructor
        if (this->producator != NULL)
            delete[] this->producator;
    }

    friend ofstream& operator <<(ofstream& fisier, const CutieDeViteze& cv) {                 //  scriere fisier txt
        if (cv.producator)
            fisier << cv.producator << " ";
        fisier << cv.pret << " ";
        fisier << cv.caiPutere << " ";
        fisier << cv.tipCutie << " ";
        fisier << cv.secondHand << "| ";
        //fisier << endl;
        return fisier;
    }

    friend ifstream& operator >>(ifstream& fisier, CutieDeViteze& cv) {                               // citire fisier txt
        if (cv.producator) {
            delete[] cv.producator;
        }
        char aux[50];
        fisier >> aux;
        cv.producator = new char[strlen(aux) + 1];
        strcpy(cv.producator, aux);
        fisier >> cv.pret;
        fisier >> cv.caiPutere;
        char aux2[50];
        fisier >> aux2;
        fisier >> cv.secondHand;

        return fisier;
    }

    void scriereFisierBinar(fstream& f) {                                            // scriere in binar
        int lungime = strlen(this->producator);
        f.write((char*)&lungime, sizeof(lungime));
        f.write(this->producator, lungime);
        char aux = '\0';
        f.write((char*)&aux, sizeof(char));
        f.write((char*)&this->pret, sizeof(this->pret));
        f.write((char*)&this->caiPutere, sizeof(this->caiPutere));
        f.write((char*)&this->secondHand, sizeof(this->secondHand));

    }

    void citesteFisierBinar(fstream& f) {                                               // citire din binar
        int lungime = 0;
        f.read((char*)&lungime, sizeof(lungime));
        if (this->producator)
            delete[]this->producator;
        this->producator = new char[lungime + 1];
        f.read(this->producator, lungime + 1);
        f.read((char*)&this->pret, sizeof(this->pret));
        f.read((char*)&this->caiPutere, sizeof(this->caiPutere));
        f.read((char*)&this->secondHand, sizeof(this->secondHand));
    }

};
static int stage1 = 30;
ostream& operator << (ostream& oStream, const CutieDeViteze& cv) {                                                                   // operator << 

    oStream << "\nCutie de viteze -> ";
    if (cv.getProducator() != NULL) {
        oStream << "| Producator: " << cv.getProducator();
    }
    if (cv.getPret() != NULL) {
        oStream << "| Pret: " << cv.getPret();
    }
    if (cv.getCaiPutere() != NULL) {
        oStream << "| Cai putere: " << cv.getCaiPutere();
    }
    if (cv.getSecondHand() != NULL) {
        oStream << "| Second hand: " << cv.getSecondHand();
    }
    if (size(cv.getTipCutie()) != NULL) {
        oStream << "| Tip cutie: " << cv.getTipCutie() << " ";
    }
    return oStream;
}


CutieDeViteze operator+(CutieDeViteze& cv1, CutieDeViteze& cv2) {            // operator + // de verificat
    CutieDeViteze cv = cv1;
    cv.setPret(cv1.getPret() + cv2.getPret());
    return cv;
}


class Masina {
public:
    Ambreiaj ambreiaj;
    CutieDeViteze cutieDeViteze;
    Distributie distributie;
    Motor motor;
    Sasiu sasiu;

    bool pornit = false;
    int nivelClima = 0;
    int vitezaCurenta = 0;
public:

    int getNivelClima() {                            // get functie virtuala nivel clima
        return nivelClima;
    }
    void setNivelClima(bool urcare) {              // set functie virtuala nivel clima
        if (urcare) {
            this->nivelClima++;
            return;
        }
        this->nivelClima--;
    }
    bool getPornit() {                                // get functie virtuala pornit
        return this->pornit;
    }

    void setPornit(bool modificarePornit) {              // set functie virtuala pornit
        if (modificarePornit != true && modificarePornit != false) {
            return;
        }
        pornit = modificarePornit;
    }

    Motor getMotor()const {               //get motor 
        return motor;
    }
    void setMotor(Motor m)const {             // set motor ??

    }


    Ambreiaj getAmbreiaj()const {              // get ambreiaj
        return ambreiaj;
    }

    void setAmbreiaj(Ambreiaj a)const {     // set ambreiaj    
       // this->ambreiaj = a;
    }

    Distributie getDistributie() const {              // get distributie
        return distributie;
    }
    void setDistributie(Distributie d)const {             // set distributie ??

    }

    CutieDeViteze getCutieDeViteze()const {              // get cutie de viteze
        return cutieDeViteze;
    }
    void setCutieDeViteze(CutieDeViteze cv) {                   // set cutie de viteze ??

    }

    Sasiu getSasiu() const {               // get sasiu
        return sasiu;
    }
    void setSasiu(Sasiu s) {           // set sasiu

    }



    friend istream& operator >>(istream& iStream, Masina& m) {          // operator >>
        cout << "Ambreiaj -> ";
        iStream >> m.ambreiaj;

        cout << "Motor -> ";
        iStream >> m.motor;

        cout << "Distributie-> ";
        iStream >> m.distributie;

        cout << "Cutie de viteze -> ";
        iStream >> m.cutieDeViteze;

        cout << "Sasiu -> ";
        iStream >> m.sasiu;

        return iStream;
    }




    virtual void startStop() = 0;
    virtual void modificareClima(bool urcare) = 0;

    Masina() {};

};
ostream& operator << (ostream& oStream, const Masina& m) {                                                                   // operator << 
    oStream << m.getAmbreiaj() << m.getMotor() << m.getDistributie() << m.getCutieDeViteze() << m.getSasiu() << endl << endl;
    return oStream;
}

class FormulaUnu : public Masina {
public:
    void startStop() {
        if (getPornit()) {
            setPornit(false);
            return;
        }
        setPornit(true);
    };
    void modificareClima(bool urcare) {
        setNivelClima(urcare);
    };

    void schimbareViteza(int viteza) {
        if (viteza < 0) {
            return;
        }
        this->vitezaCurenta = viteza;
    };

    FormulaUnu() {};


    friend ofstream& operator <<(ofstream& fisierM, const FormulaUnu& f) {
        fisierM << f.motor << " ";
        fisierM << f.ambreiaj << " ";
        fisierM << f.cutieDeViteze << " ";
        fisierM << f.sasiu << " ";
        fisierM << f.distributie << " ";
        return fisierM;
    }
    friend ifstream& operator >>(ifstream& fisierM, FormulaUnu& f) {
        cout << "Motor -> ";
        fisierM >> f.motor;

        cout << "Ambreiaj -> ";
        fisierM >> f.ambreiaj;

        cout << "Cutie de viteze -> ";
        fisierM >> f.cutieDeViteze;

        cout << "Sasiu -> ";
        fisierM >> f.sasiu;

        cout << "Distributie-> ";
        fisierM >> f.distributie;

        return fisierM;
    }

};
class motorUzat : public Motor {
private:
    bool stricat;
    int nrKM;
public:
    motorUzat() :Motor("Audi", 3000, false, "ardere", 263635633, 12) {
        this->stricat = true;
        this->nrKM = 1000000;
    }
 };


int main()
{
    //Motor
// Constructori cu parametri 

    Motor m1("Audi", 3000, false, "ardere", 263635633, 12);
    Motor m2("BMW", 2000, false, "ardere", 3);

    // Constructor copiere && operator <<

    Motor m3 = m2;
    cout << m3.getCapacitate() << endl;

    // Gets and Sets

    cout << "Valori nemodificate motor 1: " << m1.getDenumire() << " " << m1.getCapacitate() << " " << m1.getElectric() << " " << m1.getSerieMotor() << " " << m1.getFelulAprinderii() << " " << m1.getnrKm() << endl;
    cout << "Valori nemodificate motor 2: " << m2.getDenumire() << " " << m2.getCapacitate() << " " << m2.getElectric() << " " << m2.getFelulAprinderii() << " " << m2.getnrKm() << endl;

    m1.setDenumire("Opel");
    m1.setCapacitate(1500);
    m1.setElectric(true);
    m1.setSerieMotor(36324241346);
    m1.setNrKm(40);


    cout << "Valori modificate motor 1: " << m1.getDenumire() << " " << m1.getCapacitate() << " " << m1.getElectric() << " " << m1.getSerieMotor() << " " << m1.getFelulAprinderii() << " " << m1.getnrKm() << endl;

    // operator >>
    cout << "Valori pentru motorul 3: " << endl;
    // cin >> m3;

     // operator =        
    m3 = m2;
    cout << "Denumirea pentru motorul 3 dupa egalarea cu motorul 2 : " << m3.getDenumire() << endl;

    // operator +

    m3 = m1 + m2;
    cout << "Capacitatea motorului 3 dupa adunarea motoarelor 1 si 2 : " << m3.getCapacitate() << endl;

    // operator ++ ->forma I + forma II 

    cout << "Valori motor 1: " << m1.getDenumire() << " " << m1.getCapacitate() << " " << m1.getElectric() << " " << m1.getSerieMotor() << " " << m1.getFelulAprinderii() << " " << m1.getnrKm() << endl;

    /* m1 = m2++;
     cout << "Valori motor 1 dupa m2++ : " << m1.getDenumire() << " " << m1.getCapacitate() << " " << m1.getElectric() << " " << m1.getSerieMotor() << " " << m1.getFelulAprinderii()<<" " << m1.getnrKm() << endl;*/
    m1 = ++m2;
    cout << "Valori motor 1 dupa ++mt2 : " << m1.getDenumire() << " " << m1.getCapacitate() << " " << m1.getElectric() << " " << m1.getSerieMotor() << " " << m1.getFelulAprinderii() << " " << m1.getnrKm() << endl;

    // operator cast implicit

    float totalKm = (float)m1;
    cout << "Total km motor 1: " << totalKm << endl;

    // operatorul !

    // operatorul  ==
    m2 = m3;

    if (m2 == m3) {
        cout << "Sunt egale" << endl;
    }
    else {
        cout << "NU sunt egale" << endl;
    }
    //  operatorul >=
    Motor m4("Audi", 1000, false, "ardere", 263635633, 12);
    cout << "Valori motor 4: " << m4.getDenumire() << " " << m4.getCapacitate() << " " << m4.getElectric() << " " << m4.getSerieMotor() << " " << m4.getFelulAprinderii() << " " << m4.getnrKm() << endl;
    if (m4 >= m2) {
        cout << "Capacitatea motorului 4 este mai mare" << endl;
    }
    else {
        cout << "Capacitatea motorului 2 e mai mare." << endl;
    }

    // operatorul []


    // scriere in fisier txt
    ofstream fisier("fisier.txt", ios::out);
    Motor motor1("Audi", 3000, false, "ardere", 263635633, 12);
    Motor motor2("BMW", 2000, false, "ardere", 3);
    Motor motor3("Opel", 1500, true, "scanteie", 20);

    fisier << motor1;
    fisier << motor2;
    fisier.close();

    // citire din fisier txt
    ifstream fisierInput("fisier.txt", ios::in);
    fisierInput >> motor2;
    cout << motor2;


    // scriere in fisier binar
    fstream fIn("fisier1043.bin", ios::out | ios::binary);
    motor3.scriereFisierBinar(fIn);
    fIn.close();

    // citire din fisier binar
    fstream fOut("fisier1043.bin", ios::in | ios::binary);
    motor3.citireFisierBinar(fOut);
    fOut.close();
    cout << motor3;

    Motor motorFerari("Ferrari", 2000, false, "ardere", 3);
    Motor motorLamb("Lamb", 1500, true, "scanteie", 20);

    vector<FormulaUnu> masini;


    int tastaUtilizator = 1;
    bool flagRaportMasina = false;
    int nr = 0;
    int nr2 = 0;

    ofstream fisierMO("fisierM.txt", ios::out);
    ifstream fisierMI("fisierM.txt", ios::in);
    string str;

    // meniu
    while (true)
    {
        FormulaUnu mUtilizator;

        cout << "\n \nIesire meniu -> tasta 0" << endl;
        cout << "Introducere masina -> tasta 1 " << endl;
        cout << "Generare raport -> tasta 2" << endl;
        cout << "Tasta = ";
        cin >> tastaUtilizator;
        cout << endl;
        cout << "Ati apasat tasta " << tastaUtilizator;
        cout << endl;

        if (tastaUtilizator == 0) {
            break;
        }

        if (flagRaportMasina) {

            flagRaportMasina = false;

            cout << "Detalii masina: " << tastaUtilizator << endl;
            cout << masini[tastaUtilizator - 1].getMotor() << masini[tastaUtilizator - 1].getAmbreiaj() << masini[tastaUtilizator - 1].getCutieDeViteze() << masini[tastaUtilizator - 1].getDistributie() << masini[tastaUtilizator - 1].getSasiu() << endl;
        }
        else {
            switch (tastaUtilizator)
            {
            case 1:
                cout << "Introduceti datele \n";
                cin >> mUtilizator;
                masini.push_back(mUtilizator);
                fisierMO << mUtilizator;
                fisierMO.close();
                break;
            case 2:
                cout << "Afisare raport masina -> tasta 3 " << endl;
                cout << "Afisare raport fabrica -> tasta 4 " << endl;
                break;
            case 3:
                cout << "Lista masini " << endl;
                while (getline(fisierMI, str))
                {
                    nr++;
                    cout << "Masina numarul " << nr << endl;
                }

                flagRaportMasina = true;

                if (nr <= 1) {
                    cout << "Nu exista masini inregistrate." << endl;
                    flagRaportMasina = false;
                    break;

                }
                cout << "Alegeti o tasta de la 1 la " << nr - 1 << " pentru vizualizare detalii";
                break;


            case 4:
                cout << "Generam raportul fabricii...\n";
                nr2 = 0;
                while (getline(fisierMI, str))
                {
                    nr2++;
                    cout << "Masina numarul " << nr2 << endl;
                    cout << str << " \n";
                }

                break;
            default:
                cout << "Va rugam sa alegeti o tasta din meniu! \n";
                break;
            }
        }

        cout << endl;
    }




    Ambreiaj abr;
    abr.activareAmbreiaj();
    cout << "Activare ambreiaj: " << abr.getActiv() << endl;

    FormulaUnu fr1;
    fr1.startStop();
    cout << "Pornire masina: " << fr1.getPornit() << endl;

    fr1.startStop();
    cout << "Oprire masina: " << fr1.getPornit() << endl;

    fr1.modificareClima(1);
    cout << "Nivel clima: " << fr1.getNivelClima() << endl;;


    Masina* start = new FormulaUnu;  
    start->startStop();  

     
    vector<Motor*> motoare;
    motoare.push_back(new Motor("Audi", 3000, false, "ardere", 263635633, 12));
    
    
}


