#include "bouncingBall.h"
#include "course_catalogue.h"
#include "std_lib_facilities.h"
#include <fstream>
#include <string>

void read_and_echo(std::ofstream &stream);
void linenumbers(std::ofstream &ostream, std::ifstream &istream);

const map<string, string> capitalsMap{
    {"Norway", "Oslo"}, {"Sweden", "Stockholm"}, {"Denmark", "Copenhagen"}};

// Må ha .at() siden mappet er const
string getCapital(const string &country) { return capitalsMap.at(country); }

int main() {
    // Oppg. 1a
    // std::filesystem::path oppg1_path{"Oppg1.txt"};
    // std::ofstream output_stream{oppg1_path};
    // read_and_echo(output_stream);
    // output_stream.close();

    // // b)
    // std::ofstream output_stream_1{std::filesystem::path{"New_text.txt"}};
    // std::ifstream input_stream{std::filesystem::path{"Oppg1.txt"}};
    // linenumbers(output_stream_1, input_stream);

    // Oppg. 2
    // cout << "Capitals:" << endl;
    // for (pair<const string, const string> elem : capitalsMap) {
    //     cout << getCapital(elem.first) << endl;
    // }

    // Oppg. 3
    // CourseCatalogue::test_course_catalogue();

    // Oppg. 4
    bouncing_ball();
    return 0;
}

void read_and_echo(std::ofstream &stream) {
    std::string str;
    std::string input;
    while (true) {
        cout << "Skriv et ord: ";
        cin >> input;
        if (input == "quit" || input == "q") {
            break;
        }
        input.push_back('\n');
        str.append(input);
    }

    stream << str;
}

void linenumbers(std::ofstream &ostream, std::ifstream &istream) {
    int i = 1;
    std::string line;
    std::string new_text = "";
    if (!istream) {
        std::cout << "Read-file doesnt exist";
        return;
    }
    while (std::getline(istream, line)) {
        new_text += to_string(i) + " " + line + '\n';
        ++i;
    }

    ostream << new_text;
}