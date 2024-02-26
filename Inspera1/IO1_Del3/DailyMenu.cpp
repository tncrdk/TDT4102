#include "DailyMenu.h"

const map<string, double> mainDishPrices{
    // Main dishes
    {"Burger", 55}, {"Lasagna", 70}, {"Chicken", 60},      {"Porkchops", 65},
    {"Beef", 90},   {"Soup", 50},    {"Cinnamon bun", 25}, {"Baguette", 54},
};

const map<string, double> sideDishPrices{
    {"Salad", 40}, {"Fries", 30},   {"Rice", 20},     {"Mashed potatoes", 25},
    {"Pasta", 35}, {"Caviar", 150}, {"Couscous", 50}, {"Root vegetables", 35}};

const map<string, double> adjectivePriceModifiers{
    {"Vegan", 1.4},        {"Vegetarian", 1.2}, {"Gluten-free", 2.5},
    {"Lactose-free", 1.3}, {"Sugar-free", 1.1}, {"Whole grain", 1.2},
    {"Organic", 1.4},      {"Local", 1.6}

};

//------------------------------------------------------------------------------------------------

DailyMenu createDailyMenu(string adjective, string mainDish, string sideDish) {
    // BEGIN: 1a
    double main_dish_price = mainDishPrices.at(mainDish);
    double side_dish_prize = sideDishPrices.at(sideDish);
    double adjective_modifier = adjectivePriceModifiers.at(adjective);
    double price = adjective_modifier * (main_dish_price + side_dish_prize);

    DailyMenu dummy{adjective, mainDish, sideDish, price};
    return dummy;

    // END: 1a
}
ostream &operator<<(ostream &os, DailyMenu d) {

    // BEGIN: 1b

    os << d.adjective << " " << d.mainDish << " and " << d.sideDish << ": "
       << d.price << "kr\n";
    return os;

    // END: 1b
}

string getDishFromNumber(map<string, double> m, int n) {
    int i = 0;
    for (const auto &dish : m) {
        if (i == n) {
            return dish.first;
        }
        i++;
    }

    return "";
}

DailyMenu getRandomMenu() {

    int mapSize = 8;
    // BEGIN: 2b
    random_device seed;
    default_random_engine engine(seed());
    uniform_int_distribution<int> dist_dish(0, mapSize - 1);
    uniform_int_distribution<int> dist_adjectives(
        0, adjectivePriceModifiers.size() - 1);
    string rand_main_dish =
        getDishFromNumber(mainDishPrices, dist_dish(engine));
    string rand_side_dish =
        getDishFromNumber(sideDishPrices, dist_dish(engine));
    string rand_adjective =
        getDishFromNumber(adjectivePriceModifiers, dist_adjectives(engine));
    return createDailyMenu(rand_adjective, rand_main_dish, rand_side_dish);
    // END: 2b
}