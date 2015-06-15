#include <iostream>
#include <vector>

using namespace std;

struct nodes {
    int source;
    int dest;
};

vector<int> reachable(vector<nodes>n, int src, int TTL);

//main
int main()
{
    int num_of_con; //number of nodes
    int TTL;
    vector<nodes> n;
    vector<int> reach;
    vector<int> res;
    nodes n_current;
    int start_node;
    bool unique;

    while (cin >> num_of_con)
    {
        n.clear();
        reach.clear();
        res.clear();

        if (num_of_con != 0) {
            for (int i = 0; i < num_of_con; ++i) {
                cin >> n_current.source;
                cin >> n_current.dest;
                n.push_back(n_current);
            }
            cin >> start_node;
            cin >> TTL;

            while (start_node != 0 && TTL != 0) //double check
            {
                //function()

                cin >> start_node;
                cin >> TTL;
                reach = reachable(n, start_node, TTL);
                //cout << " reachable " << reach.size() << endl;

                for (int i = 0; i < n.size(); ++i) {
                    cout << n[i].source << " " << n[i].dest << endl;
                }

                for (int j = 0; j < reach.size(); ++j) {
                    unique = true;
                    for (int k = 0; k < res.size(); ++k) {
                        if (reach[j] == res[k]) {
                            unique = false;
                        }
                    }

                    if (unique) {
                        res.push_back(reach[j]);
                    }
                }
                cout << "res\n";
                for (int i = 0; i < res.size(); ++i) {
                    cout << res[i] << endl;
                }
            }
        } else {
            break;
        }
    }
    return 0;
}

vector<int> reachable(vector<nodes>n, int src, int TTL)
{
    vector<int> reach;
    vector<int> res;
    cout << "start node= " << src << endl;

    if (TTL == 0) {
        for (int i = 0; i < n.size(); ++i) {
            //cout<< "src =" << src << endl;
            if (n[i].source == src) {
                reach.push_back(n[i].source);
                //cout << "sdaf" << reach.size() << endl;
            }
        }
    } else {
        for (int i = 0; i < n.size(); ++i) {
            if (n[i].source == src) {
                res = reachable(n, n[i].dest, TTL - 1);
                for (int j = 0; j < res.size(); ++j) {
                    reach.push_back(res[j]);
                }
                reach.push_back(src);
            }

            if (n[i].dest == src) {
                res = reachable(n, n[i].source, TTL - 1);
                for (int j = 0; j < res.size(); ++j) {
                    reach.push_back(res[j]);
                }
                //reach.push_back(n[i].dest);
            }
        }
    }

    return reach;
}