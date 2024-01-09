#include <arpa/inet.h>
#include <bits/stdc++.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080
#define SERVER_IP "10.0.0.3"

std::string encryption(int key, std::string message);
std::string decryption(int key, std::string message);
std::string sendAndReceive(std::string message, int socketNumber,
                           sockaddr_in *serveraddr);

int main() {
    std::cout<<"salam"<<std::endl;

    int socketNumber;
  struct sockaddr_in serveraddr;

  socketNumber = socket(AF_INET, SOCK_DGRAM, 0);
  if (socketNumber == -1) {
    std::cout << "in cheshe?" << std::endl;
  }

  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(PORT);
  serveraddr.sin_addr.s_addr = inet_addr(SERVER_IP);

  // DF
  int p, n;
  long int key, serverkey;
  int a = 43;

  std::string buffer;
  std::string message;

  buffer = "give me p";
  message = sendAndReceive(buffer, socketNumber, &serveraddr);
  p = std::stoi(message);
  std::cout<<message<<std::endl;

  buffer = "give me n";
  message = sendAndReceive(buffer, socketNumber, &serveraddr);
    n = std::stoi(message);
    key = (long int)pow(n, a) % p;
    std::cout<<"p: "<<p<<" n: "<<n<<" key: "<<key<<std::endl;

  std::cout<<message<<std::endl;

  buffer = "my key is : " + std::to_string(key);
  message = sendAndReceive(buffer, socketNumber, &serveraddr);
  serverkey = std::stoi(message);
  std::cout<<message<<std::endl;

  key = (long int)pow(serverkey, a) % p;
  key = abs(key);
  std::cout<<"lastkey: "<<key<<std::endl;

  buffer = encryption(key, "salam");
  sendto(socketNumber, buffer.c_str(), buffer.size(), 0,
         (const struct sockaddr *)&serveraddr, sizeof(serveraddr));
}

std::string sendAndReceive(std::string message, int socketNumber,
                           sockaddr_in *serveraddr) {
  // send
  std::cout<<"          1"<<std::endl;
  sendto(socketNumber, message.c_str(), message.size(), MSG_CONFIRM,
         (const struct sockaddr *)serveraddr, sizeof(*serveraddr));
  std::cout<<"          2"<<std::endl;
  // receive
  char r[1024];
  unsigned int l = sizeof(serveraddr);

  int nnnn = recvfrom(socketNumber, r, 1024, MSG_WAITALL,
                      (struct sockaddr *)&serveraddr, &l);
  std::cout<<"          3"<<std::endl;
  r[nnnn] = '\0';

  return r;
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

      message[i] += (int)((key / pow(10, j))) * 10 - (int)(key / pow(10, j - 1));

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