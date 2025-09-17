#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first == b.first) 
            return a.second < b.second;
        return a.first > b.first;
    }
};

class FoodRatings {
private:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<pair<int,string>, cmp>> cuisineToFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
            cuisineToFoods[cuisine].insert({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        cuisineToFoods[cuisine].erase({oldRating, food});

        cuisineToFoods[cuisine].insert({newRating, food});

        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->second;
    }
};
