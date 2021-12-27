#include "part1.h"
#include "student.h"

/*1 Добавление элементов в начало deque и вставка в set.
2. Поиск элементов.
3. Удаление элементов из начала deque и удаление из set.*/


int main() {

	srand(time(NULL));
	//***************PART 1*******************//
	//1::
	std::deque<int> deq = { 42141, 421, 5, 326 };	
	add_to_deckf(deq);
	std::set<int> st = { 321412,53256,64324,2123,5253 };
	insert_in_set(st);
	//2::
	const int search_val = PRNG(num);
	deq[PRNG(num)] = search_val;
	search_deq(deq, search_val);
	st.insert(search_val);
	search_set(st, search_val);
	//3::
	del_from_deckf(deq);
	del_from_set(st);
	//***************PART 2*******************//

	std::deque<Student> stVec;
	Student temp;

	for (size_t i = 0; i < 7; i++) {

		randomizeStudent(temp);
		stVec.emplace_back(temp);
	
		stVec[i].print();

	}

	std::cout << "***************************************************\n";

	std::sort(stVec.begin(), stVec.end(), nameSort);

	for (const auto& el : stVec) {

		el.print(Student::printFlags::STUD_NAME | Student::printFlags::STUD_GROUP);

	}

	system("pause");
	return 0;

}