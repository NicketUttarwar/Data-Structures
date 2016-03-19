#include <vector>
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <stack>
#define MAXINT 999999

using namespace std;

void floyd_warshall_algorithm();
void print_route(int source, int destination);

map<string, int> city_numbers;
map<int, string> city_names;
vector<vector<int> > city_distances;
vector<vector<int> > city_routes;

struct MapData
{
    int source, destination, distance;
};

stack<MapData> UserInput;

int main()
{
    MapData UserInfo;
    int curr_city_size;
    string source, destination, distance;
    cout << "Welcome to MiniGPS.\n";
    cout << "--------------------------\n\n";
    cout << "To stop entering cities, type 'quit'." << endl << endl;

    while(true)
    {
        cout << "Enter Source City: ";
        getline(cin, source);
        if (source == "quit")
        {
            break;
        }
        cout << "Enter Destination City: ";
        getline(cin, destination);
        if (destination == "quit")
        {
            break;
        }
        cout << "Enter Distance between the above cities: ";
        getline(cin, distance);
        if (distance == "quit")
        {
            break;
        }
        cout << "--------------------------\n";
        if (city_numbers.find(source) == city_numbers.end())
        {
            curr_city_size = city_numbers.size();
            city_numbers[source] = curr_city_size;
            city_names[curr_city_size] = source;
        }
        if (city_numbers.find(destination) == city_numbers.end())
        {
            curr_city_size = city_numbers.size();
            city_numbers[destination] = curr_city_size;
            city_names[curr_city_size] = destination;
        }
        UserInfo.source = city_numbers[source];
        UserInfo.destination = city_numbers[destination];
        UserInfo.distance = atoi(distance.c_str());
        UserInput.push(UserInfo);

    }
    cout << "City Data Entered Successfully." << endl;
    cout << "----------------------------------\n\n";
    cout << "To exit program, type 'quit'.\n";

    /* Debug Code
    for (int i = 0; i < city_names.size(); ++i)
    {
        cout << city_names[i] << " " << city_numbers[city_names[i]] << endl;

    }
    Debug code ends*/


    floyd_warshall_algorithm();

    while(true)
    {


        cout << "Enter Source City: ";
        getline(cin, source);
        if (source == "quit")
        {
            break;
        }
        cout << "Enter Destination City: ";
        getline(cin, destination);
        cout << "-------------------------------------------------------" << endl;
        if (destination == "quit")
        {
            break;
        }
        if (city_numbers.find(source) == city_numbers.end())
        {
            cout << source << " is not a valid city name. Please Try again.\n";
        }
        else if (city_numbers.find(destination) == city_numbers.end())
        {
            cout << destination << " is not a valid city name. Please Try Again.\n";
        }
        else if (city_distances[city_numbers[source]][city_numbers[destination]] != MAXINT)
        {


            cout << "Distance between " << source << " and " << destination << " is " << city_distances[city_numbers[source]][city_numbers[destination]] << " miles." << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << "The route to follow is: " << endl;
            print_route(city_numbers[source], city_numbers[destination]);

        }
        else
        {
            cout << "*****Route Does Not Exist******" << endl;
        }
        cout << "-------------------------------------------------------" << endl;
    }
     /*   while((a.start_name[i]!=start) && (i<a.start_name.size()))
    {
        if(i==a.start_name.size())
        {
            a.start_name.push_back(start);
            cout<<"----"<<a.start_name[0]<<"----\n";
        }
        i++
    }
    //start_name.push_back(start);
    //start_name.push_back("second");
*/
    system("PAUSE");
    return 0;

}

void floyd_warshall_algorithm()
{
    //cout << "DEBUG1 entered" << endl;
    MapData temp;
    int total_nodes = city_names.size();

    //resizing vector to suit our dimensions
    city_distances.resize(total_nodes);
    city_routes.resize(total_nodes);
    //cout << "DEBUG2 entered" << endl;
    for (int i = 0; i < total_nodes; ++i)
    {
        city_distances[i].resize(total_nodes);
        city_routes[i].resize(total_nodes);
    }
    //cout << "DEBUG3 entered" << endl;
    //resize end

    //initializing the vectors
    for (int i = 0; i < total_nodes; ++i)
    {
        //cout << "DEBUG4 entered" << endl;
        for (int j = 0; j < total_nodes; ++j)
        {
            //cout << "DEBUG5 entered" << endl;
            city_distances[i][j] = MAXINT; //initializing array to infinity
            city_routes[i][j] = -1;
            if (i == j)
            {
                city_distances[i][j] = 0;
            }
        }
    }
    //cout << "DEBUG6 entered" << endl;

    //taking input from user and pushing it into the array
    while(!UserInput.empty())
    {
        //cout << "DEBUG8 entered" << endl;
        temp = UserInput.top();
        city_distances[temp.source][temp.destination] = temp.distance;
        city_distances[temp.destination][temp.source] = temp.distance;
        UserInput.pop();
    }
    //cout << "DEBUG7 entered" << endl;

    //actual calculation
    for (int k = 0; k < total_nodes; ++k)
    {
        for (int i = 0; i < total_nodes; ++i)
        {
            for (int j = 0; j < total_nodes; ++j)
            {
                if (city_distances[i][k] + city_distances[k][j] < city_distances[i][j])
                {
                    city_distances[i][j] = city_distances[i][k] + city_distances[k][j];
                    city_routes[i][j] = k;

                }
            }

        }
    }
    return;

}

void print_route(int source, int destination)
{
    if (city_routes[source][destination] == -1)
    {
        cout << city_names[source] << " -> " << city_names[destination] << ". Distance: " << city_distances[source][destination] << " miles" << endl;
        return;
    }
    else
    {
        print_route(source, city_routes[source][destination]);
        print_route(city_routes[source][destination], destination);
        return;
    }
}

