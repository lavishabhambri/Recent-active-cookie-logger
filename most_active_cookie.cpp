// Include all the necessary libraries
#include <iostream>  
#include <fstream>
#include <map>
#include <vector>
#include <set>
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

// Class to store the cookie details (cookie name, date).
class cookieDetails {
    public:
    string cookie = "";
    string date = "";
    cookieDetails(string cookie, string date) {
        this->cookie = cookie;
        this->date = date;
    }
};

// Function to process the CSV and extract all cookies.
cookieDetails processCSV(string line) {
    string cookie = "";
    string date = "";
    int length = line.length();
    int i = 0;
    for (i; i < length; i++) {
        while (i < length && line[i] != ',') {
            cookie = cookie + line[i];
            i++;
        }
        i++;
        break;
    }
    for (int j = 0; j < 10; j++) 
        date = date + line[i+j];
    return cookieDetails(cookie, date);
}

// Function to return all the cookies logged on given input date. 
vector<string> returnAllCookiesOnGivenDate(string inputPathName, string givenDate) {
    ifstream fin;
    string line;
    bool ignoreFirstLine = true;
    vector<string> cookies;
    fin.open(inputPathName);
    while (!fin.eof()) {
        fin >> line;
        if (ignoreFirstLine) {
            ignoreFirstLine = false;
            continue;
        }
        cookieDetails processedCookie = processCSV(line);
        string cookie = processedCookie.cookie;
        string date = processedCookie.date;
        if (date == givenDate)
            cookies.push_back(cookie);
    }
    return cookies;
}

// Function to filter out the cookies with max frequency.
vector<string> findCookiesWithMaxFrequency(vector<string> cookiesOnGivenDate, string date) {
    vector<string> maxFrequencyCookies;
    map<string, int> frequencyMap;
    int maxFrequency = 0;

    for (int i = 0; i < cookiesOnGivenDate.size(); i++) {
        frequencyMap[cookiesOnGivenDate[i]]++;
        maxFrequency = max(maxFrequency, frequencyMap[cookiesOnGivenDate[i]]);
    }

    for (auto i: frequencyMap) {
        if (maxFrequency == i.second)
            maxFrequencyCookies.push_back(i.first);
    }
    return maxFrequencyCookies;
}

// Function to print the cookies with max frequency in original order.
void printCookies(vector<string> cookiesOnGivenDate, vector<string> maxFrequencyCookies) {
    set<string> uniqueCookies;
    for (int j = 0; j < cookiesOnGivenDate.size(); j++) {
        for (int i = 0; i < maxFrequencyCookies.size(); i++) {
            if ((maxFrequencyCookies[i] == cookiesOnGivenDate[j]) && (uniqueCookies.find(maxFrequencyCookies[i]) == uniqueCookies.end())) {
                cout <<  maxFrequencyCookies[i] << "\n";
            }
        }
        uniqueCookies.insert(cookiesOnGivenDate[j]);
    }
    return;
}

// Main function
int main(int argc, char **argv) {
    fast_cin();

    // Check for valid input
    if (argc != 4) {
        cout << "You entered invalid no. of arguments!\n";
        return 0;
    }

    // Find required input date & path
    string inputDate = argv[3];
    string inputPathName = argv[1];

    // Opening the file in read mode
    FILE *file;
    if (file = fopen(argv[1], "r")) {
        // Get all the cookies on the given date
        vector<string> cookiesOnGivenDate = returnAllCookiesOnGivenDate(inputPathName, inputDate);
        
        // Find cookies with max frequency 
        vector<string> maxFrequencyCookies = findCookiesWithMaxFrequency(cookiesOnGivenDate, inputDate);

        // Printing the cookies with max frequency in original order
        printCookies(cookiesOnGivenDate, maxFrequencyCookies);

        // Closing the file
        fclose(file);
    } else 
        cout << "Entered file name is invalid!\n";
    
    return 0;
}