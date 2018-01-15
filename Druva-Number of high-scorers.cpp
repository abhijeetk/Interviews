/*
In this problem, you have to write a program that reads a file containing scores received by students in a number of subjects, and does some processing on it.

The input is being read in from a file called input.txt, in this format:

22, Data Structures, 45
23, English, 52
22, English, 51
26, Data Structures, 72
23, Data Structures, 61
26, English, 81
Each line consists of three fields "Student ID," "Subject," and "Marks." "Student ID" and "Marks" are integers and "Subject" is a string that does not contain commas or newlines. There can be any number of students and up to 6 subjects.

Your program should read this file, count the number of students whose total marks across all subjects is 100 or more, and write the count to a file called output.txt.

For example, if your program is run with the input given above, then at the end the file output.txt should contain just 2. That's because 2 students (with ID 23 and 26) have aggregates scores of 100 or more.
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>

#define NUM_FIELDS 3
struct SplitLine {
    std::string fields[NUM_FIELDS];
};

/* If you wish you can include any more files here.
(from standard libraries only) */

enum rIndex {
    STUSDENT_ID = 0,
    SUBJECT,
    MARKS
};

int processData(std::vector<struct SplitLine> data) {
    /*
    * Modify this function to process `data` as indicated
    * in the question. At the end, return the appropriate
    * value.
    *
    * Please create appropriate classes, and use appropriate
    * data structures as necessary.
    *
    * Do not print anything in this function.
    *
    * Note: the existing program is not intended to be an example
    * of good programming practice. (For example, struct
    * SplitLine is not a very good way to hold the data for this
    * problem.)  However, the code that *you* write will be
    * evaluated on the basis of the quality of the code, use of
    * appropriate classes/data-structures, comments, and
    * efficiency of the algorithm used.
    *
    * Submit this entire program (not just this function)
    * as your answer
    */

    std::map<int, int> student; // STUSDENT_ID <-> MARKS

    for (auto record : data) {
        int sId = stoi(record.fields[STUSDENT_ID]);
        int sMarks = stoi(record.fields[MARKS]);

        auto itr = student.find(sId);
        if (itr != student.end()) { // Record already exist
            int tempMarks = sMarks + itr->second;
            itr->second = tempMarks;
        } else {
            student.insert(std::make_pair(sId, sMarks));
        }
    }

    int count = 0;
    for (auto s : student) {
        if (s.second >= 100) {
            count++;
        }
    }
    return count;
}

int main(void) {
    std::ifstream in("input.txt");
    std::vector<struct SplitLine> input_data;
    while (in) {
        struct SplitLine line;
        for (int i = 0; i<NUM_FIELDS; i++) {
            if (i == NUM_FIELDS - 1)
                std::getline(in, line.fields[i]);
            else
                std::getline(in, line.fields[i], ',');
        }
        if (line.fields[0] != "")
            input_data.push_back(line);
    }
    std::ofstream out("output.txt");
    out << processData(input_data) << std::endl;
    return 0;
}