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