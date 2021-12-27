#include "part1.h"


int PRNG(int max_val) {

	uint32_t num = rand();

	while (num < max_val) { num = rand() * rand(); }

	return num % max_val;

}

//1::
void add_to_deckf(std::deque<int>& deq) {

	auto start = std::chrono::high_resolution_clock::now();

	for (size_t i = 0; i < num; i++) {

		deq.push_front(1 + rand() % 256);

	}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "Adding " << num << " elements to deque front took " << time.count() << " milliseconds\n";

}

void insert_in_set(std::set<int>& st) {

	auto start = std::chrono::high_resolution_clock::now();

	for (size_t i = 0; i < num; i++) {

		st.insert(PRNG(num));

	}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "Adding " << num << " elements to set took " << time.count() << " milliseconds\n";

}
//2::
void search_deq(std::deque<int>& deq, const int& search_val) {

	auto start = std::chrono::high_resolution_clock::now();

	std::cout << *find(deq.begin(), deq.end(), search_val) << std::endl;

	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "Searching for int value of deque took " << time.count() << " microseconds\n";

}

void search_set(std::set<int>& st, const int& search_val) {

	auto start = std::chrono::high_resolution_clock::now();

	std::cout << *st.find(search_val) << std::endl;

	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "Searching for int value of set took " << time.count() << " microseconds\n";

}
//3::
void del_from_deckf(std::deque<int>& deq) {

	auto start = std::chrono::high_resolution_clock::now();

	for (size_t i = 0; i < num; i++) {

		deq.pop_front();

	}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "Deleting " << num << " elements from deque front took " << time.count() << " milliseconds\n";

}

void del_from_set(std::set<int>& st) {

	auto start = std::chrono::high_resolution_clock::now();

	for (size_t i = 0; i < num; i++) {

		st.erase(PRNG(num));

	}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "Deleting " << num << " elements from set took " << time.count() << " milliseconds\n";

}