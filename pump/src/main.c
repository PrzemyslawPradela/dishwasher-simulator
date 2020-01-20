/**
 * @author Przemysław Pradela
 * @email przemyslaw.pradela@gmail.com
 * @create date 2020-01-20 22:38:36
 * @modify date 2020-01-20 23:03:59
 * @desc [description]
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

int main()
{
	struct my_msgbuf buf;
	int msqid;
	key_t key;
	pid_t main;

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