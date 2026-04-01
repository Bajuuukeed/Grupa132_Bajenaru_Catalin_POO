🏋️‍♂️ Spartan Gym Management System
Sistem de gestiune tip consolă pentru administrarea eficientă a unei săli de sport. Aplicația permite monitorizarea clienților, gestionarea plăților și automatizarea verificării valabilității abonamentelor.
📝 Descrierea Proiectului
Proiectul rezolvă problema evidenței manuale a clienților într-o sală de fitness. Acesta oferă o soluție digitală pentru recepție, capabilă să calculeze automat data de expirare a serviciilor și să aplice politici de fidelizare (reduceri la reactivare).
🛠️ Structura Codului 
Programul este construit folosind principii de programare orientată pe obiecte, având următoarea ierarhie:
Clasa Data: Gestionează calendarul intern al sălii și formatarea datelor calendaristice.
Clasa Abonament: Încapsulează detaliile despre tipul de serviciu, preț și logica de reducere.
Clasa Client: Reunește datele de identificare cu obiectul de tip abonament.
Clasa SalaSport: Clasa care gestionează vectorul de clienți și interacțiunea cu fișierele externe.
⚙️ Funcționalități
1. Gestiune Clienți
Adăugare: Înregistrare nume și alegere tip abonament:
Luptător
Spartan
Spartan Platinum
Căutare: Identificarea rapidă după ID-ul unic generat la înscriere.
Filtrare: Vizualizarea listei de clienți care au acces permis în prezent.
2. Controlul Timpului
Spre deosebire de o aplicație reală care preia data din sistem, acest program permite utilizatorului să "sară" peste un număr de zile pentru a vedea cum statusul unui client se schimbă din ACTIV în EXPIRAT.
3. Integrare Fișiere
Aplicația încarcă dinamic date din:
Regulament.txt - Afișat la pornire.
Beneficii.txt - Detalii despre facilitățile fiecărui tip de abonament.
