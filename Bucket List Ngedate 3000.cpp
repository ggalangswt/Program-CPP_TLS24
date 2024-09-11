#include <iostream>
#include <string>
using namespace std;
const int MAX_TASKS = 100;

struct Task {
    string description;
    bool completed;
};

class TodoList {
private:
    Task tasks[MAX_TASKS];
    int taskCount;

public:
    TodoList() : taskCount(0) {}
    void tambah() {
        if (taskCount < MAX_TASKS) {
            cout << "Mau ngapain nih sama doi: ";
            cin.ignore();
            getline(cin, tasks[taskCount].description);
            tasks[taskCount].completed = false;
            taskCount++;
            cout << "Sukses menambah ke list, semoga jadi!\n";
        }
        else {
            cout << "List udah penuh! Banyak juga bucket list kamu.\n";
        }
    }

    void lihat() {
        if (taskCount == 0) {
            cout << "Kamu belum ngerencanain apa apa, nih.\n";
        }
        else {
            cout << "Bucket list bareng doi: \n";
            for (int i = 0; i < taskCount; ++i) {
                cout << i + 1 << ". ";
                cout << (tasks[i].completed ? "[X] " : "[ ] ");
                cout << tasks[i].description << "\n";
            }
        }
    }

    void selesai() {
        lihat();
        if (taskCount > 0) {
            int index;
            cout << "Bucket list nomer berapa nih yang udah selesai: ";
            cin >> index;
            if (index > 0 && index <= taskCount) {
                tasks[index - 1].completed = true;
                cout << "Ditandai udah selesai! Yeyy!\n";
            }
            else {
                cout << "Nguawor e njenengan le milih!\n";
            }
        }
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        cout << "\n--- Bucket List Ngedate 3000 ---\n";
        cout << "1. Tambahkan kegiatan\n";
        cout << "2. Lihat Bucket List\n";
        cout << "3. Tandai sudah selesai\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihanmu: ";
        cin >> choice;

        switch (choice) {
        case 1:
            todoList.tambah();
            break;
        case 2:
            todoList.lihat();
            break;
        case 3:
            todoList.selesai();
            break;
        case 4:
            cout << "Dadahh! Semoga langgeng\n";
            break;
        default:
            cout << "Nguawor njenengan ki ncen!\n";
        }
    } while (choice != 4);

    return 0;
}