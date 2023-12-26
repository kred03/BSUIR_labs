#include <iostream>
#include <string>

bool isConsonant(char ch) {
    ch = std::tolower(ch);  //���������� � ������� ��������
    return (ch >= 'a' && ch <= 'z' && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' && ch != 'y');
}

std::string transformText(const std::string& input) {
    std::string result;
    char prevChar = '\0';

    for (char ch : input) {

        if (isConsonant(ch) && std::tolower(ch) == std::tolower(prevChar)) {
            continue; 
        }

        if (ch == 'u' && (prevChar == 'q' || prevChar == 'Q')) {
            result.pop_back(); 
            prevChar == 'q' ? result += "kv" : result += "Kv";
        }
        else if (ch == 'q') {
            result += 'k';
        }
        else if (ch == 'Q' || ch == 'W' || ch == 'C' || ch == 'X') {
            continue; // ���������� ������� 'Q', 'W', 'C' � 'X'
        }
        else if (ch == 'x' || ch == 'X') {
            ch == 'x' ? result += "ks" : result += "Ks";
        }
        else if (ch == 'w' || ch == 'W') {
            ch == 'w' ? result += 'v' : result += 'V';
        }
        else if (ch == 'h' && (prevChar == 'p' || prevChar == 'P')) {
            result.pop_back(); // ������� ���������� 'h'
            prevChar == 'p' ? result += 'f' : result += 'F';
        }
        else if ((ch == 'y' && prevChar == 'o') || (prevChar == 'y' && ch == 'o') || (prevChar == 'o' && ch == 'u')) {
            // ������ 'you' �� 'u'
            result.pop_back();
            result += 'u';
        }
        else if (ch == 'o' && (prevChar == 'o' || prevChar == 'O')) {
            result.pop_back();
            prevChar == 'o' ? result += 'u' : result += 'U';
        }
        else if (ch == 'e' && (prevChar == 'e' || prevChar == 'E')) {
            // �������� 'ee' �� 'i'
            result.pop_back(); // ������� ���������� 'e'
            prevChar == 'e' ? result += 'i' : result += 'I';
        }
        else if (ch == 'h' && (prevChar == 't' || prevChar == 'T')) {
            // �������� 'th' �� 'z'
            result.pop_back(); // ������� ���������� 'h'
            prevChar == 't' ? result += 'z' : result += 'Z';
        }
        else if ((ch == 'e' || ch == 'i' || ch == 'y') && (prevChar == 'c' || prevChar == 'C')) {
            result.pop_back();
            if (ch == 'e') prevChar == 'c' ? result += "se" : result += "Se";
            if (ch == 'i') prevChar == 'c' ? result += "si" : result += "Si";
            if (ch == 'y') prevChar == 'c' ? result += "sy" : result += "Sy";
        }
        else if (ch == 'c') {
            result += 'k';
        }
        else {
            result += std::string(1, ch);
        }
        prevChar = ch;
    }

    //return result;
    std::string finalResult;
    char prevResultChar = '\0';

    for (char resChar : result) {
        if (isConsonant(resChar) && std::tolower(resChar) == std::tolower(prevResultChar)) {
            continue; // ���������� ������� �����, ����� �������� ������������ � ������ result
        }

        finalResult += resChar;

        // ���������� prevResultChar
        prevResultChar = resChar;
    }

    return finalResult;
}

int main() {
    setlocale(LC_ALL, "rus");
    bool endProgram = false;
    while (!endProgram) {

        std::string input;
        std::cout << "Enter the text: ";
        std::getline(std::cin, input);

        std::string transformedText = transformText(input);

        std::cout << "Transformed text: " << transformedText << std::endl;

        std::string yOn;
        std::cout << "\n������������� ���������? (+ | -) ";
        while (!(std::cin >> yOn && (yOn == "+" || yOn == "-"))) {
            std::cin.clear();
            std::cin.ignore(LLONG_MAX, '\n');
            std::cout << "������������� ���������? (+ | -) ";
        }
        if (yOn == "-") endProgram = true;
        std::cin.ignore();
    }
    return 0;
}
