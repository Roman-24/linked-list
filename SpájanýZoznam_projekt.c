#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VEL 101
#define SUBOR "filmy.txt"

/* ROMAN BITAROVSKY
	VISUAL STUDIO 2019
		ZPRPR2 Projekt 2 spajany zoznam */

typedef struct meno { // viac slovne mena spojit _
	char krstne[VEL];
	char priezvysko[VEL];
} MENO;

typedef struct herec {
	MENO meno_herca;
	int narodenie;
	struct herec* dalsi;
} HEREC;

typedef struct film {
	char nazov[VEL]; // moze obsahovat medzeri, treba skenovat po koniec riadku
	int rok_vyroby;
	MENO reziser;
	HEREC* p_herec; // ukazovatel na spajany zoznam hercov daneho filmu
	struct film* dalsi;
} FILM;

FILM* nacitaj(FILM* head) { // funkcie na nacitanie zo suboru

	//otvorenie suboru
	FILE* fr;
	if ((fr = fopen(SUBOR, "r")) == NULL) {
		printf("Nepodarilo sa otvorit subor\n");
		return 0;
	}

	while (head != NULL) { // ak uz bolo nieco nacitane tak sa to znuluje
		FILM* p = head;
		while (head->p_herec != NULL) {
			HEREC* p = head->p_herec;
			head->p_herec = head->p_herec->dalsi;
			free(p);
		}
		head = head->dalsi;
		free(p);
	}

	FILM* akt = { NULL };
	HEREC* akt_herec = { NULL };
	char znak = 0;
	while (1) {

		FILM* vloz = (FILM*)malloc(sizeof(FILM)); // vytvor dalsi zaznam filmu
		vloz->p_herec = NULL;

		// oskenuje nazov filmu
		fscanf(fr, "%[^\n]", vloz->nazov);

		// oskenuje rok vyroby
		fscanf(fr, "%d", &vloz->rok_vyroby);

		// oskenuje meno a priezvysko rezisera
		fscanf(fr, "%s %s ", vloz->reziser.krstne, vloz->reziser.priezvysko);

		// oskenuje hercov
		while (1) { // skenuj hercov v loope
			HEREC* vloz_herec = (HEREC*)malloc(sizeof(HEREC));

			znak = getc(fr); // zober znak

			if (znak == EOF) { // ak je to EOF ukonci funkciu
				akt = akt->dalsi = vloz; // uloz nacitane udaje o filme
				akt->dalsi = NULL; // na koniec zoznamu daj NULL
				return head; // a vrat zaciatok zoznamu
			}

			else if (znak == '*') { // ak je to * nacitaj herca
				znak = getc(fr); // zober medzreru za *

				// naskenuj hercove udaje a vloz ho do zoznamu
				fscanf(fr, "%s %s %d ", vloz_herec->meno_herca.krstne, vloz_herec->meno_herca.priezvysko, &vloz_herec->narodenie);

				if (vloz->p_herec == NULL) { // ak sa vklada prvy herec
					vloz->p_herec = akt_herec = vloz_herec;
				}
				else { // ak sa vklada dalsi herec
					akt_herec = akt_herec->dalsi = vloz_herec;
				}
				akt_herec->dalsi = NULL; // na koniec zoznamu daj NULL
			}

			else { // ak v riadku nieje herec
				ungetc(znak, fr); // vrat znak kt. si zobral lebo to nieje *

				if (head == NULL) { // ak sa jedna o prvy zaznam
					head = akt = vloz;
				}
				else { // ak sa nejedna o prvy zaznam
					akt = akt->dalsi = vloz;
				}

				vloz->dalsi = NULL; // na koniec zoznamu daj NULL
				break; // ukonci loop na nacitavanie hercov
			}
		}
	}

	// zatvorenie suboru
	if (fclose(fr) == EOF) {
		printf("Subor sa nepodarilo zatvorit\n");
		return 0;
	}
}

