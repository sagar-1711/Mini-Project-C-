#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <math.h>
#include <iomanip>
#include <string>
#include <unordered_map>
using namespace std;

bool empty1 = false;
bool empty2 = false;

template <typename X>
class graph
{

private:
    //storing inter-connected cities in an oredered map with there name and distance or weight in pair
    map<X, list<pair<X, int>>> m;

    //avg speed of diff transports
    double car_speed = 70;

    //counter
    int i = 1;

    // Stroing destination and sources
    X des1 = "AIIMS";
    X des2 = "Fortis";
    X src;
    X des;

    // Total distance from source to destination.
    double distance1 = 0;
    double distance2 = 0;
    int distance = 0;
    double car_time = 0;

    double car_before_dec = 0;
    double car_after_dec = 0;

    double car_cost = 0;

    int car_base_fare = 500;
    int car_per10km = 80;

    string car = "CAR";

    int x = 0;

    string name_arr[7];
    string lname_arr[7];
    int age_arr[7];

    double total_cost = 0;
    double cost = 0;

public:
    // Adding nodes with one another and making them bi-directional
    //it is working like a list. multilinked list

    void addEdge(X u, X v, int dist)
    {

        m[u].push_back(make_pair(v, dist));
        m[v].push_back(make_pair(u, dist));
    }

    // this function is to print the all cities. in an ordered way or alphabatical order.
    void print()
    {

        for (auto j : m)
        {

            cout << i << ". " << j.first;

            if (i % 2 == 0)
            {

                cout << endl;
            }
            else
            {

                int spacesize = 50;
                string str = j.first;
                int size = str.length();
                spacesize = spacesize - size;
                for (int i = 0; i < spacesize; i++)
                {

                    cout << " ";
                }
            }
            i++;
        }
    }

    //dijkstra's algorithm or single source shortest path algorithm that can be used to calculate the shortest path between the node

    void SSSP()
    {

        map<X, int> dist;
        unordered_map<X, X> parent_map;
        set<pair<int, X>> s;

        for (auto node : m)
        {

            dist[node.first] = INT_MAX;
        }

        dist[src] = 0;
        parent_map[src] = src;
        s.insert(make_pair(0, src));

        while (!s.empty())
        {

            auto p = (*s.begin());

            X parent = p.second;
            int parent_dist = p.first;

            s.erase(s.begin());

            for (auto children : m[parent])
            {

                if (dist[children.first] > dist[parent] + children.second)
                {

                    auto f = s.find(make_pair(dist[children.first], children.first));

                    if (f != s.end())
                    {

                        s.erase(f);
                    }

                    dist[children.first] = dist[parent] + children.second;

                    parent_map[children.first] = parent;

                    s.insert(make_pair(dist[children.first], children.first));
                }
            }
        }

        X temp1 = "AIIMS";

        for (auto d : dist)
        {

            if ("AIIMS" == d.first)
            {

                distance1 = d.second;
            }
        }

        X temp2 = "Fortis";

        for (auto d : dist)
        {

            if ("Fortis" == d.first)
            {

                distance2 = d.second;
            }
        }

        if (distance1 <= distance2)
        {

            des = "AIIMS";
            distance = distance1;
        }
        else
        {

            des = "Fortis";
            distance = distance2;
        }

        X temp = des;

        while (temp != src)
        {

            cout << temp << "<--";

            temp = parent_map[temp];
        }

        cout << src << endl;
        cout << "Total Distance :- " << distance << "Km" << endl;
    }

    void addingedges()
    {

        addEdge("Kalindi Kunj", "Vaishali", 20);
        addEdge("Kalindi Kunj", "Vasant Vihar", 26);
        addEdge("Kalindi Kunj", "Chandini Chowk", 5);
        addEdge("Chandini Chowk", "AIIMS", 5);
        addEdge("Vasant Vihar", "Fortis", 15);
        addEdge("Vaishali", "Fortis", 30);
        addEdge("Vaishali", "Iskcon", 30);
        addEdge("Iskcon", "Khan Market", 31);
        addEdge("Khan Market", "Connaught place", 25);
        addEdge("Connaught place", "Vaishali", 21);
        addEdge("Iskcon", "Fortis", 10);
        addEdge("Connaught place", "Jama Masjid", 17);
        addEdge("Jama Masjid", "AIIMS", 8);
        addEdge("Jama Masjid", "Kalindi Kunj", 15);
    }

    void checksource(int source)
    {

        if (source >= 40)
        {

            cout << "Invalid Entry" << endl;
        }
        else
        {
            empty1 = true;
            int checkr = 1;
            for (auto j : m)
            {

                if (checkr == source)
                {

                    src = j.first;
                    cout << src;
                    break;
                }
                checkr++;
            }
        }
    }

    void timefunction()
    {
        //Car
        car_time = distance / car_speed;

        car_after_dec = modf(car_time, &car_before_dec);
        car_after_dec = (car_after_dec * 6) / 10;
        car_time = car_after_dec + car_before_dec;
    }

    void space(int i)
    {

        for (int i = 0; i < 30 - i; i++)
        {

            cout << " ";
        }
    }

    void space(string naam)
    {

        for (int i = 0; i < 30 - naam.length(); i++)
        {

            cout << " ";
        }
    }

    void print_all()
    {

        for (int i = 1; i <= 100; i++)
        {

            cout << "*";
        }
        cout << endl;
        space("aaa");
        cout << "TIME(Hrs)";
        cout << car;
        space(car);
        cout << fixed << setprecision(2) << car_time;
    }
};

int main()
{

    graph<string> india;

    cout << endl;

    india.addingedges();

    india.print();
    cout << endl;
    cout << "Enter Number of starting point :-  ";
    int start;
    cin >> start;
    india.checksource(start);
    cout << endl;
    cout << endl;
    cout << "Route map :- " << endl;
    india.SSSP();
    cout << endl;
    india.timefunction();
    india.print_all();
    return 0;
}
