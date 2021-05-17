#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void shifter (int shift_value, string shift_dir) {
    string s;
    string dir;
    while(getline(cin, s)){
        if(s[0] == 'e' || s[0] == 'd'){
            if (s[0] == 'e'){
             dir = "right";
            } else {
                dir = "left";
            }

            for(int i=1; i<s.length(); i++) {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                    if (shift_dir == dir){
                        if ((s[i] + shift_value) > 'z' || (((s[i]) >= 'A' && s[i] <= 'Z') && (s[i] + shift_value ) > 'Z')) {
                            s[i] -= 26;
                            s[i] += shift_value;
                        } else {
                            s[i] += shift_value;
                        }
                        cout << s[i];
                    } else {
                        if ((s[i] - shift_value) < 'A' || (((s[i]) >= 'a' && s[i] <= 'z') && (s[i] - shift_value ) < 'a')) {
                            s[i] += 26;
                            s[i] -= shift_value;
                        } else {
                            s[i] -= shift_value;
                        }
                        cout << s[i];
                    }
                } else {
                    cout << s[i];
                }
            }
            cout << endl;
        } else if ( s[0] == 'q') {
            break;
        }
    }
}

int main (int argument, char *args[]) {
    int n = 0;
    if (argument == 1) {
        shifter(3, "right");
    } else if (argument == 2) {
        int a = -1;
        istringstream iss{args[1]};
        if(iss>>n){
            a = n;
        } else {
            cerr << "ERROR: first argument must be an int value\n";
            return 20;
        }
        if (n < 0 || n > 25){
            cerr << "ERROR: Incorrect shift value\n";
            return 5;
        }
        shifter(a, "right");
    } else if (argument == 3) {
        int b = -1;
        istringstream iss{args[1]};
        if(iss>>n){
            b = n;
        } else {
            cerr << "ERROR: first argument must be an int value\n";
            return 20;
        }
        if (n < 0 || n > 25){
            cerr << "ERROR: Incorrect shift value\n";
            return 5;
        }
        string direction = args[2];
        if (!((direction == "left") || (direction == "right"))){
            cerr << "ERROR: Incorrect direction (only left or right allowed).\n";
            return 10;
        }
        shifter(b, args[2]);
    } else {
        int c = -1;
        istringstream iss{args[1]};
        if(iss>>n){
            c = n;
        } else {
            cerr << "ERROR: first argument must be an int value\n";
            return 20;
        }
        if (n < 0 || n > 25){
            cerr << "ERROR: Incorrect shift value\n";
            return 5;
        }
        string direction = args[2];
        if (!((direction == "left") || (direction == "right"))){
            cerr << "ERROR: Incorrect direction (only left or right allowed).\n";
            return 10;
        }
        cerr << "ERROR: program should not be called with more than 2 arguments\n";
        return 15;
    }
}
