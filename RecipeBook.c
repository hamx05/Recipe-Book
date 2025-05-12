#include "RecipeData.h"
#include <stdlib.h>

int main() {
	char end;
	
	// Initialize selected ingredients
	struct Ingredient selectedIngredients[MAX_INGREDIENTS];
	
	// Initialize structures
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		selectedIngredients[i].name[0] = '\0';
	}
	
	// Declare numSelectedIngredients here
	int numSelectedIngredients;
	
	// Print the selected ingredients for confirmation
	selection(ingredientsOption, selectedIngredients, &numSelectedIngredients);
	printSelectedIngredients(selectedIngredients, numSelectedIngredients);
	
	// Search for matched recipes
	search(selectedIngredients, recipes, numSelectedIngredients, MAX_RECIPES, ingredientsOption);
	printf("\nDo you want to continue? (Y/N): ");
	scanf(" %c", &end);
	
		
	while (end=='Y' || end=='y') {
	    // Initialize selected ingredients
	    struct Ingredient selectedIngredients[MAX_INGREDIENTS];
	
	    // Initialize structures
	    for (int i = 0; i < MAX_INGREDIENTS; i++) {
	        selectedIngredients[i].name[0] = '\0';
	    }
	
	    // Declare numSelectedIngredients here
	    int numSelectedIngredients;
	
	    // Print the selected ingredients for confirmation
	    selection(ingredientsOption, selectedIngredients, &numSelectedIngredients);
	    printSelectedIngredients(selectedIngredients, numSelectedIngredients);
	
	    // Search for matched recipes
	    search(selectedIngredients, recipes, numSelectedIngredients, MAX_RECIPES, ingredientsOption);
	    printf("\nDo you want to select ingredients again? (Y/N): ");
	    scanf(" %c", &end);
	}
	
	if (end!='Y' || end!='y') {
		printf("The program has exited. Thank you for using our software!");\
		exit (1);
	}
	
    return 0;
}