#include "net_simplelib.h"

int *argc_;
char ***argv_;
char ***envp_;



int main(int argc, char *argv[],char *envp[])
{
     
     int sock;
     if (argc < 3) {
          err_quit("sigtest_server <host address> <port#> \n");
     }

     
     argc_ = &argc;
     argv_ = &argv;
     envp_ = &envp;


     daemon_init(argv[0], 0);
     Signal(SIGCHLD, sig_chld);
     
     sock = server_socket(argv[1],argv[2]);

     accept_loop(sock);
     
     close(sock);

}
