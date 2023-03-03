// struct.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


typedef struct tableau
{
    int hide;
    int nombredeBombe;
    int flag;
	int bombe;
    
}tableau;

int returncase(int i, int j, int iSize) {
	int result = i * iSize + j;
	return result;

}

void bombe(int iSize, tableau* t) {
	int listebombe = 0;
	for (int i = 0; i < iSize * iSize; i++)
	{
		t[i].bombe = i;
		
	}
	while (listebombe < iSize * iSize * 0.13)
	{
		int bombex = rand() % (iSize * iSize);
		for (int i = 0; i < iSize * iSize; i++)
		{
			if (bombex == t[i].bombe)
			{
				t[bombex].nombredeBombe = 9;
				t[i].bombe = 30;
				listebombe = listebombe + 1;

			}
		}
	}
    
    
}



void printtable(int iSize,  tableau* t) {

	for (int j = 0; j < iSize; j++) {
		if (j < 10) {
			printf("%d ", j);
		}
		else {
			printf("%d", j);
		}
		for (int i = 0; i < iSize; i++) {
			int result = i * iSize + j;
			if (t[result].hide == 1)
			{
				if (t[result].flag == 0)
				{
					if (t[result].nombredeBombe == 9) {
						printf("[B]");
					}
					else if (t[result].nombredeBombe == 0) {
						printf("[0]");
					}
					else if (t[result].nombredeBombe == 1) {
						printf("[\033[0;36m%d\033[0;37m]", t[result].nombredeBombe);
					}
					else if (t[result].nombredeBombe == 2) {
						printf("[\033[0;32m%d\033[0;37m]", t[result].nombredeBombe);
					}
					else if (t[result].nombredeBombe == 3) {
						printf("[\033[0;31m%d\033[0;37m]", t[result].nombredeBombe);
					}
					else if (t[result].nombredeBombe == 4) {
						printf("[\033[0;35m%d\033[0;37m]", t[result].nombredeBombe);
					}
					else if (t[result].nombredeBombe == 5) {
						printf("[\033[0;33m%d\033[0;37m]", t[result].nombredeBombe);
					}
					else if (t[result].nombredeBombe == 6) {
						printf("[\033[0;36m%d\033[0;37m]", t[result].nombredeBombe);
					}
					else if (t[result].nombredeBombe == 7) {
						printf("[\033[0;30m%d\033[0;37m]", t[result].nombredeBombe);
					}
					else if (t[result].nombredeBombe == 8) {
						printf("[\033[0;37m%d\033[0;37m]", t[result].nombredeBombe);
					}
				}
				else {
					printf("[P]");
				}
			

			}
			else {
				printf("[ ]");
			}
	
			}
	
		printf("\n");
			
		}


		
	}



void check( tableau* table, int iSize) {

	int i, j, count = 0;

	for (i = 0; i < iSize; i++) {
		for (j = 0; j < iSize; j++) {
			int result = returncase(i, j, iSize);
			if (table[result].nombredeBombe == 9) {

			}
			else {

				//left
				if (j - 1 >= 0) {
					result = returncase(i, j - 1, iSize);
					if (table[result].nombredeBombe == 9) {
						count++;
					}
				}

				//right
				if (j + 1 <= iSize - 1) {
					result = returncase(i, j + 1, iSize);
					if (table[result].nombredeBombe == 9) {
						count++;
					}
				}

				//top
				if (i - 1 >= 0) {
					result = returncase(i - 1, j, iSize);
					if (table[result].nombredeBombe == 9) {
						count++;
					}
				}

				//bottom
				if (i + 1 <= iSize - 1) {
					result = returncase(i + 1, j, iSize);
					if (table[result].nombredeBombe == 9) {
						count++;
					}
				}

				//top left
				if (i - 1 >= 0 && j - 1 >= 0) {
					result = returncase(i - 1, j - 1, iSize);
					if (table[result].nombredeBombe == 9) {
						count++;
					}
				}

				//bottom left
				if (i + 1 >= 0 && j - 1 >= 0) {
					result = returncase(i + 1, j - 1, iSize);
					if (table[result].nombredeBombe == 9) {
						count++;
					}
				}

				//top right
				if (i - 1 >= 0 && j + 1 <= iSize - 1) {
					result = returncase(i - 1, j + 1, iSize);
					if (table[result].nombredeBombe == 9) {
						count++;
					}
				}

				//bottom right
				if (i + 1 >= 0 && j + 1 <= iSize - 1) {
					result = returncase(i + 1, j + 1, iSize);
					if (table[result].nombredeBombe == 9) {
						count++;
					}
				}

				result = returncase(i, j, iSize);
				table[result].nombredeBombe = count;
				count = 0;
			}
		}
	}
}


int checkwin( tableau* table, int iSize) {

	int i, j, count = 0, count2 = 0;
	for (i = 0; i < iSize; i++) {
		for (j = 0; j < iSize; j++) {
			int result = returncase(j, i, iSize);
			if (table[result].nombredeBombe >= 0 && table[result].nombredeBombe <= 8) {
				count++;
			}
			if (table[result].hide == 1) {
				count2++;
			}
		}
	}
	if (count2 == count) {
		printf("gg ez ta win");
		exit(0);
	}

	return count;
}


