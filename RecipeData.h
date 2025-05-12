#ifndef RECIPE_DATA_H
#define RECIPE_DATA_H

#include <stdio.h>
#include <string.h>

#define MAX_INGREDIENTS 8
#define MAX_RECIPE_NAME 1000
#define MAX_RECIPES 20  //Increase it according to no of recipes added

// Define a structure for ingredients
struct Ingredient {
    char name[MAX_RECIPE_NAME];
};

// Define a structure for recipes
struct Recipe {
    char name[MAX_RECIPE_NAME];
    struct Ingredient ingredients[MAX_INGREDIENTS];
    int numIngredients;
};

// Function declarations
void printIngredients();
void selection(struct Ingredient *ingredientsOption, struct Ingredient *selectedIngredients, int *numSelectedIngredients);
void printSelectedIngredients(struct Ingredient *selectedIngredients, int numSelectedIngredients);
void search(struct Ingredient *selectedIngredients, struct Recipe *recipes, int numSelectedIngredients, int numRecipes, struct Ingredient *ingredientsOption);

// Initialize ingredient options
extern struct Ingredient ingredientsOption[MAX_INGREDIENTS];

// Initialize recipes
extern struct Recipe recipes[MAX_RECIPES];

#endif