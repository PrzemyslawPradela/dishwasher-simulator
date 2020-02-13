/**
 * @author Przemysław Pradela
 * @email przemyslaw.pradela@gmail.com
 * @create date 2020-01-20 22:31:42
 * @modify date 2020-02-13 14:35:57
 * @desc A spray arms controller
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define PERMS 0644

struct my_msgbuf
{
	long mtype;
	char mtext[200];
};

/*
 * Function: rand50
 * Funkcja zwracająca 0 lub 1 z równym prawdopodobieństwem.
 *
 * Returns:
 * int.
 */
int rand50();

/*
 * Function: rand50
 * Funkcja zwracająca 1 z prawdopodobieństwiem 75%
 * lub 0 z prawdopodobieństwem 25%.
 *
 * Returns:
 * int.
 */
int rand75();

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
	int ready;
	key_t key;
	pid_t main;

	srand(time(NULL));

	if ((key = ftok("/tmp/msgq.txt", 'B')) == -1)
	{
		perror("ftok");
		exit(1);
	}

	if ((msqid = msgget(key, PERMS)) == -1)
	{
		perror("msgget");
		exit(1);
	}

	buf.mtype = 1;
	sprintf(buf.mtext, "%d", getpid());
	if (msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0) == -1)
	{
		perror("msgsnd");
		exit(1);
	}

	if (msgrcv(msqid, &buf, sizeof(buf.mtext), getpid(), 0) == -1)
	{
		perror("msgrcv");
		exit(1);
	}

	main = atoi(buf.mtext);

	while (1)
	{
		system("clear");

		ready = rand75();
		if (ready)
		{
			printf("Ramiona spryskujace wlaczone\n");
		}

		buf.mtype = main;
		sprintf(buf.mtext, "%d", ready);
		if (msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0) == -1)
		{
			perror("msgsnd");
			exit(1);
		}

		if (!ready)
		{
			while (1)
			{
				msgrcv(msqid, &buf, sizeof(buf.mtext), getpid(), IPC_NOWAIT);

				if (strcmp(buf.mtext, "stop") == 0)
				{
					exit(1);
				}

				printf("AWARIA RAMION SPRYSKUJACYCH!\n");
				sleep(3);
			}
		}

		if (msgrcv(msqid, &buf, sizeof(buf.mtext), getpid(), 0) == -1)
		{
			perror("msgrcv");
			exit(1);
		}

		if (strcmp(buf.mtext, "stop") == 0)
		{
			break;
		}

		if (strcmp(buf.mtext, "wst") == 0)
		{
			progressbar(0.03, "Mycie naczyn");
			buf.mtype = 3;
			strcpy(buf.mtext, "done3");
			if (msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0) == -1)
			{
				perror("msgsnd");
				exit(1);
			}
		}
		else if (strcmp(buf.mtext, "nor") == 0)
		{
			progressbar(0.003, "Mycie naczyn");
			buf.mtype = 3;
			strcpy(buf.mtext, "done3");
			if (msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0) == -1)
			{
				perror("msgsnd");
				exit(1);
			}
		}
		else if (strcmp(buf.mtext, "eco") == 0)
		{
			progressbar(0.005, "Mycie naczyn");
			buf.mtype = 3;
			strcpy(buf.mtext, "done3");
			if (msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0) == -1)
			{
				perror("msgsnd");
				exit(1);
			}
		}
		else if (strcmp(buf.mtext, "int") == 0)
		{
			progressbar(0.001, "Mycie naczyn");
			buf.mtype = 3;
			strcpy(buf.mtext, "done3");
			if (msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0) == -1)
			{
				perror("msgsnd");
				exit(1);
			}
		}
		else if (strcmp(buf.mtext, "bio") == 0)
		{
			progressbar(0.003, "Mycie naczyn");
			buf.mtype = 3;
			strcpy(buf.mtext, "done3");
			if (msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0) == -1)
			{
				perror("msgsnd");
				exit(1);
			}
		}
		else if (strcmp(buf.mtext, "eks") == 0)
		{
			progressbar(0.008, "Mycie naczyn");
			buf.mtype = 3;
			strcpy(buf.mtext, "done3");
			if (msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0) == -1)
			{
				perror("msgsnd");
				exit(1);
			}
		}
		else if (strcmp(buf.mtext, "wyp") == 0)
		{
			progressbar(0.0001, "Mycie naczyn");
			buf.mtype = 3;
			strcpy(buf.mtext, "done3");
			if (msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0) == -1)
			{
				perror("msgsnd");
				exit(1);
			}
		}
	}

	return (0);
}

int rand50()
{
	return rand() & 1;
}

int rand75()
{
	return rand50() | rand50();
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