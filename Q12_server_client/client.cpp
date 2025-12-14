
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serv{};
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);

    connect(s, (sockaddr*)&serv, sizeof(serv));

    char fname[100];
    cout << "Enter filename: ";
    cin >> fname;
    send(s, fname, sizeof(fname), 0);

    char buf[200] = {};
    recv(s, buf, sizeof(buf), 0);

    cout << "\nServer says: " << buf << endl;

    close(s);
}