void vypis(FILM* zac_film) {

	while (zac_film != NULL) { // chod po koniec zoznamu

		// vypisky
		printf("%s", zac_film->nazov);
		printf(" (%d) ", zac_film->rok_vyroby);
		printf("%s %s\n", zac_film->reziser.krstne, zac_film->reziser.priezvysko);
		printf("\tHraju: ");

		HEREC* zaloha_hercov = zac_film->p_herec; // zalohuj zaciatok zoznamu hercov

		while (zac_film->p_herec != NULL) { // kym neprides na koniec zoznamu hercov

			// vypis herca
			printf("%s %s (%d)", zac_film->p_herec->meno_herca.krstne, zac_film->p_herec->meno_herca.priezvysko, zac_film->p_herec->narodenie);

			if (zac_film->p_herec->dalsi != NULL) // ciarka sa vlozi vzdy ak to nieje posledny herec
				printf(", ");

			zac_film->p_herec = zac_film->p_herec->dalsi; // posun sa na dalsi zaznam herca
		}

		zac_film->p_herec = zaloha_hercov; // obnov zaciatok zoznamu
		printf("\n");
		zac_film = zac_film->dalsi; // posun sa na dalsi zaznam filmu
	}
}

FILM* pridaj(FILM* zac_film) {

	FILM* vloz = (FILM*)malloc(sizeof(FILM)); // vytvor dalsi zaznam filmu
	vloz->p_herec = NULL; // herci NULL lebo zatial ziadnych nema

	//oskenuje nazov filmu
	scanf("%[^\n]", vloz->nazov);

	//oskenuje rok vyroby
	scanf("%d", &vloz->rok_vyroby);

	//oskenuje meno a priezvysko rezisera
	scanf("%s %s", vloz->reziser.krstne, vloz->reziser.priezvysko);

	HEREC* akt_herec = NULL; // pomocny pointer na herec

	char string[VEL];
	while (1) {
		HEREC* vloz_herec = (HEREC*)malloc(sizeof(HEREC));

		scanf("%s", string);

		if (string[0] == '*') { // ak oskenuje * koniec pridavania
			break;
		}

		strcpy(vloz_herec->meno_herca.krstne, string); /* ak sa nezobrala * tak je v stringu krstne meno herca tak ho ulozi do zoznamu */

		// oskenuj zvysne udaje herca
		scanf("%s %d", vloz_herec->meno_herca.priezvysko, &vloz_herec->narodenie);

		if (vloz->p_herec == NULL) { // ak je zoznam hercov prazdny
			vloz->p_herec = akt_herec = vloz_herec;
		}
		else { // ak zoznam nieje prazdny
			akt_herec = akt_herec->dalsi = vloz_herec;
		}
		akt_herec->dalsi = NULL; // vloz NULL na koniec zoznamu
	}


	// prazdny zoznam filmov
	if (zac_film == NULL) {
		zac_film = (FILM*)malloc(sizeof(FILM));
		zac_film = vloz; // vloz udaje o nacitanom filme
		zac_film->dalsi = NULL; // vloz NULL na koniec zoznamu filmov
		return zac_film; // vrat zoznam
	}

	// pridanie na koniec existujuceho zoznamu
	FILM* akt = zac_film;
	while (akt->dalsi != NULL) //najdi koniec zoznamu
		akt = akt->dalsi;
	akt = akt->dalsi = vloz; //vloz na koniec zoznamu
	akt->dalsi = NULL; // koniec zoznamu bude NULL
	return zac_film; // vrat zoznam
}

FILM* vymaz(FILM* zac_film) { // funkcia zmaze zaznam zadaneho filmu

	char nazov_vymaz[VEL];
	scanf("%[^\n]", nazov_vymaz); // oskenuj nazov filmu kt. sa bude mazat

	FILM* akt = zac_film;
	FILM* p_predosli = { NULL };

	if (akt == NULL) // zoznam je prazdny => nic 
		return NULL;

	while (akt != NULL) { // prechadzaj zoznamom filmov az po koniec
		//printf("presiel som cez: %s\n", akt->nazov);

		if (!strcmp(akt->nazov, nazov_vymaz)) { // ak sa najde zaznam kt. sa ma zmazat

			if (akt == zac_film) { // ak chceme vymazat prvy film v zozname
				while (akt->p_herec != NULL) { // vymaz hercov
					HEREC* p = akt->p_herec;
					akt->p_herec = akt->p_herec->dalsi;
					free(p);
				}
				zac_film = zac_film->dalsi; // uloz novy zaciatok zoznamu
			}

			else if (akt->dalsi == NULL) {  // jednoprvkovy zoznam alebo posledny prvok

				while (akt->p_herec != NULL) { // vymaz hercov
					HEREC* p = akt->p_herec;
					akt->p_herec = akt->p_herec->dalsi;
					free(p);
				}
				free(akt->p_herec);
				free(akt);
				p_predosli->dalsi = NULL;
				return zac_film; // ak by sme chceli vymazat iba jeden rovnaky treba odkomentovat
			}

			else { // aspon 2 prvky v zozname, vymazanie zaznamu
				FILM* pom = akt;
				akt = akt->dalsi; // dalsi zaznam
				p_predosli->dalsi = pom->dalsi;
				while (pom->p_herec != NULL) { // vymaz hercov
					HEREC* p = pom->p_herec;
					pom->p_herec = pom->p_herec->dalsi;
					free(p);
				}
				free(pom->p_herec);
				free(pom);
				continue;
				//return zac_film; // vrat zoznam
			}
		}
		p_predosli = akt; // uklada sa predosli zaznam
		akt = akt->dalsi; // dalsi zaznam
	}
	return zac_film; // vrat zoznam
}

