/**
 * @author Przemysław Pradela
 * @email przemyslaw.pradela@gmail.com
 * @create date 2020-01-20 22:38:36
 * @modify date 2020-01-21 00:00:06
 * @desc [description]
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
 * Funkcja zwracająca 0 z prawdopodobieństwiem 75%
 * lub 0 z prawdopodobieństwem 25%.
 *
 * Returns:
 * int.
 */
int rand75();

int main()
{
	struct my_msgbuf buf;
	int msqid;
	int failure;
	key_t key;
	pid_t main;

	srand(time(NULL));

	failure = rand75();

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