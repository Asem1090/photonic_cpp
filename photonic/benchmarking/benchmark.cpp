#include <chrono>
#include <iostream>

template<typename FUNCTYPE, typename... ARGSTYPES>
auto benchmark(const FUNCTYPE& func, ARGSTYPES... args)
{
	using namespace std::chrono;
	const auto start{ high_resolution_clock::now() };
	func(args);
	const auto end{ high_resolution_clock::now() };
	const auto time{ end - start };
	std::cout << duration_cast<milliseconds>(time).count() << '\n';
	return time;
}