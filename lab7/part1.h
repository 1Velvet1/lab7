#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <deque>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <time.h>

#ifndef PART1___H
#define PART1___H


int PRNG(int max_val);

const size_t num = 99999;
//1::
void add_to_deckf(std::deque<int>& deq);

void insert_in_set(std::set<int>& st);
//2::
void search_deq(std::deque<int>& deq, const int& search_val);

void search_set(std::set<int>& st, const int& search_val);
//3::
void del_from_deckf(std::deque<int>& deq);

void del_from_set(std::set<int>& st);



#endif // !PART1___H