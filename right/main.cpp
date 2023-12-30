#include <arpa/inet.h>
#include <bits/stdc++.h>
#include <map>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080
#define SERVER_IP "10.0.0.3"

std::string encryption(int key, std::string message);
std::string decryption(int key, std::string message);


int main() {
  int socketNumber;
  struct sockaddr_in cliaddr, serveraddr;

  socketNumber = socket(AF_INET, SOCK_DGRAM, 0);
  if (socketNumber == -1) {
    std::cout << "in cheshe?" << std::endl;
  }

  memset(&cliaddr, 0, sizeof(cliaddr));
  unsigned int cliaddrLen = sizeof(cliaddr);

  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(PORT);
  serveraddr.sin_addr.s_addr = inet_addr(SERVER_IP);

  if (bind(socketNumber, (const struct sockaddr *)&serveraddr,
           sizeof(serveraddr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // DF
  std::map<in_addr_t, int> key;
  int p = 888883, n = 777;
  int a = 666;

  std::string message;
  char recmessage[1024] = {};
  int temp;

  while (true) {

    int recvmessagesize = recvfrom(socketNumber, recmessage, 1024, MSG_WAITALL,
                                   (struct sockaddr *)&cliaddr, &cliaddrLen);
    recmessage[recvmessagesize] = '\0';
    message = recmessage;

    if (message == "give me p") {
      message = std::to_string(p);
      sendto(socketNumber, message.c_str(), message.size(), MSG_CONFIRM,
             (const struct sockaddr *)&cliaddr, cliaddrLen);
    } else if (message == "give me n") {
      message = std::to_string(n);
      sendto(socketNumber, message.c_str(), message.size(), MSG_CONFIRM,
             (const struct sockaddr *)&cliaddr, cliaddrLen);
    } else if (message.substr(0, 9) == "my key is") {

      temp = (int)pow(n, a) % p;
      message = std::to_string(temp);

      sendto(socketNumber, message.c_str(), message.size(), MSG_CONFIRM,
             (const struct sockaddr *)&cliaddr, cliaddrLen);

      if (key[cliaddr.sin_addr.s_addr] < 0) {
        message = recmessage;
        temp = (int)pow(std::stoi(message.substr(8)), 666) % p;
        key[cliaddr.sin_addr.s_addr] = abs(temp);
      }
    } else {
      message = recmessage;
      message = decryption(key[cliaddr.sin_addr.s_addr],message);

      message = encryption(key[cliaddr.sin_addr.s_addr], "ke chi?");
      sendto(socketNumber, message.c_str(), message.size(), MSG_CONFIRM,
             (const struct sockaddr *)&cliaddr, cliaddrLen);
    }
  }
}

std::string encryption(int key, std::string message) {
    int temp = key;

    int key_size = 0;
    while (temp > 0) {
        temp /= 10;
        key_size++;
    }

    for (int i = 0; i < message.size(); i++) {
        int j = i % key_size;
        message[i] += (key / pow(10, j)) * 10 - key / pow(10, j - 1);
    }

    return message;
}

std::string decryption(int key, std::string message) {
    int temp = key;

    int key_size = 0;
    while (temp > 0) {
        temp /= 10;
        key_size++;
    }

    for (int i = 0; i < message.size(); i++) {
        int j = i % key_size;
        message[i] -= (key / pow(10, j)) * 10 - key / pow(10, j - 1);
    }

    return message;
}
