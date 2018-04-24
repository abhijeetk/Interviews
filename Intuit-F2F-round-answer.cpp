/*
Given a file and input of 'n' words, return back :
A] If all 'n' words exist.
B] If A] is TRUE, are there multiple occurrences of ATLEAST one of these words.
C] If B] is TRUE, return the positions (line and word number) of these
words where they are space closest to each other.

Sample Input :
----------------------------------------------------------------------------------------
File contents are as below :
>>>
Sachin has the highest number of Test centuries.
Sachin has the highest number of ODI centuries.
Sachin has total 100 centuries in which 51 are test centuries and 49 are ODI centuries.
>>>

The words to be search 'Sachin' and 'centuries'

Your answer should look like below :
A] TRUE as both words exist in content
B] TRUE, word 'Sachin' has 3 occurrences and word 'centuries' has 5 occurrences
C] Line number 3 and word number 1 and 5.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <istream>

using namespace std;

class wordFinder{
    vector<string> linesInFile; // Problem A
    unordered_map<string, int> mapWordToFreq; // Problem B
public :
    bool readFile(string fName) {
        if (fName.empty()) {
            return false;
        }

        string line;
        ifstream myfile(fName);
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                linesInFile.push_back(line);
            }
            myfile.close();
        }
    }

    bool wordExist(vector<string> words) {
        if (words.empty()) {
            return false;
        }

        vector<bool> res(words.size(), false);
        for (string str : linesInFile) {
            for (int i = 0; i < words.size(); i++) {
                if (str.find(words[i]) != std::string::npos) {
                    res[i] = true;
                }
            }

            bool doesExist = res[0];
            for (int i = 1; i < res.size(); i++) {
                doesExist = doesExist && res[i];
            }
            if (doesExist)
                return true;
        }
        return false;
    }

    bool areMultipleOccurrencesExist(vector<string>& toSearch) {
        for (string str : linesInFile) {
            for (int i = 0; i < toSearch.size(); i++) {
                size_t pos = str.find(toSearch[i]);
                while (pos != std::string::npos)
                {
                    if (mapWordToFreq.find(toSearch[i]) != mapWordToFreq.end()) {
                        //found
                        mapWordToFreq[toSearch[i]]++;
                    }
                    else {
                        // Not found, first occurrence
                        mapWordToFreq[toSearch[i]] = 1;
                    }

                    pos = str.find(toSearch[i], pos + toSearch[i].size());
                }
            }
        }

        bool result = false;
        for (int i = 0; i < toSearch.size(); i++) {
            if (mapWordToFreq.find(toSearch[i]) != mapWordToFreq.end()) {
                if (mapWordToFreq[toSearch[i]] > 1) {  // atleast one
                    result = true;
                    break;
                }

            }
        }
        return result;
    }



    vector<string> tokenize(const string& str, char delimeter = ' ') {
        vector<string> res;
        std::stringstream tokenStream(str);
        std::string token;
        while (std::getline(tokenStream, token, delimeter)) {
            res.push_back(token);
        }
        return res;
    }

    int shortestDistance(vector<string>& toSearch) {
        string w1 = toSearch[0];
        string w2 = toSearch[1];

        int minDistance = INT_MAX;
        pair<int, int> pair;
        int foundAtLine = -1;

        for (int lineNo = 0; lineNo < linesInFile.size(); lineNo++) {
            int absolutePos1 = -1;
            int absolutePos2 = -1;
            vector<string> tokenArr = tokenize(linesInFile[lineNo]);
            for (int index = 0; index < tokenArr.size(); index++) {
                if (tokenArr[index] == w1) {
                    absolutePos1 = index;
                    if (absolutePos2 != -1 && abs(absolutePos1 - absolutePos2) < minDistance) {
                        minDistance = abs(absolutePos1 - absolutePos2);
                        pair = make_pair(absolutePos1, absolutePos2);
                        foundAtLine = lineNo;
                    }
                }

                if (tokenArr[index] == w2) {
                    absolutePos2 = index;
                    if (absolutePos1 != -1 && abs(absolutePos1 - absolutePos2) < minDistance) {
                        minDistance = abs(absolutePos1 - absolutePos2);
                        pair = make_pair(absolutePos1, absolutePos2);
                        foundAtLine = lineNo;
                    }
                }
            }
        }

        if (foundAtLine != -1) {
            cout << "Line number " << foundAtLine + 1 << " and word number " << pair.first + 1 << " and " << pair.second + 1 << endl;
        }

        return minDistance;
    }
};

int main() {
    wordFinder w;
    w.readFile("sample.txt");

    vector<string> input = {"Sachin", "centuries"};
    w.wordExist(input) && w.areMultipleOccurrencesExist(input) && w.shortestDistance(input);
    // OUTPUT : Line number 3 and word number 1 and 5

    vector<string> input1 = { "51", "49" };
    w.wordExist(input1) && w.areMultipleOccurrencesExist(input1) && w.shortestDistance(input1);

    vector<string> input2 = { "49", "centuries" };
    w.wordExist(input2) && w.areMultipleOccurrencesExist(input2) && w.shortestDistance(input2);
    // OUTPUT : Line number 3 and word number 13 and 11

    return 0;

}

