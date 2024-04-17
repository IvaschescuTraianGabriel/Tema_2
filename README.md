Tema realizata in cadrul materie "Sisteme de operare"



Realizați un program în limbajul C care primește 3 argumente din linia de comandă: un director sursă, un director destinație și un număr natural pozitiv.
Se va parcurge recursiv structura de directoare din directorul sursă. Pentru fiecare intrare din directorul sursă, se vor executa următoarele operații, în funcție de tipul intrării:

Pentru directoare, se va crea un director echivalent în directorul destinație, cu aceleași drepturi ca directorul original. Astfel, structura de directoare din directorul destinație va fi asemănătoare cu cea din sursă.
Pentru fișierele obișnuite, în funcție de extensia fișierului:
Pentru fișierele cu extensia .txt, programul va calcula numărul de spații pe care îl conține fișierul. Dacă numărul de spații al acelui fișier este mai mare decât numărul dat ca al doilea argument, 
  programul va crea o legătură simbolică către acel fișier, în directorul destinație (sau din interiorul acestuia, în funcție de structura de mai sus), cu numele fișierului original, dar cu sufixul "_spaces".
  Aceste link-uri vor avea aceleași drepturi de acces ca și fișierele originale.
Exemplu: dacă un fișier numit "file1.txt" conține mai multe spații decât numărul dat ca argument, programul va crea o legătură simbolică către acel fișier, cu numele "file1.txt_spaces”.
Pentru fișierele care au altă extensie, se va crea o copie a fișierului în directorul destinație (și, după caz, în subfolderul echivalent). Aceste fișiere copie vor avea aceleași drepturi de read ca și fișierele originale 
  (Exemplu: dacă fișierul original are –rwx-wxr-x, fișierul nou va avea –r-----r--).
Pentru (sof)link-uri, nu se va executa nicio operație.

Tema va fi însoțită de fișierul Makefile corespunzător.
