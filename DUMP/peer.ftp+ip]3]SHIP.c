// C program to demonstrate peer to peer chat using Socket Programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

char name[20];
int PORT;

void sending();
void receiving(int server_fd);
void *receive_thread(void *server_fd);

int main(int argc, char const *argv[])
{
    printf("Enter name:");
    scanf("%s", name);

    printf("Enter your port number:");
    scanf("%d", &PORT);

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int k = 0;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    // Forcefully attaching socket to the port

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    //Printed the server socket addr and port
    printf("IP address is: %s\n", inet_ntoa(address.sin_addr));
    printf("port is: %d\n", (int)ntohs(address.sin_port));

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 5) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    int ch;
    pthread_t tid;
    pthread_create(&tid, NULL, &receive_thread, &server_fd); //Creating thread to keep receiving message in real time
    printf("\n*****At any point in time press the following:*****\n1.Send message\n0.Quit\n");
    printf("\nEnter choice:");
    do
    {

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            sending();
            break;
        case 0:
            printf("\nLeaving\n");
            break;
        default:
            printf("\nWrong choice\n");
        }
    } while (ch);

    close(server_fd);

    return 0;
}

//Sending messages to port
void sending()
{

    char buffer[2000] = {0};
    //Fetching port number
    int PORT_server;
    ////in ftp we hope4 📲️
     FILE *file;  //📲️


    //IN PEER WE TRUST
    printf("Enter the port to send message:"); //Considering each peer will enter different port
    scanf("%d", &PORT_server);
    /////////
        int sock = 0, valread;
    char dest_ip[16]; // assuming 15 characters for an IP address and 1 character for null termination

    // ...
    printf("Enter the destination IP address: "); //127.0.0.1
//10.0.0.16 ssh etc,
    scanf("%s", dest_ip);

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET; // For IPv4
    //inet_pton(AF_INET, "192.168.1.100", &serv_addr.sin_addr); // Example IP address

    inet_pton(AF_INET, dest_ip, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(PORT_server);

    // ...
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, 
sizeof(serv_addr)) < 0) {
        perror("connect");
        return;
    }
//}

 char hello[1024] = {0};
    /////
   

/*
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char hello[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY always gives an IP of 0.0.0.0
    serv_addr.sin_port = htons(PORT_server);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return;
    }
 */   

      file = fopen("chat.txt", "r"); // read from the chat.txt file

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char buffer_fp[2000] = {0};
    int n;

    while ((n = fread(buffer_fp, 1, sizeof(buffer_fp), file)) > 0) {
        send(sock, buffer_fp, n, 0);
    }
    
    printf("\nMessage sent\n");
    close(sock);
    /*
    ///
    char dummy;
    printf("Enter your message:");
   scanf("%c", &dummy); //The buffer is our enemy
    scanf("%[^\n]s", buffer_fp);
    sprintf(buffer, "%s[PORT:%d] says: %s", name, PORT, buffer_fp);
    send(sock, buffer, sizeof(buffer), 0);
    printf("\nMessage sent\n");
    close(sock);

    */
    
    
/*
    char dummy;
    printf("Enter your message:");
   scanf("%c", &dummy); //The buffer is our enemy
    scanf("%[^\n]s", hello);
    sprintf(buffer, "%s[PORT:%d] says: %s", name, PORT, hello);
    send(sock, buffer, sizeof(buffer), 0);
    printf("\nMessage sent\n");
    close(sock);
    */
}

//Calling receiving every 2 seconds
void *receive_thread(void *server_fd)
{
    int s_fd = *((int *)server_fd);
    while (1)
    {
        sleep(2);
        receiving(s_fd);
    }
}

//Receiving messages on our port
void receiving(int server_fd)
{
    struct sockaddr_in address;
    int valread;
    char buffer[2000] = {0};
    int addrlen = sizeof(address);
    fd_set current_sockets, ready_sockets;

    //Initialize my current set
    FD_ZERO(&current_sockets);
    FD_SET(server_fd, &current_sockets);
    int k = 0;
    while (1)
    {
        k++;
        ready_sockets = current_sockets;

        if (select(FD_SETSIZE, &ready_sockets, NULL, NULL, NULL) < 0)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < FD_SETSIZE; i++)
        {
            if (FD_ISSET(i, &ready_sockets))
            {

                if (i == server_fd)
                {
                    int client_socket;

                    if ((client_socket = accept(server_fd, (struct sockaddr *)&address,
                                                (socklen_t *)&addrlen)) < 0)
                    {
                        perror("accept");
                        exit(EXIT_FAILURE);
                    }
                    FD_SET(client_socket, &current_sockets);
                }
                else
                {
                    valread = recv(i, buffer, sizeof(buffer), 0);
                    printf("\n%s\n", buffer);
                    FD_CLR(i, &current_sockets);
                    ///////]ON!📲️
                    
                     FILE *file;
                    file = fopen("chat_0.txt", "w"); // write to the chat.txt file
                    
                     if (file == NULL) {
                        printf("Error opening file!\n");
                        return;
                    }

                    int n;

                    while ((n = fwrite(buffer, 1, valread, file)) < 0) {
                        perror("Write failed\n");
                        fclose(file);
                        return;
                    }

                    fclose(file);


                    //////📲️
                }
            }
        }

        if (k == (FD_SETSIZE * 2))
            break;
    }
}


/*
⁉️ how do i change this codebase to L
 send and recieve a file this way . for file reads instead of user keyboard input.(stdin or w/e)
 chat can read from file. 
 
 "chat.txt" and write to "chat.txt" all members in chat should have the same copy of "chat.txt"
 
 ]can oll write that mod? 
 */

//⁉️ how do i change this codebase to let me specify which ip address i want to connect with ⁉️ 

/////📝️notes? : 







