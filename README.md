Programul folosește polimorfismul pentru a trata diferit trei tipuri de experiențe pentru clienți:
Spartan Standard: Opțiunea de bază.
Spartan Platinum: Un abonament premium care are o reducere de 10% inclusă direct în prețul de listă.
Luptător: O variantă simplificată și mai ieftină. 

Motorul Temporal (Simularea Timpului)
   Aceasta este partea cea mai inovatoare a programului tău. Deoarece un abonament expiră în viața reală după 30 de zile, programul tău permite administratorului să "păcălească" timpul:

Poți seta o dată de start (ex: 1 Ianuarie).

Poți avansa timpul cu un număr de zile (ex: +45 de zile).

Sistemul recalculează automat statusul fiecărui client, marcându-i ca [ACTIV] sau [EXPIRAT] în funcție de noua dată a sistemului.

Sistemul de Fidelizare (Regula celor 90 de zile)
   Programul tău implementează o politică de marketing inteligentă pentru a readuce clienții la sală:

Dacă un client vine să își reactiveze abonamentul în mai puțin de 90 de zile de la expirare, sistemul îi aplică automat o reducere suplimentară de 10% la prețul final.

Dacă trece mai mult de 90 de zile, reducerea se pierde, penalizând absența îndelungată.

Siguranță și Integritate (Excepțiile)
   Programul este "blindat" împotriva utilizării greșite:

Prevenție: Nu poți adăuga clienți dacă nu ai setat mai întâi data curentă.

Validare: Nu poți introduce date calendaristice care nu există (ex: 30 Februarie).

Identificare: Nu poți modifica sau căuta un client care nu există (eroare de ID).
Fiecare dintre aceste greșeli este prinsă și afișată elegant, fără ca programul să se blocheze.

Managementul Memoriei
   Sub capotă, programul tău este modern și eficient. Folosește Smart Pointers (unique_ptr), ceea ce înseamnă că memoria este curățată automat de fiecare dată când un client este șters sau programul se închide, eliminând riscul de "memory leaks" (scurgeri de memorie).

Funcționalități Cheie
Interfață Dual-Tab: Organizarea meniului în două secțiuni distincte pentru o navigare intuitivă: Gestiune (operațiuni clienți) și Timp (configurări sistem).

Managementul Clienților: Înregistrarea membrilor cu nume complet (suport pentru spații) și atribuirea automată de ID-uri unice.

Ierarhie de Abonamente: Utilizarea a trei categorii polimorfice: SpartanPlatinum, Spartan și Luptator, fiecare cu structuri de preț specifice.

Simulare Timp (Time Skip): Funcție de accelerare a timpului ce permite verificarea statusului de valabilitate și testarea logicii de expirare automată după 30 de zile.

Sistem de Fidelizare: Calcul automat al reducerilor de 10% pentru membrii care își reactivează abonamentul într-un interval de maximum 90 de zile de la data expirării.

Validare Calendaristică: Protecție integrată împotriva datelor invalide (ex: împiedică setarea zilei de 29 februarie în ani nebisecți).
Concepte OOP și Tehnice Implementate
Polimorfism Dinamic: Utilizarea funcțiilor virtuale și a clasei abstracte de bază pentru gestionarea diferitelor tipuri de abonamente prin pointeri de bază.

Smart Pointers (std::unique_ptr): Gestionarea modernă a memoriei pentru a elimina riscul de memory leaks și pentru a asigura transferul sigur de proprietate al obiectelor.

Copy-and-Swap Idiom: Implementarea robustă a constructorului de copiere și a operatorului de atribuire pentru a garanta integritatea datelor în timpul manipulării obiectelor Client.

Gestiunea Excepțiilor: Arhitectură bazată pe try-catch și clase de excepții custom pentru tratarea erorilor de logică (ID-uri inexistente, date nesetate sau input-uri invalide).

Calcul Temporal de Precizie: Utilizarea bibliotecii <ctime> pentru a calcula diferențe exacte de timp între activări și reactivări, transformând secundele în zile de valabilitate.