#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <iomanip>

using namespace std;

// Функція для перевірки голосних
bool isVowel(char c) {
    char vowels[] = "aeiouyAEIOUY";
    return strchr(vowels, c) != nullptr;
}

// Завдання 1: Заміна "а" на "*" у більшому масиві
void replaceInLargerArray(string& S1, string& S2) {
    string* larger = S1.size() >= S2.size() ? &S1 : &S2;
    replace(larger->begin(), larger->end(), 'a', '*');
    cout << "Результат заміни в більшому масиві: " << *larger << endl;
}

// Завдання 2: Обробка символьного масиву S1
void processArray(string& S1) {
    // Вивід у зворотному порядку
    string reversed(S1.rbegin(), S1.rend());
    cout << "Зворотний порядок: " << reversed << endl;

    // Перше входження "а"
    size_t firstA = reversed.find('a');
    if (firstA != string::npos)
        cout << "Перше входження 'а' у зворотному масиві: " << firstA + 1 << endl;
    else
        cout << "Літера 'а' відсутня у зворотному масиві." << endl;

    // Сума входжень "_" та "о"
    int underscoreCount = count(S1.begin(), S1.end(), '_');
    int oCount = count(S1.begin(), S1.end(), 'o');
    cout << "Сума входжень '_' та 'о': " << underscoreCount + oCount << endl;

    // Видалення "а" та повторення "*"
    string modified;
    for (char c : S1) {
        if (c != 'a') {
            modified += c;
            if (c == '*') modified += '*';
        }
    }
    cout << "Результат після видалення 'а' та повторення '*': " << modified << endl;

    // Вивід символів між двома вказаними
    char ch1, ch2;
    cout << "Введіть два символи для пошуку (ch1 та ch2): ";
    cin >> ch1 >> ch2;
    size_t start = S1.find(ch1);
    size_t end = S1.find(ch2);
    if (start != string::npos && end != string::npos && start < end) {
        cout << "Символи між " << ch1 << " та " << ch2 << ": "
            << S1.substr(start + 1, end - start - 1) << endl;
    }
    else {
        cout << "Символи між " << ch1 << " та " << ch2 << " не знайдено." << endl;
    }

    // Відсоток голосних
    int vowelCount = count_if(S1.begin(), S1.end(), isVowel);
    double vowelPercentage = (S1.empty() ? 0 : (double)vowelCount / S1.size() * 100);
    cout << "Відсоток голосних: " << fixed << setprecision(2) << vowelPercentage << "%" << endl;
}

// Завдання 3: Вхід "ab", заміна голосних
void countAndReplaceSubstring(string& S1) {
    int abCount = 0;
    for (size_t i = 0; i < S1.size() - 1; ++i) {
        if (S1[i] == 'a' && S1[i + 1] == 'b') abCount++;
    }
    cout << "Кількість входжень 'ab': " << abCount << endl;

    if (abCount > 3) {
        for (char& c : S1) {
            if (isVowel(c)) c = ' ';
        }
    }
    else {
        for (char& c : S1) {
            if (isVowel(c)) c = '.';
        }
    }
    cout << "Результат після заміни: " << S1 << endl;
}

// Завдання 4: Поміняти третини слова місцями
void swapThirds(string& word) {
    if (word.size() != 12) {
        cout << "Слово має бути довжиною рівно 12 символів!" << endl;
        return;
    }
    string first = word.substr(0, 4);
    string second = word.substr(4, 4);
    string third = word.substr(8, 4);

    word = third + second + first;
    cout << "Слово після зміни третин: " << word << endl;

    if (word.find('e') != string::npos) {
        cout << "Слово містить літеру 'е'. Результат: " << word << " " << word << endl;
    }
}

// Завдання 5: Обробка слів, розділених "_"
void processWords(string& S1) {
    vector<string> words;
    size_t start = 0, end;
    while ((end = S1.find('_', start)) != string::npos) {
        words.push_back(S1.substr(start, end - start));
        start = end + 1;
    }
    words.push_back(S1.substr(start));

    int longestWord = 0, countR = 0;
    for (const auto& word : words) {
        longestWord = max(longestWord, (int)word.size());
        if (!word.empty() && word[0] == 'r') countR++;
    }

    cout << "Кількість слів: " << words.size() << endl;
    cout << "Довжина найдовшого слова: " << longestWord << endl;
    cout << "Кількість слів, що починаються з 'р': " << countR << endl;
}

// Основна функція
int main() {
    int option;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Заміна 'а' на '*' у більшому масиві\n";
        cout << "2. Обробка масиву S1\n";
        cout << "3. Вхід 'ab' та заміна голосних\n";
        cout << "4. Поміняти третини місцями\n";
        cout << "5. Обробка слів, розділених '_'\n";
        cout << "0. Вихід\n";
        cout << "Оберіть опцію: ";
        cin >> option;

        if (option == 0) break;

        string S1, S2;
        switch (option) {
        case 1:
            cout << "Введіть S1: ";
            cin >> S1;
            cout << "Введіть S2: ";
            cin >> S2;
            replaceInLargerArray(S1, S2);
            break;
        case 2:
            cout << "Введіть S1: ";
            cin >> S1;
            processArray(S1);
            break;
        case 3:
            cout << "Введіть S1: ";
            cin >> S1;
            countAndReplaceSubstring(S1);
            break;
        case 4:
            cout << "Введіть слово з 12 букв: ";
            cin >> S1;
            swapThirds(S1);
            break;
        case 5:
            cout << "Введіть S1 (слова через '_'): ";
            cin >> S1;
            processWords(S1);
            break;
        default:
            cout << "Невірний вибір!" << endl;
        }
    }

    return 0;
}
