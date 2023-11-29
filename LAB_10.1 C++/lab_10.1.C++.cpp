#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Count(ifstream& file) 
{
    int count = 0;
    char current, next;
    file.get(current);
    while (file.get(next)) {
        if (current == next) {
            int consecutive = 2;
            char temp;
            while (file.get(temp) && temp == current) {
                consecutive++;
                if (consecutive == 4) {
                    count++;
                    break;
                }
            }
        }
        current = next;
    }
    return count;
}

int main() {
    string filename;
    cout << "Enter file name: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file '" << filename << "'" << endl;
        return 1;
    }

    cout << "File content: " << endl;
    char ch;
    while (file.get(ch)) {
        cout.put(ch);
    }
    file.clear(); // Скидання стану файлу для повторного використання
    file.seekg(0, ios::beg); // Переміщення позиції файлу на початок

    int consecutiveCount = Count(file);
    cout << "Number of consecutive sequences of 4 characters: " << consecutiveCount << endl;

    file.close();
    return 0;
}