void checkzeros( tableau* table, int iSize, int result, int i, int j) {

	//X = j
	//Y = i


	if (table[result].nombredeBombe == 0) {


			//left
			if (j - 1 >= 0) {
				result = returncase(i, j - 1, iSize);
				if (table[result].hide == 0 && table[result].nombredeBombe != 9) {
					table[result].hide = 1;
					checkzeros(table, iSize, result, i, j - 1);
				}
			}

			//right
			if (j + 1 <= iSize - 1) {
				result = returncase(i, j + 1, iSize);
				if (table[result].hide == 0 && table[result].nombredeBombe != 9) {
					table[result].hide = 1;
					checkzeros(table, iSize, result, i, j + 1);
				}
			}

			//bottom
			if (i + 1 <= iSize - 1) {
				result = returncase(i + 1, j, iSize);
				if (table[result].hide == 0 && table[result].nombredeBombe != 9) {
					table[result].hide = 1;
					checkzeros(table, iSize, result, i + 1, j);
				}
			}

			//top
			if (i - 1 >= 0) {
				result = returncase(i - 1, j, iSize);
				if (table[result].hide == 0 && table[result].nombredeBombe != 9) {
					table[result].hide = 1;
					checkzeros(table, iSize, result, i - 1, j);
				}
			}
			

			//top left
			if (i - 1 >= 0 && j - 1 >= 0) {
				result = returncase(i - 1, j - 1, iSize);
				if (table[result].hide == 0 && table[result].nombredeBombe != 9) {
					table[result].hide = 1;
					checkzeros(table, iSize, result, i - 1, j - 1);
				}
			}

			if (i + 1 < iSize && j - 1 >= 0) {
				result = returncase(i + 1, j - 1, iSize);
				if (table[result].hide == 0 && table[result].nombredeBombe != 9) {
					table[result].hide = 1;
					checkzeros(table, iSize, result, i + 1, j - 1);
				}
			}



			//top right
			if (i - 1 >= 0 && j + 1 <= iSize - 1) {
				result = returncase(i - 1, j + 1, iSize);
				if (table[result].hide == 0 && table[result].nombredeBombe != 9) {
					table[result].hide = 1;
					checkzeros(table, iSize, result, i - 1, j + 1);
				}
			}

			//bottom right
			if (i + 1 < iSize && j + 1 < iSize) {
				result = returncase(i + 1, j + 1, iSize);
				if (table[result].hide == 0 && table[result].nombredeBombe != 9) {
					table[result].hide = 1;
					checkzeros(table, iSize, result, i + 1, j + 1);
				}
			}


		
	}

}

void scan( tableau* table, int iSize) {
	int i, j, flag;

	printf("Choose X\n");
	scanf_s("%d", &j);

	while (j < 0 || j > iSize - 1) {
		printf("Invalid coordinates, please try again\n");
		printf("Choose X\n");
		scanf_s("%d", &j);
	}

	printf("Choose Y\n");
	scanf_s("%d", &i);

	while (i < 0 || i > iSize - 1) {
		printf("Invalid coordinates, please try again\n");
		printf("Choose Y\n");
		scanf_s("%d", &i);
	}

	int result = returncase(i, j, iSize);
	printf("voulez vous placez un drapeau ?");
	scanf_s("%d", &flag);
	if (flag == 1) {
		table[result].flag = 1;
		table[result].hide = 1;
	}
	else {
		if (table[result].hide == 1 && table[result].flag == 0) {
			printf("This case is already open\n");
			scan(table, iSize);
		}

		if (table[result].nombredeBombe == 9) {
			table[result].hide = 1;
			table[result].flag = 0;
			printtable(iSize, table);
			printf("t'es nul gg");
			exit(5);
		}
		else {
			table[result].hide = 1;
			table[result].flag = 0;
			if (table[result].nombredeBombe == 0) {
				checkzeros(table, iSize, result, i, j);
			}
		}

	}


}

void initTable(tableau* table, int taille)
{
	for (int i = 0; i < taille; i++)
	{
		table[i].bombe = 0;
		table[i].flag = 0;
		table[i].hide = 0;
		table[i].nombredeBombe = 0;
	}
}



int main()
{
	int  iSize = 0;

	printf("Choisissez la taille de votre grille ");
	printf("\n");
	
	scanf_s("%d",  &iSize);
	int tailleTotal = iSize * iSize;
	
	
	tableau * table = (tableau*) malloc(sizeof(tableau) * tailleTotal );
	initTable(table, tailleTotal);
    
	int score = 0;
	srand(time(NULL));	

	bombe(iSize, table);

	check(table, iSize);

	printtable(iSize, table);
	while (1)
	{
		checkwin(table, iSize);
		scan(table, iSize);
		score++;
		printf("%d\n", score);
		system("cls");
		printtable(iSize, table);
		printf("%d\n", score);
	}
	
	
	
	
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
