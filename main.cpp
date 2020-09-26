#include "main.h"
using namespace std;

int main(int argc, char* argv[]) {

    // 文件参数处理
    ifstream fsin;
    if(argc > 1) {
        fsin.open(argv[1]);
        if(fsin.fail()) {
            cerr << "Invalid input file. Emulator terminated.";
            return 1;
        }
        cin.rdbuf(fsin.rdbuf());
    }

    string tape;    // 纸带内容
    int state;      // 当前状态码
    int cur;        // 图灵机当前位置
    map<int, State> states; // 所有状态集合
    const char LEFT = 'L', RIGHT = 'R', HOLD = 'N';

    // 欢迎语 与 输入纸带内容
    cout << "TURING MACHINE EMULATOR v1.0.0" << endl << "Copyright 2019 Tan Shihuai. *NO* right reserved." << endl << endl << "Please input the tape contents: " << endl;
    cin >> tape;

    // 输入并处理指令集
    cout << endl << "Pattern: state(int), x(char), w(char), h(char), next(int)" << endl << "Please input the instructions, leave blank to terminate input: " << endl;
    string instr;
    cin.get();  // 缓冲区左移，如果没有这一语句，指令读取将会出错
    while (true) {
        instr = "";
        //cin.clear();
        //cin.sync();
        getline(cin, instr);
        if (!instr.empty()) {
            stringstream iss;
            iss << instr;
            int ts;
            Instruction i;
            iss >> ts >> i.x >> i.w >> i.h >> i.q;
            if (states.find(ts) == states.end()) {
                states[ts] = State();
            }
            states[ts].instrs.emplace_back(i);
        } else {
            break;
        }
    }

    // 输入初始状态码
    cout << "Please input the initial state num: ";
    cin >> state;

    // 输入图灵机初始位置
    string curstr;
    cout << endl << "Please input the initial position, 0 for first, 'L' for last: ";
    cin.get();
    //cin.clear();
    //cin.sync();
    getline(cin, curstr);
    if (curstr[0] == 'L') {
        cur = tape.size() - 1;
    } else {
        cur = atoi(curstr.c_str());
    }
    cout << "Computing begins..." << endl << endl;

    int step = 1;
    while (true) {
        cout << step++ << ".\t" << tape << endl << '\t';
        for (int i = 0; i < cur; ++i)
            cout << ' ';
        cout << '^' << endl;

        for (Instruction i: states[state].instrs) {
            if (i.x == tape[cur]) {
                tape[cur] = i.w;
                switch (i.h) {
                    case LEFT:
                        if (cur == 0) {
                            cur = tape.size() - 1;
                        } else {
                            --cur;
                        }
                        break;
                    case RIGHT:
                        if (cur == tape.size() - 1) {
                            cur = 0;
                        } else {
                            ++cur;
                        }
                        break;
                    case HOLD:
                        goto terminate;
                    default:
                        break;
                }
                state = i.q;
                break;
            }
        }
        // 死循环风险提醒
        if (step == 2000) {
            cout << "Please notice that your tape input or instructions might had led to an ENDLESS LOOP." << endl;
            system("pause");
        }
    }
    terminate:
    cout << endl << "Final tape content: " << tape << endl << "Machine Terminated." << endl;
    system("pause");
    return 0;
}
