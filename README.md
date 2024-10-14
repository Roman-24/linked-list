# Linked List

## EN
A project focused on working with a linked list in the C language.

The program works with a linked list of movies, where each movie will contain a linked list of actors and includes the following functions:

* `load` - to load and create a linked list from the file `movies.txt`. If the list has already been loaded, all dynamically created memory is first freed, and then the linked list is created. The file will contain records of movies stored consecutively as follows: the first line of the record will be the movie title, the second line will be the year of release, the third line will contain the director's first and last name, and then several (including 0) lines will follow, each containing one actor. The lines containing actors will start with an asterisk, followed by the actor's first name, last name, and year of birth.

* `print` - to print the entire list of movies along with the list of actors.
Example output:  
*San Andreas (2015) Brad Peyton*  
*Actors: Dwayne Johnson (1972), Alexandra Daddario (1986), Carla Gugino (1971)*  
*A Star is Born (2018) Bradley Cooper*  
*Actors: Bradley Cooper (1975), Lady Gaga (1986)*  
*Skyscraper (2018) Rawson Marshall Thurber*  
*Actors: Dwayne Johnson (1972), Neve Adrianne Campbell (1973)*

* `add` - to add a movie and its list of actors to the end of the list. The input follows a similar format to the input file. The difference is that at the beginning of the actor's line, there is no `*`. Conversely, if the `*` symbol is read, it signifies the end of the record. Example input:  
*A Star is Born*  
*2018*  
*Bradley Cooper*  
*Bradley Cooper 1975*  
*Lady Gaga 1986*  
`\*`

* `delete` - to delete a movie and its corresponding list of actors. The command is followed by the line with the movie's title. Deleting also involves freeing the memory for the deleted records in addition to adjusting the pointers.

* `movies` - to print movies in which a given actor has played. The command is followed by a line containing the actor's first and last name separated by a space. The program prints a list of movies in which the given actor has appeared – one line for each movie with the title and year separated by a space in parentheses. For the actor Dwayne Johnson, the program prints:  
*San Andreas (2015)*  
*Skyscraper (2018)*

* `actors` - to print actors who played in both of two selected movies. The command is followed by two lines, each containing the movie title. The output is a list of actors who played in both movies – progressively for the given movies in the order they are stored in the list, ensuring that actors are not repeated. The output is formatted according to the output for the movies *San Andreas* and *Skyscraper*, where more actors are listed in one line separated by commas and spaces, similar to the output for the `year` command:  
*Dwayne Johnson (1972)*

* `year` - to create, print, and subsequently delete a sorted list of actors who appeared in any of the movies from a given year. The command is followed by a line containing the year. The list of actors can be represented by an array of structures or a newly created linked list where actors are not repeated. Actors are sorted by last name. If two actors have the same last name, they are sorted by first name. If two actors have the same first and last name, they are sorted by year of birth. The output for the year 2018 is formatted as follows:  
*Neve Adrianne Campbell (1973), Bradley Cooper (1975), Lady Gaga (1986), Dwayne Johnson (1972)*

* `end` - to terminate the program, freeing all dynamically allocated memory.

## SK
Projekt zameraný na prácu so spájaným zoznamom v jazyku C.

Program, pracuje so spájaným zoznamom filmov, pričom každý film bude obsahovať spájaný zoznam hercov a obsahuje nasledovné funkcie:

* `nacitaj` - na načítanie a vytvorenie spájaného zoznamu zo súboru filmy.txt. Ak už bol zoznam načítaný, všetka dynamicky vytvorená pamäť sa najprv uvoľní a potom sa vytvorí spájaný zoznam. Súbor bude obsahovať za sebou uložené záznamy o filmoch takto: v 1. riadku záznamu bude názov filmu, v 2. riadku rok výroby, v 3. riadku meno a priezvisko režiséra a potom bude nasledovať niekoľko (aj 0) riadkov, vždy jeden riadok pre jedného herca. Riadky obsahujúce hercov sa budú začínať hviezdičkou, potom bude nasledovať meno, priezvisko a rok narodenia herca.

* `vypis` - na výpis celého zoznamu filmov aj so zoznamami hercov.
Príklad výpisu: <br>
<em>San Anderas (2015) Brad Peyton <br>
Hraju: Dwayne Johnson (1972), Alexandra Daddariová (1986), Carla Gugino (1971) <br>
Zrodila sa hviezda (2018) Bradley Cooper <br>
Hraju: Bradley Cooper (1975), Lady Gaga (1986) <br>
Mrakodrap (2018) Rawson_Marshall Thurber <br>
Hraju: Dwayne Johnson (1972), Neve_Adrianne Campbell (1973)</em>
  
* `pridaj` - na pridanie filmu aj so zoznamom hercov na koniec zoznamu. Príkaz nasleduje záznam zadaný podobne ako vo vstupnom súbore. Rozdiel je, že na začiatku riadku s informáciami o hercovi nie je *. Naopak, ak sa načíta znak *, znamená to koniec zadávania záznamu. Ukážka vstupu: <br>
<em>Zrodila sa hviezda <br>
2018 <br>
Bradley Cooper <br>
Bradley Cooper 1975 <br>
Lady Gaga 1986 <br>
\* </em>

* `vymaz` - na vymazanie filmu aj s príslušným zoznamom hercov. Príkaz nasleduje riadok s názvom filmu. Vymazanie okrem zmeny ukazovateľov zahŕňa aj uvoľnenie pamäte pre vymazávané záznamy.

* `filmy` - na výpis filmov, v ktorých hral daný herec. Príkaz nasleduje riadok obsahujúci krstné meno a priezvisko herca oddelené medzerou. Program vypíše zoznam filmov, v ktorých hrá zadaný herec – pre každý film vypíše 1 riadok s názvom filmu a medzerou oddeleným rokom uvedeným v zátvorke. Pre herca Dwayne Johnson program vypíše:
<br><em>San Andreas (2015) <br>
Mrakodrap (2018) </em>

* `herci` - na výpis hercov, ktorí hrali v oboch z 2 vybraných filmoch. Príkaz nasledujú 2 riadky, každý obsahuje názov filmu. Výstupom je zoznam hercov hrajúcich v oboch filmoch – postupne pre dané filmy tak, ako sú uložené v zozname s tým, že sa herci neopakujú. Výstup formátujte podľa výstupu pre filmy San Andreas a Mrakodrap program vypíše (viac hercov je zapísaných do riadku a oddelených čiarkou a medzerou – podobne ako výstup pre príkaz rok): <br>
<em>Dwayne Johnson (1972)</em>

* `rok` - na vytvorenie, výpis a následné zmazanie usporiadaného zoznamu hercov, ktorí hrali v niektorom z filmov zadaného roku. Príkaz nasleduje riadok obsahujúci rok. Zoznam hercov reprezentujte poľom štruktúr alebo vytvoreným spájaným zoznamom, v ktorom sa herci neopakujú. Hercov usporadúvajte podľa priezviska. Ak majú 2 herci rovnaké priezvisko, usporiadajte ich podľa mena. Ak majú 2 herci rovnaké meno aj priezvisko, usporiadate ich podľa roku narodenia. Výpis hercov formátujte podľa ukážky pre rok 2018: <br>
<em>Neve_Adrianne Campbell (1973), Bradley Cooper (1975), Lady Gaga (1986), Dwayne Johnson (1972)</em>

* `koniec` - na ukončenie programu, pričom sa uvoľní všetka dynamicky vytvorená pamäť.
