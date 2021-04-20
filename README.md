# Linked-List-C

Projekt zameraný na prácu so spájaným zoznamom v jazyku C.

Program, pracuje so spájaným zoznamom filmov, pričom každý film bude obsahovať spájaný zoznam hercov a obsahuje nasledovné funkcie:

* nacitaj - na načítanie a vytvorenie spájaného zoznamu zo súboru filmy.txt. Ak už bol zoznam načítaný, všetka dynamicky vytvorená pamäť sa najprv uvoľní a potom sa vytvorí spájaný zoznam. Súbor bude obsahovať za sebou uložené záznamy o filmoch takto: v 1. riadku záznamu bude názov filmu, v 2. riadku rok výroby, v 3. riadku meno a priezvisko režiséra a potom bude nasledovať niekoľko (aj 0) riadkov, vždy jeden riadok pre jedného herca. Riadky obsahujúce hercov sa budú začínať hviezdičkou, potom bude nasledovať meno, priezvisko a rok narodenia herca.

* vypis - na výpis celého zoznamu filmov aj so zoznamami hercov.
Príklad výpisu: <br>
<em>San Anderas (2015) Brad Peyton <br>
Hraju: Dwayne Johnson (1972), Alexandra Daddariová (1986), Carla Gugino (1971) <br>
Zrodila sa hviezda (2018) Bradley Cooper <br>
Hraju: Bradley Cooper (1975), Lady Gaga (1986) <br>
Mrakodrap (2018) Rawson_Marshall Thurber <br>
Hraju: Dwayne Johnson (1972), Neve_Adrianne Campbell (1973)</em>
  
* pridaj - na pridanie filmu aj so zoznamom hercov na koniec zoznamu. Príkaz nasleduje záznam zadaný podobne ako vo vstupnom súbore. Rozdiel je, že na začiatku riadku s informáciami o hercovi nie je *. Naopak, ak sa načíta znak *, znamená to koniec zadávania záznamu. Ukážka vstupu: <br>
<em>Zrodila sa hviezda <br>
2018 <br>
Bradley Cooper <br>
Bradley Cooper 1975 <br>
Lady Gaga 1986 <br>
\* </em>

* vymaz - na vymazanie filmu aj s príslušným zoznamom hercov. Príkaz nasleduje riadok s názvom filmu. Vymazanie okrem zmeny ukazovateľov zahŕňa aj uvoľnenie pamäte pre vymazávané záznamy.

* filmy - na výpis filmov, v ktorých hral daný herec. Príkaz nasleduje riadok obsahujúci krstné meno a priezvisko herca oddelené medzerou. Program vypíše zoznam filmov, v ktorých hrá zadaný herec – pre každý film vypíše 1 riadok s názvom filmu a medzerou oddeleným rokom uvedeným v zátvorke. Pre herca Dwayne Johnson program vypíše:
<br><em>San Andreas (2015) <br>
Mrakodrap (2018) </em>

* herci - na výpis hercov, ktorí hrali v oboch z 2 vybraných filmoch. Príkaz nasledujú 2 riadky, každý obsahuje názov filmu. Výstupom je zoznam hercov hrajúcich v oboch filmoch – postupne pre dané filmy tak, ako sú uložené v zozname s tým, že sa herci neopakujú. Výstup formátujte podľa výstupu pre filmy San Andreas a Mrakodrap program vypíše (viac hercov je zapísaných do riadku a oddelených čiarkou a medzerou – podobne ako výstup pre príkaz rok): <br>
<em>Dwayne Johnson (1972)</em>

* rok - na vytvorenie, výpis a následné zmazanie usporiadaného zoznamu hercov, ktorí hrali v niektorom z filmov zadaného roku. Príkaz nasleduje riadok obsahujúci rok. Zoznam hercov reprezentujte poľom štruktúr alebo vytvoreným spájaným zoznamom, v ktorom sa herci neopakujú. Hercov usporadúvajte podľa priezviska. Ak majú 2 herci rovnaké priezvisko, usporiadajte ich podľa mena. Ak majú 2 herci rovnaké meno aj priezvisko, usporiadate ich podľa roku narodenia. Výpis hercov formátujte podľa ukážky pre rok 2018: <br>
<em>Neve_Adrianne Campbell (1973), Bradley Cooper (1975), Lady Gaga (1986), Dwayne Johnson (1972)</em>

* koniec - na ukončenie programu, pričom sa uvoľní všetka dynamicky vytvorená pamäť.
