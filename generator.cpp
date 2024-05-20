#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Paper {
    string people;
    string title;
    string journal;
    string numbers;
    string link;
    string doi;
    string text;
};

vector<Paper> readCSV(const string& filename) {
    vector<Paper> papers;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Could not open the file " << filename << endl;
        return papers;
    }

    // Skip header line
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string item;
        Paper paper;

        getline(ss, paper.people, '\t');
        getline(ss, paper.title, '\t');
        getline(ss, paper.journal, '\t');
        getline(ss, paper.numbers, '\t');
        getline(ss, paper.link, '\t');
        getline(ss, paper.doi, '\t');
        getline(ss, paper.text, '\t');

        papers.push_back(paper);
    }

    file.close();
    return papers;
}
string line0 = "<div class=\"paper\">";
string line1 = "<div class=\"paper-details\">";
string line2 = "<span class=\"paper-people\">";
// line3 = paper-people;
string line4 = "</span>";
string line5 = "<span class=\"paper-title\">";
// line6 = paper-title
string line7 = "</span>";
string line8 = "<span class=\"paper-journal\">";
// line9 = paper-journal
string line10 = "</span>";
string line11 = "<span class=\"paper-numbers\">";
// line12 = paper-numbers
string line13 = "</span>";
string line14_1 = "<a class=\"paper-doi\" href=\"";
// line14_2 = paper-link 
string line14_3 = "\" target=\"_blank\">";
// line15 =  paper-doi
string line16 = "</a>";
string line17 = "<span class=\"paper-text\">";
// line18 = paper-text
string line19 = "</span>";
string line20 = "</div>";
string line21 = "</div>";


void writeFormattedTextToFile(const string& filename, const vector<Paper>& papers) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Could not open the file " << filename << endl;
        return;
    }

    for (const auto& paper : papers) {
        // file << paper.people << ": " << paper.title << " : " << paper.journal << endl;
        // file << paper.numbers << " : " << paper.doi << " : " << paper.link << endl;
        // file << paper.text << endl << endl;
        file << line0 << endl;
        file << line1 << endl;
        file << line2 << endl;
        file << paper.people << endl;
        file << line4 << endl;
        file << line5 << endl;
        file << paper.title << endl;
        file << line7 << endl;
        file << line8 << endl;
        file << paper.journal << endl;
        file << line10 << endl;
        file << line11 << endl;
        file << paper.numbers << endl;
        file << line13 << endl;
        file << line14_1 ;
        file << paper.link ;
        file << line14_3 << endl;
        file << paper.doi << endl;
        file << line16 << endl;
        file << line17 << endl;
        file << paper.text << endl;
        file << line19 << endl;
        file << line20 << endl;
        file << line21 << endl;

    }

    file.close();
}

int main() {
    string inputFilename = "papers_data/tsv_files/future.tsv";
    string outputFilename = "output.html";

    vector<Paper> papers = readCSV(inputFilename);
    writeFormattedTextToFile(outputFilename, papers);

    cout << "Formatted text has been written to " << outputFilename << endl;

    return 0;
}
