Sistem Gestiune Sala Sport este o aplicație de consolă dezvoltată în C++ care permite administrarea eficientă a bazei de date a unei săli de fitness. Proiectul simulează fluxul real de lucru al unei recepții, de la înregistrarea membrilor până la monitorizarea valabilității abonamentelor.
Managementul Clienților: Adăugarea membrilor noi și stocarea lor într-o bază de date dinamică.

Tipuri de Abonamente: Utilizatorii pot alege între trei categorii de membru: SpartanPlatinum, Spartan și Luptator.

Sistem de Fișiere Extern: * Regulament.txt: Citirea și afișarea regulamentului sălii la pornirea aplicației.

Beneficii.txt: Panou informativ dinamic cu avantajele fiecărui tip de abonament.

Simulare Timp (Time Skip): O funcție inovatoare de accelerare a timpului pentru a testa expirarea automată a abonamentelor și validitatea logică a sistemului.

Monitorizare Status: Filtrare rapidă pentru vizualizarea clienților cu abonamente active vs. istoricul complet.

Reactivare: Posibilitatea de a prelungi abonamentele expirate direct prin ID-ul unic al clientului.
Encapsulare: Utilizarea claselor (Data, Abonament, Client, SalaSport) pentru a proteja datele private.

Rule of Three: Implementarea manuală a Constructorului de Copiere, Operatorului de Atribuire (=) și a Destructorului pentru gestionarea sigură a memoriei (alocare dinamică pentru bazaDate).

Supraîncărcarea Operatorilor: Folosirea operator<< pentru afișarea directă a obiectelor în consolă.

Compoziție: Clasa Client înglobează obiecte de tip Data și Abonament.

Pointeri și Memorie Dinamică: Gestionarea bazei de date folosind alocare pe Heap pentru a permite scalabilitatea.