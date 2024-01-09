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
  std::cout<<"salam"<<std::endl;
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
  unsigned int serveraddrLen = sizeof(serveraddr);

  if (bind(socketNumber, (const struct sockaddr *)&serveraddr,
           sizeof(serveraddr)) < 0) {
    std::cout << "-bind-" << std::endl;
    exit(EXIT_FAILURE);
  }

  // DF
  std::map<in_addr_t, long int> key;
  int p = 1008001, n = 71;
  int a = 67;

  std::string message;
  char recmessage[1024] = {};
  long int temp;
  while (true) {
      std::cout<<"          1"<<std::endl;
    int recvmessagesize = recvfrom(socketNumber, recmessage, 1024, MSG_WAITALL,
                                   (struct sockaddr *)&cliaddr, &cliaddrLen);
        std::cout<<"            2"<<std::endl;
      recmessage[recvmessagesize] = '\0';
      message = recmessage;
      std::cout << message << std::endl;
    if (message == "give me p") {
      message = std::to_string(p);
      sendto(socketNumber, message.c_str(), message.size(), MSG_CONFIRM,
             (const struct sockaddr *)&cliaddr, cliaddrLen);
    } else if (message == "give me n") {
      message = std::to_string(n);
      sendto(socketNumber, message.c_str(), message.size(), MSG_CONFIRM,
             (const struct sockaddr *)&cliaddr, cliaddrLen);
    } else if (message.substr(0, 9) == "my key is") {
      // if (key[cliaddr.sin_addr.s_addr] < 0) {
      message = message.substr(12);
      temp = (long int)pow(std::stoi(message), a) % p;
      key[cliaddr.sin_addr.s_addr] = abs(temp);
      //}
      temp = (long int)pow(n, a) % p;
      message = std::to_string(temp);
        std::cout<<"uuuuuuuuuuuuuuu"<<std::endl;
      sendto(socketNumber, message.c_str(), message.size(), MSG_CONFIRM,
             (const struct sockaddr *)&cliaddr, cliaddrLen);
    } else {
      std::cout << "recvmessage: "<<message << std::endl;
      message = decryption(key[cliaddr.sin_addr.s_addr], message);
      std::cout << "e: "<<message << std::endl;
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
    message[i] += (int)(key / pow(10, j)) * 10 - (key / pow(10, j - 1));
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
      message[i] -= (int)((key / pow(10, j))) * 10 - (key / pow(10, j - 1));
  }

  return message;
}
