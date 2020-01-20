/**
 * @author Przemysław Pradela
 * @email przemyslaw.pradela@gmail.com
 * @create date 2020-01-20 14:29:57
 * @modify date 2020-01-20 14:34:33
 */

#include <stdio.h>
#include <stdlib.h>
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
 * Funkcja służąca do wizualizacji postępu danego zadania
 *
 * Parameters:
 * progress_speed - szybkość wykonywania się zadania
 * task - nazwa zadania
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
	key_t key;
	pid_t child_pid[3];

	if ((key = ftok(".", 'B')) == -1)
	{
		perror("ftok");
		exit(1);
	}

	if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1)
	{
		perror("msgget");
		exit(1);
	}

	if ((child_pid[0] = fork()) == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (child_pid[0] == 0)
	{
		if (execl("/usr/bin/konsole", "konsole", "-e", "heater", NULL) == -1)
		{
			perror("execl");
			exit(1);
		}
	}

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
			printf("Nie ma takiej opcji (%c) w menu!\n", choice);
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