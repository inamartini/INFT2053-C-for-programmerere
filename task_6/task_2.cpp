#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <iostream>

namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
using tcp = asio::ip::tcp;

class WebServer {
private:
    asio::io_service io_service;
    tcp::acceptor acceptor;

    // Handle an HTTP server request
    void handle_request(beast::tcp_stream &stream) {
        beast::flat_buffer buffer;

        // Read a request
        http::request<http::string_body> request;
        http::read(stream, buffer, request);

        // Send the response
        http::response<http::string_body> response;

        // Process the request
        if (request.method() == http::verb::get) {
            if (request.target() == "/") {
                response.result(http::status::ok);
                response.set(http::field::content_type, "text/plain");
                response.body() = "Dette er hovedsiden";
            } else if (request.target() == "/en_side") {
                response.result(http::status::ok);
                response.set(http::field::content_type, "text/plain");
                response.body() = "Dette er en side";
            } else {
                response.result(http::status::not_found);
                response.body() = "404 Not Found";
            }
        } else {
            response.result(http::status::bad_request);
            response.set(http::field::content_type, "text/plain");
            response.body() = "Invalid request method";
        }

        // Prepare and send the response
        response.prepare_payload();
        http::write(stream, response);
    }

    // Accept a new connection
    void accept() {
        auto socket = std::make_shared<tcp::socket>(io_service);

        // Accept a new connection
        acceptor.async_accept(*socket, [this, socket](const boost::system::error_code &error) {
            if (!error) {
                beast::tcp_stream stream(std::move(*socket));

                handle_request(stream);
            }

            accept();
        });
    }

public:
    // Constructor
    WebServer() : acceptor(io_service, tcp::endpoint(tcp::v4(), 8080)) {}

    // Start the server
    void start() {
        accept();
        io_service.run();
    }
};

int main() {
    WebServer webServer;

    std::cout << "Starting echo server" << std::endl
         << "Search http://localhost:8080 in a web-browser to find the main page, or http://localhost:8080/en_side to find another page" << std::endl;

    webServer.start();
}