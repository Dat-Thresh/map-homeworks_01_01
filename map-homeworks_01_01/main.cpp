#include <iostream>
#include <thread>
#include <execution>
#include <chrono>

using namespace std::chrono_literals;

void client_queue(int& clients) {
	while (clients < 10) {
		std::this_thread::sleep_for(100ms);
		clients++;
		std::cout << "Client arrived: " << clients << std::endl;
	}
}

void operationist(int& clients) {
	while (clients > 0) {
		std::this_thread::sleep_for(200ms);
		clients--;
		std::cout << "Operationist called: " << clients << std::endl;
	}
};


int main() {
	int clients = 5;
	std::thread th1(client_queue, std::ref(clients));
	std::thread th2(operationist, std::ref(clients));
	th1.join();
	th2.join();

	return 0;

}