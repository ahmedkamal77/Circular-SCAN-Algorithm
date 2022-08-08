// Circular SCAN (C-SCAN).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    set <int> higherTracks;
    set <int>::iterator higherIt = higherTracks.begin();
    set <int> lowerTracks;
    set <int>::iterator lowerIt = lowerTracks.begin();
    int direction = 1, n = 0, x = 0;  //1 means away cylinder center (Right), 0 means twards cylinder center (Left)
    int track = 0, totalTracks = 0;
    cout << "Enter number of tracks and Initial Position and Direction e.g 70 50 1:";
    cin >> n >> track >> direction;
    cout << endl;
    cout << "Enter the number of element:";
    cin >> x;
    cout << endl;
    cout << "Enter the sequence of tracks:";
    for (int i = 0; i < x; i++)
    {
        int y = 0;
        cin >> y;
        if (y >= track)
            higherTracks.insert(y);
        else
            lowerTracks.insert(y);
    }
    cout << endl;
    

    if (direction == 1)
    {
        higherIt = higherTracks.begin();
        for (int i = 0; i < higherTracks.size(); i++)
        {
            totalTracks += *higherIt - track;
            track = *higherIt;
            higherIt++;
        }

        totalTracks += (n-track); 
        track = 0;
        lowerIt = lowerTracks.begin();

        for (int i = 0; i < lowerTracks.size(); i++)
        {
            totalTracks += *lowerIt - track;
            track = *lowerIt;
            lowerIt++;
        }
    }

    else
    {
        lowerIt = lowerTracks.end();
        lowerIt--;
        for (int i = 0; i < lowerTracks.size(); i++)
        {
            totalTracks += track - *lowerIt;
            track = *lowerIt;
            lowerIt--;
        }

        totalTracks += track - 0;  
        track = n; 
        higherIt = higherTracks.end();
        higherIt--;

        for (int i = 0; i < higherTracks.size(); i++)
        {
            totalTracks += track - *higherIt;
            track = *higherIt;
            higherIt--;
        }
    }

    cout << "Total tracks = " << totalTracks << endl;  //assumig that seek time = 1 ms for each track 
}


