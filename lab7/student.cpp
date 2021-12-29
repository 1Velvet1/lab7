#include "student.h"

/*Объект- студент (поля: ФИО,
группа, номер зачетной
книжки, массив 4-х оценок за
сессию)
********************************
deque Сортировка по ФИО в порядке
убывания
*/

std::string randomizeName() {

	static bool flag = false;
	static std::vector<std::string> fName;
	static std::vector<std::string> sName;
	if (!flag) {

		std::string temp;
		std::ifstream in("fname.txt");

		if (!in.is_open()) {
			std::cout << "Impossible to auto-generate students\nStopping...\n";
			exit(-3);
		}

		while (!in.eof()) {

			in >> temp;
			fName.push_back(temp);

		}
		in.close();
		in.open("lname.txt");

		if (!in.is_open()) {
			std::cout << "Impossible to auto-generate students\nStopping...\n";
			exit(-3);
		}

		while (!in.eof()) {

			in >> temp;
			sName.push_back(temp);

		}

		flag = true;


	}
	return fName[rand() % fName.size()] + " " + sName[rand() % sName.size()];


}

bool nameSort(const Student& l, const Student& r) {

	return l.full_name > r.full_name;

}

Student::Student(const std::string& name = "", const uint16_t group = 0, const uint16_t RBnum = 0,
	const std::vector<uint16_t>& marks = {0, 0, 0, 0}) :full_name(name), group(group), RBnumber(RBnum) {

	Smarks.resize(4);

	if (marks.size() == 4) {

		for (size_t i = 0; i < 4; i++) {

			Smarks[i] = marks[i];

		}

	}else{

		exit(-1);

	}

}

Student::Student(){

	full_name = "";
	group = 0;
	RBnumber = 0;
	Smarks = { 0, 0, 0, 0 };
	
}

void randomizeStudent(Student& st) {

	st.full_name = randomizeName();
	st.group = 1 + rand() % 10;
	st.RBnumber = 1 + rand() % USHRT_MAX;

	for (auto& el : st.Smarks) {

		el = 1 + rand() % 5;

	}

}

void Student::print() const{

	std::cout << "Name: " << this->full_name << std::endl;
	std::cout << "Group: " << this->group << std::endl;
	std::cout << "Record book number: " << this->RBnumber << std::endl;
	std::cout << "Marks: ";
	for (auto& el : this->Smarks) { std::cout << el << " "; }
	std::cout << std::endl << std::endl;

}

void Student::print(printFlags flags) const{

	if (flags & printFlags::STUD_NAME) { std::cout << "Name: " << this->full_name << std::endl; }
	if (flags & printFlags::STUD_GROUP) { std::cout << "Group: " << this->group << std::endl; }
	if (flags & printFlags::STUD_RBNUM) { std::cout << "Record book number: " << this->full_name << std::endl; }
	if (flags & printFlags::STUD_Smarks) { 
	
		std::cout << "Marks: ";
		for (const auto& el : this->Smarks) { std::cout << el << " "; }
		std::cout << std::endl;

	}

	std::cout << std::endl;

}

void Student::changeStudent() {

	std::cout << "Enter full name: ";
	std::cin >> this->full_name;
	std::cout << "Enter group: ";
	std::cin >> this->group;
	std::cout << "Enter record book number: ";
	std::cin >> this->RBnumber;
	std::cout << "Enter marks: ";
	std::cin >> this->Smarks[0] >> this->Smarks[1] >> this->Smarks[2] >> this->Smarks[3];

}

std::istream& operator>>(std::istream& is, Student& st) {

	std::getline(is, st.full_name);
	is >> st.group;
	is >> st.RBnumber;
	is >> st.Smarks[0] >> st.Smarks[1] >> st.Smarks[2] >> st.Smarks[3];

	return is;

}
