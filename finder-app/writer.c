#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char* argv[])
{
    openlog("writer", LOG_PERROR, LOG_USER);

    if (argc < 3)
    {
        syslog(LOG_ERR, "Invalid number of arguments");
        goto failed;
    }


    syslog(LOG_DEBUG, "Writing %s to %s", argv[0], argv[1]);

    int fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if(fd == -1)
    {
        syslog(LOG_ERR, "Failed to open the file %s.", argv[1]);
        goto failed;
    }
    
    int nr = write(fd, argv[2], strlen(argv[2]));
    if (nr == -1)
    {
        syslog(LOG_ERR, "Failed to write.");
        goto failed;
    }

    close(fd);

    return 0;
failed:
    closelog();
    return 1;
}