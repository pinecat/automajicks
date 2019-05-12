#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    // print some output to user
    cout << ">> =============================" << endl;
    cout << ">> |  AutoMajicks AutoClicker  |" << endl;
    cout << ">> =============================" << endl;
    cout << ">> v1.0.0                       " << endl;
    cout << ">> By pinecat                   " << endl;
    cout << "..                              " << endl;
    cout << ">> CONTROLS:                    " << endl;
    cout << ">> Press ALT+HOME for toggle on " << endl;
    cout << ">> Press ALT+END for toggle off " << endl;
    cout << ">> Press ALT+DELETE to quit     " << endl;
    cout << "..                              " << endl;
    cout << ">> Have fun :D                  " << endl << endl;

    // while true
    while (true) {
        if (GetAsyncKeyState(VK_MENU) && GetAsyncKeyState(VK_DELETE)) { break; } // exit outer loop and finish program on DELETE
        if (GetAsyncKeyState(VK_MENU) && GetAsyncKeyState(VK_HOME)) { // toggle on autoclicker on HOME
            // get cursor position
            int x;
            int y;
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            x = cursorPos.x;
            y = cursorPos.y;

            // while true
            while (true) {
                // set cursor and click
                SetCursorPos(x, y);
				mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

                // exit inner loop on END
				if (GetAsyncKeyState(VK_MENU) && GetAsyncKeyState(VK_END)) { break; } // toggle off autoclicker on END
            }
        }
    }

    // print some output to user
    cout << ">> Thanks for using AutoMajicks :D" << endl;
    cout << ">> Now quitting....Goodbye        " << endl;

    // return 0 on clean exit
    return 0;
}
