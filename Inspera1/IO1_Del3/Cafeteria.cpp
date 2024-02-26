#include "Cafeteria.h"

Cafeteria::Cafeteria(string n, Location l) : name{n}, location{l} {
    for (auto p : mainDishPrices) {
        stock.insert({p.first, 0});
    }
    for (auto p : sideDishPrices) {
        stock.insert({p.first, 0});
    }
}

vector<DailyMenu> Cafeteria::getWeeklyMenu() { return weeklyMenu; }

void Cafeteria::setWeeklyMenu(vector<DailyMenu> menu) { weeklyMenu = menu; }

int Cafeteria::getStock(string item) { return stock.at(item); }

void Cafeteria::setStock(string item, int amount) { stock.at(item) = amount; }

void Cafeteria::removeStock(string item) { stock.at(item)--; }

//------------------------------------------------------------------------------------------------

DailyMenu Cafeteria::getDailyMenu(Weekday w) {
    // BEGIN: 1c

    return weeklyMenu.at(static_cast<int>(w));

    // END: 1c
}

bool Cafeteria::isInStock(DailyMenu menu) {
    // BEGIN: 1d
    if (!stock.contains(menu.mainDish) || !stock.contains(menu.sideDish)) {
        return false;
    }

    if (stock.at(menu.mainDish) > 0 && stock.at(menu.sideDish) > 0) {
        return true;
    }

    return false;

    // END: 1d
}

void Cafeteria::saveToFile(string fileName) {
    // BEGIN: 1e

    filesystem::path filepath(fileName);
    ofstream os(filepath);

    for (int i = 0; i < weeklyMenu.size(); ++i) {
        DailyMenu menu = weeklyMenu.at(i);
        os << menu;
    }
    os.close();

    // END: 1e
}

void Cafeteria::importStock(string fileName) {
    // BEGIN: 2a

    filesystem::path filepath(fileName);
    ifstream is(filepath);

    string line;
    while (getline(is, line)) {
        int comma_pos = line.find(",");
        string dish = line.substr(0, comma_pos);
        string items_str = line.substr(comma_pos + 2);
        int items = stoi(items_str);
        stock.at(dish) = items;
    }
    // END: 2a
}

vector<DailyMenu> generateWeeklyMenu() {
    // BEGIN: 2c

    vector<DailyMenu> menus;
    for (int i = 0; i < 7; ++i) {
        menus.push_back(getRandomMenu());
    }
    return menus;

    // END: 2c
}