#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#ifndef STUDENT___H
#define STUDENT___H

std::string randomizeName();


class Student {

public:

	Student(const std::string& name, const uint16_t group, const uint16_t RBnum,
		const std::vector<uint16_t>& marks);
	Student();

	enum class printFlags {

		STUD_NAME   = 1 << 0,
		STUD_GROUP  = 1 << 1,
		STUD_RBNUM  = 1 << 2,
		STUD_Smarks = 1 << 3

	};

	void print() const;
	void print(printFlags flags) const;
	

	std::string full_name;
	uint16_t group;
	uint16_t RBnumber;
	std::vector<uint16_t> Smarks;

};

inline Student::printFlags operator|(const Student::printFlags& l, const Student::printFlags& r) {

	return static_cast<Student::printFlags>(static_cast<int>(l) | static_cast<int>(r));

}
inline bool operator&(const Student::printFlags & l, const Student::printFlags & r) {

	return static_cast<bool>(static_cast<int>(l) & static_cast<int>(r));

}

bool nameSort(const Student& l, const Student& r);

void randomizeStudent(Student& st);



#endif // !STUDENT___H