void filmy(FILM* zac_film) { // vypise kde vsade hra zadany herec

	char string_meno[VEL];
	char string_priezvysko[VEL];
	scanf("%s %s", string_meno, string_priezvysko); // oskenuj herca kt. sa bude hladat vo filmoch

	while (zac_film != NULL) { // prechadzaj zoznam filmov

		HEREC* zaloha_hercov = zac_film->p_herec; // ulozenie zaciatku hercov

		while (zac_film->p_herec != NULL) { // prechadzaj hercov
			if (!strcmp(zac_film->p_herec->meno_herca.krstne, string_meno) && !strcmp(zac_film->p_herec->meno_herca.priezvysko, string_priezvysko)) {
				//ak sa nasla zhoda vypise sa film
				printf("%s", zac_film->nazov);
				printf(" (%d)\n", zac_film->rok_vyroby);
			}
			zac_film->p_herec = zac_film->p_herec->dalsi; // dalsi herec 
		}
		zac_film->p_herec = zaloha_hercov; // obnovenie zaciatku zoznamu hercov
		zac_film = zac_film->dalsi; // dalsi film
	}
}

void herci(FILM* zac_film) { // vypis hercov 2 vybranych filmov

	char film_1[VEL];
	char film_2[VEL];
	FILM* jedna = NULL;
	FILM* dva = NULL;

	scanf("%[^\n] %[^\n]", film_1, film_2); // oskenuje dva filmy 
	int flag = 1, flag2 = 1;
	while (zac_film != NULL) { //prechadzaj zoznamom filmy

		if (!strcmp(film_1, zac_film->nazov)) { // ak sa najde prvy film
			jedna = zac_film; // ulozi sa
			flag -= 1;
		}
		if (!strcmp(film_2, zac_film->nazov)) { //ak sa najde druhy film
			dva = zac_film; //ulozi sa
			flag2 -= 1;
		}

		zac_film = zac_film->dalsi; // posun v zozname
	}

	if (flag >= 1 || flag2 >=1) {
		printf("filmy niesu\n");
		return;
	}
	
	/*if (jedna == NULL || dva == NULL) {
		printf("Zadali ste zly film\n");
		return;
	}*/

	HEREC* zaloha_hercov1 = jedna->p_herec; // zaloha zaciatku zoznamu hercov
	HEREC* zaloha_hercov2 = dva->p_herec; // zaloha zaciatku zoznamu hercov
	int pom = 1;
	// 2x while ne prechadzanie hercami oboch filmov
	while (jedna->p_herec != NULL) {
		while (dva->p_herec != NULL) {
			
			// ak je herec v oboch filmoch vypise sa
			if (!strcmp(jedna->p_herec->meno_herca.krstne, dva->p_herec->meno_herca.krstne) && !strcmp(jedna->p_herec->meno_herca.priezvysko, dva->p_herec->meno_herca.priezvysko)) {
				if(pom==0)
					printf(", ");
				printf("%s %s (%d)", jedna->p_herec->meno_herca.krstne, jedna->p_herec->meno_herca.priezvysko, jedna->p_herec->narodenie);
				pom = 0;
			}
			dva->p_herec = dva->p_herec->dalsi; // posun hercov v druhom filme
		}
		if (!strcmp(film_1, film_2)) {
			break;
		}
		jedna->p_herec = jedna->p_herec->dalsi; // posun hercov v prvom filme 
	}
	jedna->p_herec = zaloha_hercov1; // obnovenie zaciatku zoznammu hercov
	dva->p_herec = zaloha_hercov2; // obnovenie zaciatku zoznammu hercov
	printf("\n");
}

