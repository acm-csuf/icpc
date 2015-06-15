#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string lowercase(string name)
{
    for (int i = 0; i < name.length(); i++) {
        name[i] = tolower(name[i]);
    }

    return name;
}

//main
int main()
{
    int keywords;
    int excuse;
    int testCaseNum = 1;

    while (cin >> keywords)
    {
        vector<string> kw;
        vector<string> ex;
        vector<int> count;

        kw.clear();
        ex.clear();
        count.clear();


        cin >> excuse;
        //cout << " sfad " << keywords << " afsd " << excuse << endl;

        for (int i = 0; i < excuse; ++i) {
            //cout << "cccc " << count[i] << endl;
            count.push_back(0);
        }

        string w;
        for (int i = 0; i < keywords; ++i) {
            cin >> w;
            kw.push_back(w);
        }
        //cout << "w " << w << endl;
        string e;
        cin.ignore();
        for (int i = 0; i < excuse; ++i) {
            getline(cin, e);
            ex.push_back(e);
        }

        //cout << "word " << e << endl;

        int max = 0;

        for (int i = 0; i < ex.size(); ++i) {
            string e;
            e = ex[i];
            //cout << "afsd \n";
            e = lowercase(e);
            //cout << "ecca " << e << endl;

            for (int j = 0; j < kw.size(); ++j) {
                string temp;
                temp = kw[j];

                temp = lowercase(temp);

                //cout << " temo " << temp << endl;
                for (int l = e.find(temp); l != string::npos; l = e.find(temp, l + 1)) {
                    if (l == string::npos) {
                        break;
                    }

                    if (isalpha(e[l - 1]) || isalpha(e[l + temp.length()])) {
                        continue;
                    } else {
                        count[i] += 1;
                    }
                }

                //if (e[l + temp.length()] ==
                //	count[i] += 1;

                //cout << "next e " << e << endl;
                if (count[i] > max) {
                    //cout << "setting max to " << count[i] << endl;
                    max = count[i];
                }
            }
        }

        //cout << "e2 "  << endl;

        vector<string> worstExcuses;
        for (int i = 0; i < ex.size(); ++i) {
            if (count[i] == max && max != 0) {
                worstExcuses.push_back(ex[i]);
            }
        }

        cout << "Excuse Set #" << testCaseNum << endl;
        for (int i = 0; i < worstExcuses.size(); ++i) {
            cout << worstExcuses[i] << endl;
        }

        cout << endl;
        testCaseNum++;
    }
}