
#include "Account.h"
#include "Money.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;


int main()
{
    setlocale(LC_ALL, "RUS");
    string name;
    double percent, initialBalance;
    cout << "Введите имя владельца счета: ";
    getline(cin, name);

    cout << "Введите процентную ставку (например, 0.05 для 5%): ";
    cin >> percent;

    cout << "Введите начальный баланс в рублях: ";
    cin >> initialBalance;

    Account account(name, percent, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n=== МЕНЮ ОПЕРАЦИЙ ===" << endl;
        cout << "1. Пополнить счет" << endl;
        cout << "2. Снять деньги" << endl;
        cout << "3. Проверить возможность снятия" << endl;
        cout << "4. Начислить проценты" << endl;
        cout << "5. Показать балансы в разных валютах" << endl;
        cout << "6. Сменить владельца" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Введите сумму для пополнения: ";
            cin >> amount;
            account.processDeposit(amount);
            cout << "Счет пополнен. Новый баланс: " << account.getRubBalance() << " RUB" << endl;
            break;
        }
        case 2: {
            cout << "Введите сумму для снятия: ";
            cin >> amount;
            if (account.checkWithdrawalPossible(amount)) {
                account.processWithdrawal(amount);
                cout << "Деньги сняты. Новый баланс: " << account.getRubBalance() << " RUB" << endl;
            }
            else {
                cout << "Недостаточно средств для снятия!" << endl;
            }
            break;
        }
        case 3: {
            cout << "Введите сумму для проверки: ";
            cin >> amount;
            if (account.checkWithdrawalPossible(amount)) {
                cout << "Снятие возможно. Достаточно средств." << endl;
            }
            else {
                cout << "Снятие невозможно. Недостаточно средств." << endl;
            }
            break;
        }
        case 4: {
            double oldBalance = account.getRubBalance();
            account.applyInterest();
            double newBalance = account.getRubBalance();
            cout << "Проценты начислены." << endl;
            cout << "Было: " << oldBalance << " RUB" << endl;
            cout << "Стало: " << newBalance << " RUB" << endl;
            cout << "Начислено: " << (newBalance - oldBalance) << " RUB" << endl;
            break;
        }
        case 5: {
            cout << "\n=== БАЛАНСЫ В РАЗНЫХ ВАЛЮТАХ ===" << endl;
            cout << "Рубли: " << account.getRubBalance() << " RUB" << endl;
            cout << "Доллары: " << account.getUsdBalance() << " USD" << endl;
            cout << "Евро: " << account.getEurBalance() << " EUR" << endl;
            break;
        }
        case 6: {
            string newName;
            cout << "Введите новое имя владельца: ";
            cin.ignore();
            getline(cin, newName);
            account.updateOwner(newName);
            cout << "Владелец счета изменен." << endl;
            break;
        }
        case 0: {
            cout << "Выход из программы." << endl;
            break;
        }
        default: {
            cout << "Неверный выбор!" << endl;
            break;
        }
        }

    } while (choice != 0);

    cout << "\n=== ИТОГОВЫЕ ДАННЫЕ СЧЕТА ===" << endl;
    cout << "Баланс в рублях: " << account.getRubBalance() << " RUB" << endl;
    cout << "Баланс в долларах: " << account.getUsdBalance() << " USD" << endl;
    cout << "Баланс в евро: " << account.getEurBalance() << " EUR" << endl;

    return 0;
}