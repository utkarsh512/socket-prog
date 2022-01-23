#include <iostream>
#include <random>
#include <iomanip>

int main() {
  // seed the random number generator
  std::cout << std::fixed << std::setprecision(6);
  std::random_device rd;
  std::mt19937 rng(rd());

  std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  std::cout << "Generation of Poisson Traffic\n";
  std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

  // input model parameters
  double averageArrival;
  int nPackets;
  std::cout << "Average time (in ms) b/w arrival of packets: ";
  std::cin >> averageArrival;
  std::cout << "Number of packets: ";
  std::cin >> nPackets;

  std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

  // building the model
  double lamdba = 1 / averageArrival;
  std::exponential_distribution<double> exp(lamdba);
  double sum = 0;

  // start simulation
  std::cout << std::setw(10) << "Packet #" << " : ";
  std::cout << "Arrival Time (in ms)\n";
  for (int i = 0; i < nPackets; i++) {
    double newArrivalTime = exp(rng);
    sum += newArrivalTime;
    std::cout << std::setw(10) << i + 1 << " : ";
    std::cout << sum << "\n";
  }
  return 0;
}