int porovnaj(const void* a, const void* b) { // funkcia na porovnavanie 2 prvkov

	const FILM* jedna = (FILM*)a;
	const FILM* dva = (FILM*)b;

	if (!strcmp(jedna->p_herec->meno_herca.priezvysko, dva->p_herec->meno_herca.priezvysko)) { // porovnava podla priezvyska
		if (!strcmp(jedna->p_herec->meno_herca.krstne, dva->p_herec->meno_herca.krstne)) { // porovnava podla mena
			if (jedna->p_herec->narodenie < dva->p_herec->narodenie) { // porovnava podla roku narodenia
				return 1;
			}
			return strcmp(jedna->p_herec->meno_herca.krstne, dva->p_herec->meno_herca.krstne);
		}
		return strcmp(jedna->p_herec->meno_herca.priezvysko, dva->p_herec->meno_herca.priezvysko);
	}
}

void rok(FILM* zac_filmu) { // urobi pole zaznamov hercov kt. hrali v zadanom roku a vypise to pole

	int rok = 0;
	scanf("%d", &rok); // oskenuj rok 

	FILM* akt = zac_filmu;
	FILM* pole = (FILM*)malloc(sizeof(FILM));
	int pocet_pole = 1;
	int flag = 0;
	while (akt != NULL) { // prechadza zoznamom
		if (akt->rok_vyroby == rok) { // ak sa najde film s pozadovanym rokom

			HEREC* zaloha_herec = akt->p_herec; // aby sme mohli dat zoznam hercov zase na zaciatok
			while (akt->p_herec != NULL) { // prechadzaj hercov 

				for (int index = 0; index < pocet_pole - 1; index++) { // overenie ci sa herec uz nenachadza v poli 
					if (!strcmp(pole[index].p_herec->meno_herca.krstne, akt->p_herec->meno_herca.krstne)) {
						if (!strcmp(pole[index].p_herec->meno_herca.priezvysko, akt->p_herec->meno_herca.priezvysko)) {
							if (pole[index].p_herec->narodenie == akt->p_herec->narodenie) {
								flag = 1;
							}
						}
					}
				}

				if (flag == 0) { // ak teda herec este v poli nieje zapise sa tam
					pole[pocet_pole - 1].p_herec = akt->p_herec; // ulozenie herca do pola
					pocet_pole++; // posunutie sa v poli
					pole = (FILM*)realloc(pole, pocet_pole * sizeof(FILM)); // realoknutie pola pre pripadny dalsi zaznam
					flag = 0;
				}

				akt->p_herec = akt->p_herec->dalsi; // posunutie hercov
			}
			akt->p_herec = zaloha_herec; //vratenie zaciatku
		}
		akt = akt->dalsi; // posunie zoznam filmov
	}

	qsort(pole, pocet_pole - 1, sizeof(pole[0]), porovnaj); // usporiada pole hercov

	// vypis pola hercov
	for (int i = 0; i < pocet_pole - 1; i++) {
		printf("%s %s (%d)", pole[i].p_herec->meno_herca.krstne, pole[i].p_herec->meno_herca.priezvysko, pole[i].p_herec->narodenie);
		if (i != pocet_pole - 2) {
			printf(", ");
		}
	}
	printf("\n");

	// uvolni pamat
	free(pole);
	//free(akt);
}

int main() {

	FILM* head = { NULL };
	char prikaz[VEL], znak;

	while (1) {
		scanf("%s%c", prikaz, &znak); //skenovanie prikazu
		// MENU + volanie funkcii
		if (!strcmp(prikaz, "nacitaj")) {
			head = nacitaj(head);
		}
		else if (!strcmp(prikaz, "vypis")) {
			vypis(head);
		}
		else if (!strcmp(prikaz, "pridaj")) {
			head = pridaj(head);
		}
		else if (!strcmp(prikaz, "vymaz")) {
			head = vymaz(head);
		}
		else if (!strcmp(prikaz, "filmy")) {
			filmy(head);
		}
		else if (!strcmp(prikaz, "herci")) {
			herci(head);
		}
		else if (!strcmp(prikaz, "rok")) {
			rok(head);
		}
		else if (!strcmp(prikaz, "koniec")) {

			while (head != NULL) {
				FILM* p = head;
				while (head->p_herec != NULL) {
					HEREC* p = head->p_herec;
					head->p_herec = head->p_herec->dalsi;
					//p = NULL;
					free(p);
				}
				head = head->dalsi;
				//p = NULL;
				free(p);
			}
			//head = NULL;
			free(head);
			break;
		}

		else { printf("Error! operator is not correct\n"); } //ak sme zadali neplatny prikaz
	}
	return 0; //THE END
}
