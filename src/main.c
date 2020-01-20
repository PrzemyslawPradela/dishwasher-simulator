#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void progressbar(float progress_speed, char *task);

int main()
{
	char choice;

	while (1)
	{
		system("clear");

		printf("********************************************\n");
		printf("************|SYMULATOR ZMYWARKI|************\n");
		printf("|------------------------------------------|\n");
		printf("|------------------------------------------|\n");
		printf("|            WYBIERZ PROGRAM               |\n");
		printf("|------------------------------------------|\n");
		printf("|1. Wstepne zmywanie                       |\n");
		printf("|2. Normalny                               |\n");
		printf("|3. Oszczedny (ECO)    	                   |\n");
		printf("|4. Rosnaco                            	   |\n");
		printf("|5. Intensywny                       	   |\n");
		printf("|6. BIO                                    |\n");
		printf("|7. Szybki/Ekspresowy                      |\n");
		printf("|8. Wyparzanie                             |\n");
		printf("|------------------------------------------|\n");
		printf("|9. Pomoc                                  |\n");
		printf("|------------------------------------------|\n");
		printf("|------------------------------------------|\n");
		printf("|0.Zakoncz                                 |\n");
		printf("|------------------------------------------|\n");
		printf("********************************************\n");
		printf("\n");

		choice = getchar();

		switch (choice)
		{
		case '1':
			progressbar(0.004, "Wstepne zmywanie");
			break;

		case '2':
			printf("Wybor %c", choice);
			break;

		case '3':
			printf("Wybor %c", choice);
			break;

		case '4':
			printf("Wybor %c", choice);
			break;

		case '5':
			printf("Wybor %c", choice);
			break;

		case '6':
			printf("Wybor %c", choice);
			break;

		case '7':
			printf("Wybor %c", choice);
			break;

		case '8':
			printf("Wybor %c", choice);
			break;

		case '9':
			printf("Wybor %c", choice);
			break;

		case '0':
			progressbar(0.02, "Wylaczanie");
			exit(0);
			break;

		default:
			printf("Nie ma takiej opcji (%c) w menu!", choice);
			break;
		}

		getchar();
		getchar();
	}

	return (0);
}

void progressbar(float progress_speed, char *task)
{
	int barwidth = 20;
	float progress = 0.0;

	while (progress < 1.0)
	{
		printf("%3d%% %s\r", (int)(progress * 100.0), task);
		int pos = barwidth * progress;
		for (int i = 0; i < barwidth; i++)
		{
			if (i <= pos)
				printf("\u258A");
			else
				printf(" ");
		}
		fflush(stdout);

		progress += progress_speed;

		usleep(100000);
	}
	printf("100%% %s\r\n", task);
}