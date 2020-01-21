/**
 * @author Przemysław Pradela
 * @email przemyslaw.pradela@gmail.com
 * @create date 2020-01-20 14:29:57
 * @modify date 2020-01-21 01:07:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

#define PERMS 0644

struct my_msgbuf
{
	long mtype;
	char mtext[200];
};

/*
 * Function: progressbar
 * Funkcja służąca do wizualizacji postępu danego zadania.
 *
 * Parameters:
 * progress_speed - szybkość wykonywania się zadania.
 * task - nazwa zadania.
 *
 * Returns:
 * void.
 */
void progressbar(float progress_speed, char *task);

int main()
{
	struct my_msgbuf buf;
	int msqid;
	char choice;
	char help_choice;
	key_t key;
	pid_t parts[3];

	system("touch /tmp/msgq.txt");

	if ((key = ftok("/tmp/msgq.txt", 'B')) == -1)
	{
		perror("ftok");
		exit(1);
	}

	if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1)
	{
		perror("msgget");
		exit(1);
	}

	// for (size_t i = 0; i < 3; i++)
	// {
	// 	if (msgrcv(msqid, &buf, sizeof(buf.mtext), 1, 0) == -1)
	// 	{
	// 		perror("msgrcv");
	// 		exit(1);
	// 	}

	// 	parts[i] = atoi(buf.mtext);

	// 	buf.mtype = parts[i];
	// 	sprintf(buf.mtext, "%d", getpid());
	// 	if (msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0) == -1)
	// 	{
	// 		perror("msgsnd");
	// 		exit(1);
	// 	}
	// }

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
		printf("|4. Intensywny                       	   |\n");
		printf("|5. BIO                                    |\n");
		printf("|6. Szybki/Ekspresowy                      |\n");
		printf("|7. Wyparzanie                             |\n");
		printf("|------------------------------------------|\n");
		printf("|9. Pomoc                                  |\n");
		printf("|------------------------------------------|\n");
		printf("|------------------------------------------|\n");
		printf("|0. Zakoncz                                |\n");
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

		case '9':
			while (1)
			{
				system("clear");

				printf("|------------------------------------------|\n");
				printf("|                   POMOC                  |\n");
				printf("|------------------------------------------|\n");
				printf("|1. Wstepne zmywanie                       |\n");
				printf("|2. Normalny                               |\n");
				printf("|3. Oszczedny (ECO)    	                   |\n");
				printf("|4. Intensywny                       	   |\n");
				printf("|5. BIO                                    |\n");
				printf("|6. Szybki/Ekspresowy                      |\n");
				printf("|7. Wyparzanie                             |\n");
				printf("|------------------------------------------|\n");
				printf("|0. Powrot                                 |\n");
				printf("|------------------------------------------|\n");
				printf("\n");

				help_choice = getchar();

				if (help_choice == '0')
					break;

				switch (help_choice)
				{
				case '1':
					printf("|------------------------------------------|\n");
					printf("|             Wstepne zmywanie             |\n");
					printf("|------------------------------------------|\n");
					printf("|Program ten sluzy do mycia mocno zabrudzo-|\n");
					printf("|nych naczyn, gdzie nalezy je wczesniej na-|\n");
					printf("|moczyc by zabrudzenia zniknely.           |\n");
					printf("|------------------------------------------|\n");
					break;

				case '2':
					printf("|------------------------------------------|\n");
					printf("|                 Normalny                 |\n");
					printf("|------------------------------------------|\n");
					printf("|Program wybieramy gdy naczynia sa srednio |\n");
					printf("|zabrudzone.                               |\n");
					printf("|------------------------------------------|\n");
					break;

				case '3':
					printf("|------------------------------------------|\n");
					printf("|              Oszczedny (ECO)             |\n");
					printf("|------------------------------------------|\n");
					printf("|Szybkie mycie w temperaturze ok. 55°C     |\n");
					printf("|------------------------------------------|\n");
					break;

				case '4':
					printf("|------------------------------------------|\n");
					printf("|                Intensywny                |\n");
					printf("|------------------------------------------|\n");
					printf("|Program intensywny wybieramy gdy garnki   |\n");
					printf("|oraz naczynia są bardzo zabrudzone.       |\n");
					printf("|Sa one zmywane w wysokiej temperaturze.   |\n");
					printf("|------------------------------------------|\n");
					break;

				case '5':
					printf("|------------------------------------------|\n");
					printf("|                   BIO                    |\n");
					printf("|------------------------------------------|\n");
					printf("|Program przeznaczony do naczyn, ktore sa  |\n");
					printf("|wrazliwe na dzialanie silnych plynow      |\n");
					printf("|czyszczacych. Temperatura zmywania nie    |\n");
					printf("|przekracza 50°C.                          |\n");
					printf("|------------------------------------------|\n");
					break;

				case '6':
					printf("|------------------------------------------|\n");
					printf("|             Szybki/Ekspresowy            |\n");
					printf("|------------------------------------------|\n");
					printf("|Sluzy do zmywania naczyn lekko zabrudzo-  |\n");
					printf("|nych oraz do odswiezenia naczyn nieuzywa- |\n");
					printf("|nych. Czas trwania zmywania jest znacznie |\n");
					printf("|skrocony.                                 |\n");
					printf("|------------------------------------------|\n");
					break;

				case '7':
					printf("|------------------------------------------|\n");
					printf("|                Wyparzanie                |\n");
					printf("|------------------------------------------|\n");
					printf("|Zmywarka wyparza naczynia uzywajac do tego|\n");
					printf("|bardzo wysokiej temperatury. Można w niej |\n");
					printf("|wyparzac butelki dzieciece bez potrzeby   |\n");
					printf("|zakupu dodatkowego sterylizatora.         |\n");
					printf("|------------------------------------------|\n");
					break;

				default:
					printf("Niepoprawna opcja\n");
					break;
				}

				getchar();
				getchar();
			}
			break;

		case '0':
			if (msgctl(msqid, IPC_RMID, NULL) == -1)
			{
				perror("msgctl");
				exit(1);
			}

			system("rm /tmp/msgq.txt");

			progressbar(0.02, "Wylaczanie");
			exit(0);
			break;

		default:
			printf("Nie ma takiej opcji (%c) w menu!\n", choice);
			break;
		}

		printf("\nNacisnij Enter, aby kontynuowac...\n");

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