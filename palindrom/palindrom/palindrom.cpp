#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

bool isPalindrome(Node* head, int length) {
    int* dataues = new int[length];
    Node* current = head;

    for (int i = 0; i < length; i++) {
        dataues[i] = current->data;
        current = current->next;
    }

    for (int i = 0; i < length / 2; i++) {
        if (dataues[i] != dataues[length - i - 1] || dataues[i]>9 || dataues[i]<0) {
            delete[] dataues;
            return false;
        }
    }

    delete[] dataues;
    return true;
}

pair<Node*, int> findLongestPalindrome(Node* head) {
    if (!head || !head->next) return make_pair(nullptr, 0);

    Node* resultNode = nullptr;
    int maxLength = 0;
    Node* currenthead = head;

    while (currenthead) {
        Node* current = currenthead;
        int currentLength = 0;

        while (current) {
            currentLength++;
            if (currentLength >= 2) {
                if (isPalindrome(currenthead, currentLength)) {
                    if (currentLength > maxLength) {
                        maxLength = currentLength;
                        resultNode = currenthead;
                    }
                }
            }

            current = current->next;
        }

        currenthead = currenthead->next;
    }

    if (maxLength >= 2) {
        return make_pair(resultNode, maxLength);
    }
    else {
        return make_pair(nullptr, 0);
    }
}

Node* initList(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

void print(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void clear(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    const int n = 10;
    int test[n];
    for (int i = 0; i < n; i++) {
        cout << "Введите число - ";
        cin >> test[i];
    }

    Node* list = initList(test, n);

    print(list);

    pair<Node*, int> result = findLongestPalindrome(list);
    if (result.first) {
        cout << "Найден палиндром длиной " << result.second;
        cout << ", начинается с " << result.first->data << endl;
    }
    else {
        cout << "Палиндром не найден" << endl;
    }

    clear(list);

    return 0;
}