#include <unistd.h> //unsaif
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serv{};
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(8080);

    bind(s, (sockaddr*)&serv, sizeof(serv));
    listen(s, 1);

    int c = accept(s, nullptr, nullptr);

    char fname[100] = {};
    recv(c, fname, sizeof(fname), 0);

    ifstream f(fname);
    string out;

    if (!f) out = "File not found\n";
    else getline(f, out);

    send(c, out.c_str(), out.size(), 0);

    close(c);
    close(s);
}
