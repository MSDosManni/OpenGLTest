#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

string read(tcp::socket &socket) {
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\n");
    string data = boost::asio::buffer_cast<const char*>(buf.data());
    return data;
}

void send(tcp::socket &socket, const string &msg) {
    const string endl_msg = msg + "\n";
    boost::asio::write(socket, boost::asio::buffer(endl_msg));
}

int main() {
    boost::asio::io_service io_service;

    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v6(), 1234));

    tcp::socket socket(io_service);
    acceptor.accept(socket);

    string msg = read(socket);
    cout << msg << endl;

    send(socket, "Hello from Server!");
    cout << "Servent sent hello message to client!" << endl;

    return 0;
}
