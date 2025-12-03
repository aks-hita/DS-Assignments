#include <iostream>
#include <string>
using namespace std;

void concatenateStrings() {
    string str1, str2;
    cout << "(a) Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    string result = str1 + str2;
    cout << "Concatenated string: " << result << endl;
}
void reverseString() {
    string str;
    cout << "(b) Enter a string to reverse: ";
    cin >> str;

    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    cout << "Reversed string: " << str << endl;
}
bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

void deleteVowels() {
    string str;
    cout << "(c) Enter a string to delete vowels: ";
    cin >> str;
    int len= str.length();
    string result = "";

    for (int i = 0; i < len; i++) {
        if (!isVowel(str[i])) {
            result += str[i];
        }
    }
    cout << "String without vowels: " << result << endl;
}




void sortStrings() {
    int n;
    cout << "(d) Enter number of strings to sort: ";
    cin >> n;
    string arr[n];
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A'); 
    }
    return ch; 
}

void uppercaseToLowercase() {
    char ch;
    cout << "(e) Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        char lower = toLower(ch);
        cout << "Lowercase: " << lower << endl;
    } else {
        cout << "That is not an uppercase character!" << endl;
    }
}

int main() {
    concatenateStrings();
    reverseString();
    deleteVowels();
    sortStrings();
    uppercaseToLowercase();
    return 0;
}
